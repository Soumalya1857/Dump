package DesignPatterns.ObservablePattern.Observer;

import DesignPatterns.ObservablePattern.Observable.IStocksObservable;

public class EmailNotificationAlertObserver implements IObserver{

    private IStocksObservable stocksObservable;

    public EmailNotificationAlertObserver(IStocksObservable stocksObservable){
        this.stocksObservable = stocksObservable;
    }

    @Override
    public void update() {
        sendMail();
    }

    private void sendMail() {
        System.out.println("Email triggered for Iphones. new stocks added: " + this.stocksObservable.getStocks());
    }
}
