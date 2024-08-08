import java.util.ArrayList;
import java.util.List;

class Persona {
    final private String cf;

    Persona(String cf){
        this.cf = cf;
    }

    protected String getCF(){
        return this.cf;
    }
}

class PersonaVisitata extends Persona {
    private String reparto;
    private int code;

    PersonaVisitata(String rep, int code, String cf){
        super(cf);
        this.reparto = rep;
        this.code = code;
    }

    protected String getReparto() {
        return this.reparto;
    }

    protected int getCode() {
        return this.code;
    }

    public void setReparto(String reparto) {
        this.reparto = reparto;
    }

    public void setCode(int code) {
        this.code = code;
    }
}

interface Reparto {
    String getNomeReparto();
    Persona visitaPersona(Persona p);
    PersonaVisitata visitaPersona(PersonaVisitata p);
}

class RepartoEmergenze implements Reparto {
    final private String nomeReparto;

    public String getNomeReparto() {
        return this.nomeReparto;
    }

    public RepartoEmergenze(String nomeReparto) {
        this.nomeReparto = nomeReparto;
    }

    public Persona visitaPersona(Persona p) {
        return p;
    }

    public PersonaVisitata visitaPersona(PersonaVisitata p) {
        if (p.getCode() < 100) {
            return p;
        }

        p.setCode(0);
        return p;
    }
}

public class Ospedale {
    final private List<Reparto> reparti;

    public Ospedale(List<Reparto> reparti) {
        this.reparti = new ArrayList<Reparto>();
        for(Reparto rep : reparti) {
            this.reparti.add(rep);
        }
    }

    public PersonaVisitata visitaOspedale(PersonaVisitata p) {
        for(Reparto rep : this.reparti) {
            if (rep.getNomeReparto().equals(p.getReparto())) {
                return rep.visitaPersona(p);
            }
        }
        return p;
    }
}





