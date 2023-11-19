import java.util.*;

class Fibonacci {
    int last1,last2,index = 0;

    Fibonacci(){
        last1=1;
        last2=1;
    }

    int next(){
        if(index > 1){
            int change = last2;
            last2 = last2 + last1;
            last1 = change;
            index++;
        } else {
            index++;
            return 1;
        }
        return last2;
    }
}

public class Main{
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Fibonacci generator = new Fibonacci();
        for (int i = 0; i < n; i++) {
            System.out.print(generator.next());
            if (n != i - 1)
                System.out.print(" ");
        }
    }
}
