#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;
  Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

typedef Node *NodePtr;

void insertNode(Node *&root, int key) {
  if (root == nullptr) {
    root = new Node(key);
    return;
  }
  if (root->key > key)
    insertNode(root->left, key);
  else
    insertNode(root->right, key);
}

int createTree(Node *&root, int arr[], int dim) {
  for (int i = 0; i < dim; i++) {
    insertNode(root, arr[i]);
  }
  return 1;
}

void showTree(Node *root) {
  if (root == nullptr)
    return;
  showTree(root->left);
  cout << root->key << " ";
  showTree(root->right);
}

NodePtr findNode(Node *u, int key) {
  if (u == nullptr)
    return nullptr;
  if (u->key == key)
    return u;
  Node *templ = findNode(u->left, key);
  Node *tempr = findNode(u->right, key);
  return templ == nullptr ? tempr : templ;
}

int checkSameKeyAux(Node *u, int key) {
  if (u == nullptr || u->key != key)
    return 0;
  return 1 + checkSameKeyAux(u->left, key) + checkSameKeyAux(u->right, key);
}

int checkSameKey(Node *u, int key) {
  NodePtr tempo = findNode(u, key);
  if (tempo == nullptr)
    return 0;

  return checkSameKeyAux(tempo, key);
}

int main() {
  Node *root = nullptr;
  int arr[13] = {4, 2, 3, 1, 5, 5, 5, 5, 6, 7, 8, 9, 10};
  createTree(root, arr, 13);
  showTree(root);
  cout << findNode(root, 5)->key << endl;
  cout << checkSameKey(root, 5) << endl;
  return 0;
}
