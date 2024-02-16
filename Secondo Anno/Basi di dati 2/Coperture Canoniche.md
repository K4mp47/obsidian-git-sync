Definizioni di chiave:
![[Pasted image 20240216135331.png]]
Eseguire la verifica di una superchiave:
1. Dato $R(T,F)$ possiamo verificare se $X \subseteq T$ è una superchiave tramite il seguente algoritmo **polinomiale**:
	1. Calcola la chiusura di $X^+_F$
	2. Verifica se $X^+_F = T$
	![[Pasted image 20240216135746.png]]
2. Dato $R(T,F)$ possiamo verificare se $X \subseteq T$ è una chiave tramite un altro algoritmo **polinomiale**:
	1. Verifica se $X$ è una superchiave
	2. Verifica che per ogni $A \in X$ si abbia  (X \ {A})$^+_F \neq$  T   
	![[Pasted image 20240216140235.png]]
	

Dato R(T , F ), è possibile trovare una sua chiave in tempo polinomiale. L’idea dell’algoritmo è di partire da T e rimuovere uno ad uno tutti gli attributi che non sono indispensabili per derivare T .
![[Pasted image 20240216141005.png]]
Sia G = {AB → C , E → A, A → E , B → F }. Costruiamo una chiave:
- Inizializziamo $K_0$ = $ABCDEF$ 
- Rimuoviamo A da $K_0: BCDEF^+_G = ABCDEF$ , quindi $A$ deve essere rimosso ed aggiorniamo la chiave a $K_1 = BCDEF$ 
- Rimuoviamo B da $K_1: CDEF^+_G = ACDEF$, quindi B va tenuto 
- Rimuoviamo C da $K_1: BDEF^+_G = ABCDEF$ , quindi C deve essere rimosso ed aggiorniamo la chiave a $K_2 = BDEF$ 
- Rimuoviamo D da $K_2: BEF^+_G = ABCEF$ , quindi D va tenuto 
- Rimuoviamo E da $K_2: BDF^+_G = BDF$ , quindi E va tenuto 
- Rimuoviamo F da $K_2: BDE^+_G = ABCDEF$ , quindi F deve essere rimosso ed aggiorniamo la chiave a $K_3 = BDE$

L'algoritmo torna quindi $K_3 = BDE$, ma è l'unica chiave? 

Dato R(T, F), trovare tutte le chiavi ha costo esponenziale, perché ogni sottoinsime di T è potenzialmente una chiave. Esiste però un algoritmo per la ricerca di tutte le chiavi piuttosto ottimizzato.
![[Pasted image 20240216144332.png]]
![[Pasted image 20240216144350.png]]
![[Pasted image 20240216144401.png]]
![[Pasted image 20240216144408.png]]
![[Pasted image 20240216144426.png]]
![[Pasted image 20240216144437.png]]
![[Pasted image 20240216144448.png]]
Dato R(T , F ), il problema di verificare se un attributo A ∈ T è primo ha complessità esponenziale: 
- più precisamente, si può dimostrare che è un problema NP-completo 
- ciò implica che non esistono soluzioni significativamente più efficienti dell’approccio ovvio di generare tutte le possibili chiavi! 
- questo è l’approccio che useremo per trovare l’insieme degli attributi primi quando sarà necessario all’interno del corso

**Forma canonica**
È utile portare l'insieme delle dipendenze funzionali in **forma canonica**
![[Pasted image 20240216144732.png]]
![[Pasted image 20240216144802.png]]
![[Pasted image 20240216144810.png]]
![[Pasted image 20240216144816.png]]
![[Pasted image 20240216144832.png]]
![[Pasted image 20240216144848.png]]
