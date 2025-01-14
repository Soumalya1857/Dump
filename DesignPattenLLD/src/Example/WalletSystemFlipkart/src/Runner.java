package Example.WalletSystemFlipkart.src;

import Example.WalletSystemFlipkart.src.constant.SourceType;
import Example.WalletSystemFlipkart.src.constant.TransactionType;
import Example.WalletSystemFlipkart.src.constant.ViewType;
import Example.WalletSystemFlipkart.src.model.Flipkart;
import Example.WalletSystemFlipkart.src.model.User;
import Example.WalletSystemFlipkart.src.service.FlipkartServiceImpl;
import Example.WalletSystemFlipkart.src.service.UserServiceImpl;
import Example.WalletSystemFlipkart.src.service.WalletServiceImpl;
import Example.WalletSystemFlipkart.src.service.iservice.IFlipkartService;
import Example.WalletSystemFlipkart.src.service.iservice.IUserService;
import Example.WalletSystemFlipkart.src.service.iservice.IWalletService;

public class Runner {



    public static void main(String[] args) {
        try{
            IUserService userService = new UserServiceImpl();
            IWalletService walletService = new WalletServiceImpl();
            IFlipkartService flipkartService = new FlipkartServiceImpl();


            Flipkart fkSystem = new Flipkart();

            User user1 = new User("Soumalya");
            User user2 = new User("Abhishek");
            User user3 = new User("John");


            flipkartService.registerUser(fkSystem, user1);
            flipkartService.registerUser(fkSystem, user2);
            flipkartService.registerUser(fkSystem, user3);

            userService.loadMoney(user1, 200.78, SourceType.CREDIT);
            walletService.sendMoney(user1.getWallet(), user2.getWallet(), 100);
            walletService.sendMoney(user1.getWallet(), user3.getWallet(), 100);
            walletService.sendMoney(user2.getWallet(), user1.getWallet(), 50.5);

            System.out.println(walletService.showOrderedHistory(user1.getWallet(), ViewType.TIME_BASED));


            System.out.println(walletService.showFilteredHistory(user1.getWallet(), TransactionType.SENT ));




//            System.out.println(user1.getWallet());
//            System.out.println(user2.getWallet());
//            System.out.println(user3.getWallet());





        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}
