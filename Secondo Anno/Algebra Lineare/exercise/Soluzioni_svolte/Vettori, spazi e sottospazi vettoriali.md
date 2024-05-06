Vettori & co.
> Teoria dei vettori

$\bar{u}+\bar{v} = (u_x+v_x,\:u_y+v_y)$
$\lambda \bar{u} = (\lambda u_x,\: \lambda u_y)$ 

> La dimensione dello spazio determina quanti vettori generano lo spazio, $R^3 =$ vettori, ecc.

> Introduzione ai Sistemi Lineari
$$
\begin{cases}
2x +y-z=1 \\
x+2z=0\\
\end{cases} 
$$

$x = -2, \: y = 5, \: z = 1$

> Non sempre però si hanno soluzioni

> Caso 1

$$
\begin{cases}
x-2y+z = 1\\
x-4y+4z = 2\\
x-2y+2z = 3\\
\end{cases}
$$
$x =4, \: y=\frac{5}{2}, \:, z=2$

> Sistema Omogeneo: tutti i termini noti sono nulli, $b_1=b_2=b_3=\:...\:=b_n=0$ 

### Foglio esercizi 2 spazi vettoriali

## Dati i seguenti vettori nello spazio$v = (1,-1,-1)\quad e\quad w=(-2,2,0)$ 
- Calcolare
	- $v+w$
		- $z = v+w = (-1,1,-1)$
	- $v-2w$
		- $2w = (-4,4,0)\quad e \quad z = v-2w = (5,-5,-1)$ 
	- $-3v+\frac{1}{2}w$
		- $v =(-3,3,3)\quad e \quad w = (-1,1,0)\quad e \quad z=(-4,4,3)$

## Verificare se i seguenti vettori di $R^3$ sono linearmente indipendenti o meno
- $v=(1,1,0),\: w=(2,0,-1),\: z=(0,2,1)$
	- Per verificare che sia corretto

$$\begin{cases} 
x + 2y = 0 \\
x + 2z = 0 \\
-y + z = 0 \\
\end{cases}$$
$$\begin{cases} 
x = -2z \\
-2z + 2z = 0 \\
y = z \\
\end{cases}$$
$$\begin{cases} 
x = -2z \\
0 = 0 \\
y = z \\
\end{cases}$$
> I tre vettori sono linearmente dipendenti, dato che $y=z$ implica che ci sono infinite soluzioni per il sistema. Proviamo a dimostrare ora che uno dei tre è combinazione lineare degli altri due

$$z=c_1w+c_2v$$
$$c_1=-1,c_2=2\begin{cases}2(1)+(1-)(2)=0\\2(1)+(-1)(0) = 2\\2(0)+(-1)(-1) = 1 \end{cases}$$
> Questo vuol dire che $v(2)+w(-1) = z$  e quindi non sono tutti indipendenti tra loro

## Verificare se i seguenti vettori di $R^3$ sono linearmente dipendenti o indipendenti $$v1=(1,1,2), \quad v2=(0,2,2), \quad v3=(-1,3,2)$$In caso di dipendenza, trovare poi la relazione che permette di scrivere uno dei vettori come combinazione lineare degli altri due
- $$\begin{cases}a-c=0\\ a+2b+3c=0\\ 2a+2b+2c=0\end{cases}$$ $$\begin{cases}a=c\\4c+2b=0\end{cases}$$
- Con questo, noi sappiano adesso che ci sono infinite soluzioni e di conseguenza non sono tutti indipendenti, ciò vuol dire che uno dei tre vettori può essere rappresentato come combinazione lineare degli altri due vettori
- se noi facciamo infatti $2v_2+(-1)v_3$ il risultato sarà esattamente $v_1$.
- Dato il vettore $v=(1,-1,2)$ trovare altri due vettori di $R^3$ che messi assieme a $v$ diano tre vettori linearmente indipendenti.
	- Per farlo, dobbiamo prendere due componenti del vettore e usarle per creare due nuovi vettori a nostro piacimento, es, $w=(1,2,0), \quad z=(1,-2,0)$.
	- Ora per sicurezza controlliamo che siano effettivamente linearmente indipendenti tra di loro tramite il sistema
