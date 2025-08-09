package DesignPatterns.DecoratorPattern.Base;

public class MeatLover extends BasePizza{
    @Override
    public int cost() {
        return 300; // this is base cost for the pizza meatLover
    }

    @Override
    public StringBuilder getDescription() {
        return new StringBuilder("MeatLover");
    }
}
