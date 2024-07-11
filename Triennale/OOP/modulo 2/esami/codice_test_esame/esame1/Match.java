package esame1;

import java.util.List;

abstract class Match {
    private final String sq1, sq2;

    Match(String sq1,String sq2) {
        this.sq1 = sq1;
        this.sq2 = sq2;
    }

    public String getSq1() {
        return sq1;
    }

    public String getSq2() {
        return sq2;
    }

    abstract public String getWinner();
}

class SoccerMatch extends Match {
    private final int gsq1, gsq2;

    SoccerMatch(String sq1, String sq2, int gsq1, int gsq2) {
        super(sq1, sq2);
        this.gsq1 = gsq1;
        this.gsq2 = gsq2;
    }

    @Override
    public String getWinner() {
        if(gsq2 < gsq1) return getSq1();
        if(gsq1 < gsq2) return getSq2();
        return null;
    }
    
}

class SoccerException extends Exception {
    SoccerException(String message) {
        super(message);
    }
}

class SoccerTournament {
    private final List<String> teams;
    private final List<SoccerMatch> matches;

    SoccerTournament(List<String> teams, List<SoccerMatch> matches) throws SoccerException {
        this.teams = teams;
        // check if all the matches are type of SoccerMatch
        for (SoccerMatch match : matches) {
            if (!(match instanceof SoccerMatch)) { // dice che non è necessario ma secondo me manca match == null
                throw new SoccerException("Match is not a SoccerMatch");
            }
            if (!teams.contains(match.getSq1()) || !teams.contains(match.getSq2())) {
                throw new SoccerException("Match contains unknown team");
            }
        }
        this.matches = matches;
    }

    public int getPoints(String sq) {
        int points = 0;
        for (SoccerMatch match : matches) {
            if (match.getSq1().equals(sq)) {
                if (match.getWinner() == null) {
                    points += 1;
                } else if (match.getWinner().equals(sq)) {
                    points += 3;
                }
            }
        }
        return points;
    }
}

