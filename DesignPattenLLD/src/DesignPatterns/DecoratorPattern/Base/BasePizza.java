package DesignPatterns.DecoratorPattern.Base;

abstract public class BasePizza {
    int cost;
    StringBuilder description;
    public BasePizza(){
        description = new StringBuilder();
    };

    abstract public int cost();
    abstract public StringBuilder getDescription();
}
