## Esercizio 1
- Risolvere il seguente sistema lineare:
$$\begin{cases}2x+y+z=1\\4x-y+z=-5\\y-x+2z=5\end{cases}$$

Per risolvere il seguente sistema lineare utilizzeremo il metodo di Gauss:

$$\begin{pmatrix}2&1&1&1\\4&-1&1&-5\\-1&1&2&5\end{pmatrix}=\begin{pmatrix}2&1&1&1\\0&-3&-1&-7\\-1&1&2&5\end{pmatrix}=\begin{pmatrix}0&3&5&11\\0&-3&-1&-7\\-1&1&2&5\end{pmatrix}$$
$$=\begin{pmatrix}0&0&4&4\\0&-3&-1&-7\\-1&1&2&5\end{pmatrix}=\begin{pmatrix}-1&1&2&5\\0&-3&-1&-7\\0&0&4&4\end{pmatrix}$$

tutto ciò viene poi reinterpretato in:
$$\begin{cases}-x+y+2z=5\\-3y-z=-7\\z=1\end{cases}=\begin{cases}x=-1\\y=2\\z=1\end{cases}$$

Quindi $x=-1,y=2,z=1$. Per verificare basta sostituirli al sistema iniziale

---
## Esercizio 2
- Risolvere il seguente sistema lineare:
$$\begin{cases}x-y+z+2w=-1\\-x-5y+3z=-3\\x+2y-z+w=1\\2x+z+5w=-1\end{cases}$$

Per risolvere questo esercizio è necessario riportare l'intero sistema in una matrice per poi applicare l'algoritmo di Gauss.

$$\begin{pmatrix}1&-1&1&2&-1\\-1&-5&3&0&-3\\1&2&-1&1&1\\2&0&1&5&-1\end{pmatrix}=\begin{pmatrix}1&-1&1&2&-1\\0&-6&4&2&-4\\1&2&-1&1&1\\2&0&1&5&-1\end{pmatrix}=\begin{pmatrix}1&-1&1&2&-1\\0&-6&4&2&-4\\0&3&0&-1&0\\2&0&1&5&-1\end{pmatrix}$$
$$=\begin{pmatrix}1&-1&1&2&-1\\0&0&4&0&-4\\0&3&0&-1&0\\2&0&1&5&-1\end{pmatrix}=\begin{pmatrix}1&-1&1&2&-1\\0&0&4&0&-4\\0&3&0&-1&0\\0&2&-1&1&1\end{pmatrix}=\begin{pmatrix}1&-1&1&2&-1\\0&3&0&-1&0\\0&0&4&0&-4\\0&0&0&\frac{5}{3}&0\end{pmatrix}$$

Ed ora trasformiamo nuovamente in un sistema:
$$\begin{cases}x-y+z-2w=-1\\3y=w\\z=-1\end{cases}=\begin{cases}x-y+z-2w=-1\\3y=w\\z=-1\\w=0\end{cases}=\begin{cases}x=0\\y=0\\z=-1\\w=0\end{cases}$$
Se sostituiamo il sistema risulta corretto

>📝Il risultato del professore è diverso, z e w risultato essere dei parametri liberi con x e y che prendono valori diversi da quelli che ho trovato. Chi dei due ha ragione? Vanno bene entrambe? Nessuno lo saprà mai

--- 
## Esercizio 3
- Risolvere al variare di $m \in R$ il seguente sistema
$$\begin{cases}mx+(m-1)y=m+2\\(m+1)x-my=5m+3\end{cases}$$

Risolviamo sempre applicando lo stesso metodo:
$$\begin{pmatrix}m&m-1&|&m+2\\m+1&-m&|&5m+3\end{pmatrix}=II-(I*\frac{m+1}{m})=\begin{pmatrix}m&m-1&|&m+2\\0&-m(\frac{(m-1)(m+1)}{m})&|&5m+3(\frac{(m+2)(m+1)}{m})\end{pmatrix}$$

Per semplicità risolviamo anche i valori interni alla matrice:
$$-m(\frac{(m-1)(m+1)}{m})=-((m-1)(m+1))=-(m^2-1)=-(m^2)+1$$$$5m+3(\frac{(m+2)(m+1)}{m})=5m+3(\frac{m^2+3m+2}{m})=5m+3m+9+\frac{6}{m}$$
Quindi ora troviamo $x$ in funzione di $m$ 
$$m=0 \qquad \begin{pmatrix}0&-1&2\\0&1&9\end{pmatrix}$$
> # 🏴 da rifare con rouce o come cazzo si scrive

---
## Esercizio 8
- Si consideri la seguente applicazione lineare $T:R^4\rightarrow R^3$ definita da:
$$\begin{pmatrix}\alpha&0&1&1\\\alpha-1&-1&0&1\\2\alpha&0&2&1\end{pmatrix}$$
stabilire per quali valori di $\alpha \in R$ l'applicazione è iniettiva, suriettiva invertibile e con $KerT=1$

Per essere iniettiva vuol dire che non ci devono essere vettori in $R^4$ che hanno soluzione uguale. Per farlo usiamo il calcolo del determinante:

$$\begin{pmatrix}\alpha&0&1&1\\\alpha-1&-1&0&1\\2\alpha&0&2&1\end{pmatrix}=\begin{pmatrix}\alpha&0&1&1\\0&-1&\frac{1-\alpha}{\alpha}&1+\frac{1-\alpha}{\alpha}\\2\alpha&0&2&1\end{pmatrix}=\begin{pmatrix}\alpha&0&1&1\\0&-1&\frac{1-\alpha}{\alpha}&1+\frac{1-\alpha}{\alpha}\\0&0&0&-1\end{pmatrix}$$
questo vuol dire che se $\alpha \neq 0$ il rango è tre, quindi la funzione risulta suriettiva.  In questo caso quindi è impossibile però che sia iniettiva, riducendo lo spazio di partenza. cosa succede però se $\alpha=0$? La funzione non ha più rango 3, di conseguenza non è nemmeno suriettiva. Quando il determinante della matrice risulta $\neq 0$ allora la matrice è anche invertibile. Il $KerT=1$ quando $\alpha \neq 0$.