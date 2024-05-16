## Esercizio 1 
- Data la seguente trasformazione lineare $T:R^4\rightarrow R^3$ definita dalla matrice
$$A=\begin{pmatrix}k&0&1&1\\k-1&-1&0&1\\2k&0&2&1\end{pmatrix}$$
stabilire per quali valori $k \in R$ l'applicazione è iniettiva, suriettiva, invertibile, tale che la dimensione di $KerT$ sia uno

Non può essere iniettiva: passando ad uno spazio più piccolo, sicuramente ci saranno delle trasformazioni con lo stesso vettore risultante.

Per essere suriettiva, il determinante deve essere $\neq 0$, di conseguenza con rango 3: 

$rg(A)=p =$ Una sottomatrice quadrata di A non singolare di ordine $p$. Tutte le sottomatrici orlate devono avere determinante nullo.

$rg(A) \leq min(n,m)=3$ 

per cui prendiamo una sottomatrice della matrice data, per semplicità scegliamo quella che non contiene $k$, di ordine $p=1$
$$\begin{pmatrix}1&1\\0&1\end{pmatrix}$$
il determinante risulta essere diverso da zero, per cui non è di rango 2. Procediamo facendo crescere ulteriormente la nostra sottomatrice:
$$\begin{pmatrix}0&1&1\\-1&0&1\\0&2&1\end{pmatrix}$$
Utilizzando l'eliminazione di Gauss otteniamo
$$\begin{pmatrix}-1&0&1\\0&1&1\\0&0&-1\end{pmatrix}$$
abbiamo scambiato una riga per cui il segno del determinante cambia in negativo:
$-((-1)1(-1))=-1$ che comunque risulta diverso da zero, per cui la nostra matrice è di rango $3$. Non essendoci incognite dentro alle nostre sottomatrici, ciò vuol dire che vale per ogni $k \in R$.

Non ci rimane che trovare per quali valori di $k$ la dimensione del $KerT$ sia uno. Dobbiamo quindi trovare per quali valori il determinante diventa $0$.

Utilizziamo Laplace
>📝Non sono sicuro al 100%, ma la seconda colonna viene tolta essendo combinazione lineare della prima per $k=0$

$$A=\begin{pmatrix}k&1&1\\k-1&0&1\\2k&2&1\end{pmatrix}=-(k-1)\begin{pmatrix}1&1\\2&1\end{pmatrix}-\begin{pmatrix}k&1\\2k&2\end{pmatrix}$$
$$=-(k-1)(1-2)-(2k-2)=-(k-1)(-1)=k-1$$
Quindi per $k=1$ il determinante è $0$, se invece $k\neq1$ allora il rango della matrice è $3$ il determinante è diverso da zero per cui il $KerT$ ha dimensione 1.

---
## Esercizio 2
- Sia $T:R^4\rightarrow R^3$ l'applicazione lineare definita dalla seguente matrice 
$$A=\begin{pmatrix}1&2&3&0\\0&-1&2&1\\-1&-3&-1&1\end{pmatrix}$$
si richiede la legge esplicita e di trovare dimensione e base di $KerT$.

Iniziamo scrivendo la legge esplicita:

$$T\begin{pmatrix}x\\y\\z\\w\end{pmatrix}=A\begin{pmatrix}x\\y\\z\\w\end{pmatrix}=\begin{pmatrix}1&2&3&0\\0&-1&2&1\\-1&-3&-1&1\end{pmatrix}\begin{pmatrix}x\\y\\z\\w\end{pmatrix}=\begin{pmatrix}x+2y+z\\-y+2z+w\\-x-3y-z+w\end{pmatrix}$$
Ora troviamo la dimensione e base di $KerT$.

Se troviamo che il rango = $3$. Utilizziamo il teorema orlato.

Prendiamo le matrice per $p=1$ e verifichiamo che ne sia almeno una con determinante $\neq 0$

$$\begin{pmatrix}1&2\\0&-1\end{pmatrix}=1(-1)+2(0)=-1\neq0$$

quindi ora sappiamo che non è di rango 2.
Prendiamo ora per $p=2$

$$\begin{pmatrix}1&2&3\\0&-1&2\\-1&-3&-1\end{pmatrix}$$
Calcoliamone il determinante con Laplace:
$$\begin{pmatrix}2&3\\-3&-1\end{pmatrix}+\begin{pmatrix}2&3\\-1&2\end{pmatrix}=(-2+9)+(-1)(4+3)=0$$
La prima non risulta funzionare, quindi dobbiamo verificare con la seconda sottomatrice
$$\begin{pmatrix}1&2&0\\0&-1&1\\-1&-3&1\end{pmatrix}=-\begin{pmatrix}1&2\\-1&-3\end{pmatrix}+\begin{pmatrix}-1\end{pmatrix}=-(-3+2)-1=0$$
Vuol dire che la matrice in questo caso ha rango $2$!!

>📝Fare attenzione ai calcoli con le matrici orlate, e ricordare che funzionano solo se quadrate!

Avendo rango 2 ciò vuol dire che l'applicazione avrà due variabili libere:
$$A=\begin{pmatrix}1&2&3&0\\0&-1&2&1\\-1&-3&-1&1\end{pmatrix}=\begin{pmatrix}1&2&3&0\\0&-1&2&1\\0&-1&2&1\end{pmatrix}=\begin{pmatrix}1&2&3&0\\0&-1&2&1\\0&0&0&0\end{pmatrix}$$

Come possiamo quindi notare, il rango è confermato, così come le variabili libere:
$$\begin{cases}x+2y+3z=0\\-y+2z+w=0\end{cases}\rightarrow \begin{cases}x=-4z-2w-3z\\y=2z+w\end{cases}$$

