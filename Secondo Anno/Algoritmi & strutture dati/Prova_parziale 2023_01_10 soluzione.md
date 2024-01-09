
![[Pasted image 20240107141549.png]]

```cpp
#include <iostream>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
	Node(int val): key(val), right(nullptr), left(nullptr) {}
}

int k_compresoAux(Node* u, int k, int tot){
	if(u == nullptr){
		return 1;
	}
	tot += u->key;
	if(tot < k*(-1) || tot > k) return 0;
	return k_compresoAux(u->left, k, tot) && k_compresoAux(u->right, k, tot); // doppia chiamata ricorsiva, il resto è costante
	
}

int k_compreso(Node* u, int k){
	return k_compresoAux(u, k, 0);
}

int main(){
	Node* root = new Node(10);
	root->left = new Node(5);
	root->right =  new Node(15);
	cout << k_compreso(root, 30) << endl;
}
```

- Per calcolare la complessità di questo algoritmo tramite sostituzione, dobbiamo prima calcolare la relazione di ricorrenza, ovvero $T(n)=2T(n-1)+O(1)$. Ora applichiamo l'ipotesi che la soluzione sia che $T(n) \leq c2^n$, sostituendo poi alla relazione iniziale, troviamo che $c2^n \leq 2(c2^{n-1}) + O(1)$. 
	- $c2^n \leq 2c 2^{n-1} + O(1)$
	- Dividiamo tutto per $2^n$ $\rightarrow$ $c\leq c+\frac{O(1)}{2^n}$ 
	- Da qui notiamo come $\frac{O(1)}{2^n}$ tenda a $0$ e quindi possa essere trascurato.
	- $c \leq c$ è vera
	- La soluzione è corretta, ovvero $O(n^2)$.
- Utilizzo del linguaggio cpp per il codice sopra riportato

![[Pasted image 20240107145104.png]]
- Soluzione in loco, non stabile, versione del quicksort con condizione modificata per l'ordinamento, per rispettare le condizioni poste. Complessità equivalente al quicksort, quindi $O(nlogn)$, con caso peggiore $O(n^2)$
```cpp
#include <iostream>
using namespace std;

int swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int partition(int array[], int low, int high){
	int i = low-1;
	int pivot = array[high];
	for(int j = low; j < high; j++){
		i++;
		if(array[j] % 3 <= pivot % 3) swap(array[j], array[i]);
	}
	swap(array[i+1], array[high]);
	return i+1;
}

int quicksort_remake(int array[], int low, int high){
	if(low < high);
		int index = partition(array,low,high);
		quicksort_remake(array, low, index-1);
		quicksort_remake(array, index+1, high);
}
```

![[Pasted image 20240107145429.png]]
- Algoritmo A: $T(n)=5T(n/2) + O(n)$
	- Applicando il teorema Master, abbiamo $n^{log_ba}$ maggiore della $f(n)$ quindi il tempo di esecuzione sara $\Theta(n^{log_ba})$  
- Algoritmo B:$T(n)=2T(n-1)+O(1)$
	- Applicare il teorema Master in questo caso non è possibile, quindi utilizziamo il metodo di sostituzione, che torna come risultato $O(2^n)$ 
- Algoritmo C:$T(n)=9T(n/3)+O(n^2)$ 
	- Applicando il teorema Master, abbiamo $n^2$ uguale alla $f(n)$, quindi essendo nel secondo caso il tempo di esecuzione sarà $\Theta(n^2log n)$   
- La scelta migliore sembrerebbe essere l'algoritmo A, essendo quello con la crescita minore in caso di grandi input.
*Extra: qui lascio il codice python per fare i grafici, con tanto di risultato, ricorda di installare matplotlib*
```python
import matplotlib.pyplot as plt
import numpy as np

# Definiamo le funzioni di complessità
def complexity_A(n):
    return n ** (np.log2(5))

def complexity_B(n):
    return 2 ** n

def complexity_C(n):
    return n ** 2 * np.log2(n)

# Generiamo valori di n
n_values = np.arange(1, 20)

# Calcoliamo i valori delle complessità per i vari n
A_values = [complexity_A(n) for n in n_values]
B_values = [complexity_B(n) for n in n_values]
C_values = [complexity_C(n) for n in n_values]

# Creiamo il grafico
plt.figure(figsize=(10, 6))
plt.loglog(n_values, A_values, label='Algoritmo A: $n^{\log_2 5}$')
plt.loglog(n_values, B_values, label='Algoritmo B: $2^n$')
plt.loglog(n_values, C_values, label='Algoritmo C: $n^2 \log n$')

plt.xlabel('Dimensione dell\'input (n)')
plt.ylabel('Tempo di esecuzione (complessità)')
plt.title('Confronto della crescita asintotica degli algoritmi')
plt.legend()
plt.grid(True)
plt.show()

```

![[Pasted image 20240107155927.png]]