package vehicles;

import Fuels.FuelTank;
import Fuels.FuelType; /**
 * This class represent the basic structure of a vehicle
 * In that file is used to create the Car class
 *
 * @author Campagnolo Alberto
 * @since 1.0*/
public abstract class Vehicle {
    protected double fuel;
    FuelType fuelType;
    protected double speed;

    public Vehicle(double speed, FuelType fuelType, double fuel) {
        this.speed = speed;
        this.fuelType = fuelType;
        this.fuel = fuel;
    }

    /**
     * This method return the speed value of the vehicle
     *
     * @return speed value of the vehicle
     */
    public double getSpeed() {
        return speed;
    }

    /**
     * This method return the fuel value of the vehicle
     *
     * @return fuel value of the vehicle
     */
    public double getFuel() {
        return fuel;
    }

    private boolean isCompatible(FuelType type) {
        return type == this.fuelType;
    }

    /**
     * This method is responsible to refuel the car
     * checking before if the FuelType of the tank is the same of the current car
     *
     * @param tank the fuel tank
     * @return the fuel value
     */
    public void refuel(FuelTank tank) {
        if (!this.isCompatible(tank.getType())) try {
            throw new Exception("Wrong fuel type");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        fuel += tank.getAmount();
        tank.empty(); //public tank function for make itself empty
    }

    /**
     * This method is responsible to accelerate the car
     *
     * @param a, the value of the acceleration
     * @return the speed value
     */
    public void accelerate(double a) {
        if (fuel < a * fuelType.get_FUEL_CONS()) try {
            throw new Exception("Not enough fuel");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        speed += a;
        fuel -= a * fuelType.get_FUEL_CONS();
    }

    // Stop the car
    public void fullBreak() {
        speed = 0.0;
    }
}
