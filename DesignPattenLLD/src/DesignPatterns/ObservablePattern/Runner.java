package DesignPatterns.ObservablePattern;

import DesignPatterns.ObservablePattern.Observable.IStocksObservable;
import DesignPatterns.ObservablePattern.Observable.IphoneStockObservable;
import DesignPatterns.ObservablePattern.Observer.EmailNotificationAlertObserver;
import DesignPatterns.ObservablePattern.Observer.IObserver;
import DesignPatterns.ObservablePattern.Observer.NotificationAlertObserver;

public class Runner {
    /*https://www.youtube.com/watch?v=Ep9_Zcgst3U&list=PL6W8uoQQ2c61X_9e6Net0WdYZidm7zooW&index=5*/

    public static void main(String[] args) {
        IStocksObservable stocksObservable = new IphoneStockObservable();

        // seems odd but okkkkkkk
        IObserver observer1 = new EmailNotificationAlertObserver(stocksObservable);
        IObserver observer2 = new EmailNotificationAlertObserver(stocksObservable);

        IObserver observer3 = new NotificationAlertObserver(stocksObservable);
        IObserver observer4 = new NotificationAlertObserver(stocksObservable);

        /*-------------------------------------------------------------------------------*/

        stocksObservable.add(observer1);
        stocksObservable.add(observer2);
        stocksObservable.add(observer3);
        stocksObservable.add(observer4);

        /*---------------------------------------------------------------------------------*/

        stocksObservable.addStocks(10);
        stocksObservable.addStocks(20); // no notification triggered

    }
}
