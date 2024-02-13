package exam01_07_2022;

public class Persona {

    private final String codiceFiscale;
    private final String nome;
    private final String cognome;

    public Persona (String codiceFiscale, String nome, String cognome){
        this.codiceFiscale = codiceFiscale;
        this.nome = nome;
        this.cognome = cognome;
    }

    public String getCodiceFiscale() {
        return this.codiceFiscale;
    }

    public String getNome() {
        return this.nome;
    }

    public String getCognome() {
        return this.cognome;
    }
}

