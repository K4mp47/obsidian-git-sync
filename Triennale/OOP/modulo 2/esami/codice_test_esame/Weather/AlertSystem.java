package Weather;

import java.util.Collection;
import java.util.Date;
import java.util.ArrayList;

public class AlertSystem {
    public static Collection<WeatherAlert> getAlerts(Collection<WeatherAlert> data, Date start, Date end) {
        Collection<WeatherAlert> res = new ArrayList<>();
        for(WeatherAlert wa : data) {
            if(wa.getDate().after(start) && wa.getDate().before(end)) {
                res.add(wa);
            }
        }
        return res;
    }
}