$$\begin{cases}a+b+c=0 \qquad\rightarrow b = -c \qquad\rightarrow b = 0\\-a+2b-2c=0 \qquad\rightarrow 4c = 0 \qquad\rightarrow c = 0\\2a=0 \qquad\rightarrow a=0\end{cases}$$
- Tutti i vettori risultano essere indipendenti tra loro

## Dati i seguenti vettori di $R^3$ $$v_1=(3,1,k),\quad v_2=(-k,1,0), \quad v_3=(2k,-2,k)$$ stabilire per quali valori di $k\in R$ i vettori sono lin. indip. e per quando invece sono dipendenti,  stabilire quanti tra loro sono linearmente indipendenti

- Analizziamo il sistema mettendo tutto a zero (ovvero quando sono linearmente indipendenti)
$$\begin{cases}
3a-kb+2kc=0\\
a+b-2c=0\\
ka+kc=0\\
\end{cases}
\rightarrow 3r_2-r_1,3r_3-kr_1
\begin{cases}
3a-kb+2kc=0\\
(3+k)b+(-6-2k)c=0\\
k^2b+(3k-2k^2c)=0\\
\end{cases}$$
$$\text{$k=-3$}\rightarrow\begin{cases}
3a+3b-6c=0\\
0=0\\
9b-27c=0\\
	\end{cases}\rightarrow\text{2 equazioni = 2 vettori indip.}$$
$$\text{$k=0$}\rightarrow\begin{cases}
3a=0\\
3b-6c=0 \rightarrow b=2c\\
0=0\\
\end{cases}\rightarrow \text{1 equazione = 1 vettore indip.}$$
## Stabilire se il seguente sottoinsieme di $R^2$ è uno sottospazio vettoriale
- $V={(x,y) \in R^2 : x+y=5}$ 
- Per le proprietà degli spazi vettoriali sappiamo che il sottospazio deve avere un vettore nullo $(0,0)$ cosa che in questo caso non esiste data la condizione $x+y=5$

## Verificare che i seguenti sottoinsiemi di $R^4$ sono sottospazi vettoriali.
$S={(x,y,z,w)\in R^4:x+z=0, 3y-w=0}$
$T={(x,y,z,w)\in R^4:x+z=0, y-w=0}$

- Per farlo mettiamo a sistema le due equazioni, e verifichiamo 
$$S:\begin{cases}x+z=0\\3y-w=0\end{cases}\rightarrow\begin{cases}x=-z\\3y=w\end{cases}$$
- S dipende da due elementi generici: $z,w\in R$ 
$$\begin{pmatrix}-z\\y\\z\\3y\end{pmatrix}$$
- Verifichiamo ora che siano possibili somma e prodotto per scalare
$$\lambda S_1:\lambda\begin{pmatrix}-z\\\frac{1}{3}w\\z\\w\end{pmatrix}=\begin{pmatrix}-z\lambda\\\frac{1}{3}w\lambda\\z\lambda\\w\lambda\end{pmatrix}=\begin{cases}-z\lambda=z\lambda\\3\frac{1}{3}w\lambda=w\lambda\end{cases}=\begin{cases}0=0\\0=0\end{cases}$$
$$S=S_1+S_2:\begin{pmatrix}-z_a\\y_a\\z_a\\3y_a\end{pmatrix}+\begin{pmatrix}-z_b\\y_b\\z_b\\3y_b\end{pmatrix}=\begin{pmatrix}-(z_a+z_b)\\y_a+y_b\\z_a+z_b\\3(y_a+y_b)\end{pmatrix}$$
- Sostituiamo i valori trovati nel sistema di equazioni, se i risultati saranno zero allora vuol dire che è valido
$$S:\begin{cases}x+z=0\\3y-w=0\end{cases}\rightarrow\begin{cases}-(z_a+z_b)+(z_a+z_b)=0\\3(y_a+y_b)-3(y_a+y_b)=0\end{cases}\rightarrow \text{soluzione valida, è un sottospazio}$$
- Ripetendo il processo anche per $T$ scopriamo che anch'esso è uno sottospazio vettoriale valido
## Stabilire se ognuno dei seguenti sottoinsiemi di R_2[x] è formato da vettori linearmente indipendenti $\{1,x,x^2\},\{1,x\}$
$$S=\{1,x,x^2\}\rightarrow\text{si fa il sistema ricordando la regola $as_1+bs_2+cs_3=0$}$$
- In questo caso l'unico modo per far si che $a1+bx+cx^2=0$ è settare $a=b=c=0$. Se non fosse stato così, i vettori non sarebbero linearmente indipendenti. Stessa cosa vale per $\{1,x\}$.
- Per esempio $\{x+x^2,2x+2x^2\}$ non è formato da vettori linearmente indipendenti.

