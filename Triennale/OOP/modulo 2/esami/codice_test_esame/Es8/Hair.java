package Es8;

import java.util.Set;

public class Hair implements Equatable<Hair> {

    public final int length;
    public final Set<Color> colors;

    public Hair(int length, Set<Color> colors) {
        this.colors = colors;
        this.length = length;
    }

    @Override
    public boolean equals(Object o) {
        if(this == o) return true;
        if(o == null || this.getClass() != o.getClass()) return false;
        return this.equalsTo((Hair) o);
    }

    @Override
    public boolean equalsTo(Hair x) {
        return this.length == x.length && this.colors.equals(x.colors);
    }
}

