## Esercizio 1
- Stabilire quali tra le seguenti applicazioni sono lineari e trovare $KerT,ImT$
$$T:R^2\rightarrow R^3\text{ tale che }T(x,y)=(x-y,x+y+1,0)$$

Per essere valida vorrebbe dire che $T(0,0) = (0,0,0)$ che notiamo subito non essere vero quindi l'applicazione lineare non è possibile

$$T:R^2\rightarrow R^2\text{ tale che }T(x,y)=(2x,x+y)$$

In questo caso $T(0,0)=(0,0)$ di conseguenza dobbiamo andare a verificare che le operazioni di somma e moltiplicazione siano preservate:

$T(x_1+x_2,y_1+y_2)=(2x_1+2x_2,\quad x_1+y_1+x_2+y_2)$
$T(x_1+y_1)+T(x_2+y_2) = (2x_1,x_1+y_1)+(2x_2,x_2+y_2) = (2x_1+2x_2,\quad x_1+x_2+y_1+y_2)$  
La somma risulta essere preservata, così come la moltiplicazione:

$T(\lambda x,\lambda y)= (2\lambda x, \lambda x + \lambda y )$
$\lambda T(x,y)= \lambda(2x, x+y) = (2\lambda x, \lambda x + \lambda y )$ 

Da qui ora noi dobbiamo estrarre una base 

$$\begin{pmatrix}2x\\x+y\end{pmatrix}$$

Notiamo che le incognite sono due, come quindi il numero di vettori che comporranno la base

$$\begin{pmatrix}2x\\x+y\end{pmatrix}=x\begin{pmatrix}2\\1\end{pmatrix}+y\begin{pmatrix}0\\1\end{pmatrix}$$

quindi i due vettori $\begin{pmatrix}2\\1\end{pmatrix},\quad \begin{pmatrix}0\\1\end{pmatrix}$ compongono la nostra immagine

---
## Esercizio 2
- Stabilire per quali valori di $t \in R$ la seguente applicazione è lineare e per tali valori calcolare $KerT$ e $ImT$ 
$$T:R^3\rightarrow R^2 \text{ tale che } T(x,y,z)=(x+ty,tyx)$$

risulta esserci il valore nullo senza dover badare al valore di $t$, di conseguenza si controlla se somma e moltiplicazione sono preservate

$$T(x+x_1,y+y_1)=(x+x_1+ty+ty_1,\quad t(y+y_1)(x+x_1))$$
$$T(x,y,z)+T(x_1,y_1,z_1)=(x+ty,txy)+(x_1+ty_1,tx_1y_1)=$$
$$(x+ty+x_1+ty_1,txy+tx_1y_1)$$
Vuol dire che 
$$txy+tx_1y_1=t(y+y_1)(x+x_1)\rightarrow txy+tx_1y_1=(ty+ty_1)(x+x_1)$$
Tutto ciò per essere vero deve avere $t=0$.

>📝Non l'ho fatta, ma va controllata anche la moltiplicazione 

Ora dobbiamo cercare il $KerT$:
$$T(x,y,z)=(x,0)=(0,0)$$ quindi sappiamo che il $KerT$ contiene tutti quei valori dove $x=0$ mentre $y,z$ possono avere qualsiasi valore:
$$\begin{pmatrix}0\\y\\z\end{pmatrix}=y\begin{pmatrix}0\\1\\0\end{pmatrix}+z\begin{pmatrix}0\\0\\1\end{pmatrix}$$
Per quanto invece riguarda $ImT$:

$$T(x,y,z)=\begin{pmatrix}x\\0\end{pmatrix}=x\begin{pmatrix}1\\0\end{pmatrix}$$
dove $\begin{pmatrix}1\\0\end{pmatrix}$ è la base dell'immagine, con dimensione 1.

---
## Esercizio 3
- Data la seguente applicazione lineare da $R^3$ a $R^2$ determinare base di $KerT$ e $ImT$ e stabilire se il vettore $(1,0)$ appartiene ad $ImT$
$$T(x,y,z)=(x+y-2z, -x-y+2z)$$
Notiamo subito che l'elemento nullo è possibile, quindi verifichiamo se sono preservate somma e moltiplicazione

