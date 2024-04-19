---

---
## Numeri Complessi

- per le altre formule di questo genere guardo il punto 7
$$
\theta := Arg(z) = 
\begin{cases}
\frac{\pi}{2} \qquad \text{se $a=0$, $b > 0$} \\
\frac{3\pi}{2} \qquad \text{se $a=0$, $b < 0$} \\
\text{non definito} \qquad \text{se $a=0$, $b = 0$} \\
\arctan({\frac{b}{a}}) \qquad \text{se $a > 0$, $b \geq 0$} \\
\arctan({\frac{b}{a}})+2\pi \qquad \text{se $a < 0$, $b < 0$} \\
\arctan({\frac{b}{a}})+\pi \qquad \text{se $a < 0$, b qualsiasi} \\
\end{cases}
$$

### 1. Determinare parte reale e parte immaginaria del seguente numero complesso $z = \frac{i-4}{2i-3}$
- Ci accorgiamo che al denominatore abbiamo una parte immaginaria, quindi fattorizziamo
$$
z = \frac{(i-4)(2i+3)}{(2i-3)(2i+3)} = \frac{2i^2+3i-8i-12}{4i^2-9-6i+6i} 
$$
- Ora possiamo semplificare $i^2 = -1$
$$
z = \frac{2i^2+3i-8i-12}{4i^2-9-6i+6i}  = \frac{2(-1)-5i-12}{4(-1)-9}
$$
$$
z = \frac{2(-1)-5i-12}{4(-1)-9} = \frac{-14-5i}{-13} = \frac{14+5i}{13}
$$
- Quindi la parte reale corrisponde $Re(z) = \frac{14}{13}$ e la parte immaginaria $Im(z) = \frac{5}{13}$

### 2. Portare $z = \frac{3+2i}{i-2}$ in forma algebrica
- Notiamo al denominatore un termine immaginario $\rightarrow$ fattorizziamo
$$
	z = \frac{3+2i}{i-2} = \frac{(3+2i)(i+2)}{(i-2)(i+2)} = \frac{3i+2i^2+6+4i}{i^2+21-2i-4}
$$
- Semplifichiamo il tutto, compresa anche la parte immaginaria
$$
	z = \frac{3i+2i^2+6+4i}{i^2+21-2i-4} = \frac{2i^2+7i+6}{i^2-4} = \frac{2(-1)+7i+6}{(-1)-4} = \frac{7i+4}{-5}
$$
- Abbiamo quindi che $Re(z) = -\frac{4}{5}$ e $Im(z) = -\frac{7}{5}$
### 3. Portare $z = \frac{i+1}{i-1}$ in forma  algebrica
$$
	z = \frac{i+1}{i-1} = \frac{(i+1)(i+1)}{(i-1)(i+1)} = \frac{i^2+i+i+1}{i^2+i-i-1} = \frac{i^2+2i+1}{i^2-1} = \frac{2i}{-2} = -i
$$
- In questo esercizio quindi $Re(z) = 0$ e $Im(z) = -1$ 
### 4. Portare in forma algebrica $z = (\sqrt{2}-1)-i(1-\sqrt{2})$
- Non ci sono semplificazioni, risolviamo le parentesi  
$$
z = \sqrt{2}-1-i+i\sqrt{2}
$$
- Proviamo moltiplicare tutto per $-1$
$$
z = (-1)(\sqrt{2}-1)-i(1-\sqrt{2})(-1) = (-1)(\sqrt{2}-1)-i(\sqrt{2}-1) 
$$
- Divido per $\sqrt{2}-1$ 
$$
	z = -1-i
$$
- $Re(z)=-1 \quad\quad Im(z)=-1$  
### 5. Forma algebrica di $z=\overline{(1-i)^3}$ 
- Scomponiamo la potenza così da avere $i$ al quadrato
$$
z = \overline{(1-i)^2(1-i)} = \overline{(i^2+1-2i)(1-i)} = 
$$
$$
\overline{(-1+1-2i)(1-i)} = \overline{-1+i+1-i-2i-2} = 
$$
$$ 
	\overline{-2i-2} = -2+2i 
$$
### 6. Calcolare modulo e argomento di $z = -3i$
- $|z| = \sqrt{x^2+y^2}$  quindi
$$
	|z| = \sqrt{0+(-3)^2} = \sqrt{9} = 3
$$
- L'argomento invece consiste in $\theta = arctan(Im(z)/Re(z))$  
$$
	\theta = arctan(-\frac{3}{0}) = arctan(0)
$$
$$
z = 3(0-i3) = 3(\cos{\theta} + i\sin{\theta})
$$
$$ 
\begin{cases}
\cos(\theta) = 0 \\ 
\sin(\theta) = -3 \\
\end{cases}
$$
- Di conseguenza l'angolo è $\frac{-3}{0}$, ovvero $-90$ gradi.
### 7. $z = -\sqrt{3}+i$ trovare modulo e argomento
$$
z = -\sqrt3 +i
$$
$$
\mid z \mid = \sqrt{\sqrt{3}^2+1} = \sqrt4 = 2
$$
$$
Arg(z) = \frac{1}{-\sqrt3} = \pi + \frac{1}{-\sqrt{3}} = 
$$
___
> qui sotto abbiamo il calcolo dell'argomento di un numero complesso,
> da imparare per trasformarlo in base alla situazione in cui mi trovo con l'esercizio


