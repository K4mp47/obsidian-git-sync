package Es7;

import java.util.Iterator;
import java.util.Random;

public class RandomIterator implements Iterator<Integer>{
    
    private int sequence;

    public RandomIterator(int seq){
        this.sequence = seq;
    }

    @Override
    public boolean hasNext() {
        sequence -= 1;
        return sequence > 0; 
    }

    @Override
    public Integer next() {
        Random random = new Random();
        return random.nextInt();
    }
}