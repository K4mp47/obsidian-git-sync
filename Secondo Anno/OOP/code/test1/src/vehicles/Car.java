package vehicles;

import Fuels.FuelType;
import Fuels.FuelTank;

/**
* This is the generic class for the car
* @author Campagnolo Alberto
* @since 1.0
 */
public class Car extends Vehicle {

    // add constructor for initialization variables FuelType

    CarID identifier;
    public Car(double speed, FuelType fuelType, double fuel, String make, String model, String licensePlate, String VIN) {
        super(speed, fuelType, fuel);
        this.identifier = new CarID(make, model, licensePlate, VIN);
    }

    /**
    * This method return a boolean value checking if the current licensePlate
    * is the same of the one pass as parameter
    *
    * @param licensePlate the license plate of the car
    * @return boolean value*/
    public boolean checkLicensePlate(String licensePlate) {
        return identifier.isSameLicensePlate(licensePlate);
    }

    public String getLicensePlate() {
        return identifier.licensePlate;
    }

}
