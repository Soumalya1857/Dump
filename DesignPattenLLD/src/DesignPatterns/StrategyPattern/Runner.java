package DesignPatterns.StrategyPattern;

import DesignPatterns.StrategyPattern.DriveStrategy.IDriveStrategy;
import DesignPatterns.StrategyPattern.DriveStrategy.SportsDriveStrategy;
import DesignPatterns.StrategyPattern.DriveStrategy.TruckDriveStategy;
import DesignPatterns.StrategyPattern.Vechicle.IVehicle;
import DesignPatterns.StrategyPattern.Vechicle.SportsVehicle;
import DesignPatterns.StrategyPattern.Vechicle.TruckVehicle;

public class Runner {
    //https://refactoring.guru/design-patterns/strategy
    //https://youtu.be/u8DttUrXtEw?si=8SLezh-kmt3e7imb\

    /*How to do it with spring boot 's dependency manager
    * https://thegeekyasian.com/strategy-pattern-spring-boot/
    * https://github.com/thegeekyasian/strategy-pattern-in-spring-boot
    *
    * create a common interface as usual
    * mark all the strategy classes with @Service("StrategyType") annotation
    * and we can get all the concrete implementations of NotificationService interface by Autowiring NotificationService.
    *
    * we can use @Qualifier to differentiate between different implementation of an interface
    *
    * if not then it will give you list of all implementation of that particular interface
    * you can also take it as Map<"qualifierName", object> interfaceObjects
    * */

    public static void main(String[] args) {
        IDriveStrategy sportsStrategy = new SportsDriveStrategy();
        IDriveStrategy truckStrategy = new TruckDriveStategy();

        IVehicle sportsVehicle = new SportsVehicle(sportsStrategy);
        IVehicle truckVehicle = new TruckVehicle(truckStrategy);


        sportsVehicle.drive();
        truckVehicle.drive();

        System.out.println("------------------------------------");

        sportsVehicle.honk();
        truckVehicle.honk();
    }
}
