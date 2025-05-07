> Assiomi di Armstrong:
> Se $Y \subseteq X \subseteq U$ allora $X \rightarrow Y$. Si dice  Riflessività
> Se $X→Y$, allora per qualsiasi $Z⊆U$, vale $XZ→YZ$. Si dice Aumento
> Se $X→Y$ e $Y→Z$, allora $X→Z$.  Si dice Transitività

# Esercizio 1
Usando gli assiomi di Armstrong, si dimostri che se $X → Y$ e $Y W → Z$, allora $XW → Z$.

Troviamo quindi:
$X \rightarrow Y, YW \rightarrow Z \vdash X \rightarrow Y$ 
Usiamo Aumento:
$X \rightarrow Y, YW \rightarrow Z \vdash XW \rightarrow YW$  e $X \rightarrow Y, YW \rightarrow Z \vdash YW \rightarrow Z$ 
Usiamo Transitività:
$X \rightarrow Y, YW \rightarrow Z \vdash XW \rightarrow Z$ 

Ovvero:
$$
\frac{\frac{X \rightarrow Y, YW \rightarrow Z \vdash X \rightarrow Y}{X \rightarrow Y, YW \rightarrow Z \vdash XW \rightarrow YW } \quad X \rightarrow Y, YW \rightarrow Z \vdash YW \rightarrow Z}{X \rightarrow Y, YW \rightarrow Z \vdash XW \rightarrow Z}
$$

---


> Per poter scrivere in bcnf, vuol dire che lo schema relazionale ha come attributi nell'insieme delle dipendenze funzionali sono  solo **superchiavi**.
> 
> Se non è così, allora si provvede a creare dei sottogruppi partendo dagli attributi non chiave, per poi rieseguire il procedimento in maniera ricorsiva all'interno dei nuovi gruppi creati
> 
# Esercizio 2
Si consideri uno schema relazionale R con i seguenti attributi: ${A,B,C,D,E}$ e il seguente insieme di dipendenze funzionali: 
$\{ A\rightarrow C, B\rightarrow D, AC\rightarrow D, CD\rightarrow E, E\rightarrow A \}$  
Viene richiesto di: 
- Trovare tutte le chiavi di $R$ 
- Dimostrare che lo schema non è BCNF 
- Convertire in BCNF tramite l'algoritmo di analisi 
- Verificare se lo schema BCNF ha conservato le dipendenze, motivando la risposta

## Punto 1
Trovare tutte le chiavi di $R$:

Partiamo cercando tutti gli attributi singoli di destra, vedendo quali attributi riusciamo a ricavare:

- Notiamo che $B$ non appare mai a destra, motivo per cui deve essere compresa nella chiave
- Consideriamo ora tutte le combinazioni tra $B$ e $A,C,D,E$:
	- Calcoliamo $B^+ = \{B,D\}$
	- Calcoliamo $AB^+ = \{A,B,C,D,E\}$
		- **è una chiave**
	- Calcoliamo $CB^+ = \{A,B,C,D,E\}$
		- **è una chiave**
	- Calcoliamo $DB^+ = \{B,D\}$
	- Calcoliamo $EB^+ = \{A,B,C,D,E\}$
		- **è una chiave**

Abbiamo trovato 3 chiavi nello schema, e sappiamo che non è sicuramente nella forma BCNF
## Punto 2
- Dimostrare che lo schema relazionale non è in BCNF

Perché uno schema sia in BCNF tutte le relazioni devono essere $X \rightarrow Y$ con $X$ **superchiave**.

Dall'esercizio precedente, notiamo come nessuna delle relazioni riportate dallo schema relazionale è una **superchiave**.

Il motivo è che nessuna delle chiavi trovate compare nello schema delle dipendenze iniziale :)

## Punto 3 e 4 (trasformo + soluzione)
- Convertire in BCNF tramite l'algoritmo di analisi

$\{ A\rightarrow C, B\rightarrow D, AC\rightarrow D, CD\rightarrow E, E\rightarrow A \}$  schema delle relazioni

 Prendiamo la prima relazione non chiave:
$A\rightarrow C$ 
la isoliamo:
$T_1=A^+=\{A,C,D,E\}$
Calcoliamo gli attributi restanti + $A$ = $T_2=\{A,B\}$
$\{A,B\}$ **nessuna dipendenza perché chiave** (controllo sopra)

All'interno di $T_1$ controllando, tutti gli attributi sono chiave, date le dipendenze iniziali, quindi possiamo dire che:
- La forma in BCNF è composta da $\{A,B\}$ e $\{A,C,D,E\}$ 
- Questa forma in BCNF non preserva tutte le dipendenze, la dipendenza $B \rightarrow D$ è andata persa (nei singoli gruppi, noto come non sia possibile usare questa dipendenza senza dover usare entrambe le tabelle create)

---
# Esercizio 3
Si consideri l’insieme di dipendenze funzionali: $F = \{A → B, C → B, D → ABC, AC → D\}$. 
Trovare una copertura canonica di F .

