- Modelli real word objects
```java
// Una volta definita la struttura, non si può modificare
// Non si possono creare/rimuovere campi on-the-fly
class Car {
	double speed; // Field
	double fuel;
	void refuel(double amount){ // Method
		fuel += amount;
	}

	void accelerate(double a){
		speed += a;
		fuel -= a*FUEL_CONS;
	}

	// Stop the car
	void fullBreak(){
		speed = 0.0;
	}

// L'astrazione e le interfacce della classe, fatte tramite
// i commenti e la definizione della struttura della classe
}

public class Main {  
    public static void main(String[] args) {  
	    // myCar contiene la reference all'oggetto Car
		Car myCar = new Car(); // Classe istanziata come oggetto
		myCar.refuel(34.5); // Posso usare i metodi della classe 
		Car yourCar = new Car; // Posso istanziare più volte la stessa classe
    }    
}
```

- Interazione tra oggetti
```java

class FuelType {
	String name;
	double costPerLiter;
	double FUEL_CONS;
}

// Esempi di istanza
// FuelType diesel = new FuelType(“diesel“, 1.3, 0.3); 
// FuelType petrol = new FuelType(“petrol“, 1.5, 0.5); 
 
class FuelTank { 
	FuelType type; 
	double amount;
}

// La classe Car viene modificata per interagire con FuelType e FuelTank
class Car {
	double speed; // Field
	double fuel;
	FuelType fuelType; // Nuova variabile
	
	void refuel(FuelTank tank){ // Method ridefinition
		if(!tank.type.equals(fuelType)) throw new Exception();
		else fuel += tank.amount;
		tank.amount = 0;
	}

	void accelerate(double a){
		speed += a;
		fuel -= a*FUEL_CONS;
	}

	// Stop the car
	void fullBreak(){
		speed = 0.0;
	}
	
}

public class Main {  
    public static void main(String[] args) {  
	    // myCar contiene la reference all'oggetto Car
		Car myCar = new Car(); // Classe istanziata come oggetto
		myCar.refuel(34.5); // Posso usare i metodi della classe 
		Car yourCar = new Car; // Posso istanziare più volte la stessa classe
		FuelType diesel = new FuelType(“diesel“, 1.3, 0.3); 
		FuelTank dieselTank = new FuelTank();
		dieselTank.type = diesel;
		dieselTank.amount = 34.5;
    }    
}
```

- Costruttore
```java
// Il costruttore è un metodo speciale chiamato quando la classe viene
// istanziata. Se non viene definito, uno di default viene aggiunto
// dal compilatore.

// Possono esserci più costruttori per classe, in base ai parametri che gli
// vengono passati

class FuelType { 
	String name; 
	double costPerLiter; 
	double fuelConsumption; 

	FuelType(String n, double cpl, double fc) { // Constructor declaration
		name = n; 
		costPerLiter = cpl; 
		fuelConsumption = fc; 
	} 
}
```

- L'utilizzo di **this**
```java
// this è una java keyword che punta all'oggetto corrente. Essenzialmente è
// una reference all'oggetto in cui si sta operando.

 class Car { 
	 double speed; 
	 FuelType fuelType; 
	 double fuel; 
	 
	 void refuel(FuelTank tank) {…} 
	 void accelerate(double a) {…} 
	 void fullBreak() {…} 
} 

class FuelTank { 
	FuelType type; 
	double amount; 
	
	void refuelCar(Car c) { 
		c.refuel(this); 
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
```

- Type modifiers
```java
// Static
// Campo condiviso tra tutte le istanze della classe
// Accesso tramite il nome della classe
class FuelTank { 
	FuelType type; 
	double amount; 
	static int numberOfTanks = 0;
	void refuelCar(Car c) { 
		c.refuel(this); 
	}
	
	// Costruttori multipli
	FuelTank(FuelType type, double amount) { 
		this.type = type; // this per riferirsi al type dell'oggetto
		this.amount = amount; 
		numberOfTanks++;
	} 
	
	FuelTank(FuelType type) { 
		this(type, 0); 
	}
} 

// Accesso tramite nome classe
System.out.println(“Created “+ FuelTank.numberOfTanks + “tanks“)

// static può essere usato anche dali metodi
// Pùo usare solo variabili e metodi statici
static void resetTanksCount() { // Metodo statico di FuelTank 
	numberOfTanks = 0; 
} 

static { // Constructor statico
	FuelTank.resetTanksCount();
}

// Final
// Usato per dire che il campo dopo essere stato inizializzato non può subire
// modifiche, i constructor dovrebbero inizializzare tutti i campi final
// quando vengono chiamati

// Abstract
```
- Modifier on encapsulation
```java
// Access modifiers like public protected private
// Concurrency modifiers like volatile and synchronized
// static, final, abstract methods for classes

package it.unive.dais.po1.car; // package concept with import
import it.unive.dais.po1.fuel.*; 

class Car { 
	protected double speed; // this could be see from the package or the subclasses, but not from external class!! 
	private FuelType fuelType; 
	private double fuel; // just from the sameclass
	
	public void setSpeed(double s) { 
		this.speed = s;
	} 
	
	public void setSpeed(double s) { // everywhere
		if(s<0) this.speed=0 
		else this.speed = s; 
	}
}
```
![[Pasted image 20231205150826.png]]
- Classes and Contracts
>In Java, the term "contract" typically refers to the set of rules and obligations that a class or method must adhere to. These rules define the behavior and responsibilities of the class or method. By following the contract, developers ensure that their code can be used correctly and reliably by other parts of the program. Contracts are often enforced through the use of interfaces, where classes that implement an interface must adhere to the contract defined by that interface.

- Interface
```java
public interface Shape {
    double calculateArea();
}
```

```java
public class Circle implements Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }
}
```

- Abstract class
```java
public abstract class Shape { 
	public abstract double calculateArea(); 
	public abstract double calculatePerimeter(); 
}
```

```java
public class Rectangle extends Shape {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public double calculateArea() {
        return width * height;
    }

    @Override
    public double calculatePerimeter() {
        return 2 * (width + height);
    }
}
```
While both abstract classes and interfaces can define contracts and enforce behavior, there are some key differences between them:

1. **Multiple Inheritance**: A class can only extend one abstract class, but it can implement multiple interfaces. This means that interfaces provide a way to achieve multiple inheritance in Java, allowing a class to inherit behavior from multiple sources.
    
2. **Constructor**: An abstract class can have constructors, while interfaces cannot. This allows abstract classes to have instance variables and initialize them through constructors.
    
3. **Default Method**: An interface can have default methods, which provide a default implementation for a method. This allows interfaces to provide a default behavior that implementing classes inherit. In contrast, abstract classes can provide concrete implementations for all their methods.
    
4. **Implementation**: An abstract class can have both abstract and non-abstract methods, whereas an interface can only have abstract methods. This means that implementing classes of an interface must provide an implementation for all methods, while implementing classes of an abstract class have the flexibility to override only the necessary methods.
    
5. **Usage**: Abstract classes are generally used when there is a need for common behavior and state among related classes, while interfaces are used when there is a need for a contract that unrelated classes can adhere to. Abstract classes are often used to provide a base implementation for subclasses, while interfaces are used to define a common behavior that different classes can implement.
    

In summary, interfaces are used to define contracts and provide a way to achieve multiple inheritance, while abstract classes are used to provide a base implementation and common behavior for related classes. The choice between using an abstract class or an interface depends on the specific requirements and design of your application.