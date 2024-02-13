![[Pasted image 20240105161749.png]]
```java

public class Player{
	String name;
	Integer age;

	public String getName(){
		return name;
	}

	public Integer getAge(){
		return age;
	}
}

public class Squad {
	String name;

	public Squad(String name){
		this.name = name;
	}
	public String getName(){
		return this.name;
	}
	
}

public class Match {
	final private String pl1;
	final private String pl2;
	private String winner;

	public Match(String one, String two){
		this.pl1 = one;
		this.pl2 = two;
	}

	public Match(String one, String two, String winner){
		this.pl1 = one;
		this.pl2 = two;
		this.winner = winner;
	}

	public String getWinner(){
		return this.winner;
	}
}
```