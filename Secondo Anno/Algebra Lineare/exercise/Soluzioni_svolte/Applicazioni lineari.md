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

risulta esserci il valore nullo, di conseguenza si controlla se somma e moltiplicazione sono preservate
