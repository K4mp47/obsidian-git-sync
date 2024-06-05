package esame2;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.Iterator;

public class BST<T> implements Iterable<T> {

    protected final Comparator<? super T> cmp;
    protected Node root;

    protected class Node {

        protected final T data;
        protected Node left, right;

        protected Node(T data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    public BST(Comparator<? super T> cmp) {
        this.cmp = cmp;
    }

    public void insert(T x) {
        root = insertRec(root, x);
    }

    protected Node insertRec(Node n, T x) {
        if (cmp.compare(n.data, x) < 0) {
            n.right = insertRec(n, x);
        }
        if (cmp.compare(n.data, x) > 0) {
            n.left = insertRec(n, x);
        }
        return new Node(x, null, null);
    }

    protected void dfsInOrder(Node n, Collection<T> out) {
        if (n != null) {
            if (n.left != null) {
                dfsInOrder(n.left, out);
                out.add(n.left.data);
            }
            out.add(n.data);
            if (n.right != null) {
                dfsInOrder(n.right, out);
                out.add(n.right.data);
            }
        }
    }

    @Override
    public Iterator<T> iterator() {
        Collection<T> out = new ArrayList<>();
        dfsInOrder(root, out);
        return out.iterator();
    }

    public T min() {
        Iterator<T> it = this.iterator();
        return it.next();
    }

    public T max() {
        Iterator<T> it = this.iterator();
        T last = it.next();
        while (it.hasNext()) {
            last = it.next();
        }
        return last;
    }
}
