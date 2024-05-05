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

## Esercizio svolto a lezione il 22/04/24
---
$$\begin{cases}x-2y-z=0\\
kx-ky+w=0\\
y+kz_w=0\end{cases}$$

- Trovare il numero di soluzioni del sistema al variare di $k \in R$.

$$\begin{pmatrix}1&-2&-1&0\\k&-k&0&1\\0&1&k&1\end{pmatrix}$$
- Mi riporto alla situazione di creamer cerco una sottomatrice quadrata

$$\begin{pmatrix}-1&0\\0&1\end{pmatrix}\rightarrow \text{determinante = $-1$}$$
- Non va bene il determinante
$$\begin{pmatrix}1&-1&0\\k&0&1\\0&k&1\end{pmatrix}\rightarrow\text{determinante = $0$}$$
- Determinante a zero non va bene, deve dipendere da $k$, prendo allora

$$\begin{pmatrix}-2&-1&0\\-k&0&1\\1&k&1\end{pmatrix}\rightarrow\text{determinante = $k-1$}$$
- $k\neq1$ quindi $A_3$ è non singolare $rg(A)=3$. Nota come *matrice efficace*
- Ogni colonna eliminata corrisponde al fatto che la variabile perde il suo status e diventa un parametro libero
- Ogni riga eliminata corrisponde ad un'equazione eliminata perché ridondante

$$\begin{cases}-2y-z=-x\\-ky+w=-ky\\y+kz+w=0\end{cases}$$
- ⬆ $x$ diventa la colonna dei coefficienti nel sistema
- Tre equazioni e 3 incognite
- Applico Cramer

$$y=\frac{\begin{pmatrix}-x&-1&0\\-kx&0&1\\0&k&1\end{pmatrix}}{k-1}=\frac{0}{k-1}=0$$
$$\begin{cases}-z=-x\\w=-kx\\kz+w=0\end{cases}$$
- Quindi le soluzioni finali sono $(0,x,-kx)\quad x\in R\:\text{per }k\neq 1$ 
- Per $k=1$, il rango è 2. La matrice efficace è la matrice di partenza 2x2 $\begin{pmatrix}-1&0\\0&1\end{pmatrix}$ 
	- Il sistema diventa a due equazioni
	- $\begin{cases}-z=-x+2y\\w=-kx+ky\end{cases}\quad$ numero soluzioni = $\infty^2$ 
## Esercizio svolto a lezione il 22/04/24
--- 
$T:R^3\rightarrow R^2$
$T(V_1)= (-1,2)$
$T(V_2)= (0,4)$
$T(V_3)= (2,1)$

dove

$V_1=(1,1,1)\quad V_2=(0,1,1)\quad V_3=(1,1,0)$

- Trovare la matrice A associata a T rispetto alle basi canoniche
- Trovare una base di $Im(T)$ e $Ker(T)$ 

$$\begin{pmatrix}1&0&1\\1&1&1\\1&1&0\end{pmatrix}\rightarrow\text{calcolare se il determinante è $\neq 0$}$$
- Posso vedere ad occhio che se faccio $V_1-V_2$ trovo già $T(e_1)$ dove $e_1=aV_1+bV_2+cV_3$
- Anche $V_1-V_3=e_3$ 
- E anche $V_3-e_1=e_2$ 
- Quindi di conseguenza 
	- $T(e_1)=T(V_1)-T(V_2)= (-1,2)-(0,4)=(-1,-2)$
	- $T(e_3)=T(V_1)-T(V_3)= (-1,2)-(2,1)=(-3,1)$
	- $T(e_2)=T(V_3)-T(e_1)= (2,1)-(-1,-2)=(3,3)$

