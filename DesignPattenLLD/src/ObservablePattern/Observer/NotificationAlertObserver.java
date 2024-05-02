package ObservablePattern.Observer;

import ObservablePattern.Observable.IStocksObservable;

public class NotificationAlertObserver implements IObserver{

    // but if you need more granual access
    IStocksObservable stocksObservable;

    public NotificationAlertObserver(IStocksObservable observable){
        this.stocksObservable = observable;
    }

    @Override
    public void update() {
        // trigger email saying new stocks have arrived
        // but if you need more granual access
        sendMobileNotification();
    }

    private void sendMobileNotification() {
        System.out.println("Notification triggered. New stocks just dropped: " + this.stocksObservable.getStocks() + " stocks added!!") ;
    }
}