$$T(x+x_1,y+y_1,z+z_1)=(x+x_1+y+y_1-2z-2z_1,\quad -x-x_1-y-y_1+2z+2z_1)$$
 Allora dovrebbe essere uguale a 
$$T(x,y,z)+T(x_1,y_1,z_1)=(x+y-2z,-x-y+2z)+(x_1+y_1-2z_1,-x_1-y_1+2z_1)=$$
$$(x+x_1+y+y_1-2z-2z_1,\quad -x-x_1-y-y_1+2z+2z_1)$$
quindi la somma è preservata.

$$T(\lambda x, \lambda y, \lambda z)=(\lambda x+\lambda y- \lambda2z,-\lambda x - \lambda y +\lambda 2z)$$
Che notiamo subito essere uguale ad $\lambda T(x,y,z)$ per cui anche la moltiplicazione è preservata.

Ora dobbiamo trovare una base per $KerT$ e $ImT$:

$$T(x,y,z)=(0,0)$$
$$\begin{cases}x+y-2z=0\\-x-y+2z=0\end{cases}=\begin{cases}z=\frac{1}{2}(x+y)\\0=0\end{cases}$$
Notiamo come non ci siano soluzioni e abbiamo solo il vincolo che $z=\frac{1}{2}(x+y)$, per cui $x,y$ verranno presi come parametri liberi.

$$\begin{pmatrix}x\\y\\\frac{1}{2}(x+y)\end{pmatrix}=x\begin{pmatrix}1\\0\\\frac{1}{2}\end{pmatrix}+y\begin{pmatrix}0\\1\\\frac{1}{2}\end{pmatrix}$$
Per cui $\begin{pmatrix}1\\0\\\frac{1}{2}\end{pmatrix},\begin{pmatrix}0\\1\\\frac{1}{2}\end{pmatrix}$ sono la base del $KerT$

$$T(x,y,z)=\begin{pmatrix}x+y-2z\\-x-y+2z\end{pmatrix}=x\begin{pmatrix}1\\-1\end{pmatrix}+y\begin{pmatrix}1\\-1\end{pmatrix}+z\begin{pmatrix}-2\\2\end{pmatrix}$$
Notiamo che $\begin{pmatrix}-2\\2\end{pmatrix}$ sia una combinazione lineare di $-2\begin{pmatrix}1\\-1\end{pmatrix}$ per cui viene scartato, portandoci ad avere $\begin{pmatrix}1\\-1\end{pmatrix}$ come base per $ImT$ di dimensione 1.

> 📝Facciamo attenzione a come abbiamo scartato uno dei due vettori $(1,-1)$ essendo altrimenti doppio. Inoltre consiglio di prestare molta attenzione a come si è trovata la base per il $KerT$ 

Inoltre possiamo notare che $\begin{pmatrix}1\\0\end{pmatrix}$ non appartiene ad $ImT$ per il semplice fatto che non possiamo esprimerlo usando $\lambda \begin{pmatrix}1\\-1\end{pmatrix}$.

---
## Esercizio 4
- Data la seguente applicazione lineare da $R^4$ a $R^3$ trovare una base di $KerT$  e $ImT$, stabilire se $(7,-1,11)\in ImT$ e trovare se possibile un vettore di $R^3$ che non sia presente in $ImT$ 
$$T(x,y,z,w)=(x+2y+z-3w, -y+z+2w, 2x+y+5z)$$ L'elemento nullo esiste, controlliamo somma e moltiplicazione
>📝Salto il passaggio perché sono verificate entrambe e non ho voglia di scrivere :)

Troviamo una base per $KerT$

$$\begin{cases}x+2y+z-3w=0\\-y+z+2w=0\\2x+y+5z=0\end{cases}=\begin{cases}x+3z+w=0\\y=z+2w\\2x+y+5z=0\end{cases}=\begin{cases}x=-3z-w\\y=z+2w\\-6z-2w+z+2w+5z=0\end{cases}=$$
$$\begin{cases}x=-3z-w\\y=z+2w\\0=0\end{cases}$$

