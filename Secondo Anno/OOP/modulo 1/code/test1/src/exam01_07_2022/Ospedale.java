package exam01_07_2022;

import java.util.ArrayList;
import java.util.List;

public class Ospedale {
    private final List<Reparto> reparti;

    public Ospedale() {
        this.reparti = new ArrayList<>();
    }

    public void addReparto(Reparto reparto){
        this.reparti.add(reparto);
    }

    public PersonaVisitata visitarePersona(PersonaVisitata persona) {
        for(Reparto reparto: this.reparti){
            if(reparto.nomeReparto().equals(persona.getReparto()))
                persona = reparto.visitpersonaVisitata(persona);
        }
        return persona;
    }
}
