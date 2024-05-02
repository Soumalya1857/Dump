package DesignPatterns.StrategyPattern.Vechicle;

import DesignPatterns.StrategyPattern.DriveStrategy.IDriveStrategy;

public class TruckVehicle extends BaseVehicle{

    public TruckVehicle(IDriveStrategy driveStrategy){
        super(driveStrategy);
    }
}
