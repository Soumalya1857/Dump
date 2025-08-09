package DesignPatterns.StrategyPattern.Vechicle;

import DesignPatterns.StrategyPattern.DriveStrategy.IDriveStrategy;

public class SportsVehicle extends BaseVehicle{

    public SportsVehicle(IDriveStrategy driveStrategy){
        super(driveStrategy);
    }
}