## Stabilire se ognuno dei seguenti sottoinsiemi di $R^3$ è formato da vettori linearmente indipendenti e se è un insieme di generatori. Se il sottoinsieme non costituisce una base di $R^3$, completarlo ad una base o estrarre una base

$$S={(1,0,0),(1,1,0),(0,1,1)} =$$
$$a(1,0,0)+b(1,1,0)+c(0,1,1)=0$$
- Metto a sistema
$$\begin{cases}a+b=0\\b+c=0\\c=0\end{cases}\rightarrow\begin{cases}a=0\\b=0\\c=0\end{cases}$$
- I vettori sono linearmente indipendenti.
- Ora verifico che siano un insieme generatore
💡*metodo errato, da non seguire, guardare esercizio sotto*
$$x(1,0,0)+y(1,1,0)+z(0,1,1)=(x+y,y+z,z)$$
- i vettori coprono tutte le direzioni in $R^3$ e di conseguenza sono insieme generatore di $R^3$



- Un altro sottoinsieme è costituito da
$$T={(1,0,0),(0,1,1),(5,1,1)} =$$
- Mettiamo a sistema
$$S=a(1,0,0)+b(0,1,1)+c(5,1,1) = 0$$
$$\begin{cases}a+5c=0\\b+c=0\end{cases}$$
- In questo caso abbiamo un sistema non esaustivo, di conseguenza non sono tutti indipendenti
- Se notiamo bene, $(5,1,1)$ può essere visto come combinazione lineare degli altri due vettori, infatti $(5,1,1)=5(1,0,0)+1(0,1,1)$. Di co(1, 0, 0), (1, 1, 0) di conseguenza possiamo toglierlo per rimanere solo con i primi due vettori, ma questi fanno si che $dim(Span T) = 2 < 3$, quindi dobbiamo trovare un terzo vettore per poter creare una base di $R^3$.
- Calcoliamo il rango della matrice dei due vettori
$$rg\begin{pmatrix}1&0&0\\0&1&1\end{pmatrix}=2$$
- Serve ora un terzo vettore anch'esso indipendente dagli altri due, prendiamo per esempio $(0,1,0)$
- Ora facendo il controllo del rango utilizzando Gauss
$$rg\begin{pmatrix}1&0&0\\0&1&1\\0&1&0\end{pmatrix}=(scambio\:r_3\:con\:r_2)\:poi\:r_3-r_2=\begin{pmatrix}1&0&0\\0&1&0\\0&0&1\end{pmatrix}=3$$

- Essendo la matrice $3*3$ e il rango $3$ i tre vettori sono linearmente indipendenti tra loro 

- Un altro insieme è costituito da 
$$U=\{(1,0,0),(5,1,1)\}=$$

- Mettiamo tutto a sistema
$$\begin{cases}a+5b=0\\b=0\\c=0\end{cases}$$
- i due vettori sono indipendenti tra loro
- Essendo solo due non possono generare $R^3$, per cui mi serve un altro vettore
- Ipotizziamo che esso sia $(0,0,1)$ 
- Verifichiamo ora con Gauss
$$\begin{pmatrix}1&0&0\\5&1&1\\0&0&1\end{pmatrix}=r_2-5r_3=\begin{pmatrix}1&0&0\\0&1&1\\0&0&1\end{pmatrix}=3$$

