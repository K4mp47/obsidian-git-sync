package Es3;

import java.util.ArrayList;
import java.util.Collection;

public class ThreadMultiplier {

    public static void main(String[] args) {
        Collection<Integer> numbers = new ArrayList<>();
        for (int i = 0; i < 10; i += 1) {
            numbers.add(i);
        }

        Collection<FactThread> list = MultiFact.multiFact(numbers);
        for (FactThread elem : list) {
            try {
                elem.join();
            } catch (InterruptedException e) {
                throw new RuntimeException();
            }
            System.out.println(elem.res);
        }        
    }
}
