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