- Un altro insieme è costituito da
$$V = \{(1,1,0),(0,1,1),(5,1,1),(1,2,1)\}$$
- Poniamo tutto a sistema
$$\begin{cases}a+5c+d=0\\a+b+c+2d=0\\b+c+d=0\end{cases}$$
- Non è possibile risolvere un sistema a 4 incognite con 3 equazioni, sono dipendenti. Notiamo come $(1,2,1)$ sia combinazione lineare di $(1,1,0)+(0,1,1)$ e quindi possa essere rimosso. Se ora proviamo a fare il sistema
$$\begin{cases}a+5c=0\\a+b+c=0\\b+c=0\end{cases}\rightarrow \begin{cases}a+5c = 0\\a-c+c=0\\b=-c\end{cases}\rightarrow\begin{cases}c=0\\a=0\\b=0\end{cases}$$
- I tre vettori risultano linearmente indipendenti, posso usarli come base se sono anche generatori, e con piacere per noi il rango della matrice è
$$\begin{pmatrix}1&1&0\\0&1&1\\5&1&1\end{pmatrix}=\begin{pmatrix}1&1&0\\0&1&1\\0&-4&1\end{pmatrix}=\begin{pmatrix}1&1&0\\0&1&1\\0&0&5\end{pmatrix}=3$$
- I vettori sono generatori dello spazio in $R^3$

- Proviamo con un altro insieme, stavolta però nello spazio $R^4$ 
$$\{(1,0,0,0),(1,1,0,0),(1,1,1,0),(1,1,1,1)\}$$

- Poniamo tutti e quattro a sistema
$$\begin{cases}a+b+c+d=0\\b+c+d=0\\c+d=0\\d=0\end{cases}\rightarrow\begin{cases}a=0\\b=0\\c=0\\d=0\end{cases}$$

- I 4 vettori risultano essere linearmente indipendenti. Ora verifichiamo che essi siano un insieme generatore dello spazio $R^4$.
$$\begin{pmatrix}1&0&0&0\\1&1&0&0\\1&1&1&0\\1&1&1&1\end{pmatrix}=\text{con il metodo di Gauss scambio $r_4,r_1$ e $r_2,r_3$}=4$$
- I vettori costituiscono una base per $R^4$

- Un altro sottoinsieme di $R^4$ 
$$\{(1, 0, 0, 0), (0, 1, 1, 1), (1, 1, 1, 0), (1, 1, 1, 1), (0, 3, 0, 0)\}$$
- Notiamo subito che $v_4$ può essere visto come combinazione lineare dei vettori $v_1,v_2$ e quindi lo scartiamo
- Ora poniamo il tutto a sistema
$$\begin{cases}a+c=0\\b+c+3d=0\\b+c=0\\b=0\end{cases}\rightarrow\begin{cases}b=0\\c=0\\d=0\\a=0\end{cases}$$

- I vettori rimasti risultano essere linearmente indipendenti tra di loro. Verifichiamo ora che si tratti di generatori

$$\begin{pmatrix}1&0&0&0\\0&1&1&1\\1&1&1&0\\0&3&0&0\end{pmatrix}=\begin{pmatrix}1&0&0&0\\0&3&0&0\\0&1&1&1\\1&1&1&0\end{pmatrix}=\begin{pmatrix}1&0&0&0\\0&3&0&0\\0&1&1&1\\0&0&0&-1\end{pmatrix}=\begin{pmatrix}1&0&0&0\\0&3&0&0\\0&0&1&1\\0&0&0&-1\end{pmatrix}=4$$
- I quattro vettori rimasti sono indipendenti tra loro

- Stabilire se i seguenti vettori di $R^4$ sono linearmente indipendenti, se fungono da base e se serve un vettore $v_4$ per completare la base

$$v_1=(1,0,2,-2)\quad v_2=(2,0,2,1)\quad v_3=(1,1,0,1)$$
- Per stabilire se sono indipendenti li si mette tutti a sistema

$$
\begin{cases}
a+2b+c=0\\
c=0\\
2a+2b=0\\
-2a+b+c=0
\end{cases} \rightarrow
\begin{cases}
a=-2b \rightarrow a=0 \\ 
c=0\\
2a+2b=0\\
-2a+b=0 \rightarrow b=0
\end{cases}
$$
- I tre vettori risultano essere indipendenti tra loro, ora verichiamo che possano fungere da base per $R^4$ 

$$\begin{pmatrix}
1&0&2&-2\\
2&0&2&1\\
1&1&0&1\\
\end{pmatrix}
\rightarrow
\begin{pmatrix}
1&0&2&-2\\
0&0&-2&5\\
1&1&0&1\\
\end{pmatrix}\rightarrow
\begin{pmatrix}
1&0&2&-2\\
0&0&-2&5\\
1&1&0&1\\
\end{pmatrix}\rightarrow
\begin{pmatrix}
1&0&2&-2\\
1&1&0&1\\
0&0&-2&5\\
\end{pmatrix}\rightarrow
$$
$$
\begin{pmatrix}
1&0&2&-2\\
0&1&-2&-1\\
0&0&-2&5\\
\end{pmatrix} = 3$$
- Il rango risulta essere inferiore di quello di $R^4$ di conseguenza non sono generatori, serve $v_4$. Il vettore $v_4=(0,0,0,1)$ sembrerebbe fare al caso nostro, infatti se lo inseriamo nella matrice, il risultato diverrà 4, ed il sistema rimane indipendente

