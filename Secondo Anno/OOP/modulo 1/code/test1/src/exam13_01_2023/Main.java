package exam13_01_2023;

import java.util.List;

public class Main {

    public static void main(String[] args) {
        Player player = new Player("Alberto", 21);
        Player player2 = new Player("Alex", 25);
        System.out.println(player.getName());
        System.out.println(player.getAge());
        Match Match1 = new Match("Alberto", player2.getName());
        System.out.println(Match1.getWinner());
        Squad squad1 = new Squad("InterGalactic", 40);
        Squad squad2 = new Squad("Invincible", 30);
        // Squad squad3 = new Squad("InterCapsule", 20);
        Match Match2 = new Match(squad1.getName(), squad2.getName(), squad2.getName());
        System.out.println(Match2.getWinner());
        SoccerMatch soccerMatch = new SoccerMatch(squad1, squad2);
        System.out.println(soccerMatch.getGoalsFirstSquad());
        System.out.println(soccerMatch.getGoalsSecondSquad());
        System.out.println(soccerMatch.getWinner());
        List<String> teams = List.of("InterGalactic", "Invincible", "InterCompetitive", "Galactic", "Epic");
        List<Match> matches = List.of(soccerMatch);
        try {
            SoccerTournament soccerTournament = new SoccerTournament(teams, matches);
            System.out.println(soccerTournament.getPoints("InterGalactic"));
        } catch (SoccerTournamentException e) {
            System.out.println(e.getMessage());
        }
    }
}
