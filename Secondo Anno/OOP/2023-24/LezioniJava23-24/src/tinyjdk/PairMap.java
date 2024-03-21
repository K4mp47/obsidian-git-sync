package tinyjdk;

public class PairMap<K, V> implements Map<K, V> {
    private List<Pair<K, V>> l = new ArrayList<>();

    @Override
    public void put(K k, V v) {
        assert (k != null);
        l.add(new Pair<>(k, v));
    }

    @Override
    public V get(K k) throws KeyNotFoundException {
        for (int i = l.size() - 1; i >= 0 ; --i) {
            Pair<K, V> p = l.get(i);
            if (p.first.equals(k))
                return p.second;
        }
        throw new KeyNotFoundException(k);
    }

    @Override
    public Iterator<Pair<K, V>> iterator() {
        return new Iterator<>() {
            private int pos = l.size() -1;
            private Set<K> history = new HashSet<>();
            
            @Override
            public boolean hasNext() {
                return pos < l.size();
            }

            @Override
              public Pair<K, V> next() {
                Pair<K, V> r = l.get(pos--);
                if (history.contains(r.first)){
                    if (hasNext()) return next();
                } else {
                    history.add(r.first);
                    return r;
                }
                return r;
            }
        };
    }
}
