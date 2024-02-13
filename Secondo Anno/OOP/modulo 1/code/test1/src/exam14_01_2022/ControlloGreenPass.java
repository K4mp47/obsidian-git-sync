package exam14_01_2022;

import java.util.Calendar;
import java.util.List;

public class ControlloGreenPass {

    public static Boolean haGreenPassNormale(PersonaConGreenPass persona){
        List<GreenPass> gp = persona.getGreenPasses();
        return !gp.isEmpty();
    }

    public static Boolean haGreenPassSuper(PersonaConGreenPass persona){
        List<GreenPass> gp = persona.getGreenPasses();
        for(GreenPass g: gp){
            if(g instanceof VaccinoGreenPass)
                System.out.println(g.getScadenza() + " " + Calendar.getInstance().getTime());
                return g.getScadenza().before(Calendar.getInstance().getTime());
        }
        return true;
    }
}