2 equazioni 4 incognite = 2 variabili libere con 2 vincoli su x e y
$$\begin{pmatrix}-3z-w\\z+2w\\z\\w\end{pmatrix}=z\begin{pmatrix}-3\\1\\1\\0\end{pmatrix}+w\begin{pmatrix}-1\\2\\0\\1\end{pmatrix}$$
$$\begin{pmatrix}-3\\1\\1\\0\end{pmatrix},\begin{pmatrix}-1\\2\\0\\1\end{pmatrix}$$
![[Pasted image 20240508115017.png]]
>⚠ Non so chi abbia ragione ma la base del $KerT$ risulta diversa da quella estratta dal tutorato (come in foto). Il procedimento rimane lo stesso in ogni caso(chatgpt da ragione a me anyway).
>invece $(7,-1,11)$ appartiene a $ImT$ semplicemente ha sbagliato il segno all'ultima riga prima del sistema scrivendo $(7,1,11)$

Troviamo ora la base per $ImT$
$$\begin{pmatrix}x+2y+z-3w\\-y+z+2w\\2x+y+5z\end{pmatrix}=x\begin{pmatrix}1\\0\\2\end{pmatrix}+y\begin{pmatrix}2\\-1\\1\end{pmatrix}+z\begin{pmatrix}1\\1\\5\end{pmatrix}+w\begin{pmatrix}-3\\2\\0\end{pmatrix}$$

Possiamo scartare $v_3,v_4$ restando con $\begin{pmatrix}1\\0\\2\end{pmatrix},\begin{pmatrix}2\\-1\\1\end{pmatrix}$ per la base dell'immagine di $T$
$(7,-1,11)$ appartiene all'immagine essendo risultato della combinazione lineare $5\begin{pmatrix}1\\0\\2\end{pmatrix}+\begin{pmatrix}2\\-1\\1\end{pmatrix}$.

Vediamo subito che la dimensione è minore di quella di $R^3$ quindi sicuramente esiste un vettore di $R^3$ che non appartiene a $ImT$. per esempio il vettore $(1,0,3)$ non è combinazione lineare dei due vettori della base dell'immagine di $T$.

---
## Esercizio 5
- Sia $\{e_1,e_2,e_3\}$ la base canonica di $R^3$, e si consideri l'unica applicazione lineare $T:R^3\rightarrow R^2$ tale che:
$$T(e_1)=(1,0),\qquad T(e_2)=(2,-1)\qquad T(e_3)=(1,1)$$
determinare $T(1,2,0)$ e $T(3,-1,-1)$ e $T(x,y,z) \text{ per ogni } x,y,z \in R^3$

La base canonica corrisponde a:
$$\begin{pmatrix}1,0,0\\0,1,0\\0,0,1\end{pmatrix}$$
per cui noi sappiamo che:
$$T(1,0,0)=(1,0)==(x,y,z)=(x,0),\qquad T(0,1,0)=(2,-1)==(x,y,z)=(2y,-y)$$
$$\qquad T(0,0,1)=(1,1)==(x,y,z)=(z,z)$$
ciò vuol dire che la applicazione lineare corrisponde ad:
$$(x+2y+z,-y+z)$$
ciò vuol dire che $T(1,2,0)=(5,-2)$ e $T(3,-1,-1)=(0,0)$

>📝$(x+2y+z,-y+z)$ è la forma più generale :)

---
## Esercizio 6
- Determinare l'unica applicazione lineare $T: R^2\rightarrow R^2$ tale che:
$$T(1,0)=(2,1)\qquad e \qquad (1,1) \in KerT$$

Risolviamo facendo:
$$T(1,0)=(2,1)==(x,y)=(2x,x)\qquad (1,1)=(0,0)==(x,y)=(a(x-y),b(x-y))$$

così facendo notiamo che per arrivare ad avere $T(1,0)=(2,1)$ ci basta cambiare $a$ o $b$ nella seconda formula, ovvero:
$$T(x,y)=(2(x-y),x-y)$$

