package Races;

import vehicles.Vehicle;

/**
 * This class is used to represent the race of the cars,
 * just cars are allowed
 * This class doesn't have a constructor
 *
 * @author Campagnolo Alberto
 * @since 1.0*/
public class Race<T extends Vehicle> {
    private final T v1, v2;
    public Race(T v1, T v2) {
        this.v1 = v1;
        this.v2 = v2;
    }
    /**
     * Calculates the winner of a race between two vehicles over a specified distance.
     *
     * @param  length  the length of the race track in meters
     * @return         the result of the race:
     *                 -1 if both vehicles reached the finish line,
     *                 1 if the first vehicle reached the finish line,
     *                 2 if the second vehicle reached the finish line.
     */
    public int race(double length) {
        v1.fullBreak();
        v2.fullBreak();
        double distancev1 = 0;
        double distancev2 = 0;
        while (distancev1 < length && distancev2 < length) {
            v1.accelerate(Math.random()*10.0);
            v2.accelerate(Math.random()*10.0);
            distancev1 += v1.getSpeed();
            distancev2 += v2.getSpeed();
            System.out.println("[+] Distance: " + distancev1 + " <==> " + distancev2);
        }
        if (distancev1 >= length) {
            if(distancev2 >= length)
                return -1;
            else
                return 1;
        } else {
            return 2;
        }
    }
}
