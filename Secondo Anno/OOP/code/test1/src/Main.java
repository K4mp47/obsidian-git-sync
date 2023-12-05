class Car {
    double speed;
    FuelType fuelType;
    double fuel;

    // add constructor for initialization variables FuelType
    Car(double speed, FuelType fuelType, double fuel) {
        this.speed = speed;
        this.fuelType = fuelType;
        this.fuel = fuel;
    }

    public void refuel(FuelTank tank) {
        if(!tank.type.equals(fuelType)) try {
            throw new Exception("Wrong fuel type");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        fuel += tank.amount;
    }
    void accelerate(double a){
        if(fuel < a*fuelType.FUEL_CONS) try {
            throw new Exception("Not enough fuel");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        speed += a;
        fuel -= a*fuelType.FUEL_CONS;
    }

    // Stop the car
    void fullBreak(){
        speed = 0.0;
    }
}

class FuelTank {
    FuelType type;
    double amount;

    void refuelCar(Car c) {
        c.refuel(this);
    }

    void refuelTank(double amount) {
        this.amount += amount;
    }
    // Costruttori multipli
    FuelTank(FuelType type, double amount) {
        this.type = type; // this per riferirsi al type dell'oggetto
        this.amount = amount;
    }

    FuelTank(FuelType type) {
        this(type, 0);
    }
}

class FuelType {
    String fuelType;
    double FUEL_CONS;

    public FuelType(String fuelType, double FUEL_CONS) {
        this.fuelType = fuelType;
        this.FUEL_CONS = FUEL_CONS;
    }
}

public class Main {
    public static void main(String[] args) {
        FuelType diesel = new FuelType("diesel", 0.5);
        Car car = new Car(0.0, diesel, 0.0);
        FuelTank tank1 = new FuelTank(diesel);
        tank1.refuelTank(50.0);
        tank1.refuelCar(car);
        car.accelerate(10.0);
        car.accelerate(20.0);
        tank1.refuelTank(30.0);
        FuelTank tank2 = new FuelTank(diesel, 100.0);
        //tank.refuelCar(car);
        System.out.println(car.speed);
        System.out.println(car.fuel);
    }
}