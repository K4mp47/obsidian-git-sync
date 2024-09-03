package Es7;

public class WrapperRandom {

    private static Random random;

    public WrapperRandom() {
    }

    public static Random instance(){
        if(random == null){
            random = new Random();
        }
        return random;
    }

    public static Random instance(int seed){
        if(random == null){
            random = new Random(seed);
        }
        return random;
    }

    public static boolean nextBoolean() { return random.nextBoolean(); }
    public static int nextInt() { return instance().nextInt(10); }
    public static double nextDouble() { return random.nextDouble(); }
}
