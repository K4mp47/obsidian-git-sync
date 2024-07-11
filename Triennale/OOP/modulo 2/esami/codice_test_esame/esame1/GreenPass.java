package esame1;


import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

abstract class GreenPass {
    private final String cf;
    private final Date date;

    GreenPass(String cf, Date date) {
        this.cf = cf;
        this.date = date;
    }

    public String getCf() {
        return cf;
    }

    public Date getDate() {
        return date;
    }
}

class VaccinoGreenPass extends GreenPass {
    public VaccinoGreenPass(String cf, Date dt){
        super(cf, dt);
    }
}

class TamponeGreenPass extends GreenPass {
    public TamponeGreenPass(String cf, Date dt){
        super(cf, dt);
    }
}

class PersonaSbagliataException extends Exception {
    public PersonaSbagliataException(String message){
        super(message);
    }
}

class PersonaConGreenPass {
    private final String cf;
    private final List<GreenPass> greenPasses;

    public PersonaConGreenPass(String cf) {
        this.cf = cf;
        this.greenPasses = new ArrayList<>();
    }

    public List<GreenPass> getPass() { // forse è meglio <?>
        return greenPasses;
    }

    public boolean addGreenPass(GreenPass a) throws PersonaSbagliataException {
        if (!this.cf.equals(a.getCf())) throw new PersonaSbagliataException("Errore, codice fiscale errato");
        
        for(GreenPass o : greenPasses){
            if(o.getDate().compareTo(a.getDate()) == 0){
                return false;
            }
        }
        greenPasses.add(a);
        return true;
    } 
}

class ControlloGreenPass {
    public static boolean haGreenPassNormale(PersonaConGreenPass p){
        List<GreenPass> check_to = p.getPass();
        if(check_to.isEmpty()) return true;
        return false;
    }

    public static boolean haGreenPassSuper(PersonaConGreenPass p){
        List<GreenPass> check_to = p.getPass();
        for(GreenPass o : check_to){
            if(o instanceof VaccinoGreenPass)
                if(!o.getDate().after(Calendar.getInstance().getTime()))
                    return true;
        }
        return false;
    }
}