$$
\theta = Arg(z) \in (-\pi,\pi] \quad \text{sono quelle che userò sempre}
$$

$$
\theta := Arg(z) = 
\begin{cases}
\frac{\pi}{2} \qquad \text{se $a=0$, $b > 0$} \\
-\frac{\pi}{2} \qquad \text{se $a=0$, $b < 0$} \\
\text{non definito} \qquad \text{se $a=0$, $b = 0$} \\
\arctan({\frac{b}{a}}) \qquad \text{se $a > 0$, b qualsiasi} \\
\arctan({\frac{b}{a}})+\pi \qquad \text{se $a < 0$, $b \geq 0$} \\
\arctan({\frac{b}{a}})-\pi \qquad \text{se $a < 0$, $b < 0$} \\
\end{cases}
$$

$$
\theta = Arg(z) \in [0,2\pi)
$$

$$
\theta := Arg(z) = 
\begin{cases}
\frac{\pi}{2} \qquad \text{se $a=0$, $b > 0$} \\
\frac{3\pi}{2} \qquad \text{se $a=0$, $b < 0$} \\
\text{non definito} \qquad \text{se $a=0$, $b = 0$} \\
\arctan({\frac{b}{a}}) \qquad \text{se $a > 0$, $b \geq 0$} \\
\arctan({\frac{b}{a}})+2\pi \qquad \text{se $a < 0$, $b < 0$} \\
\arctan({\frac{b}{a}})+\pi \qquad \text{se $a < 0$, b qualsiasi} \\
\end{cases}
$$


___
### 8. module e argomento di $z = \frac{1+i\sqrt{3}}{1-i}$

- Necessita di essere fattorizzato avendo la parte immaginaria al denominatore
$$
z = \frac{1+i\sqrt{3}}{1-i} = \frac{1+i\sqrt{3}}{1-i} \frac{1+i}{1+i} = \frac{(1+i\sqrt{3})(1+i)}{1+i-i+1} = \frac{1+i+i\sqrt{3}-\sqrt{3}}{2}
$$
$$
z = \frac{1-\sqrt{3}+i(1+\sqrt{3})}{2}
$$

$$
\mid z \mid = \sqrt{(\frac{1-\sqrt{3}}{2})^2+(\frac{1+\sqrt{3}}{2}})^2 = \sqrt{\frac{1+3-2\sqrt{3}}{4}+\frac{1+3+2\sqrt{3}}{4}} = \sqrt{\frac{8}{4}} = \sqrt{2}
$$

$$
Arg(z) = arctan(\frac{1+\sqrt{3}}{2} : \frac{1-\sqrt{3}}{2}) = arctan(\frac{1+\sqrt{3}}{1-\sqrt{3}}) + \pi = \text{circa }1.833 
$$

### 9. Scrivere in forma trigonometrica il numero $z = -1+\sqrt{3}i$ 

- sapendo che $|z| = 2$ e $\theta = \arctan{-\sqrt3} = \frac{2\pi}{3}$ 
- La forma trigonometrica di un numero complesso è uguale a: $|z|(cos{(\theta)}+i\:sin{(\theta)})$
$$
z = 2(cos(\frac{2\pi}{3})+i\:sin(\frac{2\pi}{3})) = 2(-\frac{1}{2}+i\:\frac{\sqrt3}{2}) = -1+i\sqrt3
$$
___
> Attenzione all'esercizio precedente, forse non è corretto conseguenza di ciò andrebbe corretto: come fa la forma polare ad essere uguale alla forma algebrica??
___
### 10. Scrivere in forma trigonometrica il numero $z = 3 + 3i$
- Sappiamo che $|z| = \sqrt{9+9} = \sqrt{18}$ e $arctan(z) = \frac{\pi}{4}$
- Guardare punto precedente per la forma trigonometrica
$$
z = \sqrt{18}(cos(\frac{\pi}{4})+i\:sin(\frac{\pi}{4})) = \sqrt{18}(\frac{\sqrt2}{2}+i\frac{\sqrt2}{2})
$$

### 11. Calcolare $z^2,\:z^6,\:z^{22}$ di $z=-\frac{3}{\sqrt3}+\frac{1}{i}$ 
$$
z = -\frac{3}{\sqrt3} + \frac{1}{i} = -\frac{3}{\sqrt3} - i 
$$

- Troviamo modulo e argomento

