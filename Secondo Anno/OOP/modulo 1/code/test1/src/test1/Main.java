package test1;

import Fuels.FuelTank;
import Fuels.FuelType;
import vehicles.Car;
import Races.*;
import vehicles.List;
import vehicles.SuperCar;
public class Main {
    public static void main(String[] args) {
        FuelType diesel = new FuelType("diesel", 0.5);
        FuelType benzina = new FuelType("benzina", 0.3);
        Car car1 = new Car(0.0, diesel, 0.0, "ford", "fiesta", "AA123BB", "123456789");
        Car car2 = new Car(0.0, benzina, 0.0, "fiat", "punto", "BB123CC", "987654321");
        FuelTank tank1 = new FuelTank(diesel);
        tank1.refuelTank(30.0);
        tank1.refuelCar(car1);
        car1.accelerate(10.0); // accelerate
        car1.accelerate(20.0);
        System.out.println("[+] First tank fuel: " + tank1.getAmount());
        tank1.refuelTank(30.0);
        FuelTank tank2 = new FuelTank(benzina, 50.0);
        //tank.refuelCar(car);
        System.out.println(car1.getSpeed()); // check the current speed
        System.out.println(car1.getFuel());
        // System.out.println("[+] First car fuel: " + car1.refuel(tank1));
        tank2.refuelCar(car2);
        System.out.println("[+] second car fuel: " + car2.getFuel());
        System.out.println(tank1.getAmount());
        System.out.println(tank2.getAmount());
        Race Mainrace = new Race(car1, car2);
        System.out.println(Mainrace.race(100.0));
        System.out.println(car1.checkLicensePlate("AA123BB"));// check if the license plate is the same
        SuperCar supercar = new SuperCar(0.0, 0.0, "cleopatra", "supercar", "AA123BC", "123456779");
        supercar.reload(10);
        supercar.reload(20);
        supercar.accelerate(200);
        System.out.println(supercar.getSpeed());
        supercar.shoot();
        Car car3 = new Car(0.0, benzina, 0.0, "Lancia", "epsilon", "BB123CC", "987654321");
        List<Car> list = new List<Car>();
        System.out.println(List.length(list));
        list.add(car1);
        list.add(car2);
        list.add(supercar);
        list.contains(car1);
        System.out.println( list.contains(car3));
        System.out.println(List.length(list));
    }
}