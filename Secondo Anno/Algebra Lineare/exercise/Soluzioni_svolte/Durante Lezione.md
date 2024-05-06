## Esercizio svolto a lezione il 22/04/24
---
$$\begin{cases}x-2y-z=0\\
kx-ky+w=0\\
y+kz_w=0\end{cases}$$

- Trovare il numero di soluzioni del sistema al variare di $k \in R$.

$$\begin{pmatrix}1&-2&-1&0\\k&-k&0&1\\0&1&k&1\end{pmatrix}$$
- Mi riporto alla situazione di creamer cerco una sottomatrice quadrata

$$\begin{pmatrix}-1&0\\0&1\end{pmatrix}\rightarrow \text{determinante = $-1$}$$
- Non va bene il determinante
$$\begin{pmatrix}1&-1&0\\k&0&1\\0&k&1\end{pmatrix}\rightarrow\text{determinante = $0$}$$
- Determinante a zero non va bene, deve dipendere da $k$, prendo allora

$$\begin{pmatrix}-2&-1&0\\-k&0&1\\1&k&1\end{pmatrix}\rightarrow\text{determinante = $k-1$}$$
- $k\neq1$ quindi $A_3$ è non singolare $rg(A)=3$. Nota come *matrice efficace*
- Ogni colonna eliminata corrisponde al fatto che la variabile perde il suo status e diventa un parametro libero
- Ogni riga eliminata corrisponde ad un'equazione eliminata perché ridondante

$$\begin{cases}-2y-z=-x\\-ky+w=-ky\\y+kz+w=0\end{cases}$$
- ⬆ $x$ diventa la colonna dei coefficienti nel sistema
- Tre equazioni e 3 incognite
- Applico Cramer

$$y=\frac{\begin{pmatrix}-x&-1&0\\-kx&0&1\\0&k&1\end{pmatrix}}{k-1}=\frac{0}{k-1}=0$$
$$\begin{cases}-z=-x\\w=-kx\\kz+w=0\end{cases}$$
- Quindi le soluzioni finali sono $(0,x,-kx)\quad x\in R\:\text{per }k\neq 1$ 
- Per $k=1$, il rango è 2. La matrice efficace è la matrice di partenza 2x2 $\begin{pmatrix}-1&0\\0&1\end{pmatrix}$ 
	- Il sistema diventa a due equazioni
	- $\begin{cases}-z=-x+2y\\w=-kx+ky\end{cases}\quad$ numero soluzioni = $\infty^2$ 
## Esercizio svolto a lezione il 22/04/24
--- 
$T:R^3\rightarrow R^2$
$T(V_1)= (-1,2)$
$T(V_2)= (0,4)$
$T(V_3)= (2,1)$

dove

$V_1=(1,1,1)\quad V_2=(0,1,1)\quad V_3=(1,1,0)$

- Trovare la matrice A associata a T rispetto alle basi canoniche
- Trovare una base di $Im(T)$ e $Ker(T)$ 

$$\begin{pmatrix}1&0&1\\1&1&1\\1&1&0\end{pmatrix}\rightarrow\text{calcolare se il determinante è $\neq 0$}$$
- Posso vedere ad occhio che se faccio $V_1-V_2$ trovo già $T(e_1)$ dove $e_1=aV_1+bV_2+cV_3$
- Anche $V_1-V_3=e_3$ 
- E anche $V_3-e_1=e_2$ 
- Quindi di conseguenza 
	- $T(e_1)=T(V_1)-T(V_2)= (-1,2)-(0,4)=(-1,-2)$
	- $T(e_3)=T(V_1)-T(V_3)= (-1,2)-(2,1)=(-3,1)$
	- $T(e_2)=T(V_3)-T(e_1)= (2,1)-(-1,-2)=(3,3)$

