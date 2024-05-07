## Esercizio 1
- Calcolare $\frac{1-i}{1+i}^3$ in forma algebrica e trigonometrica
Troviamo prima la forma algebrica del numero datoci

$$\frac{1-i}{1+i}=\frac{1-i}{1+i}\frac{1-i}{1-i}=\frac{(1-i)^2}{(1+i)(1-i)}=\frac{1+i^2-2i}{1-i+i-i^2}=\frac{-2i}{1-i^2}=\frac{-2i}{2}=-i$$

Da qui, estraiamo la forma trigonometrica
$$(-i)^3=(-i)^2(-i)=i=\rho e^{i\theta}$$ ❓Immagino che sia perché $(-i)^2=-1$ per  cui $-1(-i)=i$ 

Inoltre dobbiamo trovare:
- $\rho=|z|=\sqrt{x^2+y^2}=\sqrt{1}=1$ 
- $\theta=Arg(z)=arctan(\frac{1}{0})=\text{forma a=0,b>0} = \frac{\pi}{2}$ 

Quindi il nostro numero in forma trigonometrica risulta essere $e^{i\frac{\pi}{2}}$ 

--- 
## Esercizio 2
- Dato $z=\frac{1}{\sqrt3}-\frac{1}{i}$ determinare nella forma più comoda $z^22$

Per farlo troviamo prima il numero in forma algebrica

$$z=\frac{1}{\sqrt3}-\frac{1}{i}=\frac{1}{\sqrt3}+i$$

Da qui estraiamo modulo e argomento di $z$.

$\rho=\sqrt{x^2+y^2}=\sqrt{\frac{1}{3}+1}=\sqrt{\frac{4}{3}}=\frac{2}{\sqrt3}$ 

$\theta=arctan(\frac{1}{-\sqrt{3}})=arctan(\sqrt3)=\frac{\pi}{3}$ 

Per cui arriviamo ad avere $z^{22}=(\frac{2}{\sqrt3})^{22}*e^{i\frac{\pi}{3}*22}$ 
Semplifichiamo ora la parte immaginaria notando che $\frac{22}{3}\pi$ può essere semplificato, avendo $\frac{6}{3}\pi$ come giro completo, possiamo far si che $\frac{22}{3}\pi-\frac{18}{3}\pi=\frac{4}{3}\pi$
Per trasformarlo nella forma più comoda, troviamo coseno e seno del numero esponenziale e abbiamo finito
$$\rho^{22}(cos(\frac{4}{3})+isin(\frac{4}{3}))=\rho^{22}(-\frac{1}{2}+i\frac{\sqrt3}{2})$$
---
## Esercizio 3
- Determinare le seguenti radici e rappresentarle sul piano complesso
$$(\frac{-2}{1-i\sqrt3})^{\frac{1}{4}}$$

troviamo intanto la forma algebrica
$$z=\frac{-2}{1-i\sqrt3}\frac{1+i\sqrt3}{1+i\sqrt3}=\frac{-2-2i\sqrt3}{1-i^23}=\frac{-1}{2}-\frac{i\sqrt3}{2}$$
trovo modulo ed argomento

$|z|=\sqrt{\frac{-1}{2}^2+\frac{-i\sqrt3}{2}^2}=\sqrt{\frac{1}{4}+\frac{-i^23}{4}}=\sqrt{\frac{1}{4}+\frac{3}{4}}=\sqrt{1}=1$

$Arg(z)=\frac{\frac{-\sqrt3}{2}}{\frac{-1}{2}}=$  
❓Non capisco come risolvere questo argomento!!! Devo chiedere una mano

---
## Esercizio 7.
- Stabilire se $W=\{(x,y,z) \in R^3:z=x-y\}$ è un sottospazio vettoriale di $V=R^3$

Per dimostrare che è $W$ sia un sottospazio vettoriale occorre verificare che sia chiuso rispetto alla somma e al prodotto. Iniziando dalla somma, troviamo due vettori di $W$ e controlliamo che siano ancora all'interno del suo stesso spazio

$$(x_1,y_1,x_1-y_1)\qquad(x_2,y_2,x_2-y_2)$$ 
I due vettori se sommati generano $(x_1+x_2,y_1+y_2,(x_1-y_1)+(x_2-y_2))$ che risulta essere ancora all'interno di $W$.  Difatti appoggiandoci alla funzione precedente abbiamo che

$$z=x-y\rightarrow x_1-y_1+x_2-y_2=x_1+x_2-y_1-y_2 \rightarrow 0=0$$


Ora non ci manca che controllare che esso appartenga a $W$ anche con il prodotto per scalare

$$\lambda(x_1,y_1,x_1-y_1)=(\lambda x_1,\lambda y_1,\lambda (x_1-y_1))$$
Che rimane in $W$ , affermando che esso sia un sottospazio di $R^3$.

---
## Esercizio 8
- Stabilire se $W = \{(x,y,z) \in R^3: z\geq 0\}$  è un sottospazio vettoriale di $V=R^3$ 

Proviamo a supporre un numero per cui $z\geq 0$ non viene soddisfatta, e questo è possibile per un qualunque scalare $< 0$. 

---
## Esercizio 10
- Stabilire se $W=\{(x,y,z,t) \in R^4:xy=0\}$ è un sottospazio vettoriale di $V=R^4$

Proviamo a verificare per la somma tra vettori 

$$(x_1,y_1,z_1,t_1)+(x_2,y_2,z_2,t_2)=(x_1+x_2,y_1+y_2,z_1+z_2,t_1+t_2)$$
Ciò vuol dire che $0=(x_1+x_2)(y_1+y_2)$.
Da questa equazione Capiamo che se troviamo due vettori la cui somma delle $x$ e le $y$, susseguita dalla moltiplicazione dei due risultati desse un risultato diverso da $0$ esso non farebbe parte di $R^4$, proprio come nel caso scegliessimo $(1,0,0,0),(0,1,0,0)$.

---