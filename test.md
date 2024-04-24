 Un altro insieme è costituito da
$$V = \{(1,1,0),(0,1,1),(5,1,1),(1,2,1)\}$$
- Poniamo tutto a sistema
$$\begin{cases}a+5c+d=0\\a+b+c+2d=0\\b+c+d=0\end{cases}$$
- Non è possibile risolvere un sistema a 4 incognite con 3 equazioni, sono dipendenti. Notiamo come $(1,2,1)$ sia combinazione lineare di $(1,1,0)+(0,1,1)$ e quindi possa essere rimosso. Se ora proviamo a fare il sistema
$$\begin{cases}a+5c=0\\a+b+c=0\\b+c=0\end{cases}\rightarrow \begin{cases}a+5c = 0\\a-c+c=0\\b=-c\end{cases}\rightarrow\begin{cases}c=0\\a=0\\b=0\end{cases}$$
- I tre vettori risultano linearmente indipendenti, posso usarli come base se sono anche generatori, e con piacere per noi il rango della matrice è
$$\begin{pmatrix}1&1&0\\0&1&1\\5&1&1\end{pmatrix}=\begin{pmatrix}1&1&0\\0&1&1\\0&-4&1\end{pmatrix}=\begin{pmatrix}1&1&0\\0&1&1\\0&0&5\end{pmatrix}=3$$
- I vettori sono generatori dello spazio in $R^3$ 