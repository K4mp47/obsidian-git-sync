Legenda argomenti:
- Concetti di base
- Stima puntuale
- Stima intervallare
- Verifica d'ipotesi
- Dipendenza
	- Come usare informazioni di una variabile per prevederne un'altra

- Popolazione: tutte le unità (statistiche) di interesse 
- Parametro: una caratteristica numerica della popolazione di interesse θ 
- Censimento: osservazione di tutte le unità della popolazione per valutare θ 
- Campione: sottoinsieme delle popolazione utilizzato per stimare θ quando il censimento non è opportuno 
- Statistica: una qualsiasi funzione dei dati censuari o campionari 
- Stimatore: statistica ˆθ utilizzata per ricostruire θ 
- Stima: valore dello stimatore corrispondente al particolare campione osservato
Tipi di Errori 
- Errori campionari: inevitabili 
	- dovuti al fatto che osserviamo solo un campione dei dati 
	- diminuiscono al crescere della dimensione campionaria se lo stimatore ˆθ  è ‘ragionevole’ \
- Errori non campionari: evitabili 
	- dovuti ad una sbagliata costruzione del campione o all’utilizzo di uno stimatore non appropriato 
	- possono non diminuire al crescere della dimensione campionaria
	- Per evitare questo tipo di errori il metodo più efficace è estrarre le unità campionarie **CASUALMENTE** dalla popolazione
		- Esistono diversi tipi per estrarre casualmente chiamati **disegni di campionamento** (es. campione casuale semplice)

### Disegno campione casuale semplice
In questo campionamento le unità sono estratte:
- Indipendentemente l'una dall'altra
- Tutte con la stessa probabilità di essere selezionate
- Le osservazioni sono variabili casuali indipendenti e identicamente distribuite

### Dati campionari
Consideriamo l'insieme dei campioni casuali di dimensione $n$
![[Pasted image 20240215091448.png]](Insieme dei campioni)
Esempio: campione casuale dei tempi di elaborazione (CPU) di 30 processi (jobs) in secondi
![[Pasted image 20240215091138.png]]
L’obiettivo è usare i dati campionari per ricostruire alcuni parametri della popolazione

$(x_1,...,x_n)$
$\vartheta=E(x_1)$ 
$\hat{\vartheta}=\bar{X}\rightarrow$ Stimatore
Voglio stimare il tempo medio di un processo, per farlo lancio il processo 30 volte $n=30$ e poi effettuo l'analisi per arrivare alle *realizzazioni delle variabili casuali* (ogni volta che faccio l'analisi avrò diversi campioni come risultato)

##### Statistiche campionarie
Statistiche che misurano la posizione:
- Media campionaria
- Mediana campionaria
- Quantili, percentili, quartili
Statistiche che misurano la variabilità:
- Varianza campionaria e deviazione standard
- Scarto interquartile
Statistiche $\rightarrow$ variabili casuali quando calcolate su un campione casuale di dati

Esempio di caso di studio: tempo necessario per concludere un processo nel 90% dei casi

output funzione: 
- Numero se riferito al singolo campione
- Variabili casuali se opero sull'insieme di campioni

##### Media campionaria
Supponiamo che le osservazioni $X_i$ siano variabili $i.i.d$ con valore atteso $E[X] = \mu$ e varianza $Var[X] = \sigma^2$ 
La media campionaria
![[Pasted image 20240215092326.png]]
 è uno stimatore della media di popolazione.
 La media campionaria dei tempi della CPU(esempio sopra)  è $\hat{x} = 48.23$
 $x$ = particolare valore numerico osservato della media campionaria
 $X$ = variabile casuale campionaria

