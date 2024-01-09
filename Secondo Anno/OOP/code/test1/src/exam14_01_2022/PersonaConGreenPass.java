package exam14_01_2022;

import java.util.List;
import java.util.ArrayList;

class PersonaSbagliataException extends Exception{
    public PersonaSbagliataException(String message){
        super(message);
    }
}
public class PersonaConGreenPass {
    private final String codiceFiscale;
    private final List<GreenPass> greenPasses;

    public PersonaConGreenPass(String codiceFiscale){
        this.codiceFiscale = codiceFiscale;
        this.greenPasses = new ArrayList<>();
    }

    public List<GreenPass> getGreenPasses(){
        return this.greenPasses;
    }

    public Boolean addGreenPass(GreenPass greenPass) {
        try{
           if (!greenPass.getCodiceFiscale().equals(this.codiceFiscale)) throw new PersonaSbagliataException("Codice fiscale errato");
        } catch(Exception e){
            return false;
        }
        for(GreenPass gp: this.greenPasses){
            if(gp.getCodiceFiscale().equals(greenPass.getCodiceFiscale()))
                return false;
        }
        this.greenPasses.add(greenPass);
        return true;
    }
}
