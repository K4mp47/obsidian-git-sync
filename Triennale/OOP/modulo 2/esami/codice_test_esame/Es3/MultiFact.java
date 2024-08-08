package Es3;

import java.util.ArrayList;
import java.util.Collection;

public class MultiFact {
    
    public static Collection<FactThread> multiFact(Collection<Integer> coll){
        Collection<FactThread> threads = new ArrayList<>();
        
        for(int num: coll){
            FactThread thread = new FactThread(num);
            threads.add(thread);
            thread.start();
        }

        return threads;
    }
}