## Sono dati i vettori di $R^3$ $$v_1=(1,2,1)\quad v_2=(1,0,2) \quad v_3=(1,k,-1)$$ trovare per quali valori di $k$ i tre vettori formano una base di $R^3$ calcolare al suo variare la dimensione del sottospazio $E=Span\{v_1,v_2,v_3\}$ ed $F=Span\{v_2,v_3\}$

- Per verificare che siano indipendenti mi basta porli a sistema e verificare quando tutti e tre danno $0$ 
$$\begin{cases}a+b+c=0\\2a+kc=0\\a+2b-c=0\end{cases}\rightarrow\begin{cases}a=-b-c\\2a+kc=0\\-b-c+2b-c=0\rightarrow b-2c=0\end{cases} \rightarrow$$ $$\begin{cases}a=-b-c\\-2b-2c+kc=0\rightarrow-2b+(k-2)c=0\\b-2c=0\end{cases}\rightarrow \begin{cases}a=-b-c\\-4c+(k-2)c=0\\b-2c=0\end{cases}$$
- Arriviamo quindi a $-4c+kc-2c=0 \rightarrow kc-6c=0 \rightarrow k=6$ . Se quindi, $k=6$  $v_3$ diventa combinazione lineare degli altri due.  
	- Ciò vuol dire che sono lin. indip. se $k\neq6$ 
- Se $k=6$ $Dim(E)=2$ altrimenti $3$ 
- Per $F$ dobbiamo verificare il tutto ma solo per $v_2,v_3$
$$\begin{cases}a+b=0\\kb=0\\2a-b=0\end{cases}=\begin{cases}a=-b\\kb=0\\ b=0\end{cases}$$
- Questo vuol dire che i due rimangono lin. indip. per ogni valore che $k$ assume
## Dati i seguenti sistemi lineari omogenei nelle incognite $x,y,z$ determinare in ciascun caso una base del sottospazio di $R^3$ formato dalle soluzioni del sistema

$$S_1=x-y+2z=0 \quad S_2=\begin{cases}x+y-z=0\\x-3y=0\end{cases} \quad S_3=\begin{cases}x+y-z=0\\x-3y=0\\2x+y=0\end{cases}$$

$$S_1=\{\:(x,y,z) \in R^3: \: x-y+2z=0\:\} \rightarrow \text{$s \in S_1$ nella forma } s=\begin{pmatrix}a-2b\\ a\\ b\end{pmatrix}=a\begin{pmatrix}1\\1\\0\end{pmatrix}+b\begin{pmatrix}-2\\0\\1\end{pmatrix}$$

- Siamo arrivati a quella forma ponendo come matrice il sistema e trovandone il rango che nel nostro caso corrisponde ad $1$ ed essendo uno sottospazio di $R^3$ ciò vuol dire che abbiamo $3-1=2$ variabili libere che chiamiamo $a$ e $b$. 
- sostituiamole ora all'interno dell'equazione che abbiamo $x-a+2b=0 \rightarrow x=a-2b$ di conseguenza sappiamo che $(a-2b,a,b)$ è la forma che dobbiamo trascrivere in una combinazione lineare di due vettori moltiplicati per $a$ e $b$    trovando così $a\begin{pmatrix}1\\1\\0\end{pmatrix}+b\begin{pmatrix}-2\\0\\1\end{pmatrix}$ e trovando la soluzione al nostro esercizio
## Stabilire per quali valori di $T \in R$ $u=(2,t,0,1)$ appartiene al sottospazio $W$ generatore da $v=(1,0,0,1)$ e $w=(0,1,0,1)$. Calcolare poi la dimensione del sottospazio di $R^4$ generato dai tre al variare di $t \in R$

