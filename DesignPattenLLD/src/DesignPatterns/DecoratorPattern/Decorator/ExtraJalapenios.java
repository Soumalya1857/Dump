package DesignPatterns.DecoratorPattern.Decorator;

import DesignPatterns.DecoratorPattern.Base.BasePizza;

public class ExtraJalapenios extends ToppingsDecorator{
    public ExtraJalapenios(BasePizza basePizza) {
        super(basePizza);
    }

    @Override
    public int cost() {
        return 30 + basePizza.cost();
    }
    @Override
    public StringBuilder getDescription() {
        return basePizza.getDescription().append(new StringBuilder("+ ExtraJalapenios"));
    }
}
