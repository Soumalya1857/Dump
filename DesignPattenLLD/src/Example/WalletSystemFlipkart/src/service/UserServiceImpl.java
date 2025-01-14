package Example.WalletSystemFlipkart.src.service;

import Example.WalletSystemFlipkart.src.constant.SourceType;
import Example.WalletSystemFlipkart.src.constant.TransactionStatus;
import Example.WalletSystemFlipkart.src.constant.TransactionType;
import Example.WalletSystemFlipkart.src.exception.InvalidAmountDetectedException;
import Example.WalletSystemFlipkart.src.exception.UserNotPresentException;
import Example.WalletSystemFlipkart.src.model.Transaction;
import Example.WalletSystemFlipkart.src.model.User;
import Example.WalletSystemFlipkart.src.service.iservice.IUserService;

import java.time.Instant;
import java.util.Objects;

public class UserServiceImpl implements IUserService {

    @Override
    public void loadMoney(User user, double amount, SourceType sourceType) {
        try{
            if(Objects.isNull(user)){
                throw new UserNotPresentException("User is null!");
            }

            if(amount <= 0){
                throw new InvalidAmountDetectedException("Amount: " + amount + " is less than or equal to 0");
            }

            user.getWallet().setCurrentAmount(user.getWallet().getCurrentAmount() + amount);
            user.getWallet().getTransactionList().add(
                    new Transaction(
                            user.getUserId(),
                            user.getWallet().getWalletId(),
                            Instant.now(),
                            amount,
                            sourceType,
                            TransactionType.LOAD,
                            TransactionStatus.SUCCESS,
                            "Successfully loaded money to wallet: " + user.getWallet().getWalletId() + " with amount: " + amount
                    )
            );

        }catch (UserNotPresentException e){
            throw new UserNotPresentException(e.getMessage());
        }catch(InvalidAmountDetectedException e){
            throw new InvalidAmountDetectedException(e.getMessage());
        }
    }
}
