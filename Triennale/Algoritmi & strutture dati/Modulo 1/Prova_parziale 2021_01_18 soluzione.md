![[Pasted image 20240102174840.png]]

```cpp
#include <iostream>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
	Node(int val): key(val), left(nullptr), right(nullptr) {}
};

int klimitatoAux(Node* u, int k,int tot){
	if(u == nullptr) return 1; //O(1)
	tot += u->key;
	int left = klimitatoAux(u->left, k, tot);
	int right = klimitatoAux(u->right, k, tot);
	if(tot <= k && left == 1 && right == 1){
		return 1;
	} else {
		return 0;
	}
}

int klimitato(Node* u, int k){
	if(u == nullptr) return 0;
	int count = 0; // O(1)
	return klimitatoAux(u,k,count);
}

int main(){
	Node* root = new Node(10);
	root->left = new Node(20);
	root->left->left = new Node(30);
	root->left->right = new node(40);
	root->right = new Node(40);
	root->right->right = new Node(30);
	root->right->left = new Node(10);
	cout << klimitato(root, 100) << endl;
	return 0;
}
```

![[Pasted image 20240104184005.png]]

```cpp
#include <iostream>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int partition(int punteggi[], int low, int high){
	int i = low;
	int pivot = punteggi[high];

	for(int j = low; j < high; j++){
		if(punteggi[j] < pivot){
			swap(punteggi[j],punteggi[i]);
			i++;
		}
	}

	swap(punteggi[i],punteggi[high]);
	return i;
}

void quick(int punteggi[], int low, int high){
	if(low < high){
		int pivot_location = partition(punteggi, low, high);
		quick(punteggi, low, pivot_location-1);
		quick(punteggi, pivot_location+1, high);
	}
}

int scarto(int n, int punteggi[]){
	quick(punteggi,0,n-1);// ricordo che n è pari
	int scart = 0;
	for(int i = 0; i < n; i += 2){
		scart += punteggi[i] + punteggi[i+1];
	}
	return scart;
}

int main(){
	int arr[12] = {0,2,5,3,8,12,9,1,7,13,17,16};
	cout << scarto(12, arr) << endl;
	return 0;
}
```

- La complessità di questo algoritmo risulta essere:
	- Essendoci un $O(n^2)$ e $O(n)$ per via del quicksort e del for, prevale la complessità del quicksort, portando la funzione ad una complessità $\Theta(n log n)$ con caso peggiore $O(n^2)$.

![[Pasted image 20240104165833.png]]
- Algoritmo numero 1:
	- Al di fuori delle operazioni costanti come dichiarazioni e for ripetuti per un tempo costante, troviamo un doppio for annidato e una chiamata ricorsiva effettuata sette volte. Dovendo studiare quando $n \rightarrow \infty$ abbiamo che $T(n) = 7T(n/3) + \Theta(n^2)$. ora troviamo che $n^{log_37}$ fa $n^{1.33}$ . Utilizzando il teorema Master ci troviamo nella terza casistica dove $f(n)=\Omega(n^{log_ba+\epsilon})$, dove in questo caso $\epsilon = 0.67$. Bisogna comunque controllare la *regularity condition* $af(n/b) \leq cf(n)$ per una costante $c< 1$, quindi abbiamo $7(\frac{n}{3})^2 \leq cn^2$ con c risultante $\frac{7}{9}$. Concludiamo dicendo che il tempo di esecuzione della funzione è $\Theta(n^2)$.
- Algoritmo numero 2:
	- Utilizzando lo stesso sistema usato nel precedente esercizio, notiamo un for singolo effettuato $n$ volte e una chiamata ricorsiva eseguita 16 volte. Da qui arriviamo quindi ad avere $T(n)=16T(n/4)+\Theta(n)$ . in questo caso avremo un $n^2$ trovandoci così nel primo caso, dove $f(n)=O(n^{log_ba-\epsilon})$ con conseguente tempo di esecuzione della funzione $\Theta(n^2)$ .