---
## Esercizio 7
- Siano $v1=(1,1,1),\quad v_2=(1,-1,0)\quad v_3=(1,1,0)$ vettori di $R^3$. Dobbiamo determinare l'unica applicazione lineare tale che $T(v_1)=T(v_2)=(2,1,1),T(v_3)=(4,4,2)$ la dimensione e una base di $KerT$, di $ImT$

Iniziamo cercando l'applicazione lineare
$$T(1,1,1)=\begin{pmatrix}a_1+b_1+c_1\\a_2+b_2+c_2\\a_3+b_3+c_3\end{pmatrix}=\begin{pmatrix}2\\1\\1\end{pmatrix}$$
$$T(1,-1,0)=\begin{pmatrix}a_1-b_1\\a_2-b_2\\a_3-b_3\end{pmatrix}=\begin{pmatrix}2\\1\\1\end{pmatrix}$$
$$T(1,1,0)=\begin{pmatrix}a_1+b_1\\a_2+b_2\\a_3+b_3\end{pmatrix}=\begin{pmatrix}4\\4\\2\end{pmatrix}$$
Ora mettiamo tutte le soluzioni a sistema per ogni incognita che stiamo cercando:
$$\begin{cases}a_1+b_1+c_1=2\\a_1-b_1=2\\a_1+b_1=4\end{cases}=\begin{cases}a_1=3\\b_1=1\\c_1=-2\end{cases}$$

$$\begin{cases}a_2+b_2+c_2=1\\a_2-b_2=1\\a_2+b_2=4\end{cases}=\begin{cases}a_2=\frac{5}{2}\\b_2=\frac{3}{2}\\c_2=-3\end{cases}$$
$$\begin{cases}a_3+b_3+c_3=1\\a_3-b_3=1\\a_3+b_3=2\end{cases}=\begin{cases}a_3=\frac{3}{2}\\b_3=\frac{1}{2}\\c_3=-1\end{cases}$$

>📝Non ho scritto tutti i calcoli, erano troppo lunghi

$$T(x,y,z)=(3x+y-2z,\frac{5}{2}x+\frac{3}{2}y-3z,\frac{3}{2}x+\frac{1}{2}y-z)$$

--- 
## Esercizio 8
- Sia $T:R^3\rightarrow R^3$ tale che
$$T(x,y,z)=(x+ay,(1-a)y+z,ax+y+2z)$$
determinare per quali valori di $a \in R$ l'omomorfismo $T$  non è suriettivo, per tali valori determinare una base di $KerT$ e $ImT$ con la relativa dimensione, inoltre per tali valori di $a$ è vero che  $KerT+ImT=R^3$?

$$\begin{pmatrix}x+ay\\(1-a)y+z\\ax+y+2z\end{pmatrix}=x\begin{pmatrix}1\\0\\a\end{pmatrix}+y\begin{pmatrix}a\\1-a\\1\end{pmatrix}+z\begin{pmatrix}0\\1\\2\end{pmatrix}$$

$$\begin{cases}x+ay=0\\y-ay+z=0\\xa+y+2z=0\end{cases}=\begin{cases}x=-ay\\(1-a)y+z=0\\(1-a^2)y+2z=0\end{cases}=\begin{cases}x=-ay\\z=-(1-a)y\\y-a^2y-2y+2ay=0\end{cases}=$$ $$\begin{cases}x=-ay\\z=-(1-a)y\\(a^2-1+2a)y=0\end{cases}=\begin{cases}x=-y\\z=0\\a^2-1+2a=0\rightarrow a=1\end{cases}$$
in questo modo abbiamo $\begin{pmatrix}1\\0\\1\end{pmatrix},\begin{pmatrix}1\\0\\1\end{pmatrix},\begin{pmatrix}0\\1\\2\end{pmatrix}$ quindi $\begin{pmatrix}1\\0\\1\end{pmatrix},\begin{pmatrix}0\\1\\2\end{pmatrix}$ come base di dimensione 2, non è suriettiva.
Per trovare ora il $KerT,\:\:a=1$:
$$\begin{pmatrix}x+y\\z\\x+y+2z\end{pmatrix}=\begin{pmatrix}0\\0\\0\end{pmatrix}$$
$$\begin{cases}x+y=0\\z=0\\x+y+2z=0\end{cases}=\begin{cases}z=0\\x=-y\end{cases}$$

