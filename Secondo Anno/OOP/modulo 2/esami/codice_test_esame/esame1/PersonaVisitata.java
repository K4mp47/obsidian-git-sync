package esame1;

import java.util.ArrayList;
import java.util.List;

class Persona {
    private final String cf;

    public Persona(String cf) {
        this.cf = cf;
    }

    public String getCf() {
        return cf;
    }
}

public class PersonaVisitata extends Persona {
    private String rep;
    private int code;

    PersonaVisitata(String cf, String rep, int code) {
        super(cf);
        this.rep = rep;
        this.code = code;
    }

    public String getRep() {
        return rep;
    }

    public int getCode() {
        return code;
    }

    public void setRep(String rep) {
        this.rep = rep;
    }

    public void setCode(int code) {
        this.code = code;
    }
}

interface Reparto {
    public String getReparto();

    public Persona visitaPersona(Persona p);

    public Persona visitaPersona(PersonaVisitata p); // ereditarietà, guardo bene nel main
}

class RepartoEmergenza implements Reparto {
    private final String reparto;

    RepartoEmergenza(String reparto) {
        this.reparto = reparto;
    }

    @Override
    public String getReparto() {
        return reparto;
    }

    @Override
    public Persona visitaPersona(PersonaVisitata p) {
        if(p.getCode() > 100) {
            return visitaPersona((Persona)p);
        } else {
            return p;
        }
    }

    @Override
    public Persona visitaPersona(Persona p) {
        return p;
    }
}

class Ospedale {
    private final List<RepartoEmergenza> reps;

    Ospedale(List<RepartoEmergenza> reps) {
        this.reps = reps;
    }

    public Persona Visita(PersonaVisitata p){
        for(Reparto x: reps){
            if(x.getReparto().equals(p.getRep())){
                return x.visitaPersona(p);
            }
        }
        return p;
    }

    public static void main(String[] args) {
        // make a List of RepartoEmergenza
        List<RepartoEmergenza> reps = new ArrayList<>();
        reps.add(new RepartoEmergenza("Reparto1"));
        reps.add(new RepartoEmergenza("Reparto2"));
        reps.add(new RepartoEmergenza("Reparto3"));
        reps.add(new RepartoEmergenza("Reparto4"));
        reps.add(new RepartoEmergenza("Reparto5"));

        Ospedale osp = new Ospedale(reps);

        PersonaVisitata p = new PersonaVisitata("CF", "Reparto5", 1);
        Persona p1 = osp.Visita(p);
        // cast p1 to PersonaVisitata
    }
}