$$
|z| = \sqrt{(-\frac{3}{\sqrt3})^2 + (-1)^2} = \sqrt4 = 2 \qquad Arg(z) = arctan(\frac{-1}{-\frac{3}{\sqrt3}}) = arctan(\frac{\sqrt3}{3})
$$
- noto che $a$ nell'argomento è negativo quindi devo aggiungere $\pi$ 
$$
Arg(z) = arctan(\frac{\sqrt3}{3})+\pi = \frac{7\pi}{6}
$$
- scrivo ora il numero in forma esponenziale
$$
	z = 2e^{\frac{7\pi}{6}i}
$$

- ora posso elevare alla seconda, sesta e ventiduesima

$$
z^2 = (2e^{\frac{7\pi}{6}i})^2 = 2^2 * (e^{\frac{7\pi}{6}i})^2 = 4e^{\frac{7\pi}{3}i}
$$
$$
z^6 = (2e^{\frac{7\pi}{6}i})^6 = 2^6 * (e^{\frac{7\pi}{6}i})^6 = 64e^{7\pi i}
$$
$$
z^{22} = (2e^{\frac{7\pi}{6}i})^{22} = 2^{22} * (e^{\frac{7\pi}{6}i})^{22} = 2^{22}e^{\frac{77}{3}i}
$$

> Sappiamo che 22 può essere visto come 11*2



## Vettori & co.
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

- Dati i seguenti vettori nello spazio
$v = (1,-1,-1)\quad e\quad w=(-2,2,0)$ 
- Calcolare
	- $v+w$
		- $z = v+w = (-1,1,-1)$
	- $v-2w$
		- $2w = (-4,4,0)\quad e \quad z = v-2w = (5,-5,-1)$ 
	- $-3v+\frac{1}{2}w$
		- $v =(-3,3,3)\quad e \quad w = (-1,1,0)\quad e \quad z=(-4,4,3)$

- Verificare se i seguenti vettori di $R^3$ sono linearmente indipendenti o meno
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

- Verificare se i seguenti vettori di $R^3$ sono linearmente dipendenti o indipendenti $$v1=(1,1,2), \quad v2=(0,2,2), \quad v3=(-1,3,2)$$In caso di dipendenza, trovare poi la relazione che permette di scrivere uno dei vettori come combinazione lineare degli altri due
	- $$\begin{cases}a-c=0\\ a+2b+3c=0\\ 2a+2b+2c=0\end{cases}$$ $$\begin{cases}a=c\\4c+2b=0\end{cases}$$
	- Con questo, noi sappiano adesso che ci sono infinite soluzioni e di conseguenza non sono tutti indipendenti, ciò vuol dire che uno dei tre vettori può essere rappresentato come combinazione lineare degli altri due vettori
	- se noi facciamo infatti $2v_2+(-1)v_3$ il risultato sarà esattamente $v_1$.
- Dato il vettore $v=(1,-1,2)$ trovare altri due vettori di $R^3$ che messi assieme a $v$ diano tre vettori linearmente indipendenti.
	- Per farlo, dobbiamo prendere due componenti del vettore e usarle per creare due nuovi vettori a nostro piacimento, es, $w=(1,2,0), \quad z=(1,-2,0)$.
	- Ora per sicurezza controlliamo che siano effettivamente linearmente indipendenti tra di loro tramite il sistema
$$\begin{cases}a+b+c=0 \qquad\rightarrow b = -c \qquad\rightarrow b = 0\\-a+2b-2c=0 \qquad\rightarrow 4c = 0 \qquad\rightarrow c = 0\\2a=0 \qquad\rightarrow a=0\end{cases}$$
- Tutti i vettori risultano essere indipendenti tra loro

- Dati i seguenti vettori di $R^3$ $$v_1=(3,1,k),\quad v_2=(-k,1,0), \quad v_3=(2k,-2,k)$$ stabilire per quali valori di $k\in R$ i vettori sono lin. indip. e per quando invece sono dipendenti,  stabilire quanti tra loro sono linearmente indipendenti
	- Bisogna mettere a sistema i vettori e analizzare come variano al variare di $k$
$$\begin{cases}3x-ky+2kz=0 \qquad\rightarrow -y-ky+\frac{2}{3}ky=0 \qquad\rightarrow\frac{-3-3k+2ky}{3} = 0 \qquad\rightarrow\\1x+1y-2z=0 \qquad\rightarrow z=\frac{1}{3}y\\ kx+kz=0 \qquad\rightarrow x = -z \qquad\rightarrow x=-\frac{1}{3}y\end{cases}$$
$$\begin{cases}\frac{-3-3k+2ky}{3} = 0 \qquad\rightarrow y=\frac{3+3k}{2k}\\ z=\frac{1}{3}y\\ x=-\frac{1}{3}y\end{cases}$$
- ora che abbiamo $y=\frac{3+3k}{2k}$ non rimane che vedere cosa succede al variare di $k$
	- se $y = 0$ allora $\frac{3+3k}{2k} = 0$ questo vuol dire che $3+3k=0$ e quindi
- # Da FINIRE È in qualche modo sbagliato
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