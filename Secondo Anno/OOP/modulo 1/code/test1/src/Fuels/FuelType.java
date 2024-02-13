package Fuels;

/**
* This class is used to represent a fuel type for the vehicles
*
* @author Campagnolo Alberto
* @since 1.0
* */
public class FuelType {
    final String fuelType;
    private final double FUEL_CONS;

    /**
    * This method return the current cost per liter of the fuel
    *
     * @param   None         No parameters needed.
    * @return    FUEL_CONS   the cost per liter
     * */
    public double get_FUEL_CONS() {
        return FUEL_CONS;
    }
    public FuelType(String fuelType, double FUEL_CONS) {
        this.fuelType = fuelType;
        this.FUEL_CONS = FUEL_CONS;
    }
}
