### Esercizio 1
```cpp
int aux_set_fruitful(PTNode r, int &k);

  

void set_fruitful(PTNode r, int k) {

aux_set_fruitful(r, k);

return;

}

  

/*

* La funzione mostra una complessita temporale in \Theta(n)

* essendo che la funzione deve per forza passare una volta per tutti i nodi dell'albero.

*

* Calcolo della complessità:

*

* T(n) = 3T(n/3) + \Theta(1)

* log_3(3) = 1 -> n^d = n^1

* \Theta(1) = f(n)

*

* f(n) = O(n^1)

*/

  

int aux_set_fruitful(PTNode r, int &k){

if (r == nullptr)

return 0;

int left = aux_set_fruitful(r->left, k);

int center = aux_set_fruitful(r->center, k);

int right = aux_set_fruitful(r->right, k);

(left > k && right > k && center > k) ? r->fruitful = true : r->fruitful = false;

return r->key + left + right + center;

}
```