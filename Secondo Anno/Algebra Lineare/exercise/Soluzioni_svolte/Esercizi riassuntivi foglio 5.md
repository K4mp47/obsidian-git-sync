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