la base di $KerT$ risulta essere $x\begin{pmatrix}-1\\1\\0\end{pmatrix}$ con dimensione 1.

>📝Non serve ricalcolare $ImT$ avendola già trovata prima per $a=1$

Ora bisogna verificare che $KerT+ImT=R^3$, che tradotto vuol dire $KerT \cap ImT = \varnothing$ 

$$\begin{cases}x=-z\\y=z\\x+2y=0\end{cases}=\begin{cases}x=0\\y=0\\z=0\end{cases}$$
Essendo quindi la loro intersezione solo l'elemento nullo, e tutti linearmente indipendenti tra loro, essi formano $R^3$.

---
## Esercizio 12

- Sia $T:R^3\rightarrow R^3$ tale che
$$T(x,y,z)=(-x+(2-a)y+z, x-y+z, x-y+(4-a)z)$$
con $a \in R$. Determinare per quali valori del parametro $a \in R$ l'omomorfismo $T$ è suriettivo e per quali è iniettivo. Inoltre determinare per quali $a \in R$ il vettore $w=(1,1,1) \in ImT$ e $KerT,con\: a=1$.

Uso il metodo di eliminazione di Gauss
$$\begin{pmatrix}-1&2-a&1\\1&-1&1\\1&-1&4-a\end{pmatrix}=\begin{pmatrix}-1&2-a&1\\1&-1&1\\0&0&3-a\end{pmatrix}=\begin{pmatrix}-1&2-a&1\\0&1-a&2\\0&0&3-a\end{pmatrix}$$

E calcolo il determinante: $-1(1-a)(3-a)\neq0$ per $a\neq3,a\neq0$
quindi per $a\neq3,a\neq0$ la funzione è suriettiva e per via del determinante è anche iniettiva.
>📝Se il determinante estratto in questo modo è diverso da zero ciò vuol dire che i vettori sono indipendenti, di conseguenza generano l'intero spazio, inoltre vuol dire che la matrice è invertibile e di conseguenza il $Ker$ corrisponde al solo elemento nullo. Tutto ciò perché rimaniamo nello stesso spazio vettoriale $R^3$.

Ciò implica anche che per $a\neq3,a\neq0,\quad w=(1,1,1)\in ImT$ 


$$a=1\quad\begin{pmatrix}-1&1&1\\1&-1&1\\1&-1&3\end{pmatrix}=\begin{pmatrix}-1\\1\\1\end{pmatrix},\begin{pmatrix}1\\1\\3\end{pmatrix}$$
$$\begin{cases}-a+b=1\\a+b=1\\a+3b=1\end{cases}=\begin{cases}b=1+a\\a+1+a=1\rightarrow a=0\\a+3+3a=1\end{cases}=\begin{cases}b=1\\a=0\\impossibile\end{cases}\neq(1,1,1)=w\notin ImT$$

$$a=3\quad\begin{pmatrix}-1&-1&1\\1&-1&1\\1&-1&1\end{pmatrix}=\begin{pmatrix}-1\\1\\1\end{pmatrix},\begin{pmatrix}1\\1\\1\end{pmatrix}$$
$$\begin{cases}-a+b=1\\a+b=1\\a+b=1\end{cases}=\begin{cases}b=1+a\\a+1+a=1\end{cases}=\begin{cases}a=0\\b=1\end{cases}=b\begin{pmatrix}1\\1\\1\end{pmatrix}=(1,1,1)=w\in ImT$$

$$KerT\:con\:a=1\quad (-x+(2-a)y+z, x-y+z, x-y+(4-a)z)$$
$$\begin{cases}-x+y+z=0\\x-y+z=0\\x-y+3z=0\end{cases}=\begin{cases}x=y\\z=0\\\end{cases}$$ Quindi posso prendere 1 per fare la base $\begin{pmatrix}1\\1\\0\end{pmatrix}$ del $KerT$.