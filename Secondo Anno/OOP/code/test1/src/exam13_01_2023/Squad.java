package exam13_01_2023;

public class Squad {
    String name;
    int goals;

    public Squad(String name){
        this.name = name;
        this.goals = 0;
    }

    public Squad(String name, int goals){
        this.name = name;
        this.goals = goals;
    }

    public Integer getGoals(){
        return this.goals;
    }

    public String getName(){
        return this.name;
    }

}