## Punto 1
Si ottiene uno schema di dipendenze tale da avere un solo valore alla destra per ogni relazione:
 $F= \{A → B, C → B, D → A, D → B, D → C, AC → D\}$


## Punto 2
Eliminiamo ora gli attributi estranei, in questo caso che possono solo provenire da $AC → D$
Nel caso $A^+_G = A,B$ e nel caso $C^+_G=C,B$  e non vi sono attributi estranei.

## Punto 3
Infine dobbiamo eliminare le relazioni ridondanti, che risultano essere:
- $D → B: \quad D^+_{G \backslash \{D → B\}} \quad =A,C,D,B$  quindi viene rimossa
La copertura canonica è quindi $\{A → B, C → B, D → A, D → C, AC → D\}$.

---

# Esercizio 4 (BD2 Deps&Normal Questions)
$F=\{ABC \rightarrow DF, BD \rightarrow AE, B \rightarrow A\}$
- Forma canonica
- Trovare tutte le chiavi
- Dire se in BCNF, se no trasformarlo in BCNF

## Punto 1
Riduciamo ai singoli di destra:
$F_1 = \{ ABC \rightarrow D, ABC \rightarrow F, BD \rightarrow E, BD \rightarrow A, B \rightarrow A\}$

## Punto 2
Troviamo ora gli elementi estranei
- In $ABC \rightarrow D$, $A$ è estraneo dato che $\{B,C\}^+ = A,B,C,D,E,F$ per cui posso sostituire con quello che ho trovato
- In $ABC \rightarrow F$, $A$ è estraneo come il punto precedente, per cui posso sostituire con quello che ho trovato ($B,C \rightarrow F$ in questo caso)
- In $BD \rightarrow A$, $D$ è estraneo perché $\{B\}^+ = B,A$ per cui posso sostituire

La forma di $F$ trovata risulta quindi essere:

$F = \{BC \rightarrow D, BC \rightarrow F, BD \rightarrow E, B \rightarrow A, B \rightarrow A\}$

Rimuovo le operazioni ridondanti per avere come risultato finale:

$F = \{BC \rightarrow D, BC \rightarrow F, BD \rightarrow E, B \rightarrow A\}$

## Punto 3

Troviamo le chiavi presenti nel sistema:

$BC^+ = BCDFEA$, quindi è chiave
$B^+ = BA$, quindi non è chiave
$BD^+ = BDEA$ quindi non è chiave

Le chiavi sono quindi: $\{(B,C)\}$ 

## Punto 4

Verifichiamo subito che lo schema non si trova in forma BCNF.

Prendiamo quindi la prima $DF$ non chiave: $BD \rightarrow E$ 
$T_1 = BD^+ = BDEA$
$T_2 = F^+ - \{BD^+\} = BCDF$

In $T_1$ noto come nelle dipendenze ci sia $B \rightarrow A$ che non è chiave per cui dobbiamo di nuovo scomporlo in:

$T_{1,1} = B^+ = AB$ 
$T_{1,2} = T_1 - \{B^+\} = BDE$ 

il risultato saranno quindi i tre gruppi $T_2, T_{1,1}, T_{1,2}$ per la forma in BCNF

---

# Esercizio 5
$F = \{AB → CDE, AC → BDE, B → C, C → B, C → D, B → E\}$. 
Estrarre da $F$ la forma canonica e trovare tutte le chiavi

## Punto 1 
Tutti gli attributi a destra devono essere singoli:
$F = \{AB  \rightarrow C, AB \rightarrow D, AB \rightarrow E, AC \rightarrow B, AC \rightarrow D, AC \rightarrow E, B \rightarrow C, C \rightarrow B, C \rightarrow D, B \rightarrow E\}$
## Punto 2
Troviamo gli attributi estranei
- $AB \rightarrow C$, $A$ è estraneo per $B \rightarrow C$
- $AB \rightarrow E$, A è estraneo per $B \rightarrow E$
- $AB \rightarrow D$ è estraneo per $B \rightarrow C, C \rightarrow D$ 
- $AC \rightarrow B$, A è estraneo per $C \rightarrow B$ 
- $AC \rightarrow D$, A è estraneo per $C \rightarrow D$
- $AC \rightarrow E$, A è estraneo per $C \rightarrow B, B \rightarrow E$ 

Rimangono $F=\{B \rightarrow C, C \rightarrow B, C \rightarrow D, B \rightarrow E\}$ 

> interessante, come vedremo sotto, che per aiutarci a capire come trovare subito le chiavi, possiamo iniziare cercando gli attributi che non escono a destra, se ce ne sono
## Punto 3 
Cerchiamo ora le chiavi per il nostro schema di dipendenze. Notiamo come $A$ non appaia mai a destra, quindi farà **sicuramente** parte delle chiavi.

Da qui iniziamo con le prime coppie: $\{AB,AC,AD,AE\}$

- $AB^+ = ABCDE$ quindi è chiave
- $AC^+ = ABCDE$ quindi è chiave
- $AD^+ = AD$ quindi non è chiave
- $AE^+ = AE$ quindi non è chiave

Le chiavi trovate risultano quindi essere $\{AB,AC\}$ 

