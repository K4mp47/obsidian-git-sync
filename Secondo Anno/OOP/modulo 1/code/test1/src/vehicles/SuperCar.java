package vehicles;

import Fuels.FuelType;

/**
* This class is used to represent the supercar
* a supercar is a car with a gun
*
* @author Campagnolo Alberto
* @since 1.0*/
interface Gun { // interface for the Gun in the supercar

    void shoot();
    void reload(int ammo);
}

/**
* This class is used to represent the gun in the supercar
* it used an implementation of the interface gun for
* represent the rifle inside the car
*
* @author Campagnolo Alberto
* @since 1.0*/
class Rifle implements Gun {
    private int ammo;
    public Rifle() {
        ammo = 0;
    }

    public void reload(int ammo) {
        this.ammo = ammo;
    }
    @Override
    public void shoot() {
        while(ammo > 0) {
            System.out.print("Bang ");
            ammo--;
        }
        System.out.println();
    }

    public int check_magazine() {
        return ammo;
    }
}

public class SuperCar extends Car {

    private final Rifle gun = new Rifle();
    public SuperCar(double speed, double fuel, String make, String model, String licensePlate, String VIN) {
        super(speed, new FuelType("nuclear", 0.0), fuel, make, model, licensePlate, VIN);
    }

    /**
     * Shoots the gun.
     *
     * @param  None   No parameters needed.
     * @return        No return value.
     */
    public void shoot() {
        gun.shoot();
    }

    /**
     * Reloads the gun.
     *
     * @param   ammo  num of ammo to insert inside the gun.
     * @return        No return value.
     */
    public void reload(int ammo) {
        gun.reload(ammo);
    }
    /**
     * Check the magazine, the ammo.
     *
     * @param  None   No parameters needed.
     * @return        No return value.
     */
    public int check_magazine() {
        return gun.check_magazine();
    }
}
