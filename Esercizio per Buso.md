$$\begin{pmatrix}1&0&t\\1&2&1\\2&0&-1\end{pmatrix}$$
Per quali valori di $t$ la matrice non è invertibile??
dobbiamo calcolare il **determinante** della matrice e vedere per quali valori di $t$ esso è uguale a zero.

Il **determinante** lo si calcola velocemente usando il Teorema di **Sarrus**:

$$det(A)=1*det(\begin{pmatrix}2&1\\0&-1\end{pmatrix})-0*det(\begin{pmatrix}1&1\\2&-1\end{pmatrix})+t*det(\begin{pmatrix}1&2\\2&0\end{pmatrix})$$

Risolvendo troviamo che: $-2-4t=0$
Quindi per $t=-\frac{1}{2}$ la matrice non è invertibile.

Ora cerchiamo i valori di $t$ per cui gli **autovalori** sono tutti reali.
$$B=\begin{pmatrix}1-\lambda&0&t\\1&2-\lambda&1\\2&0&-1-\lambda\end{pmatrix}$$

Per trovare gli autovalori, Troviamo il determinante della matrice $B$:
$$det(A)=1*det(\begin{pmatrix}2-\lambda&1\\0&-1-\lambda\end{pmatrix})+t*det(\begin{pmatrix}1&2-\lambda\\2&0\end{pmatrix})$$

Continuiamo con i calcoli:

$$det(A)=(2-\lambda)(-1-\lambda)+t(-4+2\lambda)$$
$$= -2+\lambda-2\lambda+\lambda^2-4t+2\lambda t$$
$$=\lambda^2-\lambda+2\lambda t -4t-2$$
Da qui credo di dover raccogliere $\lambda$:

$$\lambda^2+\lambda(-1+2t)-4t-2 = 0$$
$$=\lambda^2+\lambda(-1+2t) = 4t+2$$
$$=\lambda(\lambda+(-1+2t)) = 4t+2$$