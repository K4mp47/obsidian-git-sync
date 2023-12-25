package vehicles;

import java.util.ArrayList;
public class List<V> {
    private final ArrayList<V> elements = new ArrayList<V>(0);

    public void add(V el)  {
        elements.add(el);
    }

    public static <V> int length(List<V> list) {
        return list.elements.size();
    }
    public boolean contains(V el) {
        for (V element : elements) {
            if (element == el) return true;
        }
        return false;
    }
    public V get(int i) {
        return elements.get(i);
    }

}
