## Esercizio 1
- Date le matrici
$$A=\begin{pmatrix}1&-1&0\\1&1&2\end{pmatrix}, \qquad B=\begin{pmatrix}0&2&1\\1&1&2\end{pmatrix}$$

Capire quali tra i due prodotti $AB$ oppure $A^TB$ e possibile eseguire, e poi calcolarlo.

Notiamo che solo $A^TB$ è possibile avendo il numero di colonne $A$ uguale al numero di righe $B$
$$\begin{pmatrix}1&1\\-1&1\\0&2\end{pmatrix}*\begin{pmatrix}0&2&1\\1&1&2\end{pmatrix}=\begin{pmatrix}1&3&3\\1&-1&1\\2&2&4\end{pmatrix}$$

--- 
## Esercizio 2
![[Pasted image 20240509104804.png]]
$$AC:\begin{pmatrix}-1&0\\1&0\end{pmatrix}\quad B+CA:\begin{pmatrix}-2&1&-1\\2&1&1\\1&1&0\end{pmatrix}+\begin{pmatrix}-1&1&0\\0&0&0\\1&-1&0\end{pmatrix}=\begin{pmatrix}-3&2&0\\2&1&1\\2&0&0\end{pmatrix}$$

---
## Esercizio 3
![[Pasted image 20240509112811.png]]
$$\begin{cases}1+a=b+c\\c-2b=-4a-b\\3c-a=-a-b\end{cases}=\begin{cases}a=b+c-1\\c=-4a+b\\b=-3c\end{cases}=\begin{cases}a=b+c-1\\c=-4a+b\\b=3a\end{cases}=\begin{cases}a=3a+c-1\\c=-a\\b=3a\end{cases}=\begin{cases}a=1\\c=-1\\b=3\end{cases}$$

$$A=\begin{pmatrix}2&0\\-7&-4\end{pmatrix}, \quad B=\begin{pmatrix}-2&0\\7&4\end{pmatrix}$$

--- 
## Esercizio 4
- Determinare il rango delle seguenti matrici
$$A=\begin{pmatrix}1&0&2&0\\0&1&0&1\\1&1&2&1\end{pmatrix} \quad C=\begin{pmatrix}2&1&3&4&6\\-2&3&-1&5&3\\6&-1&7&4&10\\-8&8&-6&13&5\end{pmatrix}$$

Calcoliamo il rango di $A$:
$$A=\begin{pmatrix}1&0&2&0\\0&1&0&1\\1&1&2&1\end{pmatrix}=\begin{pmatrix}1&1&2&1\\0&1&0&1\\1&0&2&0\end{pmatrix}=\begin{pmatrix}1&1&2&1\\0&1&0&1\\0&-1&0&-1\end{pmatrix}=\begin{pmatrix}1&1&2&1\\0&1&0&1\\0&0&0&0\end{pmatrix}$$

Notiamo che abbiamo due pivot non nulli, quindi due vettori linearmente indipendenti e rango della matrice = 2.

Calcoliamo il rango di $C$:
$$C=\begin{pmatrix}2&1&3&4&6\\-2&3&-1&5&3\\6&-1&7&4&10\\-8&8&-6&13&5\end{pmatrix}=\begin{pmatrix}2&1&3&4&6\\0&4&2&9&9\\6&-1&7&4&10\\-8&8&-6&13&5\end{pmatrix}=\begin{pmatrix}2&1&3&4&6\\0&4&2&9&9\\0&-4&1&-8&-8\\-8&8&-6&13&5\end{pmatrix}$$
$$\begin{pmatrix}2&1&3&4&6\\0&4&2&9&9\\0&0&3&1&1\\-8&8&-6&13&5\end{pmatrix}=\begin{pmatrix}2&1&3&4&6\\0&4&2&9&9\\0&0&3&1&1\\0&12&6&29&29\end{pmatrix}=\begin{pmatrix}2&1&3&4&6\\0&4&2&9&9\\0&0&3&1&1\\0&0&0&2&2\end{pmatrix}$$

Il rango di $C$ risulta essere 4 con 4 vettori linearmente indipendenti tra loro dati i 4 pivot non nulli.

---

## Esercizio 5
Calcolare il rango delle seguenti matrici al variare del parametro $k \in R$
$$A=\begin{pmatrix}-2&-2&-1\\k&-1&1\\4&k&2\end{pmatrix}$$

Calcoliamo il rango di $A$:
$$A=\begin{pmatrix}-2&-2&-1\\k&-1&1\\4&k&2\end{pmatrix}=\begin{pmatrix}-2&-2&-1\\k&-1&1\\0&k-4&0\end{pmatrix}=\frac{1}{2}k=\begin{pmatrix}-2&-2&-1\\0&-1-k&1-\frac{1}{2}k\\0&k-4&0\end{pmatrix}=$$$$\begin{pmatrix}-2&-2&-1\\0&-1-k&1-\frac{1}{2}k\\0&-5&1-\frac{1}{2}k\end{pmatrix}=(-5)=\begin{pmatrix}-2&-2&-1\\0&-1-k&1-\frac{1}{2}k\\0&5k&-4+2k\end{pmatrix}$$$$=\begin{pmatrix}-2&-2&-1\\0&-1&\frac{1}{5}-\frac{1}{10}k\\0&5k&-4+2k\end{pmatrix}=\begin{pmatrix}-2&-2&-1\\0&-1&\frac{1}{5}-\frac{1}{10}k\\0&0&-4+3k-\frac{1}{2}k^2\end{pmatrix}$$
quando $-4+3k-\frac{1}{2}k^2=0$?

