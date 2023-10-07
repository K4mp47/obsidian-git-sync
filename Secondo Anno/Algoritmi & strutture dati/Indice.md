# Introduzione
> Il corso di algoritmi si basa sulla risoluzione, lo studio ed il confronto degli algoritmi

# Notazioni asintotiche
> Durante lo studio di un algoritmo dobbiamo andare anche ad analizzare la massima e minina velocitá di esecuzione, ed é qui che entrano in gioco le varie notazioni
> 

- $\Theta-notation$ 
Immaginiamo ora la seguente funzione da analizzare:
$$(\frac{c_2}{2}+\frac{c_6}{2}+\frac{c_7}{2})n^2+(c_1+c_2+c_4+\frac{c_5}{2}-\frac{c_6}{2}-\frac{c_7}{2}+c_8)n-(c_2+c_4+c_5+c_8)$$
Dobbiamo scartare tutti gli elementi di ordine minore $(c_1 + c_2 + c_4 + c_5/2 - c_6/2 - c_7/2 + c_8)n$
ed anche $c_2 + c_4 +c_5 +c_8$ ed ignoriamo il coefficiente davanti ad $n^2$.
Mettiamo in $\Theta-notation$ la funzione, quindi $\Theta(n^2)$. Noi usiamo questo stile per caratterizzare il tempo di esecuzione degli algoritmi: usiamo la notazione che si concentra nella velocitá del tempo di esecuzione.

Andiamo nello specifico:
$0-notation$: la "zero notation" ci serve per calcolare la velocitá massima di crescita che un algoritmo puó raggiungere, basato nel termine di ordine maggiore all'interno dell'algoritmo.
Per fare un esempio:
$$7n^3 + 100n^2 + 6$$
In questa funzione il termine di ordine maggiore é $n^3$, quindi diciamo che questa funzione ha un ordine di grandezza di $n^3$. Dato che questa funzione non cresce piú veloce di $n^3$, possiamo scrivere $0(n^3)$ .

$\Omega-notation$ La "Omega notation" ci serve invece per trovare la soglia di crescita piú bassa che l'algoritmo puó raggiungere, anch'essa si basa sul termine di ordine maggiore, quindi é corretto scrivere $\Omega(n^3)$, o piú in generale $\Omega(n^c) \mid c \leq 3$.

$\Theta-notation$ La "teta notation" dice invece che la funzione cresce *precisamente* in un certo raggio, basato sempre sul termine di ordine maggiore. Sostanzialmente, se in una funzione puoi trovare sia la zero notation che la omega, stai dimostrando che la funzione é $\Theta(f(n))$.

Vediamo ora come lavorare con la notazione asintotica analizzando l'algoritmo di *insertion sort*

### Insertion sort
Esempio reale:
- Mano sinistra vuota, mano destra con un mazzo di carte, prendo una carta alla volta e la metto al suo posto nella mano sinistra in modo che sia ordinata, una alla volta, partendo dalla prima del mazzo fino all'ultima:
- ![[Pasted image 20230929075755.png]]

```cpp
#include <iostream>

using namespace std;

// esempio di insertion_sort in cpp
void insertion_sort(int a[], int n) {
  // ovviamente devo modificare gli indici rispetto allo pseudocodice
  for (int i = 1; i < n; i++) { 
	int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key){ 
      a[j + 1] = a[j]; 
      j -= 1;
    }

    a[j + 1] = key;
  }
}

int main() {
  int a[7] = { 4, 3, 5, 2, 7, 6, 1 };

  for(int i=0; i < 7; i++) {
    cout << a[i] << " ";
  }
  
  cout << endl;
  insertion_sort(a, 7);
  
  for (int i = 0; i < 7; i++) {
    cout << a[i] << " ";
  }

  cout << endl;
  return 0;
}
```

Osservando l'algoritmo, notiamo come il ciclo *for* viene eseguito $n-1$ volte, indifferentemente dalla lunghezza dell'array da ordinare. Il loop *while* annidato invece, varia a seconda di come sono gli elementi nell'array. Il loop inizia da $i-1$ e si decrementa di 1 ogni iterazione,

