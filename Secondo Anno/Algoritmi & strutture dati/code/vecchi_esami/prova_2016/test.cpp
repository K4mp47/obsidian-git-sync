#include <iostream>
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
	if(u == nullptr) return 0;
	if(u->key == value)
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
	cout << checkSameKey(root, val) << endl;
	return 0;
}
