import java.util.Random;
/*
ESEMPIO DI SINGLETON E ELEMENTI NECESSARI PER IMPLEMENTARE IL PATTERN

public class Board {
    // 1) istanza privata e statica come membro
    private static Board b;
    //2)  costruttore privato
    private Board(){
    }

    //3) metodo static public per accedere all'istanza
    public static Board getBoard(){
        if(b==null) b = new Board();
        return b;
    }


}*/


    /*Random r = new Random(10)
    r.nextInt();
    * */

    public class RandomSingleton {

        private RandomSingleton(){

        }

        public void setSeed(int seed){
            instance = new Random();
        }

        private static Random instance;

        private static Random getInstance(){
            if(instance == null) instance = new Random();
            return instance;
        }

        /*
        * Random r = RandomSingleton.getInstance()
        * */




        public static int nextInt (){
            return getInstance().nextInt();
        }

        public static boolean nextBoolean(){
            return getInstance().nextBoolean();
        }

        public static double nextDouble(){
            return getInstance().nextDouble();
        }


    }




