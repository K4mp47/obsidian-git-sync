## Esercizio 1
- Calcolare il determinante delle matrice
$$A=\begin{pmatrix}-1&0&1&2\\2&1&3&-1\\0&1&2&-1\\3&0&1&-2\end{pmatrix}$$
utilizzando lo sviluppo di Laplace e l'eliminazione di Gauss, verificando che i risultati siano gli stessi. Calcolare infine, se possibile il determinante di $A^{-1}$

Risolviamo prima con Gauss:
$$\begin{pmatrix}-1&0&1&2\\2&1&3&-1\\0&1&2&-1\\3&0&1&-2\end{pmatrix}=\begin{pmatrix}-1&0&1&2\\0&1&5&3\\0&1&2&-1\\3&0&1&-2\end{pmatrix}=\begin{pmatrix}-1&0&1&2\\0&0&3&4\\0&1&2&-1\\3&0&1&-2\end{pmatrix}=\begin{pmatrix}-1&0&1&2\\0&0&3&4\\0&1&2&-1\\0&0&4&4\end{pmatrix}$$
$$=\begin{pmatrix}-1&0&1&2\\0&0&0&1\\0&1&2&-1\\0&0&4&4\end{pmatrix}=\begin{pmatrix}-1&0&1&2\\0&1&2&-1\\0&0&4&4\\0&0&0&1\end{pmatrix}$$ 
Quindi secondo Gauss abbiamo che il determinante è uguale ad $-4$.
Ora proviamo a risolvere usando Laplace:

Iniziamo scegliendo la riga o colonna con più zeri al suo interno, in questo caso la seconda colonna ricade sulla nostra scelta.

Ora riscriviamo le matrici, usando le righe e colonne che non hanno gli zeri:

$$A=\begin{pmatrix}-1&0&1&2\\2&1&3&-1\\0&1&2&-1\\3&0&1&-2\end{pmatrix}$$

$$cof(a_{22})=+\begin{pmatrix}-1&1&2\\0&2&-1\\3&1&-2\end{pmatrix} \qquad cof(a_{32})=-\begin{pmatrix}-1&1&2\\2&3&-1\\3&1&-2\end{pmatrix}$$

Rifacciamo anche per le due nuove matrici trovate:

$$cof(a_{22})=+\begin{pmatrix}-1&1&2\\0&2&-1\\3&1&-2\end{pmatrix}=-1(+\begin{pmatrix}2&-1\\1&-2\end{pmatrix})+3(\begin{pmatrix}1&2\\2&-1\end{pmatrix})$$
$$=-1(-4-(-1))+3(-1-4)=3-15=-12$$
$$cof(a_{32})=-\begin{pmatrix}-1&1&2\\2&3&-1\\3&1&-2\end{pmatrix}=-[-(\begin{pmatrix}3&-1\\1&-2\end{pmatrix})-2(\begin{pmatrix}1&2\\1&-2\end{pmatrix})+3(\begin{pmatrix}1&2\\3&-1\end{pmatrix})]$$
$$=-[-(-6-(-1))-2(-2-2)+3(-1-6)]=-[5+8-21]=+8$$

E in tutto questo:
$$-12+8=-4$$ quindi i due sono corretti.
Per calcolare il determinante di $A^{-1}$ ci basta fare $\frac{1}{det(A)}=-\frac{1}{4}$ 

---
## Esercizio 2
- Data 
$$\begin{pmatrix}2&1&1\\4&1&0\\-2&2&1\end{pmatrix}$$
trovare se esiste, $A^{-1}$ e verificare che $AA^{-1}=I$.
Troviamo il determinante usando Laplace

$$\begin{pmatrix}2&1&1\\4&1&0\\-2&2&1\end{pmatrix}=1\begin{pmatrix}4&1\\-2&2\end{pmatrix}+1\begin{pmatrix}2&1\\4&1\end{pmatrix}=(8+2)+(2-4)=10-2=8$$

Ora sappiano che non è singolare avendo il determinante diverso da zero, quindi esiste $A^{-1}$.

$$\begin{pmatrix}2&1&1&|&1&0&0\\4&1&0&|&0&1&0\\-2&2&1&|&0&0&1\end{pmatrix}$$
$$=\begin{pmatrix}2&1&1&|&1&0&0\\0&-1&-2&|&-2&1&0\\-2&2&1&|&0&0&1\end{pmatrix}$$

$$=\begin{pmatrix}2&1&1&|&1&0&0\\0&-1&-2&|&-2&1&0\\0&3&2&|&1&0&1\end{pmatrix}$$
$$=\begin{pmatrix}2&1&1&|&1&0&0\\0&-1&-2&|&-2&1&0\\0&0&-4&|&-5&3&1\end{pmatrix}$$

$$=\begin{pmatrix}2&0&-1&|&-1&1&0\\0&-1&-2&|&-2&1&0\\0&0&-4&|&-5&3&1\end{pmatrix}$$

$$-\frac{1}{4}=\begin{pmatrix}2&0&0&|&-1+\frac{5}{4}&1-\frac{3}{4}&-\frac{1}{4}\\0&-1&-2&|&-2&1&0\\0&0&-4&|&-5&3&1\end{pmatrix}$$
$$-\frac{1}{2}=\begin{pmatrix}2&0&0&|&-1+\frac{5}{4}&1-\frac{3}{4}&-\frac{1}{4}\\0&-1&0&|&-2+\frac{5}{2}&1-\frac{3}{2}&-\frac{1}{2}\\0&0&-4&|&-5&3&1\end{pmatrix}$$

