package exam13_01_2023;

public class Player{
    String name;
    Integer age;

    public Player(String name, Integer age){
        this.name = name;
        this.age = age;
    }

    public String getName(){
        return name;
    }

    public Integer getAge(){
        return age;
    }
}
