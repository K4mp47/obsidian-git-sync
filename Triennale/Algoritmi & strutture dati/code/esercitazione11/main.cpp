#include <iostream>
#include <iomanip>

// Campagnolo Alberto, 897569
// Esercizio 1
//
// Complessità Theta(n), dovuta al fatto che l'algoritmo passa per ogni nodo una volta sola, il 
// valore di ritorno viene salvato nella variabile reference t.
//
// Algoritmo: usa una funzione ausiliaria

struct Node {
  int key;
  Node* left;
  Node* right;
};

typedef Node* Pnode;

int tBilaux(Pnode u, int& t);
int tBil(Pnode u); 

class BinaryTree {
public:
  BinaryTree() : root(nullptr) {}
  ~BinaryTree() {
    destroy(root);
  }
  void insert(int key) {
    root = insertRecursive(root, key);
  };

  void remove(int key) {
    root = removeRecursive(root, key);
  }
  
  void printInOrder() {
    printInOrderRecursive(root, 0);    
  } 

  Node* getRoot() {
    return root;
  }
private:
  Node* root;

  Node* insertRecursive(Node* u, int key) {
    if (u == nullptr) {
      u = new Node;
      u->key = key;
      u->left = nullptr;
      u->right = nullptr;
    } else if (key < u->key) {
      u->left = insertRecursive(u->left, key);
    } else if (key > u->key) {
      u->right = insertRecursive(u->right, key);
    }
    return u;
  }

  void printInOrderRecursive(Node* u, int indent) {
    if (u != nullptr) {
      printInOrderRecursive(u->right, indent+4);
      std::cout << std::setw(indent) << " " << u->key << std::endl;
      printInOrderRecursive(u->left, indent+4);
    }
  }

  Node* removeRecursive(Node* u, int key) {
    if (u == nullptr) {
      return nullptr;
    }
    if (key < u->key) {
      u->left = removeRecursive(u->left, key);
    } else if (key > u->key) {
      u->right = removeRecursive(u->right, key);
    } else {
      if (u->left == nullptr && u->right == nullptr) {
        delete u;
        u = nullptr;
      } else if (u->left == nullptr) {
        Node* tmp = u;
        u = u->right;
        delete tmp;
      } else if (u->right == nullptr) {
        Node* tmp = u;
        u = u->left;
        delete tmp;
      } else {
        Node* tmp = u->left;
        while (tmp->right != nullptr) {
          tmp = tmp->right;
        }
        u->key = tmp->key;
        u->left = removeRecursive(u->left, tmp->key);
      }  
    }
    return u;
  }

  void destroy(Node* u) {
    if (u != nullptr) {
      destroy(u->left);
      destroy(u->right);
      delete u;
    }
  }
};

int main (int argc, char *argv[]) {
  BinaryTree tree;
  tree.insert(10);
  tree.insert(5);
  tree.insert(15);
  tree.insert(3);
  tree.insert(7);
  tree.insert(20);
  tree.insert(2);
  tree.insert(30);
  tree.insert(40);
  tree.insert(45);
  tree.insert(50);
  tree.insert(12);
  tree.insert(1);
  std::cout << std::endl;
  tree.printInOrder();
  int t = tBil(tree.getRoot());
  std::cout << std::endl << "Valore di t: >> " << t << " <<" << std::endl; 
  return 0;
}

int tBilaux(Pnode u, int& t) {
  if (u == nullptr) {
    return 0;
  } 
  int left = 1 + tBilaux(u->left, t);
  int right = 1 + tBilaux(u->right, t);
  //return std::abs(left - right);
  t = std::max(t, std::abs(left - right));
  return std::max(left, right);
}

int tBil(Pnode u) {
  int t = 0;
  tBilaux(u, t);
  return t;
} 
