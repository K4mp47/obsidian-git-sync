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
# k <- occorrenze nel campo di controllo
# k <- totale massimo occorrenze
# N <- Casi possibili totali
# n <- campo di controllo 
Probabilita <- dhyper(k, K, N - K, n)
```
#### Distribuzione di Bernoulli$$P(X = x) = p^x(1-p)^{1-x}$$
```R
# X è la variabile casuale che rappresenta l'evento "ottenere testa".
# x può assumere i valori 0 o 1.
# p è la probabilità di successo (in questo caso, la probabilità di ottenere testa).

# Definire i parametri
x <- 1
p <- 0.5

# Calcolare la probabilità
probabilita <- dbinom(x, 1, p)
print(probabilita)
```

#### Distribuzione binomiale $$P(X = k) = \binom{n}{k}p^k(1-p)^{n-k}$$
```R
# Calcolare la probabilità di ottenere esattamente 3 teste in 5 lanci di una moneta equa, utilizzando la distribuzione binomiale.
# X è la variabile casuale che rappresenta il numero di successi (nel nostro caso, il numero di teste).
# k è il numero esatto di successi che vogliamo ottenere (3 nel nostro esempio).
# n è il numero totale di prove (5 nel nostro esempio).
# p è la probabilità di successo in una singola prova (0.5, poiché la moneta è equa).

# Definire i parametri
k <- 3
n <- 5
p <- 0.5

# Calcolare la probabilità
probabilita <- dbinom(k, n, p)
print(probabilita)
```

#### Distribuzione di Poisson$$P(X=k)=\frac{e^{-\lambda}\lambda^k}{k!}$$
```R
# Calcolare la probabilità di osservare esattamente 8 auto in un'ora, quando la media è di 10 auto all'ora, utilizzando la distribuzione di Poisson.

# Definire i parametri
k <- 8
lambda <- 10

# Calcolare la probabilità
probabilita <- dpois(k, lambda)
print(probabilita)
```

#### Distribuzione gamma {ancora da scrivere}
$$\int_0^\infty \frac{\lambda^\alpha}{\Gamma(\alpha)}x^{\alpha-1}e^{-\lambda x}dx
$$
- Posso semplificare
$$\int_0^\infty \frac{\lambda^\alpha}{\Gamma(\alpha)}x^{(\alpha+1)-1}e^{-\lambda x}dx$$
- Per Poi
$$\frac{\lambda^\alpha}{\Gamma(\alpha)}\int_0^\infty x^{(\alpha+1)-1} e^{-\lambda x}dx=\int_0^\infty\frac{\lambda^{\alpha+1}}{\Gamma(\alpha+1)}x^{(\alpha+1)-1} e^{-\lambda x}dx$$
```r
# Definire i parametri della distribuzione gamma
k <- 2
theta <- 3

# Calcolare la probabilità di aspettare più di 10 minuti
probabilita <- 1 - pgamma(10, shape = k, scale = theta)
print(probabilita)
```
#### Distribuzione esponenziale $$f(x;\lambda) = \lambda e^{-\lambda x}$$$$P(X > 10) = \int_0^\infty f(x;\lambda) dx$$ $$ E[X] = \frac{1}{\lambda}, Var[X] = \frac{1}{\lambda^2}$$
```r
# Definire il parametro di tasso della distribuzione esponenziale
lambda <- 0.2

# Calcolare la probabilità di aspettare più di 10 minuti
probabilita <- 1 - pexp(10, rate = lambda)
print(probabilita)
```
