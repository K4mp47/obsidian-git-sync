 per le altre formule di questo genere guardo il punto 7
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
⚠ Sempre bene vedere gli esercizi del foglio 5 estratti dagli esami! All'interno è presente anche il calcolo di radici di un numero complesso

Per calcolare la radice di un numero complesso si arriva alla forma esponenziale $\rho e^{\theta_k}$ per poi risolvere $\theta_k$
$$\theta_k=\frac{Arg(z)+2k\pi}{n}$$
dove $n$ è la radice (quarta, cubica, ecc.) e $k$ viene sostituito con $0,1,2 ,...,n-1$ 
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
- $Re(z)=-1 \quad\quad Im(z)=-i$
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
