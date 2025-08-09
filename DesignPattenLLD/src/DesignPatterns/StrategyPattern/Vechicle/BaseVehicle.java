package DesignPatterns.StrategyPattern.Vechicle;

import DesignPatterns.StrategyPattern.DriveStrategy.IDriveStrategy;

abstract public class BaseVehicle implements IVehicle{

    IDriveStrategy driveStrategy;

    public BaseVehicle(IDriveStrategy driveStrategy){
        this.driveStrategy = driveStrategy;
    }

    public void drive(){
        driveStrategy.drive();
    }

    public void honk() {
        driveStrategy.honk();
    }
}
