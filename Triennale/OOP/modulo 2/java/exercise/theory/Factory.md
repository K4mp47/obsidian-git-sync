The factory design pattern is used when we have a super class with multiple sub-classes and based on input, we need to return one of the sub-class. This pattern takes out the responsibility of the instantiation of a class from the client program to the factory class. Let’s first learn how to implement a factory design pattern in java and then we will look into factory pattern advantages. We will see some of the factory design pattern usage in jdk.

- The Factory design pattern is useful because it allows delegating the creation of objects to a static or non-static method of a class (the "Factory"), which can use polymorphism to return instances of subclasses based on the provided parameters or existing conditions

Super class in factory design pattern can be an interface, abstract class or a normal java class. For our factory design pattern example, we have abstract super class with overridden `toString()` method for testing purpose.

```java
package com.journaldev.design.model;

public abstract class Computer {

	public abstract String getRam();
	public abstract String getRam();
	public abstract String getRam();
	
	@Override
	public String toString(){
		return "Ram= " + this.getRam() + ", Hdd= "+this.getHdd()+", Cpu= "+this.getCpu();
	}
}
```

Let’s say we have two sub-classes PC and Server with below implementation.

```java
package com.journaldev.design.model;

public class PC extends Computer {

	private String ram;
	private String hdd;
	private String cpu;
	
	public PC(String ram, String hdd, String cpu){
		this.ram=ram;
		this.hdd=hdd;
		this.cpu=cpu;
	}
	@Override
	public String getRAM() {
		return this.ram;
	}

	@Override
	public String getHDD() {
		return this.hdd;
	}

	@Override
	public String getCPU() {
		return this.cpu;
	}

}
```

```java
package com.journaldev.design.model;

public class Server extends Computer {

	private String ram;
	private String hdd;
	private String cpu;
	
	public Server(String ram, String hdd, String cpu){
		this.ram=ram;
		this.hdd=hdd;
		this.cpu=cpu;
	}
	@Override
	public String getRAM() {
		return this.ram;
	}

	@Override
	public String getHDD() {
		return this.hdd;
	}

	@Override
	public String getCPU() {
		return this.cpu;
	}

}
```

Now we create our factory class, the heart of the Factory Design Pattern.

```java
package com.journaldev.design.factory;

import com.journaldev.design.model.Computer;
import com.journaldev.design.model.PC;
import com.journaldev.design.model.Server;

public class ComputerFactory {

	public static Computer getComputer(String type, String ram, String hdd, String cpu){
		if("PC".equalsIgnoreCase(type)) 
			return new PC(ram, hdd, cpu);
		else if("Server".equalsIgnoreCase(type)) 
			return new Server(ram, hdd, cpu);
		return null;
	}
}
```

Here is a simple test client program that uses above factory design pattern implementation.

```java
package com.journaldev.design.test;

import com.journaldev.design.factory.ComputerFactory;
import com.journaldev.design.model.Computer;

public class TestFactory {

	public static void main(String[] args) {
		Computer pc = ComputerFactory.getComputer("pc","2 GB","500 GB","2.4 GHz");
		Computer server = ComputerFactory.getComputer("server","16 GB","1 TB","2.9 GHz");
		System.out.println("Factory PC Config::"+pc);
		System.out.println("Factory Server Config::"+server);
	}

}
```
