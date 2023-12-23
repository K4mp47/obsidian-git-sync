#include <string>
#include <iostream>

using namespace std;

struct Node {
  std::string colore;
  Node * right;
  Node * left;

  Node(std::string s) : colore(s), right(nullptr), left(nullptr) {} 

  ~Node() {
    delete right;
    delete left;
  }
};

int contaDiscendenti(Node* radice, int& countBianchi, int& countNeri) {
  if (radice == nullptr) return 0;

  int countLeft = contaDiscendenti(radice->left, countBianchi, countNeri);
  int countRight = contaDiscendenti(radice->right, countBianchi, countNeri);

  (radice->colore == "bianco")? countBianchi++ : countNeri++;

  if (countBianchi == countNeri) return countLeft + countRight + 1;
  return countLeft + countRight;
}

int main() {
    // Esempio di creazione di un albero binario
    Node* radice = new Node("bianco");
    radice->left = new Node("nero");
    radice->left->left = new Node("bianco");
    radice->left->right = new Node("nero");
    radice->right = new Node("bianco");
    radice->right->right = new Node("nero");

    // Variabili per memorizzare il conteggio
    int countBianchi = 0, countNeri = 0;

    // Chiamata alla funzione per contare i nodi con lo stesso numero di discendenti bianchi e neri
    int totale = contaDiscendenti(radice, countBianchi, countNeri);

    // Stampa il conteggio
    std::cout << "Totale nodi con discendenti bianchi e neri uguali: " << totale << std::endl;

    return 0;
}
