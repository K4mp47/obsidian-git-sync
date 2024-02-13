package vehicles;

/**
* This class is used to represent the legal information about a car
*
* @author Campagnolo Alberto
* @since 1.0*/
public class CarID {
    public final String make;
    public final String model;
    public final String licensePlate;
    public final String VIN;

    public CarID(String make, String model, String licensePlate, String VIN) {
        this.make = make;
        this.model = model;
        this.licensePlate = licensePlate;
        this.VIN = VIN;
    }

    public boolean isSameLicensePlate(String licensePlate) {
        return this.licensePlate.equals(licensePlate);
    }


}
