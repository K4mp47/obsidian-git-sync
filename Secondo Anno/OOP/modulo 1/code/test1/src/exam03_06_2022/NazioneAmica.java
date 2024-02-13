package exam03_06_2022;

interface Nazione {

    boolean nazioneAmica(Nazione nazione);
    String getNazione();
}

interface NazioneAmicaInterfaccia extends Nazione {

    @Override
    default boolean nazioneAmica(Nazione nazione){
        return true;
    };
}

public class NazioneAmica implements NazioneAmicaInterfaccia {

    private final String name;

    public NazioneAmica(String name){
        this.name = name;
    }
    public String getNazione(){
        return this.name;
    }

}


