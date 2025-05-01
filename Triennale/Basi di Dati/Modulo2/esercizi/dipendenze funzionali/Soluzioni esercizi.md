# Esercizio 1
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

$A^+$ otteniamo $A,C,D,E$ 
$E^+$ otteniamo $A,C,D,E$ 
$AB^+$ otteniamo $A,B,C,D,E$  **chiave**
$AC^+$ otteniamo $A,C,D,E$ 
$AD^+$ otteniamo $A,C,D,E$ 
$AE^+$ otteniamo $A,C,D,E$ 
$BE^+$ otteniamo $A,B,C,D,E$ **chiave**
$BAC^+$ otteniamo $A,B,C,D,E$ con le nuove dipendenze $BAC \rightarrow E$ // non è minimale
$ACD^+$ otteniamo $A,C,D,E$ 
$BCD^+$ otteniamo $A,B,C,D,E$ con le nuove dipendenze $BCD \rightarrow A$ **chiave** 

Le chiavi sono $AB,BE, BCD$ ($BAC$ non è minimale contenendo al suo interno $AB$) 
## Punto 2
- Dimostrare che lo schema relazionale non è in BCNF

Perché uno schema sia in BCNF tutte le relazioni devono essere $X \rightarrow Y$ con $X$ **superchiave**.

Dall'esercizio precedente, notiamo come nessuna delle relazioni riportate dallo schema relazionale non ci siano **superchiavi**.

Il motivo ·e che nessuna delle chiavi trovate compare nello schema delle dipendenze iniziale :)

## Punto 3 e 4 (trasformo + soluzione)
- Convertire in BCNF tramite l'algoritmo di analisi

$\{ A\rightarrow C, B\rightarrow D, AC\rightarrow D, CD\rightarrow E, E\rightarrow A \}$  schema delle relazioni

Cominciamo dalla prima relazione non chiave:
$A\rightarrow C$ 
la isoliamo:
$T_1=A^+=\{A,C,D,E\}$
Calcoliamo gli attributi restanti + $A$ = $T_2=\{A,B\}$
$\{A,B\}$ **nessuna dipendenza perché chiave**

All'interno di $T_1$ controllando, tutti gli attributi sono chiave, date le dipendenze iniziali, quindi possiamo dire che:
- La forma in BCNF è composta da $\{A,B\}$ e $\{A,C,D,E\}$ 
- Questa forma in BCNF non preserva tutte le dipendenze, la dipendenza $B \rightarrow D$ è andata persa