$$-4+3k-\frac{1}{2}k^2=0$$
$$\frac{1}{2}k^2-3k+4=0$$
$$\frac{-b+-\sqrt{b^2-4ac}}{2a}=\frac{3+-\sqrt{1}}{1}=4=2$$
quindi per $k=4=2$ la funzione ritorna rango 2, altrimenti il rango è 3

---
## Esercizio 8
- Stabilire per quali valori di $h \in R$ la seguente matrice ha rango $1$.
$$A=\begin{pmatrix}1&-1&h\\h&2h&0\end{pmatrix}$$
Se $h=0$ allora il rango è 1. Per $h\neq0$ invece:
$$A=\begin{pmatrix}1&-1&h\\h&2h&0\end{pmatrix}=(-h)=\begin{pmatrix}1&-1&h\\ 0&3h&(-h)(h)\end{pmatrix}$$
Vediamo che per qualunque valore di $h\neq0$ la matrice avrà sempre 2 pivot al suo interno.

--- 

## Esercizio 9
- Scrivere la matrice associata alla trasformazione lineare $T$ rispetto alle basi canoniche di $R^3$ e $R^2$ per
$$T\begin{pmatrix}x\\y\\z\end{pmatrix}=\begin{pmatrix}x+y-2z\\-x-y+2z\end{pmatrix}$$
La matrice associata è semplicemente la matrice dell'applicazione, fatta dei coefficienti, ovvero:
$$\begin{pmatrix}1&+1&-2\\-1&-1&+2\end{pmatrix}$$
--- 
## Esercizio 10
- Sono date le matrici
$$A=\begin{pmatrix}-1&2\\2&-4\end{pmatrix}, \quad B=\begin{pmatrix}1&2&1&-1\\1&2&1&-1\\1&2&1&-1\end{pmatrix}$$

Per ciascuna scrivere esplicitamente l'applicazione lineare $T_A:R^2\rightarrow R^2,\:T_B:R^3\rightarrow R^4$ rappresentata dalla matrice rispetto alle basi canoniche, e trova per ognuna una base del $KerT_x$ e $ImT_x$

Le matrici delle applicazioni lineari corrispondono ad:
$$A=\begin{pmatrix}-x&2y\\2x&-4y\end{pmatrix}, \quad B=\begin{pmatrix}x&2y&z&-w\\x&2y&z&-w\\x&2y&z&-w\end{pmatrix}$$

>📝Troverò solo per B Ker e Im

$KerT_B$ corrisponde a tutti quei vettori per cui la trasformazione ritorna $0$:

$$\begin{cases}x+2y+z-w=0\end{cases}$$

Tre variabili libere, per cui:
$$\begin{pmatrix}2y+z-w\\y\\z\\w\end{pmatrix}=y\begin{pmatrix}2\\1\\0\\0\end{pmatrix}+z\begin{pmatrix}1\\0\\1\\0\end{pmatrix}+w\begin{pmatrix}-1\\0\\0\\1\end{pmatrix}$$

Per quanto riguarda l'immagine invece:

$$B=\begin{pmatrix}x&2y&z&-w\\x&2y&z&-w\\x&2y&z&-w\end{pmatrix}=\begin{pmatrix}1&2&1&-1\\1&2&1&-1\\1&2&1&-1\end{pmatrix}=\begin{pmatrix}1\\1\\1\end{pmatrix}$$

---
## Esercizio 11
- Sia $T:R^3\rightarrow R^2$ definita da:
$$T(0,-2,1)=(3,-1)$$
$$T(1,1,-2)=(1,2)$$
$$T(2,0,-1)=(11,1)$$
Determinare la matrice che rappresenta $T$.

Per farlo dobbiamo prima trovare la matrice di ogni singola applicazione lineare:
$$T(0,-2,1)=\begin{pmatrix}-2y_1+z_1\\-2y_2+z_2\end{pmatrix}=(3,-1)$$
$$T(1,1,-2)=\begin{pmatrix}x_1+y_1-2z_1\\x_2+y_2-2z_2\end{pmatrix}=(1,2)$$
$$T(2,0,-1)=\begin{pmatrix}2x_1-z_1\\2x_2-z_2\end{pmatrix}=(11,1)$$
Con queste tre matrici ora troviamo i valori che hanno tutte in comune:
$$\begin{cases}-2y_1+z_1=3\\x_1+y_1-2z_1=1\\2x_1-z_1=11\end{cases}=\begin{cases}z_1=3+2y_1\\x_1=1-y_1+2z_1\\2-2y_1+9+6y_1=11\rightarrow y=0\end{cases}=\begin{cases}z_1=3\\x_1=7\\y_1=0\end{cases}$$
$$\begin{cases}-2y_2+z_2=-1\\x_2+y_2-2z_2=2\\2x_2-z_2=1\end{cases}=\begin{cases}z_2=-1+2y_2\\x_2=-y_2+2z_2+2\\-2y_2-4+8y_2+4+1-2y_2=1\rightarrow y_2=0\end{cases}=\begin{cases}z_2=-1\\x_2=0\\y_2=0\end{cases}$$

$$T(x,y,z)=(7x+3z,-z)$$
che espressa sotto forma di matrice corrisponde ad:
$$\begin{pmatrix}7&0&3\\0&0&-1\end{pmatrix}$$
