package DesignPatterns.AbstractFactory;

public class LuxaryVehicle1 implements LuxaryVehicleFactory{

    @Override
    public void sayMyName() {
        System.out.println("Luxary Vehicle 1 loading");
    }
}