Da cui ricaviamo la base per $KerT$:
$$\begin{pmatrix}-4z-3z-2w\\2z+w\\z\\w\end{pmatrix}=z\begin{pmatrix}-7\\2\\1\\0\end{pmatrix}+w\begin{pmatrix}-2\\1\\0\\1\end{pmatrix}=\begin{pmatrix}-7\\2\\1\\0\end{pmatrix},\begin{pmatrix}-2\\1\\0\\1\end{pmatrix}$$

---
## Esercizio 3
- Sia $T:R^3\rightarrow R^2$ l'applicazione lineare definita dalla seguente matrice 
$$A=\begin{pmatrix}2&0&1\\3&-1&2\end{pmatrix}$$
Dato il vettore $u=(1,-2) \in R^2$ determinare $T^{-1}(u)$. L'applicazione è invertibile??

Per determinare $T^{-1}(u)$ dobbiamo trovare sia il $v$ generale che il $Ker$
$$\begin{cases}2x+z=0\\3x-y+2z=0\end{cases}\rightarrow \begin{cases}z=-2x\\y=-x\end{cases}$$ Per cui:
$$\begin{pmatrix}x\\-x\\-2x\end{pmatrix}=x\begin{pmatrix}1\\-1\\-2\end{pmatrix}$$ Funge da base del $Ker$, mentre:
$$\begin{cases}2x+z=1\\3x-y+2z=-2\end{cases}\rightarrow \begin{cases}z=1-2x\\y=-x+4\end{cases} \rightarrow \begin{pmatrix}x\\-x+4\\1-2x\end{pmatrix}$$
Inoltre l'applicazione non è invertibile essendo non iniettiva l'applicazione.

---

## Esercizio 4
- Si consideri al variare di $\alpha \in R$ l'applicazione lineare $T_{\alpha}:R^3 \rightarrow R^3$ tale che
$$T_\alpha \begin{pmatrix}x\\y\\z\end{pmatrix}=\begin{pmatrix}-x+(2-\alpha)y+z\\x-y+z\\x-y+(4-\alpha)z\end{pmatrix}$$
Scrivere la matrice $A_\alpha$ associata a $T_a$ rispetto alla base canonica, determinare per quali $\alpha \in R$ l'applicazione è iniettiva, suriettiva, ed il vettore $\begin{pmatrix}1\\1\\1\end{pmatrix} \in Im(T_\alpha)$ e determinare il $KerT_1$.

Scriviamo come prima cosa la matrice associata:
$$\begin{pmatrix}-1&2-a&1\\1&-1&1\\1&-1&4-a\end{pmatrix}$$
l'applicazione è iniettiva se il rango risulta massimo, quindi dobbiamo calcolare il determinante:
$$(1)\begin{pmatrix}2-a&1\\-1&1\end{pmatrix}-(1)\begin{pmatrix}2-a&1\\-1&4-a\end{pmatrix}+(-1)\begin{pmatrix}-1&1\\-1&4-a\end{pmatrix}$$

$$=((2-a)+1)-((2-a)(4-a)+1)-(-4+a+1)=$$$$2-a+1-8+6a-a^2-1+4-a-1=+4a-a^2-3$$ Quindi $a^2-4a+3$ è il nostro determinante, che noi vogliamo sapere quando $\neq 0$.
$$a^2-4a+3=0=\frac{4+-\sqrt{16-12}}{2}=\begin{cases}\frac{4+2}{2}=3\\\frac{4-2}{2}=1\end{cases}$$
Questo vuol dire che la funzione è iniettiva, e in questo caso anche suriettiva per tutti quei valori dove $\forall \alpha \in R \text{ tale che } \{ \alpha \neq 1 \neq 3\}$.

$$\begin{pmatrix}-1&2-a&1&|&1\\1&-1&1&|&1\\1&-1&4-a&|&1\end{pmatrix}=\begin{pmatrix}-1&2-a&1&|&1\\1&-1&1&|&1\\0&0&3-a&|&0\end{pmatrix}=$$$$\begin{pmatrix}-1&2-a&1&|&1\\0&1-a&2&|&2\\0&0&3-a&|&0\end{pmatrix}$$
$$\begin{cases}-x+(2-a)y+z=1\\(1-a)y+2z=2\\(3-a)z=0\end{cases}=\begin{cases}-1+(2-a)y=x\\y=\frac{2}{(1-a)}\\z=0\end{cases}=\begin{cases}-1+\frac{4-2a}{(1-a)}=x\\y=\frac{2}{(1-a)}\\z=0\end{cases}$$
$$=\begin{cases}\frac{3-a}{(1-a)}=x\\y=\frac{2}{(1-a)}\\z=0\end{cases}$$
quindi per $a\neq 1$ il sistema ha soluzione, e quindi il vettore appartiene all'immagine della matrice.

Per quanto riguarda il $KerT_1$ invece, la matrice risulta avere rango 2 per $a=1$ e ciò vuol dire che avrá un parametro libero

$$\begin{pmatrix}-1&1&1\\0&0&2\\0&0&2\end{pmatrix}=\begin{cases}-x+y+z=0\\2z=0\end{cases}=\begin{cases}x=y\\z=0\end{cases}$$
per cui avremo il nostro parametro libero y a cui daremo il valore a: per cui diventa
$(a,a,0)=a(1,1,0)$ per cui il  vettore $\begin{pmatrix}1\\1\\0\end{pmatrix}$ è base del $KerT_1$.
>📝 Meglio fare la verifica:
>$$\begin{pmatrix}-x+y+z\\x-y+z\\x-y+3z\end{pmatrix}\begin{pmatrix}1\\1\\0\end{pmatrix}=\begin{pmatrix}-1+1\\1-1\\1-1\end{pmatrix}=\begin{pmatrix}0\\0\\0\end{pmatrix}$$
