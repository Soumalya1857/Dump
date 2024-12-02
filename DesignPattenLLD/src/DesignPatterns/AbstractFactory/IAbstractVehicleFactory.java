package DesignPatterns.AbstractFactory;

public interface IAbstractVehicleFactory {
    void sayMyName(); // gives car name "sports car, utility car"
    void giveCarSpecs(); // gives type of car "SUV", "Sedan", "hatchback"
}
