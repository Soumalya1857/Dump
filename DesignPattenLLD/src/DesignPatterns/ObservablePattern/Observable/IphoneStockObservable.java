package DesignPatterns.ObservablePattern.Observable;

import DesignPatterns.ObservablePattern.Observer.IObserver;

import java.util.ArrayList;
import java.util.List;

public class IphoneStockObservable implements IStocksObservable{

    private List<IObserver> observerList;
    private int stockCount;

    public IphoneStockObservable(){
        observerList = new ArrayList<>();
        stockCount = 0;
    }

    @Override
    public void add(IObserver observer) {
        this.observerList.add(observer);
    }

    @Override
    public void remove(IObserver observer) {
        this.observerList.remove(observer);
    }

    @Override
    public void notifyAllObserver() {
        for(IObserver observer : observerList){
            observer.update(); // call all the upadte method
        }
    }

    @Override
    public void addStocks(int data) {
        if(stockCount == 0){
            this.stockCount = data;
            notifyAllObserver(); // if the stock count was 0 and new stocks are added call all the subscribers
        }else{
            this.stockCount += data;
        }
    }

    @Override
    public int getStocks() {
        return this.stockCount;
    }
}
