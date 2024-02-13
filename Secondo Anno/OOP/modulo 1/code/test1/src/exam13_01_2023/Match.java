package exam13_01_2023;

public class Match {
    final private String pl1;
    final private String pl2;
    String winner;

    public Match(String one, String two){
        this.pl1 = one;
        this.pl2 = two;
    }

    protected Match(String one, String two, String winner){
        this.pl1 = one;
        this.pl2 = two;
        this.winner = winner;
    }

    public String getPl1(){
        return this.pl1;
    }

    public String getPl2(){
        return this.pl2;
    }

    public String getWinner(){
        return this.winner;
    }
}
