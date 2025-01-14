package Example.WalletSystemFlipkart.src.service.iservice;

import Example.WalletSystemFlipkart.src.constant.TransactionType;
import Example.WalletSystemFlipkart.src.constant.ViewType;
import Example.WalletSystemFlipkart.src.model.Transaction;
import Example.WalletSystemFlipkart.src.model.Wallet;

import java.util.List;

public interface IWalletService {
    List<Transaction> showOrderedHistory(Wallet wallet, ViewType viewType);
    List<Transaction> showFilteredHistory(Wallet wallet, TransactionType transactionType);

    boolean sendMoney(Wallet senderWallet, Wallet receiverWallet, double amount);

}
