package DesignPatterns.DecoratorPattern.Base;

public class MargherittaPizza extends BasePizza {

    @Override
    public int cost() {
        return 100; // price for base pizza class
    }

    @Override
    public StringBuilder getDescription() {
        return new StringBuilder("MargherittaPizza");
    }
}
