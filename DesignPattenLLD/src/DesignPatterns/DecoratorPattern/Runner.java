package DesignPatterns.DecoratorPattern;

import DesignPatterns.DecoratorPattern.Base.*;
import DesignPatterns.DecoratorPattern.Decorator.*;


public class Runner {
    public static void main(String[] args) {

        /*
        * https://refactoring.guru/design-patterns/decorator
        * https://www.youtube.com/watch?v=w6a9MXUwcfY&list=PL6W8uoQQ2c61X_9e6Net0WdYZidm7zooW&index=6
        */

        // create a pizza with cheese jalapeneos and MeanLover
        BasePizza customerPizza1 = new ExtraJalapenios(new ExtraCheese( new MeatLover()));
        System.out.println("Customer ordered: " + customerPizza1.getDescription() + " and costed: " + customerPizza1.cost());

        // create a pizza with cheese jalapeneos and MeanLover
        BasePizza customerPizza2 = new ExtraMushroom(new ExtraJalapenios(new CheeseBlast( new VeggieDelight())));
        System.out.println("Customer ordered: " + customerPizza2.getDescription() + " and costed: " + customerPizza2.cost());
    }

    /*
   Use the Decorator pattern when you need to be able to assign extra behaviors to objects at runtime without breaking the code that uses these objects.
 The Decorator lets you structure your business logic into layers, create a decorator for each layer and compose objects with various combinations of this logic at runtime.
 The client code can treat all these objects in the same way, since they all follow a common interface.

    *
    * */
}
