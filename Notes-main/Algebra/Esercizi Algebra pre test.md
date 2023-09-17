Interessante link: https://www.dropbox.com/sh/mmnv9peish4ix9h/AAB3t_mvYBpvWM6bM-q9ZPsYa?dl=0
>Trovare gli autovalori, determinare le dimensioni degli autospazi associati agli autovalori e determinare gli autovettori associati ad uno dei due autovalori.
>$$\begin{pmatrix}1&0&2\\1&0&1\\0&0&1\end{pmatrix}$$
> Cominciamo con trovare gli autovalori, per farlo abbiamo bisogno di trovare il determinante senza lambda:
> $$\begin{pmatrix}1-\lambda&0&2\\1&0-\lambda&1\\0&0&1-\lambda\end{pmatrix}$$
> $$det(A-\lambda I) = Sarrus$$
> $$1-\lambda *-\lambda * 1-\lambda+0+0-0-0-0$$
> $$diventa$$
> $$-\lambda(1-\lambda)^2$$
> Ponendo il determinante uguale a zero, troviamo gli autovalori:
> $$-\lambda(1-\lambda)^2=0=>\lambda={0,1}$$
> $0$ e $1$ sono i due autovalori che stiamo cercando.
> sostituendo poi con i valori trovati $\lambda$ poi troviamo autovettori ed autospazi. 

> Date le rette
> $r_1:\begin{cases}x=1+3t\\y=3t\\z=2+t\end{cases}r_2:\begin{cases}x=2r\\y=5+r\\z=2\end{cases}$
> Dimostrare che sono coincidenti e si determini il punto di incidenza della retta $r_1$ con il piano $\pi$ di equazione lineare $x+2y-3z-1=0$.
>
>Per dimostare che sono coincidenti basta fare:
>$$\begin{cases}1+3t=2r\\3t=5+r\\2+t=2\end{cases}$$
>$$t=0$$
>$$0=5+r=>r=-5$$
>$$1=-10$$
>
>Dai risultati si deduce che le due funzioni non sono coincidenti.
>Per trovare invece la coincidenza nel piano $\pi$, dobbiamo sostituire le varie incognite nell'equazione lineare con quelle nel sistema, trovando:
>$$(1+3t)+2(3t)-3(2+t)-1=0$$
>da cui $$1+3t+6t-6-3t-1=0$$
>$$6t-6=0$$
>$$t=1$$
>da qui basta sostituire $t$ nel sistema per trovare il punto di incidenza tra retta e piano.
>Determinare per quali valori si ammette soluzione in $Ax=b$:
>$$A:\begin{pmatrix}-1&2&0\\0&1&-1\\0&0&2t\end{pmatrix}b:\begin{pmatrix}1\\1\\1\end{pmatrix}$$
>$det(A)=2t$. quindi tutto varia al variare di $t$, il determinante deve essere diverso da $0$ o non abbiamo soluzioni. $t$ deve essere diverso da zero altrimenti abbiamo un termine nullo cosa che non abbiamo in $b$ avendo il terzo valore ad $1$.
>immaginiamo ora la possibile $x$:
>$$\begin{cases}-x+2y=1\\y-z=1\\2tz=1\end{cases}$$
>$$z=\frac{1}{2t}$$
>$$y=\frac{2t+1}{2t}$$
>$$-x+2\frac{2t+1}{2t}=1=>$$
>$$x=-1+2\frac{2t+1}{2t}=>x=-1+\frac{2t+1}{t}=>x=\frac{t+1}{t}$$

> dai punti $A=(1,2)B=(-1,3)$ trova l'equazione parametrica.
> $(-1,3)-(1,2)=(-2,1)=(x,y)$
> Si prendono le coordinate di $x_0$ che corrisponde ad $A$ e per le incognite si mette invece le coordinate del risultato $(-2,1)$.
> $\begin{cases}x=x_0+x\\ y=y_0+y\end{cases}=\begin{cases}x=1-2t\\ y=2+t\end{cases}$
> Per trovare in caso anche l'equazione lineare, bisogna prima trovare $t$ e poi sostituirlo:
> $$y=2+t=>t=y-2$$
> $$x=1-2(y-2)=>x=1+4-2y$$
> $$x=-2y+5=>x+2y-5=0$$
> equazione trovata!
> Nel caso invece si tratti di un vettore e di un punto, le coordinate del punto vengono prese come $x_0$ mentre quelle del vettore come incognite $t$, per esempio, immaginiamo che abbiamo il punto di coordinate $(2,3)$ parallele al vettore $(-1,2)$:
> l'equazione parametrica sará
> $$\begin{cases}x=2-t\\y=3+2t\end{cases}$$
> per quanto riguarda invece l'equazione cartesiana/lineare
> $$\begin{cases}x=2-t\\y=3+2t\end{cases}$$
> $$t=2-x$$
> $$y=3+2(2-x)$$
> $$y=3+4-2x$$
> $$2x+y-7=0$$$\begin{cases}2x+y+z=1\\4x+2y+(k+2)z=2\\2x+3y+(1+2k)z=1+2k\end{cases}$
> Risolvere il sistema lineare posto sopra.
> Trasformiamolo in una matrice con i relativi valori:
> $$\begin{pmatrix}2&1&1&1\\4&2&k+2&2\\2&3&1+2k&1+2k\end{pmatrix}$$
> $$\begin{pmatrix}2&1&1&1\\0&0&k&0\\2&3&1+2k&1+2k\end{pmatrix}$$
>$$\begin{pmatrix}2&1&1&1\\0&0&k&0\\0&2&2k&2k\end{pmatrix}$$
>$$\begin{pmatrix}2&1&1&1\\0&2&2k&2k\\0&0&k&0\end{pmatrix}$$
>$$\begin{cases}2x+y+z=1\\2y+2kz=2k\\kz=0\end{cases}$$
>$$\begin{cases}2x+y+z=1\\2y+2kz=2k\\z=0<=\end{cases}$$
>$$\begin{cases}2x+y+z=1\\2y+0=2k <=\\z=0\end{cases}$$
>$$\begin{cases}2x+y+z=1\\y=k <=\\z=0\end{cases}$$
>$$\begin{cases}x=\frac{1-k}{2} <=\\y=k\\z=0\end{cases}$$Se sostituiamo poi $k$ con $0$ la matrice invece diventa:
>$$\begin{pmatrix}2&1&1&1\\0&2&0&0\\0&0&0&0\end{pmatrix}$$
>da cui ricaviamo:
>$$\begin{cases}2x+y+z=1\\2y=0\end{cases}$$
>$$\begin{cases}2x+z=1\\y=0\end{cases}$$
>$$\begin{cases}2x+z=1\\y=0\\x=t\\z=1-2t\end{cases}$$
>### !! Importante, perché devo mettere $x=t$ e non $z=t$? Cambia qualcosa?