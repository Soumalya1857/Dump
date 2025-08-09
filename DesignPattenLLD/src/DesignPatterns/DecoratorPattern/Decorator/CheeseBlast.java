package DesignPatterns.DecoratorPattern.Decorator;

import DesignPatterns.DecoratorPattern.Base.BasePizza;

public class CheeseBlast extends ToppingsDecorator{
    public CheeseBlast(BasePizza basePizza) {
        super(basePizza);
    }

    @Override
    public int cost() {
        return 50 + basePizza.cost();
    }

    @Override
    public StringBuilder getDescription() {
        return basePizza.getDescription().append(new StringBuilder("+ CheeseBlast"));
    }
}
