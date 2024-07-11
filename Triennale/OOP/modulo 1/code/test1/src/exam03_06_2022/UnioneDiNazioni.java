package exam03_06_2022;

import java.util.ArrayList;
import java.util.List;
public class UnioneDiNazioni {
    List<Nazione> nazioniUnite;

    public UnioneDiNazioni(){
        this.nazioniUnite = new ArrayList<>();
    }

    public boolean removeNazione(Nazione nazione){
        return nazioniUnite.remove(nazione);
    }

    public boolean addNazione(Nazione nazione){
        for(Nazione nazioneUnita : nazioniUnite){
            if(!nazioneUnita.nazioneAmica(nazione) || nazioneUnita.getNazione().equals(nazione.getNazione())) return false;
        }
        return nazioniUnite.add(nazione);
    }
}
