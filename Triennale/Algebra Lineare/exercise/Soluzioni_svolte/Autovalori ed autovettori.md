## Esercizio 1
- Trovare gli autovalori ed autovettori delle seguenti matrici
$$\begin{pmatrix}2&1\\-4&-2\end{pmatrix}$$
Per farlo dobbiamo usare la formula per cui $Av=\lambda_0v\rightarrow Av-\lambda_0v=0\rightarrow (A-\lambda_0Id_n)v=0$  per cui $det(A-\lambda_0Id_n)$ equivale ad un polinomio

$$\begin{pmatrix}2&1\\-4&-2\end{pmatrix}-\lambda\begin{pmatrix}1&0\\0&1\end{pmatrix}=\begin{pmatrix}2-\lambda&1\\-4&-2-\lambda\end{pmatrix}=(2-\lambda)(-2-\lambda)+4=$$
$$\lambda^2=0 \text{ Ricordo che cerchiamo i valori per cui diventa 0}$$ 
>📝Importante sottolineare che qua abbiamo solo teoria di come si risolve, in pratica non ho esattamente capito a cosa corrisponde but that's ok!

ora per $\lambda=0$ cerchiamo gli autovettori $\begin{pmatrix}x\\y\end{pmatrix}$ per cui $\begin{pmatrix}2&1\\-4&-2\end{pmatrix}\begin{pmatrix}x\\y\end{pmatrix}=0$
$$\begin{cases}2x+1y=0\\-4x-2y=0\end{cases}\rightarrow\begin{cases}y=-2x\\-2x=y\end{cases}$$ ciò vuol dire che un parametro è libero, scegliamo $x$ quindi $y=\frac{1}{2}x$ 
e la base risultante sarà pari a $\begin{pmatrix}x\\\frac{1}{2}x\end{pmatrix}=\begin{pmatrix}1\\\frac{1}{2}\end{pmatrix}$
$A$ non è diagonalizzabile.
