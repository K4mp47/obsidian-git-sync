package exam01_07_2022;

interface Reparto {
    String nomeReparto();
    Persona visitpersona(Persona persona);
    PersonaVisitata visitpersonaVisitata(PersonaVisitata personaVisitata);
}

public class RepartoEmergenza implements Reparto {

    private final String nomeReparto;

    public RepartoEmergenza(String nome) {
        this.nomeReparto = nome;
    }

    @Override
    public String nomeReparto() {
        return this.nomeReparto;
    }

    @Override
    public Persona visitpersona(Persona persona) {
        return persona;
    }

    @Override
    public PersonaVisitata visitpersonaVisitata(PersonaVisitata personaVisitata) {
        if(personaVisitata.getPriority_code() > 100){
            personaVisitata.setPriority_code(0);
        }
        return personaVisitata;
    }
}
