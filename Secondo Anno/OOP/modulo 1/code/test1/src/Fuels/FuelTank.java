package Fuels;

import vehicles.Car;

/*
* This class is used to represent a fuel tank
*
* @author Campagnolo Alberto
* @since 1.0
* */
public class FuelTank {
    private final FuelType type;
    private double amount;

  /*
  * This method is used to refuel the car
  *
  * @param c the car to refuel
  * @return nothing
  * */
    public void refuelCar(Car c) {
        c.refuel(this);
    }

    public void empty() {
        this.amount = 0.0;
    }
    /*
    * This method is responsible to refuel the current tank
    *
    * @param amount the amount of fuel
    * @return nothing
    * */
    public void refuelTank(double amount) {
        this.amount += amount;
    }

    public FuelType getType() {
        return type;
    }

    public double getAmount() {
        return amount;
    }
    // Costruttori multipli
    public FuelTank(FuelType type, double amount) {
        this.type = type; // this per riferirsi al type dell'oggetto
        this.amount = amount;
    }

    public FuelTank(FuelType type) {
        this(type, 0);
    }
}
