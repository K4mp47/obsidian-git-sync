package esame1;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class Esame1 {

    private static int c = 0;

    public static int somma(int a, int b) {
        return a + b;
    }

    public static void main(String[] args) throws Exception {
        Class<?> d = Esame1.class;
        for (Method a : d.getDeclaredMethods()) {
            System.out.println(a);
        }
        // new d instance
        Method m = d.getDeclaredMethod("somma", int.class, int.class);

        System.out.println(m.invoke(m, 1, 2));
        Field f = d.getDeclaredField("c");
        f.setAccessible(true);
        f.set(f, 10);
        System.out.println(d.getDeclaredField("c").get(c));
    }
}
