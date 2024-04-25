
class Vehicle {
  protected String name;

  public void refuel() {
    System.out.println("Generic vehicle refueling");
  }

  public Vehicle(String name) {
    this.name = name;
  }

  // method getName
  // @author Alberto Campagnolo 897569
  // @return the name of the Vehicle 
  // 
  public String getName() { // function for test inheritance
    return this.name;
  }
}

class Car extends Vehicle {
  @Override
  public void refuel() {
    System.out.println("Car is refueled");
  }

  public Car(String name) { // Constructor
    super(name);
  }
}

class Race {
  public void race(Vehicle vehicle1) {
    if (vehicle1 instanceof Car) {
      Vehicle car1 = (Vehicle) vehicle1;
      car1.refuel(); // This will call Car's refuel method even if it's casted as Vehicle
    }

    // Simulate the race
    System.out.println("Race started between " + vehicle1.getName() + " and another vehicle");
  }
}

public class Main {
  public static void main(String[] args) {
    Car car1 = new Car("Lamborghini");
    Race race1 = new Race();

    race1.race(car1);
  }
}
