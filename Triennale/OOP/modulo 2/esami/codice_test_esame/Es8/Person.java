package Es8;

public class Person<P extends Person<P>> implements Equatable<P> {

    /*
     * p1.equals(p1) == true 
     * p1.equals(null) == false 
     * p1.equals(e) == false se l’espressione e ha tipo diverso dal tipo di p1
     * p1.equals(p2) == p1.equalsTo(p2)
     */
    public final String name;
    public final int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public boolean equals(Object o) {
        if(this == o) return true;
        if(o == null || this.getClass() != o.getClass()) return false;
        return this.equalsTo((P) o);
    }

    @Override
    public boolean equalsTo(P other) {
        return this.name.equals(other.name) && this.age == other.age;
    }

    @Override
    public String toString() {
        return name;
    }

    public static void main(String[] args) {
        Person p1 = new Person("Alberto", 12);
        Person p2 = new Person("Alberto", 13);
        Person p3 = null;

        System.out.println(p1.equals(p1)); // true
        System.out.println(p1.equals(p2)); // false
        System.out.println(p1.equals(p3)); // false
    }
}
