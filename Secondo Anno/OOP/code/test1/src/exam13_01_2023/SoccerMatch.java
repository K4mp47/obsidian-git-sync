package exam13_01_2023;

public class SoccerMatch extends Match{
    private int goals1;
    private int goals2;

    public SoccerMatch(Squad one, Squad two){
        super(one.getName(), two.getName());
        this.goals1 = one.getGoals();
        this.goals2 = two.getGoals();
        this.winner = setSoccerWinner(one, two);
    }

    private String setSoccerWinner(Squad one, Squad two){
        if(one.getGoals() > two.getGoals())
            return one.getName();
        else
            return two.getName();
    }

    public int getGoalsFirstSquad(){
        return this.goals1;
    }

    public int getGoalsSecondSquad(){
        return this.goals2;
    }
}
