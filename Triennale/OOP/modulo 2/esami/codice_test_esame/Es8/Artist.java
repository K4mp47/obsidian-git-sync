package Es8;

public class Artist extends Person<Artist> {

    public final Hair hair;

    public Artist(String name, int age, Hair hair) {
        super(name, age);
        this.hair = hair;
    }

    @Override
    public boolean equalsTo(Artist other) {
        return super.equalsTo(other) && this.hair.equals(other.hair);
    }
}
