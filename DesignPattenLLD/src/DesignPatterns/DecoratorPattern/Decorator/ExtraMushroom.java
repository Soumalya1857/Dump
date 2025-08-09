package DesignPatterns.DecoratorPattern.Decorator;

import DesignPatterns.DecoratorPattern.Base.BasePizza;

public class ExtraMushroom extends ToppingsDecorator{
    public ExtraMushroom(BasePizza basePizza) {
        super(basePizza);
    }

    @Override
    public int cost() {
        return 20 + basePizza.cost();
    }

    @Override
    public StringBuilder getDescription() {
        return basePizza.getDescription().append(new StringBuilder("+ ExtraMushroom"));
    }
}
