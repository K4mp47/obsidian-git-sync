package Es9;

public class Node<T> {

    protected Node<T> left, right = null;
    protected final T data;

    public Node(T data) {
        this.data = data;
    }
}
