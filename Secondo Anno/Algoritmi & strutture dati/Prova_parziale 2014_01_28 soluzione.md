![[Pasted image 20231220100651.png]]
```cpp
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

  if (countNeri == countBianchi) return countLeft + countRight + 1;
  return countLeft + countRight;
}

int main() {
    // Esempio di creazione di un albero binario
    Node* radice = new Node("bianco");
    radice->left = new Node("nero");
    radice->right = new Node("bianco");
    radice->right->right = new Node("nero");

    // Variabili per memorizzare il conteggio
    int countBianchi = 0, countNeri = 0;

    // Chiamata alla funzione per contare i nodi con lo stesso numero di discendenti bianchi e neri
    int totale = contaDiscendenti(radice, countBianchi, countNeri);

    // Stampa il conteggio, in questo caso, 3
    std::cout << "Totale nodi con discendenti bianchi e neri uguali: " << totale << std::endl;

    return 0;
}
```

La complessità di tale algoritmo risulta essere $O(n)$ dato il fatto che nel caso peggiore (in realtà sempre) scorre l'intero albero, con un'unica interazione per nodo

