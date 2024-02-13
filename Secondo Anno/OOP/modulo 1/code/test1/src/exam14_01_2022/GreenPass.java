package exam14_01_2022;

import java.util.Date;
public abstract class GreenPass {
    private final String codiceFiscale;
    private final Date scadenza;

    public GreenPass(String codiceFiscale, Date scadenza){
        this.codiceFiscale = codiceFiscale;
        this.scadenza = scadenza;
    }

    public String getCodiceFiscale(){
        return this.codiceFiscale;
    }

    public Date getScadenza(){
        return this.scadenza;
    }
}
