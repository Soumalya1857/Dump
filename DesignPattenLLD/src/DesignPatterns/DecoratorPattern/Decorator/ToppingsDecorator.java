package DesignPatterns.DecoratorPattern.Decorator;

import DesignPatterns.DecoratorPattern.Base.BasePizza;

public abstract class ToppingsDecorator extends BasePizza{
    // TopppingsDecorator should have a constuctor
    // yes they can have a constructor => they need NOT to be static for final

    BasePizza basePizza; // has a relationship, for constructor chaining

    public ToppingsDecorator(BasePizza basePizza){
        this.basePizza = basePizza;
    }

    abstract public int cost();
}