- Per appartenere al sottospazio vuol dire che $t$ è una combinazione lineare di $v,w$ infatti $2v-w=u$ che ci porta a sapere che $t=-1$. Da qui per calcolare la dimensione del sottospazio vediamo semplicemente che se $t=-1$ è combinazione lineare e di conseguenza la dimensione è $2$ altrimenti è $3$ essendo tutti e tre linearmente indipendenti

## Sia $E$ un sottospazio di $R^4$ formato dalle soluzioni dell'equazione $x+y+z+w=0$ e sia $F=Span\{(1,1,1,-3),(1,-1,1,-1),(1,-1,0,0)\}$. Determinare una base e la dimensione di $E$ e di $F$ e dire se $F$ è sottospazio in $E$ e se $F=E$ 

- Prima cosa da fare prendere l'equazione e come visto nell'esercizio precedente trovare la base 
- Notiamo subito che il rango è $1$ e quindi ci servono $3$ variabili libere, che sceglieremo come $y,z,w$. di conseguenza avremo come combinazione lineare $(y+z+w,y,z,w)$ ovvero $$y(1,1,0,0)+z(1,0,1,0)+w(1,0,0,1)$$
- Da qui ora possiamo dedurre che la dimensione del sottospazio $E$ sia $3$.
- Per rispondere alla seconda e terza domanda, $F\subset E$ è errata essendo entrambe della stessa dimensione, mentre $F=E$ non è comunque possibile, per esempio $(-2,0,-4,2)$ non esiste in $F$ ma in $E$ si 

## Siano $U$ e $W$ due sottospazi di $R^3$ tali che $$U=Span\{\begin{pmatrix}1\\1\\0 \end{pmatrix},\begin{pmatrix}2\\1\\3 \end{pmatrix}\} \quad e \quad W=Span\{\begin{pmatrix}2\\1\\0 \end{pmatrix},\begin{pmatrix}-4\\-2\\0 \end{pmatrix}\}$$ Si determini una base di $U$, $W$, e $U \cap W$

- Notiamo subito che lo Span di $U$ può fare già da base, di $Dim(Span(U))=2$, per $W$ invece la questione è diversa, essendo uno il prodotto per scalare dell'altro. Di conseguenza una possibile base potrebbe essere anche solo il primo vettore, da noi scelto(si poteva anche scegliere il secondo).
- Ora bisogna trovare una base di $U \cap W$. Essendo $\cap$ ciò ci fa capire immediatamente che ciò che stiamo andando a cercare è un sottospazio vettoriale di dimensione $1$ dove il sottospazio corrisponde ai vettori presenti in entrambi i sottospazi. Per questo possiamo scriverlo come:
$$a\begin{pmatrix}1\\1\\0 \end{pmatrix}+b\begin{pmatrix}2\\1\\3 \end{pmatrix}=c\begin{pmatrix}2\\1\\0 \end{pmatrix}$$ il che vuol dire:
$$\begin{cases}a+2b=2c\\a+b=c\\3b=0\end{cases}\rightarrow\begin{cases}a=2c\\a=c\\b=0\end{cases}$$
in questo caso $a=b=c=0$ e di conseguenza l'unica soluzione dell'esercizio è il vettore nullo

## In $R^3$ sono dati: Il sottospazio E delle soluzioni dell’equazione x + y − z = 0 . Il sottospazio F generato dai vettori (2,4,3),(1,3,1) . Determinare una base e la dimensione di E . Trovare una base e la dimensione di E ∩ F . Trovare una base e la dimensione di E + F .

- Partiamo trovando il sottospazio $E$:
$$z=x+y \text{ due variabili libere per il rango 1 } (a,b,a+b)$$
$$\text{quindi diventa: }\begin{pmatrix}a\\b\\a+b \end{pmatrix}=a\begin{pmatrix}1\\0\\1\end{pmatrix}+b\begin{pmatrix}0\\1\\1\end{pmatrix}$$

quindi la nostra base risulta essere $\begin{pmatrix}1\\0\\1\end{pmatrix},\begin{pmatrix}0\\1\\1\end{pmatrix}$ con dimensione 2.

