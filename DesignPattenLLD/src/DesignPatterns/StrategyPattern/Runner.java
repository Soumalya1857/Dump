package DesignPatterns.StrategyPattern;

import DesignPatterns.StrategyPattern.DriveStrategy.IDriveStrategy;
import DesignPatterns.StrategyPattern.DriveStrategy.SportsDriveStrategy;
import DesignPatterns.StrategyPattern.DriveStrategy.TruckDriveStategy;
import DesignPatterns.StrategyPattern.Vechicle.IVehicle;
import DesignPatterns.StrategyPattern.Vechicle.SportsVehicle;
import DesignPatterns.StrategyPattern.Vechicle.TruckVehicle;

public class Runner {
    //https://refactoring.guru/design-patterns/strategy
    //https://youtu.be/u8DttUrXtEw?si=8SLezh-kmt3e7imb

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
