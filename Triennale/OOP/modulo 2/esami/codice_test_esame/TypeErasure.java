import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Humanoid implements Comparable<Humanoid> {

    protected int strength;

    public Humanoid(int strength) {
        this.strength = strength;
    }

    @Override
    public int compareTo(Humanoid o) {
        return -(strength - o.strength);
    }

}

class Elf extends Humanoid {

    protected int mana;

    public Elf(int strength, int mana) {
        super(strength);
        this.mana = mana;
    }

    @Override
    public int compareTo(Humanoid o) {
        if (o instanceof Elf) {
            Elf e = (Elf) o;
            return -((mana + strength) - (e.mana + e.strength));
        } else {
            return super.compareTo(o);

        }
    }
}

public class TypeErasure {

    static <T extends Comparable<T>> void sort(List<T> l) {
        Collections.sort(l);
    }


    // That code produce type erasure during compile time
    // 
    // static void sort(List l) {} is what they will become
    
    
    // static <T> void sort(List<T extends Comparable<T>> l) {}

    public static void main(String[] args) {
        List<Humanoid> l = new ArrayList<>();
        Humanoid a = new Elf(10, 8), b = new Humanoid(8), c = new Humanoid(12);
        l.add(a);
        l.add(b);
        l.add(c);
        sort(l);
        // stampa l'ultimo elemento;
        System.out.println(l.lastIndexOf(l.get(l.size() - 1)));
        for (Humanoid humanoid : l) {
            System.out.println(humanoid.strength);
        }
    }
}