Ora bisogna moltiplicare tutti i valori della riga 1,2 e 3 per i valori della diagonale di sinistra girati, ovvero $\frac{1}{2},-1,{-\frac{1}{4}}$.

$$\begin{pmatrix}\frac{1}{8}&\frac{1}{8}&-\frac{1}{8}\\
-\frac{1}{2}&\frac{1}{2}&\frac{1}{2}\\
\frac{5}{4}&-\frac{3}{4}&-\frac{1}{4}\end{pmatrix}=\frac{1}{8}\begin{pmatrix}1&1&-1\\-4&4&2\\10&-6&-2\end{pmatrix}$$

---
## Esercizio 4
- Risolvere il sistema usando il metodo di Cramer
$$\begin{cases}x+7y+3z=6\\-x+2z=-7\\3x+y+z=2\end{cases}$$

Iniziamo trasformando in matrice, senza tenere conto dei coefficienti.
$$\begin{pmatrix}1&7&3\\-1&0&2\\3&1&1\end{pmatrix}$$
calcolo del determinante:
$$\begin{pmatrix}1&7&3\\-1&0&2\\3&1&1\end{pmatrix}=-7\begin{pmatrix}-1&2\\3&1\end{pmatrix}-\begin{pmatrix}1&3\\-1&2\end{pmatrix}=-7(-1-6)-(2+3)=49-5=44$$

>📝Ricordo che per poter usare Cramer il sistema deve essere quadrato e non singolare altrimenti non posso usare il metodo!!

Trovato il determinante, sostituiamo per ogni colonna di incognite quella dei coefficienti, troviamo il determinante di quest'ultima e lo dividiamo per il determinante appena trovato, 44.
$$\begin{pmatrix}6&7&3\\-7&0&2\\2&1&1\end{pmatrix}=-7\begin{pmatrix}-7&2\\2&1\end{pmatrix}-\begin{pmatrix}6&3\\-7&2\end{pmatrix}=-7(-7-4)-(12+21)=77-33=44$$
E quindi risulta che
$$x=\frac{44}{44}=1$$
Poi cerchiamo la $y$:
$$\begin{pmatrix}1&6&3\\-1&-7&2\\3&2&1\end{pmatrix}=-6\begin{pmatrix}-1&2\\3&1\end{pmatrix}-7\begin{pmatrix}1&3\\3&1\end{pmatrix}-2\begin{pmatrix}1&3\\-1&2\end{pmatrix}$$$$=-6(-1-6)-2(2+3)-7(1-9)=42+56-10=88$$
Quindi risulta che
$$y=\frac{88}{44}=2$$

Ed infine abbiamo $z$:

$$\begin{pmatrix}1&7&6\\-1&0&-7\\3&1&2\end{pmatrix}=-7\begin{pmatrix}-1&-7\\3&2\end{pmatrix}-\begin{pmatrix}1&6\\-1&-7\end{pmatrix}=-7(19)-1=-133+1=-132$$
$$z=-\frac{132}{44}=-3$$
quindi la soluzione al sistema sono le incognite con valore $(1,2,-3)$.

--- 
## Esercizio 6
- Si considerino le due equazioni $3x-y+z=0$ e $x-2y-3z=0$.
	- Aggiungere una terza equazione in modo da ottenere un sistema con la sola soluzione nulla
	- Aggiungere una terza equazione in modo da ottenere un sistema con una unica soluzione non nulla. Trovare poi la soluzione
	- Aggiungere una terza equazione in modo da ottenere un sistema con infinite soluzioni. È possibile ottenere $\infty^2$ soluzioni? Motivare la risposta. 

Mettiamo il tutto intanto il sistema:

$$\begin{cases}3x-y+z=0\\x-2y-3z=0\\?+?+?=0\end{cases}$$
$$\begin{pmatrix}3&-1&1&0\\1&-2&-3&0\\?&?&?&0\end{pmatrix}=(-\frac{1}{3})=\begin{pmatrix}3&-1&1&0\\0&-\frac{7}{3}&-\frac{10}{3}&0\\?&?&?&0\end{pmatrix}$$

$$\begin{cases}3x-y+z=0\\-\frac{7}{3}y-\frac{10}{3}z=0\\z=0\end{cases}=\begin{cases}3x-y+z=0\\-\frac{7}{3}y-\frac{10}{3}z=0\\z=0\end{cases}$$

$x=y=z=0$ risulta essere una soluzione alla domanda per trovare una soluzione nulla.

Per risolvere il punto due risolviamo l'intera matrice, ma senza contare i coefficienti:
$$\begin{pmatrix}1&-2&-3\\0&5&8\\?&?&?\end{pmatrix}=\begin{pmatrix}1&-2&-3\\0&5&8\\0&0&1\end{pmatrix}$$
questo ci sta a significare che con qualunque valore noi scegliamo di attribuire a $z$ il sistema ha un'unica soluzione.

Per risolvere nel caso volessimo soluzioni infinite, ci basterà aggiungere una equazione tale per cui il rango della matrice sia non massimo, per cui z diventa una variabile libera e con quindi infinite soluzioni. 

Trovare invece una soluzione di $\infty^2$ non è possibile dato che possiamo agire solo su una delle tre equazioni e quindi non ci è data la possibilità di rendere variabili libere più di una sola incognita tra quelle presenti nel sistema

>📝Prestare attenzione al rango. Il determinante se $\neq 0$ dimostra che il sistema ha una sola soluzione. Inoltre se il rango non è massimo ricordiamo che questo implica la presenza di una variabile libera o più.