dobbiamo ora trovare una base e la dimensione di $E \cap F$ come nell'esercizio precedente.
$$a\begin{pmatrix}1\\0\\1\end{pmatrix}+b\begin{pmatrix}0\\1\\1\end{pmatrix}=c\begin{pmatrix}2\\4\\3\end{pmatrix}+d\begin{pmatrix}1\\3\\1\end{pmatrix}$$
$$\begin{cases}a=2c+d\\b=4c+3d\\a+b=3c+d\rightarrow2c+d+4c+3d=3c+d\end{cases}=\begin{cases}a=2c+d\\b=4c+3d\\3d=-3c\rightarrow d=-c\end{cases}=$$
$$\begin{cases}a=c\\b=c\\d=-c\end{cases}$$
- Abbiamo quindi trovato i valori che $a,b,c,d$ devono avere per poter avere come risultato i vettori presenti in entrambi i sottospazi
- Quindi il risultato si dimostra essere:
$$c\begin{pmatrix}1\\0\\1\end{pmatrix}+c\begin{pmatrix}0\\1\\1\end{pmatrix}=c\begin{pmatrix}1\\1\\2\end{pmatrix}$$
quindi $\begin{pmatrix}1\\1\\2\end{pmatrix}$ funge da base per $E \cap F$ con conseguente dimensione 1.
Dobbiamo ora trovare però base e dimensione di $E + F$ 
- Per farlo in questo caso il procedimento è differente.
- Passo numero 1 da fare è trovare la dimensione avendo $E \cap F$ tramite la formula
$$Dim(E)+Dim(F)-Dim(E\cap F)=Dim(E+F)= 2+2-1=3$$
- Ora sappiamo la dimensione, quindi dai 4 vettori sopra ce ne aspettiamo solo 3 lin. indip. infatti:
$$\begin{pmatrix}2\\4\\3\end{pmatrix}-\begin{pmatrix}1\\0\\1\end{pmatrix}-\begin{pmatrix}0\\1\\1\end{pmatrix}=\begin{pmatrix}1\\3\\1\end{pmatrix}$$
Quindi la base di $E+F$ sarà composta da: $\begin{pmatrix}2\\4\\3\end{pmatrix},\begin{pmatrix}1\\0\\1\end{pmatrix},\begin{pmatrix}0\\1\\1\end{pmatrix}$
## Si considerino i seguenti vettori di $R^4$: 
$v_1=(0,1,-2,1)\quad v_2=(1,0,2,-1)\quad v_3=(3,2,2,-1) \quad v_4=(0,0,1,0) \quad v_5=(0,0,0,1)$
## Trovare la dimensione e una base di $U=Span\{v_1,v_2\}\cap Span\{v_2,v_3,v_4\}$
$$a\begin{pmatrix}0\\1\\-2\\1\end{pmatrix}+b\begin{pmatrix}1\\0\\2\\-1\end{pmatrix}=c\begin{pmatrix}1\\0\\2\\-1\end{pmatrix}+d\begin{pmatrix}3\\2\\2\\-1\end{pmatrix}+e\begin{pmatrix}0\\0\\1\\0\end{pmatrix}$$
$$\begin{cases}b=c+3d\\a=2d\\-2a+2b=2c+2d+e\\a-b=-c-d\end{cases}=\begin{cases}b=c+3d\\a=2d\\-4d+2c+6d=2c+2d+e\rightarrow e=0\\2d-c-3d=-c-d\rightarrow0=0\end{cases}=\begin{cases}b=c+3d\\a=2d\\ e=0\\d=\lambda\\c=\theta\end{cases}=\begin{cases}b=\theta+3\lambda\\a=2\lambda\\ e=0\\d=\lambda\\c=\theta\end{cases}$$

- Assegnando un qualunque valore a $c$ e $d \in R$ chiamati $\theta$ e $\lambda$ otteniamo:
$$\theta+3\lambda\begin{pmatrix}1\\0\\2\\-1\end{pmatrix}+2\lambda\begin{pmatrix}0\\1\\-2\\1\end{pmatrix}=\begin{pmatrix}\theta+3\lambda\\2\lambda\\2\theta+2\lambda\\-\theta-\lambda\end{pmatrix}=\theta\begin{pmatrix}1\\0\\2\\-1\end{pmatrix}+\lambda\begin{pmatrix}3\\2\\2\\-1\end{pmatrix}$$

- $v_2\:e \: v_3$ fungono quindi da base di dimensione 2 per l'insieme $U$

