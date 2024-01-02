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

int kilimitatoAux(Node* u, int k, int tot){
	if(u == nullptr) return 1; //O(1)
	tot += u->key; //O(1)
	if(tot != k) 
		return 0; //0(1)
	else
		return klimitatoAux(u->left, k, tot) && klimitatoAux(u->right, k, tot); //T(n/2) per ogni sottoalbero
}

int klimitato(Node* u, int k){
	if(u == nullptr) return 0;
	count = 0; // O(1)
	return klimitatoAux(u,k,count);
}

int main(){
	Node* root = new Node(10);
	
	return 0;
}
```