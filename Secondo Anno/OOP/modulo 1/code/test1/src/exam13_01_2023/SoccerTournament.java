package exam13_01_2023;

import java.util.List;

class SoccerTournamentException extends Exception{
    public SoccerTournamentException(String message){
        super(message);
    }
}

public class SoccerTournament {
    private final List<String> teams;
    private final List<Match> matches;

    public SoccerTournament(List<String> teams, List<Match> matches) throws SoccerTournamentException {
        this.teams = teams;
        this.matches = matches;
        for(Match match: this.matches){
            if(!(match instanceof SoccerMatch))
                throw new SoccerTournamentException("Non tutti i match sono un torneo di calcio!");
            if(!this.teams.contains(match.getPl1()) || !this.teams.contains(match.getPl2()))
                throw new SoccerTournamentException("il match non può esistere, non esiste una/le squadra/e!");
        }
    }

    public int getPoints(String team) throws SoccerTournamentException {
        if(!this.teams.contains(team))
            throw new SoccerTournamentException("La squadra non è nel torneo, non esiste una/le squadra/e!");
        int points = 0;
        for(Match match: this.matches){
            if(match.getPl1().equals(team) || match.getPl2().equals(team)){
                if(team.equals(match.getWinner())){
                    points += 3;
                } else if(match.getWinner() == null){
                    points += 1;
                } else {
                    points += 0;
                }
            }
        }
        return points;
    }
}

