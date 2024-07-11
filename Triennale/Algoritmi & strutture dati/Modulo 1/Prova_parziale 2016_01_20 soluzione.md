![[Pasted image 20240102133608.png]]
```cpp
/*
* La complessità di questo codice risulta essere:
* - T(n) = 2T(n/2) + O(1)
* - Si ricade nel primo caso del teorema master,
*   dove n^1 > O(1), facendo si che T(n) = \Theta(n)
*/


#include <iostream>java: unreported exception exam13_01_2023.SoccerTournamentException; must be caught or declared to be thrown
using namespace std;

// struttura del nodo
struct Node {
	int key;
	Node* left_child;
	Node* right_sib;
	Node(int val): key(val), left_child(nullptr), right_sib(nullptr) {}
};

// potrebbe essere ottimizzata riducendo gli accessi al left_child
int checkSameKey(Node* u, int& value){
	if(u == nullptr) return 0; //O(1)
	if(u->key == value) // sempre T(n/2) sia if che else
		return 1 + checkSameKey(u->left_child, value) + checkSameKey(u->right_sib, value); 
	else 
		return 0 + checkSameKey(u->left_child, value) + checkSameKey(u->right_sib, value); 
}

int main(){
	Node* root = new Node(10);
	root->left_child = new Node(5);
	root->left_child->left_child = new Node(4);
	root->left_child->left_child->left_child = new Node(10);
	root->left_child->left_child->right_sib = new Node(10);
	root->left_child->left_child->right_sib->right_sib = new Node(2);

	int val = 10;
	cout << checkSameKey(root, 10) << endl;
	return 0;
}
```


![[Pasted image 20240102143944.png]]


```cpp
#include <iostream>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
	Node(int val): key(val), left(nullptr), right(nullptr), {}
}

int checkValue(Node* u, int value){
	if(u == nullptr) return 0; // O(1)
	if(value == u->key) // entrambi T(n/2)
		return 1 + checkValue(u->left, value) + checkValue(u->right, value);
	else
		return 0 + checkValue(u->left, value) + checkValue(u->right, value);
}
// complexity checkValue = T(n) = 2T(n/2) + O(1) = \Theta(n)


int main(){
	Node* root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(7);
	root->left->left = new Node(10);
	root->left->right = new Node(8);
	root->right->right = new Node(5);
	cout << checkValue(root, 10) << endl; 
	return 0;
}
```


![[Pasted image 20240102151759.png]]
- Definizione formale delle relazioni:
	- $O$
		- Esiste una funzione $f(n)$ tale che, per $n$ abbastanza grandi, se abbiamo $O(g(n))$ allora $0 \leq f(n) \leq cg(n)$ dove c è una costante intera positiva
	- $\Omega$
		-  Esiste una funzione $f(n)$ tale che, per $n$ abbastanza grandi, se abbiamo $\Omega(g(n))$ allora $0 \leq cg(n) \leq f(n)$ dove c è una costante intera positiva
	- $\Theta$
		-  Esiste una funzione $f(n)$ tale che, per $n$ abbastanza grandi, se abbiamo $O(g(n))$ allora $0 \leq f(n) \leq cg(n)$ dove c è una costante intera positiva
	- $o$
		-  Esiste una funzione $f(n)$ tale che, per $n$ abbastanza grandi, se abbiamo $\Theta(g(n))$ allora $0 \leq c_1g(n) \leq f(n) \leq c_2g(n)$ dove $c_1$ e $c_2$ sono due costanti intere positive
	- $\omega$ 
		-  Esiste una funzione $f(n)$ tale che, per $n$ abbastanza grandi, se abbiamo $\omega(g(n))$ allora $0 \leq f(n) \leq cg(n)$ per ogni $c > 0$ 
- a) Essendo $P(n)$ un polinomio possiamo pensarlo come $a_kn^k$ come elemeno rilevante.
	- $0 \leq c_1g(n) \leq f(n) \leq c_2g(n)$, uguale ad $0 \leq c_1n^k \leq a_kn^k \leq c_2n^k$ quindi possiamo dare come rispettivo valori a $c_1$  e $c_2$ un valore che sia maggiore/minore di $a_k$ e la funzione è verificata
- b) In questo caso abbiamo una $O$, quindi $0 \leq f(n) \leq cg(n)$
	- Semplificando viene $1 \leq log(log(n))c$ ipotizzando poi un $n \geq 2$ 
	- Sappiamo che un logaritmo per essere positivo deve far si che $n \geq 2$ 
	- Da qui rimane solo trovare un $c \geq loglog(n)$ per $n \geq 2$ 
- c) In questa equazione abbiamo che:
	- Semplificando per $n$ si ha $loglog(n) \leq cn^\epsilon$ 
	- Ipotizziamo un $c=1$ 
	- $n^\epsilon$ sarà sempre più grande essendo un esponenziale
- d) L'affermazione risulta essere vera, essendoci entrambe le condizioni per Big o e Omega rispettate
- e) L'affermazione risulta essere falsa nel momento in cui, per esempio, la funzione $f(n)$ cresce uguale a quella di $g(n)$. 
