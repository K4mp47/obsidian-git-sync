package Tutorato;

public class MyArrayList<T> {
    private Object[] a; // Object perchè deve essere il più generico possibile
    private int size;

    public MyArrayList() {
        this.a = new Object[10];
        this.size = 0;
    }

    public void add(T elem) {
       a[size++] = elem;
    }
}