- La matrice estrapolata risulta essere
$$A=\begin{pmatrix}-1&3&-3\\-2&3&1\end{pmatrix}$$
$$A_2=\begin{pmatrix}-1&3\\-2&3\end{pmatrix}=|A_2|=3\neq0\text{ non singolare quindi rg(A) = 2 = dim Im(T)}$$
- $dim\:Ker(T)+2=3\text{ quindi dim Ker(T)=1}$  
$$B_{Im(T)}={(-1,2);(3,3)}$$
$$\begin{cases}-x+3y-3z=0\\-2x+3y+z=0\end{cases}\rightarrow\begin{cases}-x+3y=3z\\-2x+3y=-z\end{cases}\rightarrow r_1-r_2\rightarrow\begin{cases}x=4z\\y=\frac{7}{3}z\end{cases}$$
- $z=3\quad B_{ker(T)}={(12,7,3)}$ 
## Esami e Tutorati
---
### Dato il numero complesso $z = \frac{1}{2}(\sqrt3+i)$ si dica se le affermazioni sono vere
1. $\bar z = e^{-i\frac{\pi}{6}}$ 
	1. Dal nostro z ricaviamo il modulo e l'argomento che corrispondono ad $1$ e $\frac{\pi}{6}$ 
	2. trasformiamo in forma euclidea(se si chiama così, non lo so e non mi interessa)
	3. Il coniugato corrisponde al numero complesso con la parte immaginaria di senso opposto, quindi il caso è vero
2. $z  = cos(\frac{\pi}{3})+i sin(\frac{\pi}{3})$
	1. Impossibile siano uguali dato che $Arg(z)= \frac{\pi}{6} \ne \frac{\pi}{3}$   
3. $z^2 = \frac{1}{2}(1-i\sqrt3)$
	1. In questo caso bisogna trasformare il numero nella forma polare, quindi diventa $e^{i\frac{\pi}{3}}$
	2. Trasformo in $(cos(\frac{\pi}{3}) + i sin(\frac{\pi}{3}))$
	3. Risolvo e noto che sono diversi, quindi l'affermazione è falsa
4. $z^3 = i$
	1. Stessa cosa del punto precedente, dove in questo caso arriviamo ad $1(0+i*1)=i$ e quindi l'affermazione è vera

### Si considerino in $R^4$ il sottospazio $V$ generato dai primi tre vettori della base canonica e il sottospazio $W$ dei vettori $\begin{array}{} x_1\\ x_2\\ x_3\\ x_4\\  \end{array}$  $\in R^4$  che soddisfano le relazioni $\begin{cases} 2x_1+x_3 = 0\\ x_2 +x_4 =0 \\2x_1+x_2+x_3+x_4=0\\ \end{cases}$  Si dica, giustificando la risposta, se esiste un endomorfismo $T$ di $R^4$ tale che $ker\:T=V$ e $Im\:T=W$
- Osserviamo che la dimensione sia 3 date le 3 equazioni che compongono il sottospazio
- Notiamo inoltre che $\begin{cases} 2x_1+x_3 = 0\\ x_2 +x_4 =0 \\2x_1+x_2+x_3+x_4=0\\ \end{cases}$  diventa senza problemi $\begin{cases} x_3 = -2x_2\\ x_4 = -x_2 \end{cases}$
- $x_1,\:x_2$ possono essere viste come le nostre variabili libere, di conseguenza gli alterniamo i valori [1,0]  per poter avere una base di partenza. inoltre in questo modo trovo lo Span di $W$. Per il teorema della dimensione comunque, l'esercizio non ha soluzione, non esiste un endomorfismo $T : R^4 \rightarrow R^4$ tale che le due condizioni di Ker e Im siano vere, infatti $dim\:ker\:T+dim\:Im\:T=3+2=5\ne dim\:R^4 = 4$  
### Data la matrice $$ \begin{pmatrix}
1 & 1  & 1 & 0\\
k & -1 & 0 & k\\
3 & 1  & 2 & 0\\
1 & 1  & k & 1-k
\end{pmatrix}
$$con $k \in R$, determinare: 1) Il rango di $A_k$ al variare di $k$ 2) Il nucleo e l'immagine di $L_{A_k}$ al variare di $k$, indicando per tali sottospazi la dimensione ed una base 3) I valori di $k$ per cui l'applicazione lineare $L_{A_k}$associata ad $A_k$ è iniettiva, suriettiva, bigettiva 4) Posto $k=1$ sia $E=ker\:L_{A_1}$. Si determini una base del complemento ortogonale $E^{\perp}$ di $E$. (DA FARE QUESTO)

