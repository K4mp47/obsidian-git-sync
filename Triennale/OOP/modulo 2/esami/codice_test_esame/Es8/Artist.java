package Es8;

import java.util.Arrays;
import java.util.Collection;
import java.util.Comparator;
import java.util.List;
import java.util.Set;

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

    static <T> T max(Collection<? extends T> c, Comparator<? super T> cmp) {
        T max = null;
        for (T elem : c) {
            if (max == null || cmp.compare(elem, max) > 0) {
                max = elem;
            }
        }
        return max;
    }

    public static void main(String[] args) {
        Person alice = new Person("Alice", 23), david = new Artist("Bowie", 69, new Hair(75, Set.of(Color.RED, Color.BROWN, Color.GRAY)));
        Artist morgan = new Artist("Morgan", 47, new Hair(20, Set.of(Color.GRAY, Color.DARK))), madonna = new Artist("Madonna", 60, new Hair(50, Set.of(Color.BLONDE)));

        List<Artist> artists = Arrays.asList((Artist) david, morgan, madonna);
        List<Person> persons = Arrays.asList(alice, david, morgan, madonna);

        Artist hairest = max(artists, new Comparator<Artist>() {
            @Override
            public int compare(Artist a, Artist b) {
                return a.hair.length - b.hair.length + (a.hair.colors.size() - b.hair.colors.size());
            }
        });

        Person first = max(persons, new Comparator<Person>() {
            @Override
            public int compare(Person a, Person b) {
                // cerca chi è primo in ordine alfabetico
                if(a.name.compareTo(b.name) > 0) return -1;
                return 1;
            }
        });
        System.out.println(hairest);
        System.out.println(first);
    }
}