##### Stimatori e stime
Uno stimatore è non distorto se
$E(\hat{\theta}) = \theta$  per tutti i valori di $\theta$
La distorsione di $\hat{\theta}$ è
$Bias(\hat{\theta})=E(\hat{\theta}) - \theta$ 
Uno stimatore non distorto è:
- Uno stimatore corretto in media, ovvero uno stimatore che in media non sottostima o sovrastima il parametro
La media campionaria è uno stimatore non distorto della popolazione, infatti
![[Pasted image 20240215093042.png]]
(Il valore atteso è un operatore lineare)
$E(\hat{\mu}) = \mu$ 
**CONSISTENZA**:
Uno stimatore è consistente se al crescere della dimensione campionaria $n$ il suo errore campionario converge a zero
![[Pasted image 20240215093429.png]]
ovvero
![[Pasted image 20240215093438.png]]
La media campionaria è uno stimatore consistente della media di popolazione
![[Pasted image 20240215093713.png]]
![[Pasted image 20240215093724.png]](l'ultimo punto indica la probabilità che sia vero o meno il valore con cui si sta operando)
$Var(A+B)= Var(A)+Var(B)+2Cov(A,B)$
$Var(cA+dB)= c^2Var(A)+d^2Var(B)\frac{+}{}2cdCov(A,B)$

##### Calcolare la consistenza di stimatori distorti
come verificare che uno stimatore sia non distorto?
Lo stimatore deve:
- Asintoticamente essere non distorto
  ![[Pasted image 20240215094652.png]]
- La sua varianza svanisce asintoticamente (lo stimatore si avvicina alla quantità di interesse)
  ![[Pasted image 20240215094713.png]]

 Normalità asintotica
 ![[Pasted image 20240215095015.png]]
 ![[Pasted image 20240215100140.png]](Nella foto precedente il grafico rappresenta un campione doppiamente modale dei tempi della CPU, notiamo però come si possa comunque ricavare una distribuzione normale)

**VALORI ANORMALI**
La media ha il difetto di essere sensibile alle osservazioni estreme (Non è robusto)
![[Pasted image 20240215091138.png]]
![[Pasted image 20240215100416.png]]

**MEDIANA**
La mediana campionaria stima la mediana di popolazione, è una misura di posizione molto meno sensibile alle osservazioni estreme rispetto alla media.
Essa suddivide la distribuzione della variabile casuale $X$ in due parti uguali, ovvero
![[Pasted image 20240215100825.png]]
La mediana campionaria $\bar{M}$ è
- Inferiore al più a metà dei dati campionari
- Superiore al più a metà dei dati campionari
![[Pasted image 20240215101159.png]]
**Calcolo della media campionaria**
1. Si ordinano le ordinazioni dalla più piccola alla più grande
	1. Se n è dispari allora $\hat{M}$ è l'osservazione del campione ordinato di posizione $(n + 1)/2$
	2. Se n è dispari allora $\hat{M}$ è un qualsiasi valore nell'intervallo fra le osservazioni di posizione $n/2$ e $(n + 2)/2$ 

**Quantili percentili e quartili**
Il *quantile di ordine p* è tale che:
![[Pasted image 20240220110341.png]]
Il *quantile di ordine p campionario* invece è:
- maggiore al più del $100p\%$ delle osservazioni
- minore al più del $100(1-p)\%$ delle osservazioni

il *percentile di ordine $\gamma$* corrisponde al quartile di ordine 0.01$\gamma$ 
Primo Secondo e Terzo quartile corrispondo al 25-esimo 50-esimo e 75-esimo percentile

	secondo quartile <==> mediana

quanto la media è precisa? Lo si calcola con la 
**Varianza e deviazione standard campionarie**
La varianza è definita come:
![[Pasted image 20240220111207.png]]
![[Pasted image 20240220111625.png]]

Varianza ancora più sensibile per via dei casi anomali, si preferisce di solito usare il valore assoluto al posto del quadrato

La deviazione standard campionaria invece è definita come:
![[Pasted image 20240220111235.png]]

Meglio usare la deviazione standard avendo dei valori preferibili (ricordiamo che la varianza è al quadrato, nell'esempio sopra dei processi meglio $\underline{secondi}$  o secondi$^2$??)

![[Pasted image 20240220111207.png]]
$\uparrow$ Notiamo $1/n-1$ per proprio $n-1$? Per assicurare la non distorsione con campioni piccoli, altrimenti si può dividere per $n$.
![[Pasted image 20240220113607.png]]
![[Pasted image 20240220113748.png]]
![[Pasted image 20240220115315.png]]
![[Pasted image 20240220115812.png]]
![[Pasted image 20240220115822.png]]
**Precisione e Accuratezza**

- Accuratezza: stimatore è poco distorto
- Preciso: stimatore è poco variabile

Entrambe sono combinate nell'errore quadratico medio
![[Pasted image 20240220115738.png]]