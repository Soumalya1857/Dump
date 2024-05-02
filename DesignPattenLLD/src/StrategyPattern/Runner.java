package StrategyPattern;

import StrategyPattern.DriveStrategy.IDriveStrategy;
import StrategyPattern.DriveStrategy.SportsDriveStrategy;
import StrategyPattern.DriveStrategy.TruckDriveStategy;
import StrategyPattern.Vechicle.IVehicle;
import StrategyPattern.Vechicle.SportsVehicle;
import StrategyPattern.Vechicle.TruckVehicle;

public class Runner {

    /*https://refactoring.guru/design-patterns/strategy*/
    /*https://youtu.be/u8DttUrXtEw?si=8SLezh-kmt3e7imb*/

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
