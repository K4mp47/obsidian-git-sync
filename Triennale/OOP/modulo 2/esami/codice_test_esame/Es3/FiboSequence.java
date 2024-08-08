package Es3;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class FiboSequence implements Iterable<Integer> {

    List<Integer> list = new ArrayList<>();

    final public void fillSequence(int size, int ind) {
        if (ind < size - 1) {
            if (ind < 2) {
                list.add(1);
            } else {
                list.add(list.get(ind - 1) + list.get(ind - 2));
            }
            fillSequence(size, ind + 1);
        }
    }

    public FiboSequence(int length) {
        fillSequence(length, 0);
    }

    @Override
    public Iterator<Integer> iterator() {
        return list.iterator();
    }

    public static void main(String[] args) {
        for (int n : new FiboSequence(100)) {
            System.out.println(n);
        }
    }

    
}
