#include <iostream>
#include <iomanip>
#include <fstream>
// Campagnolo Alberto, 897569
// Esercizio 1
//
// Complessità Theta(n), dovuta al fatto che l'algoritmo passa per ogni nodo una volta sola, il 
// valore di ritorno viene salvato nella variabile reference t.
//
// Algoritmo: usa una funzione ausiliaria
//
// Campagnolo Alberto, 897569
// Esercizio 2
//
// Complessità {da inserire} dovuto al fatto che l'algoritmo passa per tutti i nodi presenti nel peggiore dei casi.

struct Node {
  int key;
  Node* left;
  Node* right;
};

typedef Node* Pnode;

bool inNonDecAux(Pnode u);
bool inNonDec(Pnode u);
void printDotFile(Node* u, std::ostream& out);
 
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
    printInOrderRecursive(root,0);    
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
  tree.insert(30);
  tree.insert(40);
  tree.insert(35);
  tree.insert(32);
  tree.insert(33);
  tree.insert(31);
  tree.insert(34);
  tree.insert(45);
  tree.insert(42);
  tree.insert(20);
  tree.insert(22);
  tree.insert(24);
  tree.insert(23);
  tree.insert(25);
  tree.insert(29);
  tree.insert(26);
  tree.insert(27);
  tree.insert(28);
  tree.insert(15);
  tree.insert(16);
  std::cout << std::endl;
  Pnode u = tree.getRoot();
  u->left->right->right->right->key = 100;
  tree.printInOrder();
  bool t = inNonDec(tree.getRoot());
  std::cout << t << std::endl;
  std::ofstream dotFile("tree.dot");
    if (dotFile.is_open()) {
        dotFile << "digraph BinaryTree {" << std::endl;
        printDotFile(tree.getRoot(), dotFile);
        dotFile << "}" << std::endl;
        dotFile.close();

        // Run Graphviz to convert DOT to PNG (you need to have Graphviz installed)
        system("dot -Tpng tree.dot -o tree.png");
        std::cout << "Graphical representation saved as tree.png" << std::endl;
    } else {
        std::cerr << "Unable to open DOT file for writing." << std::endl;
    }

    return 0;
}

// Possible solution

bool inNonDecAux(Pnode u) {
  if(u->right) return u->key < u->right->key;
  return true; 
}

bool inNonDec(Pnode u) {
  if(u == nullptr) return true;
  bool x = inNonDecAux(u);
  if(!x) return false;
  return inNonDec(u->left) && inNonDec(u->right); 
}

void printDotFile(Node* u, std::ostream& out) {
    if (u != nullptr) {
        if (u->left != nullptr) {
            out << u->key << " -> " << u->left->key << " [label=\"L\"];" << std::endl;
            printDotFile(u->left, out);
        }
        if (u->right != nullptr) {
            out << u->key << " -> " << u->right->key << " [label=\"R\"];" << std::endl;
            printDotFile(u->right, out);
        }
    }
}
