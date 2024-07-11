![[Pasted image 20231230171440.png]]
```cpp
#include <iostream>
using namespace std;

struct Node { // changed in cpp language
	int key;
	Node * left;
	Node * right;
  Node(int val) : key(val), left(nullptr), right(nullptr) {}
};


// auxiliary function with recursion
int retIntermedioAux(Node* U, int tot, int& check){
	if(U == nullptr) return 0;
	int sottodx = retIntermedioAux(U->right, tot+U->key, check);
	int sottosx = retIntermedioAux(U->left, tot+U->key, check);
	if(tot == (sottosx+sottodx)) check++;
	return sottosx+sottodx+U->key;
}

int retIntermedio(Node* U){ // inizialize value for auxiliary
  int check = 0;
  retIntermedioAux(U, 0, check);
  return check;
} 

int main(){
  // create a binary tree
  Node* root = new Node(10);
  root->left = new Node(5);
  root->right = new Node(15);
  root->left->left = new Node(3);
  root->left->right = new Node(7);
  root->right->left = new Node(2);
  root->right->right = new Node(8);
  int ret = retIntermedio(root);
  cout << ret << endl; 
  return 0;
}
```

In that case the code have complexity $\theta(n)$, 'cause it always run n time, where n is the number of nodes inside the binary tree.

![[Pasted image 20231231164726.png]]

```cpp
#include <iostream>
using namespace std;

int checkSequenceAux(char* p1, char* p2){
	if(*p2 == '\0') return 0; // O(1)
	if(*p1 == 'a' && *p2 == 'r') {
	    return 1 + checkSequenceAux(++p1, ++p2);
  } else { 
	    return 0 + checkSequenceAux(++p1, ++p2);
  }
}

int checkSequence(char* array, int dim){
	if(dim < 2) return 0;
	char* point1 = array;
	char* point2 = point1 + 1;
  cout << "iniziamo" << endl;
	return checkSequenceAux(point1, point2); 
}

int main(){
	char arr[7] = {'a','r','o','o','a','r','o'};
	cout << checkSequence(arr, 7) << endl;
	return 0;
}
```

- La complessità dell'algoritmo sopra è:
	- Essendoci una sola chiamata ricorsiva per volta, e dovendo richiamare tante volte quanti sono gli elementi dell'array, la complessità risulta essere O(n).

![[Pasted image 20231231171638.png]]

- Nel primo caso la soluzione è:
	- $a=3$ e $b=2$ quindi $n^{log_ba}= 1.58$ circa
	- $n^{1.58}$ è minore di $n^2$, quindi siamo nel terzo caso
	- $f(n) = n^{1.58 + 0.42}$ dove $\epsilon = 0.42$, regular condition $3(\frac{n}{2}^2) \leq cn^2$ per $c = \frac{3}{4}$.
	- Essendo verificata, $T(n) = \Theta(n^2)$ 
- Nel secondo caso la soluzione è:
	- $a=4$ e $b=2$ quindi $n^{log_ba}=2$
	- $n^2$ anche per $f(n)$, quindi siamo nel secondo caso
	- $f(n)=n^{log_24}lg^k n$, dove $lg^k n$ possiamo porlo $k=0$
	- Essendo che la condizione sopra risulta essere vera, $T(n)=\Theta(n^{log_24}lg^1 n)$ 
- Nel terzo caso la soluzione è:
	- $a=1$  e $b=2$ quindi $n^{log_ba}=1$ 
	- $1$ è minore della $f(n)$ quindi siamo nel terzo caso
	- regular condition, ovvero $2^{\frac{n}{2}} \leq c 2^n$ che, semplificando dividendo per $2^n$, risulta essere $c \geq 2^{-\frac{n}{2}}$ 
	- Essendo risolta anche la regular condition, $T(n) = \Theta(2^n)$ 