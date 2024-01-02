#include <iostream>
using namespace std;

struct Node {
	int key;
	Node * left;
	Node * right;
  Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

int retIntermedioAux(Node* U, int tot, int& check){
	if(U == nullptr) return 0;
	int sottodx = retIntermedioAux(U->right, tot+U->key, check);
	int sottosx = retIntermedioAux(U->left, tot+U->key, check);
	if(tot == (sottosx+sottodx)) check++;
	return sottosx+sottodx+U->key;
}

int retIntermedio(Node* U){
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