- La matrice estrapolata risulta essere
$$A=\begin{pmatrix}-1&3&-3\\-2&3&1\end{pmatrix}$$
$$A_2=\begin{pmatrix}-1&3\\-2&3\end{pmatrix}=|A_2|=3\neq0\text{ non singolare quindi rg(A) = 2 = dim Im(T)}$$
- $dim\:Ker(T)+2=3\text{ quindi dim Ker(T)=1}$  
$$B_{Im(T)}={(-1,2);(3,3)}$$
$$\begin{cases}-x+3y-3z=0\\-2x+3y+z=0\end{cases}\rightarrow\begin{cases}-x+3y=3z\\-2x+3y=-z\end{cases}\rightarrow r_1-r_2\rightarrow\begin{cases}x=4z\\y=\frac{7}{3}z\end{cases}$$
- $z=3\quad B_{ker(T)}={(12,7,3)}$ 
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

## Foglio 10
## Calcolare il determinante della matrice $$ \begin{pmatrix}-1 & 0  & 1 & 2\\2 & 1 & 3 & -1\\0 & 1  & 2 & -1\\3 & 0  & 1 & -2\end{pmatrix}$$
- Uso il metodo di Laplace:
	- Si sceglie una riga o una colonna da usare (scelgo la seconda colonna perché ha più zeri)
		- $\sum a_{ij}(-1)^{i+j}Det(matrice\:restante)$     
	- Se il determinante è $\neq$ 0, allora posso fare il determinante della matrice inversa
		- Matrice inversa = righe diventano colonne e viceversa
- Uso il metodo di eliminazione di Gauss
	- Si prende la matrice triangolare superiore (risolvo mettendo a zero tutta la matrice triangolare inferiore)
	- determinante = prodotto degli elementi sulla diagonale
	- **Se scambiamo righe cambia anche il segno!**
## Calcolare $A^{-1}$ e verificare che $AA^{-1}=I$ $$\begin{pmatrix}2&1&1\\4&1&0\\-2&2&1\end{pmatrix}$$

$$1(-1)^{1+3} \begin{pmatrix}4&1\\-2&2\end{pmatrix}+1(-1)^{3+3}\begin{pmatrix}2&1\\4&1\end{pmatrix} = 1(8-(-2))+1(2-4)=10-2=8\neq0 $$

- quindi esiste $A^{-1},\: det(A^{-1})=\frac{1}{det(A)}=\frac{1}{8}$ 
- Calcolo inversa
$$\begin{pmatrix}
2&1&1|1&0&0\\
4&1&0| 0&1&0\\
-2&2&1| 0&0&1
\end{pmatrix}$$
- Uso Gauss fino a quando la matrice di sinistra non diventa la matrice identità

- Prima operazione mettere 4 e -2 a zero: $r_2 = r_2 -2r_1\:e\: r_3=r_3+r_1$
$$\begin{pmatrix}
2&1&1|1&0&0\\
0&-1&-2| -2&1&0\\
0&3&2| 1&0&1
\end{pmatrix}$$
- Alla matrice di destra la trattiamo come fosse una matrice intera, quindi $0-1(-2) = -2$ ecc.
- Ora $r_3=r_3+3r_2$ 