---
### Simulazione svolta esame 2020/2021 domanda teoria
1. Siano $v_1,v_2,v_3 \in R^2$. Quale delle seguenti affermazioni è vera? Si giustifichi la risposta
	1. $v_1,v_2,v_3$ sono linearmente dipendenti se e solo se due di essi sono proporzionali.
		- Falso. Affinché questa doppia implicazione sia vera, entrambe le implicazioni (diretta e inversa) devono essere vere. Verifichiamole.
			- Supponiamo che i due vettori proporzionali siano $v_1,v_2$ e siano legati dalla costante di proporzionalità $\lambda$ per cui $v_2 = \lambda v_1$. I tre vettori sono linearmente dipendenti se esistono $\alpha_1,\alpha_2,\alpha_3 \in R$ non tutti nulli tali che  $$\alpha_1v_1+\alpha_2v_2+\alpha_3=0$$
			- In virtù della proporzionalità tra $v_1$ e $v_2$ è sufficiente utilizzare $\alpha_1 = -\lambda,\alpha_2=1,\alpha_3=0$ per soddisfare l'uguaglianza sopra $$-\lambda v_1+v_2 = 0$$ Non vi è nessuna coppia di vettori proporzionali, basta confutare questa implicazione con un controesempio come $v_1=(-1,3),v_2=(1,2),v_3=(0,5)$ per ottenere $$v_1+v_2-v_3=0$$ confutando così l'implicazione
	2. $v_1,v_2,v_3$ sono linearmente indipendenti.
		- Falso. Dato che la dim di $R^2=2$ la cardinalità del sottoinsieme massimale di $R^2$ di vettori linearmente indipendenti è 2, di conseguenza tra i tre vettori ce ne sarà uno sicuramente linearmente dipendente dagli altri due. 
	3. $v_1,v_2,v_3$ sono linearmente dipendenti. 
		- _Vero_
			- Dato dim $R^2=2$ questo implica che tra di loro non sono tutti linearmente indipendenti. Di conseguenza vuol dire che sono linearmente dipendenti!!

---

## Foglio 10
## Calcolare il determinante della matrice $$ \begin{pmatrix}-1 & 0  & 1 & 2\\2 & 1 & 3 & -1\\0 & 1  & 2 & -1\\3 & 0  & 1 & -2\end{pmatrix}$$
- Uso il metodo di Laplace:
	- Si sceglie una riga o una colonna da usare (scelgo la seconda colonna perché ha più zeri)
		- $\sum a_{ij}(-1)^{i+j}Det(matrice\:restante)$     
	- Se il determinante è $\neq$ 0, allora posso fare il determinante della matrice inversa
		- Matrice inversa = righe diventano colonne e viceversa
- Uso il metodo di eliminazione di Gauss
	- Si prende la matrice triangolare superiore (risolvo mettendo a zero tutta la matrice triangolare inferiore)
	- determinante = prodotto degli elementi sulla diagonale
	- **Se scambiamo righe cambia anche il segno!**
## Calcolare $A^{-1}$ e verificare che $AA^{-1}=I$ $$\begin{pmatrix}2&1&1\\4&1&0\\-2&2&1\end{pmatrix}$$

$$1(-1)^{1+3} \begin{pmatrix}4&1\\-2&2\end{pmatrix}+1(-1)^{3+3}\begin{pmatrix}2&1\\4&1\end{pmatrix} = 1(8-(-2))+1(2-4)=10-2=8\neq0 $$

- quindi esiste $A^{-1},\: det(A^{-1})=\frac{1}{det(A)}=\frac{1}{8}$ 
- Calcolo inversa
$$\begin{pmatrix}
2&1&1|1&0&0\\
4&1&0| 0&1&0\\
-2&2&1| 0&0&1
\end{pmatrix}$$
- Uso Gauss fino a quando la matrice di sinistra non diventa la matrice identità

- Prima operazione mettere 4 e -2 a zero: $r_2 = r_2 -2r_1\:e\: r_3=r_3+r_1$
$$\begin{pmatrix}
2&1&1|1&0&0\\
0&-1&-2| -2&1&0\\
0&3&2| 1&0&1
\end{pmatrix}$$
- Alla matrice di destra la trattiamo come fosse una matrice intera, quindi $0-1(-2) = -2$ ecc.
- Ora $r_3=r_3+3r_2$ 

