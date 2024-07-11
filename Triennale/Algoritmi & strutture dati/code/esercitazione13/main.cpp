#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
// Campagnolo Alberto, 897569
// Esercizio 1
//
// Complessità Theta(n), dovuta al fatto che l'algoritmo passa per ogni nodo una volta sola, il 
// valore di ritorno viene salvato nella variabile reference t.
//
// Algoritmo: usa una funzione ausiliaria
//
// Campagnolo Alberto, 897569
// Esercizio 3
//
// Complessità {da inserire} 

struct Node {
  int key;
  Node* left;
  Node* right;
};

typedef Node* Pnode;


void printDotFile(Node* u, std::ostream& out);
Pnode ricostruisci(const std::vector<int>& va, const std::vector<int>& vs);
Pnode ricostruisciAux(const std::vector<int>& va, const std::vector<int>& vs, int start, int end, int& index);

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
    printInOrderRecursive(root,0,false);    
  } 

  Node* getRoot() {
    return root;
  }

  void copyRoot(Pnode u){
    root = u;
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

  void printInOrderRecursive(Node* u, int indent, bool isLeft = false) {
    if (u != nullptr) {
        printInOrderRecursive(u->right, indent + 4, false);

        if (indent > 0) {
            std::cout << std::setw(indent - 1);
            if (isLeft) {
                std::cout << "/";
            } else {
                std::cout << "\\";
            }
            std::cout << "-- ";
        }

        std::cout << u->key << std::endl;

        printInOrderRecursive(u->left, indent + 4, true);
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
  std::cout << "Creating the new binary tree" << std::endl;
  // tree.printInOrder();

  std::vector<int> myVector  = {1, 2, 3, 5, 6, 9, 11, 10};
  std::vector<int> myVector2 = {5, 3, 6, 2, 1, 11, 9, 10};
  
  Pnode new_tree = ricostruisci(myVector, myVector2);
  tree.copyRoot(new_tree); // need to be changed to new_tree;
  tree.printInOrder();
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

Pnode ricostruisciAux(const std::vector<int>& va,const std::vector<int>& vs,int start,int end,int& index){
  if(start > end){
    return nullptr;
  }
  int x = va[index]; // radice dell'albero
  int i = start; // indice per simmetrivo
  while(i < end && vs[i] != x){
    i++;
  }
  // passare ricorsivamente i due indici
  std::cout << x << " " << i << std::endl;
  index++;
  Pnode root = new Node{x, ricostruisciAux(va, vs, start, i-1, index), ricostruisciAux(va, vs, i+1, end, index)};
  return root; 
}

Pnode ricostruisci(const std::vector<int>& va, const std::vector<int>& vs){
  if(va.size() != vs.size()){
    return nullptr;
  }
  int index = 0;
  return ricostruisciAux(va, vs, 0, va.size()-1, index);
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
