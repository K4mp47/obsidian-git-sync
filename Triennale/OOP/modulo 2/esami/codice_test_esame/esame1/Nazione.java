package esame1;

import java.util.ArrayList;
import java.util.List;

interface Nazione {
    
    public String getName();

    public boolean isFriend(Nazione na);
}

interface NazioneAmicaInterfaccia extends Nazione {

    @Override
    default boolean isFriend(Nazione na){
        return true;
    };
}

class NazioneAmica implements NazioneAmicaInterfaccia {
    private final String name;

    NazioneAmica(String name) {
        this.name = name;
    }

    @Override
    public String getName() {
        return name;
    }
}

class UnioneNazioni {
    private List<Nazione> union = new ArrayList<>();

    public UnioneNazioni(){

    }

    public boolean add(NazioneAmica na) {
        for(Nazione n : union){
            if(!n.isFriend(na)){
                return false;
            }
        }
        union.add(na);
        return true;
    }

    public boolean remove(Nazione na){
        for(Nazione n : union){
            if(na.getName().equals(n.getName())){
                union.remove(n);
                return true;
            }
        }
        return false;
    }

}

