## Calcolo sottospazi con e senza reinserimento
### con $$\binom{n}{k} (\frac{m}{N})^k(1-\frac{m}{N})^{n-k}$$

### senza $$\frac{\binom{m}{k}\binom{N - m}{n - k}}{\binom{N}{n}}$$
### probabilitá condizionata $$P[A\mid B] = \frac{P[A \cap B]}{P[B]}$$
### probabilitá di un'intersezione (prob. composte)$$P[A\cap B] = P[A\mid B]P[B] = P[B\mid A]P[A]$$
### eventi indipendenti $$P[A\mid B] = P[A]$$$$P[A\cap B] = P[A]P[B]$$
#### variabile aleatoria discreta $$ P[X = x_i] = p_i, \forall i=1,2,3 .... $$
- Le probabilità $p_i$ sono tali che:
	- #### $0 \leq p_i \leq 1, \forall i=1,2,....$
	- #### $\sum_{i} p_i =1$

#### variabile aleatoria continua 
#### $P[X \in A]$ = area su $A$ sottesa ad una curva $$P[X \in A]=\int_{A}f(x)dx$$
- La curva è il grafico di una funzione $f(x)$ che:
	- #### $f(x)\ge0, \forall x \in R;$
	- $\int_{R}f(x)dx=1$ 

#### valore atteso o media + varianza v.a. discreta $$E[X]=\sum_{i}x_ip_i=x_1p_1+x_2p_2+.....$$ $$Var[X]=\sum_{i}x_i^2p_i-[E[X]]^2$$
#### valore atteso o media + varianza v.a. continua $$E[X]=\int_{R}xf(x)dx$$ $$Var[X]=\int_{R}x^2f(x)dx-[E[X]]^2$$
#### Distribuzione ipergeometrica$$P(X = x)\frac{\binom{K}{k}\binom{N - K}{n - k}}{\binom{N}{n}}$$
```R
Probabilita <- dhyper(k, K, N - K, n)
```
#### Distribuzione di Bernoulli$$$$