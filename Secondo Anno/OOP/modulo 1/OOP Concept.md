## Encapsulation

The idea behind encapsulation is to create a good organization structure behind the code of classes and methods in order to perform as well as possible without occur in issues of data access. You need to ask yourself how and where put the data that you use for your class, who use the data/methods in order to perform inside the code ecc. 

The other concept is that in Java, which is an object oriented programming language, you shouldn't think at the code as an unique block, but as a separated smaller units, all for a better and easier maintenance of the code.

## Information Hiding
That concept follow the problem of: how can i hide the implementation of class and methods to the final user? In order to do that, you need to provide some mechanism to hide components. In that way, the user doesn't need to see how the implementation works, he needs just to watch the interface provided. This approach brings to various benefits as:
1. The dependencies between different components are minimized
2. A user can see only the components that were intended to be the interface of the piece of the software, and not its implementation details, so that he needs just to explore the interface components in order to understand how the code could be use
3. We can change the code behind the components without the need to consider how it is used.

To perform the information hiding Java provides the access modifiers:

| | same class |  same package |  subclasses | Everywhere | 
-------------:|----------------:|------------:|--------------:|--------------:|
public  | 🤝 | 🤝| 🤝| 🤝|
protected | 🤝 | 🤝| 🤝| ✋|
\<default\> | 🤝 | 🤝| ✋| ✋|
private | 🤝 | ✋| ✋| ✋|

💡 Usually the variable inside a class are all private, but it could depends by the implementation inside the code. For example:

```java
class A {
	private int private_field;
	int foo(A a){
		return this.private_field + a.private_field;
	}
}
```

Has you can see in the snipped code the private modifier is correctly executed 'cause it applies at class level

### Getters and Setters
To access at the fields inside a class, if it's private, there are hoc methods that allow to read and write fields values called Getters and Setters.
For example:

```java
class FuelTank { 
	public FuelType getFuelType() { 
		return this.type; 
	} 
	
	public double getAmount() { // Getter 
		return this.amount; 
	} 
	
	public void emptyTank() { // Setter
		this.amount = 0; 
	}
}
```


## Comments as Documentation

Java, for a better comprehension of the code, gives at programmers a special comment syntax to describe the code: as
- `@author`: to specify who wrote the class
- `@since` : to specify since which version of the software the class has been present
- `@version`: to specify the current version of the class
- `@param <name>`: to document a specific method parameter
- `@return`: to specify what a method return
- `@requires`: to specify what a method need in input in order to perform correctly
- `@ensure`: to specify what a method should return

## Artifacts
An artifact is the result of the compilation and build of a program. An artifact usually encapsulates several packages together, it can be downloaded and installed. The idea of such an artifact is that a developer might load it inside his/her Java application, and use our classes as a library. The Java Development Kit for example, provides a utility (jar.exe) that allows to pack together several .class files into a unique jar archive. A jar file is nothing else than a zipped file containing all the .class file obtained by the compilation of our source code, all the resource files, and a manifest file (file with information about the code like the version of the jar, its vendor, Creator ecc.). 
## Contracts

A contract in Java is the agreement between user and programmer about what the programmers has the right of receiving in input from the user, and his obligation to providing back the results of the computation as specified by the capsule APIs (e.g., method signature) and the documentation provided. 

An example could be:
```java
class Car{
	void refuel(Fueltank tank){ ... }
	void accelerate(double a){ ... }
	void fullBrake(){ ... }
	void brake(double amount){ ... }
}
```

The interface of this class establishes a contract where the client has a class Car with four methods available. each method defines what it requires and what it ensures. We might see the name of the method as a part of the contract, so for instance we might infer that after we invoke method `fullBrake` on a `Car`, the `Car` is not moving ahead anymore.

## Overriding and Overloading

Overloading means that the same class defines several methods with the same name but different signatures. This is possible since when calling the method the runtime environment will be able to decide exactly what method to execute.

Overloading example:

```java
public class Vehicle { 
	public void accelerate(double a) { 
		if(a>0) 
			this.speed += a; 
	} 
	
	public void accelerate(String a) { 
		if(a>0) 
			this.speed += Double.valueOf(a); 
	} 
}
```

The signatures are different, look at the parameters passed. The meaning of overloading is to have the same function with different implementation based on the source code.

we talk about override instead  when a class implements a method with the same signature of another method already implemented in a super class. Remember that overriding inside the same class is not possible, it is just between a child class and its super class.

## Abstract
In Java is a keyword that allows one to define a method without providing its implementation. However, if a class contain abstract methods cannot be instantiated, as otherwise the abstract method is invoked in the object instance of the class. Therefore, if a class contains at least one abstract method, then the class itself must be abstract. A class extending an abstract class, can either override all the abstract methods or be abstract.

Here is an example:

```java
public abstract class Vehicle { 
	protected double speed; 
	public abstract void accelerate(double a); 
} 

public class Car extends Vehicle { 
	public void accelerate(double amount) { 
		double fuelConsumed = amount*fuelType.getLitresPerKmH()); 
		if(fuelConsumed < fuel) { 
			this.speed += amount; 
			fuel = fuel - fuelConsumed; 
		} else { 
			this.speed += fuel / fuelType.getLitresPerKmH(); 
			fuel = 0; 
		} 
	}
}

public class Bicycle extends Vehicle { 
	public void accelerate(double a) { 
		if(a>0) this.speed += a;
	} 
}
```