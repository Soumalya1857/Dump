package DesignPatterns.DecoratorPattern.Decorator;

import DesignPatterns.DecoratorPattern.Base.BasePizza;

public class ExtraCheese extends ToppingsDecorator{

    public ExtraCheese(BasePizza basePizza) {
        super(basePizza);
    }

    @Override
    public int cost() {
        return 10 + basePizza.cost(); // 10 is cost for ExtraCheese and addedWith basePizza
    }

    @Override
    public StringBuilder getDescription() {
        return basePizza.getDescription().append(new StringBuilder("+ ExtraCheese"));
    }
}
