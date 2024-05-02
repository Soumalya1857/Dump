package StrategyPattern.Vechicle;

import StrategyPattern.DriveStrategy.IDriveStrategy;

public class SportsVehicle extends BaseVehicle{

    public SportsVehicle(IDriveStrategy driveStrategy){
        super(driveStrategy);
    }
}
