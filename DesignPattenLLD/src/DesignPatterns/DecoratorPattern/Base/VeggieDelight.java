package DesignPatterns.DecoratorPattern.Base;

public class VeggieDelight extends BasePizza {


    @Override
    public int cost() {
        return 200; // base cost for BasePizza VeggieDelight
    }

    @Override
    public StringBuilder getDescription() {
        return new StringBuilder("VeggieDelight");
    }
}