## Verificare che sono sottospazi e trovare base di $S\cap T$ e $S+T$
$$S=\{(x,y,z,w): x+z=0,\:3y-w=0\} \quad e \quad T=\{(x,y,z,w): x+z=0,\:y+2w=0\}$$

$$S=\begin{cases}x+z=0\\3y-w=0\end{cases}=\begin{cases}x=-z\\ w=3y\end{cases}=(-z,y,z,3y)=(-a,b,a,3b)=a\begin{pmatrix}-1\\0\\1\\0\end{pmatrix}+b\begin{pmatrix}0\\1\\0\\3\end{pmatrix}$$
$$T=\begin{cases}x+z=0\\y+2w=0\end{cases}=\begin{cases}x=-z\\y=-2w\end{cases}=(-z,-2w,z,w)=(-a,-2b,a,b)=a\begin{pmatrix}-1\\0\\1\\0\end{pmatrix}+b\begin{pmatrix}0\\-2\\0\\1\end{pmatrix}$$
Essendo entrambi chiusi rispetto a somma e prodotto scalare sono sottospazi vettoriali

- Calcoliamo ora $S\cap T$
$$a\begin{pmatrix}-1\\0\\1\\0\end{pmatrix}+b\begin{pmatrix}0\\1\\0\\3\end{pmatrix}=c\begin{pmatrix}-1\\0\\1\\0\end{pmatrix}+d\begin{pmatrix}0\\-2\\0\\1\end{pmatrix}$$
$$\begin{cases}a=c\\b=-2d\\3b=d\end{cases}=\begin{cases}a=c\\b=-2d\\d=0\end{cases}=\begin{cases}a=\theta\\c=\theta\\b=0\\d=0\end{cases}$$
$$\theta\begin{pmatrix}-1\\0\\1\\0\end{pmatrix}=\theta\begin{pmatrix}-1\\0\\1\\0\end{pmatrix}$$
- Quindi con dimensione 1 $\begin{pmatrix}-1\\0\\1\\0\end{pmatrix}$ funge da base per $S\cap T$
- $Dim(S+T)=Dim(S)+Dim(T)-Dim(S\cap T)=2+2-1=3$ 
- la base quindi per $S+T$ risulta essere:
$$\begin{pmatrix}-1\\0\\1\\0\end{pmatrix},\begin{pmatrix}0\\1\\0\\3\end{pmatrix},\begin{pmatrix}0\\-2\\0\\1\end{pmatrix}$$

---
## Lo spazio $W=Span\{v_1,v_2\}+Span\{v_2,v_3,v_4\}$ può coincidere con $R^4$?
- Per risolverlo ci basta usare la formula: $Dim(Span_1)+Dim(Span_2)-Dim(Span_1\cap Span_2)=Dim(Span_1+Span_2)= 2+3-2=3$
	- Il fatto che le dimensioni non coincidano ci permette di capire che non possono coincidere
## Trovare una base e dimensione di $W$
La base del nostro sottospazio corrisponde ad $\{v_1,v_2,v_4\}$  essendo $v_3=2v_1+3v_2$ 

## Calcolare somma e intersezione del seguente sottospazio di $R^4$
$V=Span\{(1,0,0,1),(0,1,0,0)\} \quad W=Span\{(0,1,0,1),(1,0,0,0)\}$
$$V\cap W=a\begin{pmatrix}1\\0\\0\\1\end{pmatrix}+b\begin{pmatrix}0\\1\\0\\0\end{pmatrix}=c\begin{pmatrix}0\\1\\0\\1\end{pmatrix}+d\begin{pmatrix}1\\0\\0\\0\end{pmatrix}=$$
$$\begin{cases}a=d\\b=c\\a=c\\d=c\end{cases}=c\begin{pmatrix}1\\0\\0\\1\end{pmatrix}+c\begin{pmatrix}0\\1\\0\\0\end{pmatrix}=c\begin{pmatrix}1\\1\\0\\1\end{pmatrix}$$

Dove $\begin{pmatrix}1\\1\\0\\1\end{pmatrix}$ funge da base con dimensione 1.
Per quanto riguarda la somma invece sappiamo intanto che $2+2-1=3$ 
$$V+W=\begin{pmatrix}0\\1\\0\\0\end{pmatrix},\begin{pmatrix}0\\1\\0\\1\end{pmatrix},\begin{pmatrix}1\\0\\0\\0\end{pmatrix}$$
