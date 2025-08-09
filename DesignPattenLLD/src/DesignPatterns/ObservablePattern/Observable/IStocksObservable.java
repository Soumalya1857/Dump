package DesignPatterns.ObservablePattern.Observable;

import DesignPatterns.ObservablePattern.Observer.IObserver;

public interface IStocksObservable{

    public void add(IObserver observer);
    public void remove(IObserver observer);

    public void notifyAllObserver();

    public void addStocks(int data);
    public int getStocks();
}