$$\begin{pmatrix}
2&1&1|1&0&0\\
0&-1&-2| -2&1&0\\
0&0&-4| -5&3&1
\end{pmatrix}$$
- Rimane da calcolare 1,1 della prima riga e -2 della seconda che devono essere a 0, $r_1 = r_1+r_2$
$$\begin{pmatrix}
2&0&-1|-1&1&0\\
0&-1&-2| -2&1&0\\
0&0&-4| -5&3&1
\end{pmatrix}$$
- $r_1=r_1-\frac{1}{4}r_3$ 
$$\begin{pmatrix}
2&0&0|\frac{1}{4}&\frac{1}{4}&-\frac{1}{4}\\
0&-1&-2| -2&1&0\\
0&0&-4| -5&3&1
\end{pmatrix}$$
- $r_2=r_2-\frac{1}{2}r_3$ 
$$\begin{pmatrix}
2&0&0|\frac{1}{4}&\frac{1}{4}&-\frac{1}{4}\\
0&-1&0| \frac{1}{2}&-\frac{1}{2}&-\frac{1}{2}\\
0&0&-4| -5&3&1
\end{pmatrix}$$
- Moltiplichiamo le righe per $\frac{1}{2},-1,-\frac{1}{4}$
$$\begin{pmatrix}
1&0&0|\frac{1}{8}&\frac{1}{8}&-\frac{1}{8}\\
0&1&0| -\frac{1}{2}&\frac{1}{2}&\frac{1}{2}\\
0&0&1| \frac{5}{4}&-\frac{3}{4}&-\frac{1}{4}
\end{pmatrix}$$
- a sinistra abbiamo la matrice identità, a destra la matrice inversa
$$A^{-1}=\begin{pmatrix}
\frac{1}{8}&\frac{1}{8}&-\frac{1}{8}\\
-\frac{1}{2}&\frac{1}{2}&\frac{1}{2}\\
\frac{5}{4}&-\frac{3}{4}&-\frac{1}{4}
\end{pmatrix} = \frac{1}{8}\begin{pmatrix}
1&1&-1\\
-4&4&4\\
10&-6&-2
\end{pmatrix}$$$$\text{la matrice è stata moltiplicata solo per una rappresentazione diversa}$$
## Risolvere usando Cramer
$$\begin{cases}
x+7y+3z=6\\
-x+2z=-7\\
3x+y+z=2
\end{cases}$$

- Verifichiamo se possiamo usare Cramer

$$\begin{pmatrix}
1&7&3\\
-1&0&2\\
3&1&1
\end{pmatrix}$$
- Verificare che il determinante sia $\neq$ 0

#### Passaggi
- Specchiamo le prime due colonne

$$\begin{pmatrix}
1&7&3&1&7&3\\
-1&0&2&-1&0&2\\
3&1&1&3&1&1
\end{pmatrix}$$

- prendo le prime tre diagonali verso destra con segno positivo e le diagonali da destra a sinistra con segno negativo. TUTTO QUESTO VALE SOLO PER MATRICI 3X3
$$det(A)=1*0*1+7*2*3+3*(-1)*1-1*2*1-7*(-1)*1-3*0*3=$$
$$42-3-2+7=44\neq0\quad\text{quindi si può usare Cramer}$$
- Ci serve matrice  e termini noti
$$x =\begin{pmatrix}
1&7&3\\
-1&0&2\\
3&1&1
\end{pmatrix}\text{sostituisco colonna 1 con termini noti}=\begin{pmatrix}
6&7&3\\
-7&0&2\\
2&1&1
\end{pmatrix}$$
$$\text{faccio il determinante della matrice sopra fratto determinante di A:}=\frac{44}{44}=1$$
- Faccio la stessa cosa per $y$ e $z$
$$y=\begin{pmatrix}
1&6&3\\
-1&-7&2\\
3&2&1
\end{pmatrix}=\frac{88}{44}=2$$

$$z = \begin{pmatrix}
1&7&6\\
-1&0&-7\\
3&1&2
\end{pmatrix}=\frac{-132}{44}=-3$$

## Si considerino le equazioni $3x-y+z=0,x-2y-3z=0$
- Si aggiunga una terza equazione in modo da ottenere un sistema con la sola soluzione nulla
$$\begin{pmatrix}3&-1&1\\1&-2&-3\\?&?&?\end{pmatrix}$$
- Introduciamo $z=0$
$$\begin{cases}
3x-y+z=0\\x-2y-3z=0\\z=0\end{cases}$$
$$\begin{pmatrix}3&-1&1\\1&-2&-3\\0&0&1\end{pmatrix}$$
- Con $z=0$ il sistema diventa omogeneo e quindi la soluzione di cui sopra è valida
-  Con una sola soluzione? $z=1$

$$\begin{cases}
3x-y+z=0\\x-2y-3z=0\\z=1\end{cases}\rightarrow\begin{cases}
3x-y=-1\\x-2y=3\\z=1\end{cases}$$

$$\begin{cases}y=1+3x\rightarrow y=-2\\x-2(1+3x)=3\rightarrow x=-1\\z=1\end{cases}$$