package StrategyPattern.DriveStrategy;

public class SportsDriveStrategy implements IDriveStrategy{

    @Override
    public void drive() {
        System.out.println("drive with SPEEEEEEEEEEEEEEEEDDDDDDDDDDDDDDd!!! ");
    }

    @Override
    public void honk() {
        System.out.println("Squiky sports honkkk!");
    }
}
