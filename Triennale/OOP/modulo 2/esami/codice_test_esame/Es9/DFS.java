package Es9;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

public class DFS<T> implements Iterable<T> {

    protected Node<T> root;
    protected final Comparator<T> cmp;

    public DFS(Comparator<T> cmp) {
        this.cmp = cmp;
        root = null;
    }

    public T insert(Node<T> node) {
        if (this.root == null) {
            this.root = node;
            return node.data;
        }
        return insertRec(node, this.root).data;
    }

    private Node<T> insertRec(Node<T> node, Node<T> root) {
        if (cmp.compare(root.data, node.data) < 0) {
            if (root.right == null) {
                root.right = node;
                return node;
            }
            return insertRec(node, root.right);
        }
        if (cmp.compare(root.data, node.data) > 0) {
            if (root.left == null) {
                root.left = node;
                return node;
            }
            return insertRec(node, root.left);
        }
        return root;
    }
    
    private List<Node<T>> dfsInOrder(Node<T> root) {
        List<Node<T>> ret = new ArrayList<>();
        if (root != null) {
            ret.addAll(dfsInOrder(root.left));
            ret.add(root);
            ret.addAll(dfsInOrder(root.right));
        }
        return ret;
    }

    @Override
    public Iterator<T> iterator() {

        return new Iterator<T>() {

            private final List<Node<T>> stack = dfsInOrder(root);
            private int index = 0;

            @Override
            public boolean hasNext() {
                return index < stack.size();
            }

            @Override
            public T next() {
                return stack.get(this.index++).data;
            }
        };
    }

    public static void main(String[] args) {
        DFS<Integer> dfs = new DFS<>(Integer::compareTo);
        System.out.println(dfs.insert(new Node<>(5)));
        System.out.println(dfs.insert(new Node<>(6)));
        System.out.println(dfs.insert(new Node<>(10)));
        System.out.println(dfs.insert(new Node<>(4)));
        System.out.println(dfs.insert(new Node<>(8)));
        System.out.println();
        for (Integer i : dfs) {
            System.out.println(i);
        }
    }
}
