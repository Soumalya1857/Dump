package Example.WalletSystemFlipkart.src.service.iservice;

import Example.WalletSystemFlipkart.src.constant.SourceType;
import Example.WalletSystemFlipkart.src.model.User;

public interface IUserService {
    void loadMoney(User user, double amount, SourceType sourceType);
}
