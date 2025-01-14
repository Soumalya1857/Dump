package Example.WalletSystemFlipkart.src.model;

import Example.WalletSystemFlipkart.src.constant.SourceType;
import Example.WalletSystemFlipkart.src.constant.TransactionStatus;
import Example.WalletSystemFlipkart.src.constant.TransactionType;

import java.time.Instant;

public class Transaction {
    String sender;
    String receiver;
    Instant transactionTmstmp;
    double amount;
    SourceType sourceType;
    TransactionType transactionType;
    TransactionStatus transactionStatus;
    String note;

    public Transaction(String sender, String receiver, Instant transactionTmstmp, double amount, SourceType sourceType, TransactionType transactionType, TransactionStatus transactionStatus, String note) {
        this.sender = sender;
        this.receiver = receiver;
        this.transactionTmstmp = transactionTmstmp;
        this.amount = amount;
        this.sourceType = sourceType;
        this.transactionType = transactionType;
        this.transactionStatus = transactionStatus;
        this.note = note;
    }

    public String getSender() {
        return sender;
    }

    public void setSender(String sender) {
        this.sender = sender;
    }

    public String getReceiver() {
        return receiver;
    }

    public void setReceiver(String receiver) {
        this.receiver = receiver;
    }

    @Override
    public String toString() {
        return "Transaction{" +
                "sender='" + sender + '\'' +
                ", receiver='" + receiver + '\'' +
                ", transactionTmstmp=" + transactionTmstmp +
                ", amount=" + amount +
                ", sourceType=" + sourceType +
                ", transactionType=" + transactionType +
                ", transactionStatus=" + transactionStatus +
                ", note='" + note + '\'' +
                '}';
    }

    public Instant getTransactionTmstmp() {
        return transactionTmstmp;
    }

    public void setTransactionTmstmp(Instant transactionTmstmp) {
        this.transactionTmstmp = transactionTmstmp;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public SourceType getSourceType() {
        return sourceType;
    }

    public void setSourceType(SourceType sourceType) {
        this.sourceType = sourceType;
    }

    public TransactionType getTransactionType() {
        return transactionType;
    }

    public void setTransactionType(TransactionType transactionType) {
        this.transactionType = transactionType;
    }

    public TransactionStatus getTransactionStatus() {
        return transactionStatus;
    }

    public void setTransactionStatus(TransactionStatus transactionStatus) {
        this.transactionStatus = transactionStatus;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }
}
