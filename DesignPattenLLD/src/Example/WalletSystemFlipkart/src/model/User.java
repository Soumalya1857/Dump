package Example.WalletSystemFlipkart.src.model;

import java.util.UUID;

public class User {

    String userId;
    String userName;
    Wallet wallet;

    public User(String userName){
        this.userId = UUID.randomUUID().toString();
        this.userName = userName;
        this.wallet = new Wallet();
    }

    public User(String userId, String userName, Wallet wallet) {
        this.userId = userId;
        this.userName = userName;
        this.wallet = wallet;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public Wallet getWallet() {
        return wallet;
    }

    public void setWallet(Wallet wallet) {
        this.wallet = wallet;
    }
}
