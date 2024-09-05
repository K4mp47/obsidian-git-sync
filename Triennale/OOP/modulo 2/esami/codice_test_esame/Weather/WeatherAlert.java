package Weather;

import java.util.Date;
import weather.WeatherData;
import weather.WeatherValueException;

public interface WeatherAlert {

    Date getDate();

    String getByCity();
}

class WindWeatherAlert implements WeatherAlert {

    private final String city;
    private final Date date;

    public WindWeatherAlert(WeatherData data) throws WeatherValueException {
        if (data.wind < 100) {
            throw new WeatherValueException("Wind value is negative");
        }
        city = data.name;
        date = data.date;
    }

    @Override
    public Date getDate() {
        return date;
    }

    @Override
    public String getByCity() {
        return city;
    }
}
