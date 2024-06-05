import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

class Vehicle {
    /**
     * The class Vehicle represents a vehicle with a speed attribute.
     * The class Vehicle has a constructor that receives an initial speed and sets the speed attribute to that value.
     * 
     * @param initialSpeed the initial speed of the vehicle
     */

    private double speed = 0;

    public Vehicle(double initialSpeed) {
        speed = initialSpeed; 
    }

    public void accelerate(double amount) {
        speed = speed + amount; // increase the speed by the amount
    }
}

class FuelType {

    private final double litresPerKmH;

    public FuelType(double litresPerKmH) {
        this.litresPerKmH = litresPerKmH;
    }

    public double getLitresPerKmH() {
        return litresPerKmH;
    }
}

// Exception implementation
class NullPointerException extends Exception {
    public NullPointerException(String message) {
        super(message); // call the constructor of the superclass to print the message
    }
}

class Car extends Vehicle{
    /**
     * The class Car extends the class Vehicle and adds a fuel attribute to it.
     * The fuel attribute represents the amount of fuel in the car.
     * The class Car also has a method accelerate that receives an amount and increases the speed of the car by that amount.
     * 
     * The method accelerate should also decrease the amount of fuel in the car.
     * 
     * @throws NullPointerException if the fuel type is null
     * 
     * @param initialSpeed the initial speed of the car
     * @param f the fuel type of the car
     */

    private double fuel = 0;
    private final FuelType fuelType;

    public Car(double initialSpeed, FuelType f) throws NullPointerException {
        super(initialSpeed);
        if (f == null) {
            throw new NullPointerException("null fuel type is not allowed");
        }
        fuelType = f;
    }
 
    /**
     * Compute the amount of fuel consumed by the car given the amount of fuel and the litres per km/h
     * @param amount the amount of fuel
     * @param litresPerKmH the amount of litres per km/h
     * @return
     */
    public static double computeConsumedFuel(double amount, double litresPerKmH) {
        return amount / litresPerKmH;
    }


    // Override the accelerate method to decrease the fuel
    @Override
    public void accelerate(double amount) {
        double f = computeConsumedFuel(amount, fuelType.getLitresPerKmH());
        if (f < fuel) {
            super.accelerate(amount);
            fuel = fuel - f;
        } else {
            double increaseSpeed = fuel / fuelType.getLitresPerKmH();
            super.accelerate(increaseSpeed);
            fuel = 0;
        }
    }

    public static void main(String[] args) throws NullPointerException {
        FuelType f = new FuelType(1.0);
        Car c = new Car(0, f);
        c.accelerate(10);

        Class<Car> cls = Car.class;
        for(Constructor<?> t: cls.getDeclaredConstructors()) {
            System.out.println(t);
        }
        for(Field t: cls.getDeclaredFields()) {
            System.out.println(t);
        }
        for(Method t: cls.getDeclaredMethods()) {
            System.out.println(t);
        }
        System.out.println("The class name is: " + cls.getName());
        System.out.println("The superclass is: " + cls.getSuperclass());
        for(Method t: cls.getSuperclass().getDeclaredMethods()) {
            System.out.println(t);
        }
        System.err.println("The package is: " + cls.getPackage());      
    }
}
