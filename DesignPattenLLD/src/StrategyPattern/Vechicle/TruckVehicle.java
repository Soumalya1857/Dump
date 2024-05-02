package StrategyPattern.Vechicle;

import StrategyPattern.DriveStrategy.IDriveStrategy;

public class TruckVehicle extends BaseVehicle{

    public TruckVehicle(IDriveStrategy driveStrategy){
        super(driveStrategy);
    }
}
