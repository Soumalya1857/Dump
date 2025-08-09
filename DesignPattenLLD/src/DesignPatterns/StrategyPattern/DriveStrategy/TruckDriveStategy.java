package DesignPatterns.StrategyPattern.DriveStrategy;

public class TruckDriveStategy implements IDriveStrategy{
    @Override
    public void drive() {
        System.out.println("Drive with powerrrr!!");
    }

    @Override
    public void honk() {
        System.out.println("Loud truck horn!!!!");
    }
}
