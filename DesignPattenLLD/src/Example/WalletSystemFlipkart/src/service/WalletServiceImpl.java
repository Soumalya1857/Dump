package Example.WalletSystemFlipkart.src.service;

import Example.WalletSystemFlipkart.src.constant.SourceType;
import Example.WalletSystemFlipkart.src.constant.TransactionStatus;
import Example.WalletSystemFlipkart.src.constant.TransactionType;
import Example.WalletSystemFlipkart.src.constant.ViewType;
import Example.WalletSystemFlipkart.src.exception.InsufficientAmountException;
import Example.WalletSystemFlipkart.src.exception.InvalidAmountDetectedException;
import Example.WalletSystemFlipkart.src.exception.InvalidSortingOrderException;
import Example.WalletSystemFlipkart.src.exception.WalletNotFoundException;
import Example.WalletSystemFlipkart.src.model.Transaction;
import Example.WalletSystemFlipkart.src.model.Wallet;
import Example.WalletSystemFlipkart.src.service.iservice.IWalletService;

import java.time.Instant;
import java.util.Comparator;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

public class WalletServiceImpl implements IWalletService {

    private Comparator<Transaction> sortByAmount = Comparator.comparing(Transaction::getAmount);
    private Comparator<Transaction> sortByTimestamp = Comparator.comparing(Transaction::getTransactionTmstmp);



    @Override
    public List<Transaction> showOrderedHistory(Wallet wallet, ViewType viewType) {
        try{
            List<Transaction> transactionList = wallet.getTransactionList();

            if(ViewType.AMOUNT_BASED.equals(viewType)){
                transactionList.sort(sortByAmount);
            } else if(ViewType.TIME_BASED.equals(viewType)){
                transactionList.sort(sortByTimestamp);
            } else{
                throw new InvalidSortingOrderException("The sorting order is not valid!");
            }

            return transactionList;
        }catch (InvalidSortingOrderException e){
            throw new InvalidSortingOrderException(e.getMessage());
        }

    }

    @Override
    public List<Transaction> showFilteredHistory(Wallet wallet, TransactionType transactionType) {
        return wallet.getTransactionList()
                .stream()
                .filter(transaction -> transaction.getTransactionType().equals(transactionType))
                .collect(Collectors.toList());
    }

    @Override
    public boolean sendMoney(Wallet senderWallet, Wallet receiverWallet, double amount) {
        try{

            if(Objects.isNull(senderWallet) || Objects.isNull(receiverWallet)){
                throw new WalletNotFoundException("Wallet is null or not present");
            }

            if(amount <= 0){
                throw new InvalidAmountDetectedException("The amount " + amount + " is less than or equal to 0");
            }

            if(senderWallet.getCurrentAmount() < amount){
                senderWallet.getTransactionList().add(new Transaction(
                        senderWallet.getWalletId(),
                        receiverWallet.getWalletId(),
                        Instant.now(),
                        amount,
                        SourceType.WALLET_TRANSFER,
                        TransactionType.SENT,
                        TransactionStatus.FAILED,
                        "Not enough amount detected in sender wallet!"
                ));
                throw new InsufficientAmountException("Wallet with walletId " + senderWallet.getWalletId() + " doesn't have enough amount to send: " + amount );
            }

            // get amount from sender
            senderWallet.setCurrentAmount(senderWallet.getCurrentAmount() - amount);
            senderWallet.getTransactionList().add(new Transaction(
                    senderWallet.getWalletId(),
                    receiverWallet.getWalletId(),
                    Instant.now(),
                    amount,
                    SourceType.WALLET_TRANSFER,
                    TransactionType.RECEIVED,
                    TransactionStatus.SUCCESS,
                    "Successful transaction!"
                    ));

            //credit in receiver
            receiverWallet.setCurrentAmount(receiverWallet.getCurrentAmount() + amount);
            receiverWallet.getTransactionList().add(new Transaction(
                    senderWallet.getWalletId(),
                    receiverWallet.getWalletId(),
                    Instant.now(),
                    amount,
                    SourceType.WALLET_TRANSFER,
                    TransactionType.RECEIVED,
                    TransactionStatus.SUCCESS,
                    "Successful transaction!"
            ));

            return true;


        }catch(WalletNotFoundException e){
            throw new WalletNotFoundException(e.getMessage());
        } catch (InsufficientAmountException e){
            throw new InsufficientAmountException(e.getMessage());
        }
    }
}
