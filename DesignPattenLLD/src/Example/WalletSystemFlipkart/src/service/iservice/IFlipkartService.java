package Example.WalletSystemFlipkart.src.service.iservice;

import Example.WalletSystemFlipkart.src.model.Flipkart;
import Example.WalletSystemFlipkart.src.model.User;

public interface IFlipkartService {

    boolean registerUser(Flipkart flipkart, User user);
    boolean deRegisterUser(Flipkart flipkart, User user);

}
