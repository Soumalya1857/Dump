package Example.WalletSystemFlipkart.src.model;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

public class Wallet {

    String walletId;
    double currentAmount;

    List<Transaction> transactionList;

    Wallet(){
        walletId = UUID.randomUUID().toString();
        currentAmount = 0;
        transactionList = new ArrayList<>();
    }

    public String getWalletId() {
        return walletId;
    }

    @Override
    public String toString() {
        return "Wallet{" +
                "walletId='" + walletId + '\'' +
                ", currentAmount=" + currentAmount +
                ", transactionList=" + transactionList +
                '}';
    }

    public void setWalletId(String walletId) {
        this.walletId = walletId;
    }

    public double getCurrentAmount() {
        return currentAmount;
    }

    public void setCurrentAmount(double currentAmount) {
        this.currentAmount = currentAmount;
    }

    public List<Transaction> getTransactionList() {
        return transactionList;
    }

    public void setTransactionList(List<Transaction> transactionList) {
        this.transactionList = transactionList;
    }
}
