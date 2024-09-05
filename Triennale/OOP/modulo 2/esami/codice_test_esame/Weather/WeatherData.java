package weather;

import java.util.Date;


public class WeatherData {
    public final float temperature_min;
    public final float temperature_max;
    public final float rain;
    public final int wind;
    public final String name;
    public final Date date;

    public WeatherData(float temperature_max, float temperature_min, float rain, int wind, String name, Date date) throws WeatherValueException {
        this.temperature_max = temperature_max;
        this.temperature_min = temperature_min;
        if (temperature_max < temperature_min) {
            throw new WeatherValueException("Temperature max is less than temperature min");
        }
        this.rain = rain;
        this.wind = wind;
        this.name = name;
        this.date = date;
    }
}