$$\begin{pmatrix}
2&1&1|1&0&0\\
0&-1&-2| -2&1&0\\
0&0&-4| -5&3&1
\end{pmatrix}$$
- Rimane da calcolare 1,1 della prima riga e -2 della seconda che devono essere a 0, $r_1 = r_1+r_2$
$$\begin{pmatrix}
2&0&-1|-1&1&0\\
0&-1&-2| -2&1&0\\
0&0&-4| -5&3&1
\end{pmatrix}$$
- $r_1=r_1-\frac{1}{4}r_3$ 
$$\begin{pmatrix}
2&0&0|\frac{1}{4}&\frac{1}{4}&-\frac{1}{4}\\
0&-1&-2| -2&1&0\\
0&0&-4| -5&3&1
\end{pmatrix}$$
- $r_2=r_2-\frac{1}{2}r_3$ 
$$\begin{pmatrix}
2&0&0|\frac{1}{4}&\frac{1}{4}&-\frac{1}{4}\\
0&-1&0| \frac{1}{2}&-\frac{1}{2}&-\frac{1}{2}\\
0&0&-4| -5&3&1
\end{pmatrix}$$
- Moltiplichiamo le righe per $\frac{1}{2},-1,-\frac{1}{4}$
$$\begin{pmatrix}
1&0&0|\frac{1}{8}&\frac{1}{8}&-\frac{1}{8}\\
0&1&0| -\frac{1}{2}&\frac{1}{2}&\frac{1}{2}\\
0&0&1| \frac{5}{4}&-\frac{3}{4}&-\frac{1}{4}
\end{pmatrix}$$
- a sinistra abbiamo la matrice identità, a destra la matrice inversa
$$A^{-1}=\begin{pmatrix}
\frac{1}{8}&\frac{1}{8}&-\frac{1}{8}\\
-\frac{1}{2}&\frac{1}{2}&\frac{1}{2}\\
\frac{5}{4}&-\frac{3}{4}&-\frac{1}{4}
\end{pmatrix} = \frac{1}{8}\begin{pmatrix}
1&1&-1\\
-4&4&4\\
10&-6&-2
\end{pmatrix}$$$$\text{la matrice è stata moltiplicata solo per una rappresentazione diversa}$$
## Risolvere usando Cramer
$$\begin{cases}
x+7y+3z=6\\
-x+2z=-7\\
3x+y+z=2
\end{cases}$$

- Verifichiamo se possiamo usare Cramer

$$\begin{pmatrix}
1&7&3\\
-1&0&2\\
3&1&1
\end{pmatrix}$$
- Verificare che il determinante sia $\neq$ 0

#### Passaggi
- Specchiamo le prime due colonne

$$\begin{pmatrix}
1&7&3&1&7&3\\
-1&0&2&-1&0&2\\
3&1&1&3&1&1
\end{pmatrix}$$

- prendo le prime tre diagonali verso destra con segno positivo e le diagonali da destra a sinistra con segno negativo. TUTTO QUESTO VALE SOLO PER MATRICI 3X3
$$det(A)=1*0*1+7*2*3+3*(-1)*1-1*2*1-7*(-1)*1-3*0*3=$$
$$42-3-2+7=44\neq0\quad\text{quindi si può usare Cramer}$$
- Ci serve matrice  e termini noti
$$x =\begin{pmatrix}
1&7&3\\
-1&0&2\\
3&1&1
\end{pmatrix}\text{sostituisco colonna 1 con termini noti}=\begin{pmatrix}
6&7&3\\
-7&0&2\\
2&1&1
\end{pmatrix}$$
$$\text{faccio il determinante della matrice sopra fratto determinante di A:}=\frac{44}{44}=1$$
- Faccio la stessa cosa per $y$ e $z$
$$y=\begin{pmatrix}
1&6&3\\
-1&-7&2\\
3&2&1
\end{pmatrix}=\frac{88}{44}=2$$

$$z = \begin{pmatrix}
1&7&6\\
-1&0&-7\\
3&1&2
\end{pmatrix}=\frac{-132}{44}=-3$$

## Si considerino le equazioni $3x-y+z=0,x-2y-3z=0$
- Si aggiunga una terza equazione in modo da ottenere un sistema con la sola soluzione nulla
$$\begin{pmatrix}3&-1&1\\1&-2&-3\\?&?&?\end{pmatrix}$$
- Introduciamo $z=0$
$$\begin{cases}
3x-y+z=0\\x-2y-3z=0\\z=0\end{cases}$$
$$\begin{pmatrix}3&-1&1\\1&-2&-3\\0&0&1\end{pmatrix}$$
- Con $z=0$ il sistema diventa omogeneo e quindi la soluzione di cui sopra è valida
-  Con una sola soluzione? $z=1$

$$\begin{cases}
3x-y+z=0\\x-2y-3z=0\\z=1\end{cases}\rightarrow\begin{cases}
3x-y=-1\\x-2y=3\\z=1\end{cases}$$

$$\begin{cases}y=1+3x\rightarrow y=-2\\x-2(1+3x)=3\rightarrow x=-1\\z=1\end{cases}$$