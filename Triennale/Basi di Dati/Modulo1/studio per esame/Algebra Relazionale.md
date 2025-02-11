### Legenda:
| segno    |     significato |
| -------- | --------------: |
| $\pi$    |      Proiezione |
| $\sigma$ |     Restrizione |
| $\cup$   |          Unione |
| $\rho$   | Ridenominazione |
| $\cap$   |    Intersezione |
| ◃▹       |            Join |

### **Operatori Primitivi**

1. **Ridenominazione (ρ)**: Consente di rinominare gli attributi di una relazione.
    
    - Es: ρA←B(R) ridenomina l'attributo A di R in B.
2. **Proiezione (π)**: Seleziona un sottoinsieme di colonne (attributi) di una relazione, eliminando i duplicati.
    
    - Es: πNome, Matricola (Studenti) estrae solo i campi "Nome" e "Matricola" dalla relazione "Studenti".
3. **Unione (∪)**: Combina due relazioni con lo stesso schema, restituendo tutte le tuple presenti in almeno una delle due.
    
    - Es: R ∪ S unisce le relazioni R e S.
4. **Differenza (−)**: Restituisce le tuple che sono in una relazione ma non nell'altra.
    
    - Es: R − S restituisce le tuple che sono in R ma non in S.
5. **Restrizione (σ)**: Filtra le tuple di una relazione in base a una condizione.
    
    - Es: σProvincia = 'VE'(Studenti) seleziona gli studenti della provincia di Venezia.
6. **Prodotto cartesiano (×)**: Combina tutte le tuple di due relazioni, creando una nuova relazione che contiene tutte le combinazioni possibili delle tuple.
    
    - Es: R × S combina ogni tupla di R con ogni tupla di S.
    - concateno ogni ennupla di S con una di R per tutte quelle di R
    - Tipo del prodotto = sia R che S
	
### **Operatori Derivati**

1. **Giunzione (Join)**: Unisce due relazioni su una condizione specifica di uguaglianza tra attributi comuni (come una chiave esterna).
	- Studenti(Nome, Cognome, Matricola, Anno, Provincia)
		Insegnamenti(Codice, Nome, CFU)
		Frequenta(Matricola, Codice)
		
		$Studenti ◃▹ Frequenta ◃▹ Insegnamenti$
		$\uparrow$ Questa non funziona, Per via di **Nome** presente solo in studenti e insegnamenti, per poter funzionare necessita, per esempio, di essere rinominata:
		
		$Studenti ◃▹ Frequenta ◃▹ \rho(Nome\rightarrow NomeIns) Insegnamenti$
		

    
    - Es: R ◃▹ S unisce R e S sulle chiavi comuni.
2. **Intersezione (∩)**: Restituisce le tuple comuni a entrambe le relazioni.
    
    - Es: R ∩ S restituisce solo le tuple presenti sia in R che in S.
3. **Divisione (÷)**: Usata per rispondere a query che coinvolgono la **quantificazione universale** (del tipo "per tutti").
    
    - Es: Matricole degli studenti che hanno sostenuto tutti gli esami che ha sostenuto un altro studente.
	Tabella $R$
	
	| x     | y     |
	| ----- | ----- |
	| $t_1$ | $s_1$ |
	| $t_2$ | $s_1$ |
	| $t_1$ | $s_2$ |
	| $t_3$ | $s_1$ |
	| $t_3$ | $s_2$ |
	
	Tabella $S$
	
	| y     |
	| ----- |
	| $s_1$ |
	| $s_2$ |
	
	Tabella $T$ = $R ÷ S$
	
	| x     |
	| ----- |
	| $t_1$ |
	| $t_3$ |
	
	

### **Funzioni di Aggregazione**

- Le funzioni come `sum`, `avg`, `count`, `min`, `max` permettono di ottenere valori aggregati (es: somma di voti, numero di esami sostenuti).
- Si usa il **raggruppamento** (γ) per suddividere i dati in gruppi e applicare funzioni di aggregazione su ciascun gruppo.

### **Proprietà**

- Gli operatori dell'algebra relazionale possono essere combinati in espressioni più complesse.
- La trasformazione algebrica consente di ottimizzare le query scegliendo diverse sequenze di operazioni (es: anticipare proiezioni o restrizioni per ridurre la dimensione dei dati da processare).

### **Ennuple**
Le ennuple nel momento in cui utilizzo "$\pi$" per settare quale attributo sto cercando, se sono duplicati non vengono visti!

$|\pi_{a_n\rightarrow a_m} (R) |< n$

dove $n$ è il numero di tuple.

### Esercizio 1:
- Quella sotto raffigurata è la tabella degli oggetti noti come `Studenti`

| Nome    | Cognome | Matricola | Anno | Provincia |
| ------- | ------- | --------- | ---- | --------- |
| Paolo   | Verdi   | 71523     | 2005 | VE        |
| Anna    | Rossi   | 76366     | 2006 | PD        |
| Giorgio | Zeri    | 71347     | 2005 | VE        |
| Chiara  | Scuri   | 71346     | 2006 | VE        |

1. Trova i nomi e le matricole degli studenti della provincia di Venezia.
2. Trova le matricole degli studenti iscritti nel 2005.

##### Punto 1
$\pi Nome, Matricola(\sigma Provincia= 'VE'(Studenti))$   
##### Punto 2
$\pi Matricola(\sigma Anno=2005(Studenti))$

### Esercizio 2: Unione e Differenza

Date le seguenti relazioni **Docenti** e **Studenti**:

**Docenti:**

|Nome|Cognome|Numero|
|---|---|---|
|Marco|Bianchi|1234|
|Anna|Rossi|5678|
|Giorgio|Neri|9101|

**Studenti:**

|Nome|Cognome|Matricola|
|---|---|---|
|Paolo|Verdi|71523|
|Anna|Rossi|76366|
|Giorgio|Zeri|71347|

1. Trova i nomi e cognomi presenti in **almeno una** delle due relazioni.
2. Trova i nomi e cognomi che sono **solo** studenti e non docenti.

##### Punto 1:
$\pi Nome, Cognome(Studenti) \cup \pi Nome, Cognome(Docenti)$ 

##### Punto 2:
$\pi Nome, Cognome(Studenti) - \pi Nome, Cognome(Docenti)$

### Esercizio 3

**Studenti:**

| Matricola | Nome    | Anno | Provincia |
| --------- | ------- | ---- | --------- |
| 71523     | Paolo   | 2005 | VE        |
| 76366     | Anna    | 2006 | PD        |
| 71347     | Giorgio | 2005 | VE        |

**Esami:**

| Codice | Materia | Candidato | Voto | Data     |
| ------ | ------- | --------- | ---- | -------- |
| B112   | BD      | 71523     | 27   | 08.07.06 |
| F31    | FIS     | 76366     | 26   | 08.07.07 |
| B247   | BD      | 76366     | 28   | 28.12.06 |

1. Trova i nomi degli studenti che hanno sostenuto un esame di **BD**.
2. Trova i nomi e i voti degli studenti che hanno sostenuto un esame con **voto maggiore di 26**.

##### Punto 1:
$\pi Nome(\sigma Materia = 'BD'(Studenti ◃▹ Matricola = Candidato Esami))$

##### Punto 2:
$\pi Nome, Voto(\sigma Voto > 26(Studenti ◃▹ Matricola = Candidato Esami))$

---
Matricola degli studenti che hanno fatto tutti gli esami che ha fatto Anna Rossi (76366)

| Nome    | Cognome | Matricola | Anno | Provincia |
| ------- | ------- | --------- | ---- | --------- |
| Paolo   | Verdi   | 71523     | 2005 | VE        |
| Anna    | Rossi   | 76366     | 2006 | PD        |
| Giorgio | Zeri    | 71347     | 2005 | VE        |
| Chiara  | Scuri   | 71346     | 2006 | VE        |

$T(Candidato)$

$S(Matricola)$

$EsAR = \pi Materia(\sigma candidato=76366(Esami)) \rightarrow R(Candidato, Materia)$ 

$ES ÷ ESAR$

### Esercizio preso da [[2023_03Finale.pdf]]
Si considerino i seguenti schemi di relazione (le chiavi primarie sono sottolineate, le chiavi esterne sono date esplicitamente):
-  Pizze(codPizza, nome, tempoPrep, prezzo) 
- Ingredienti(codIngrediente, nome, quantità Magazzino, costoBase) 
- Ricette(codPizza\*, codIngrediente\*, quantità) 
	- codPizza FK(Pizze) codIngrediente FK(Ingredienti) 
- Ordini(codOrdine, nomeCliente, indirizzoCliente, oraConsegna, codPizza\*) 
	- codPizza FK(Pizze) (i) 

Tramite l'algebra relazionale, restituire il nome delle pizze, il nome degli ingredienti e il loro costoBase per le pizze che hanno un prezzo maggiore di 15 euro e un tempo di preparazione inferiore a 20 minuti.

query relazionale:
$$\pi Pizza.Nome, Ingredienti.nome, Ingredienti.costoBase(\sigma prezzo > 15 \text { and } tempoPrep < 20(Pizze) ◃▹_{codPizza} (Ricette) ◃▹_{codIngredienti} Ingredienti)$$ 
## Esercizi presi da youtube 
[youtube](https://youtu.be/y4pn_-NZix8?si=qdLy3qyewybFYMiY)

![[Pasted image 20241107161058.png]]
##### Query 1
Elenco prodotti con prezzo maggiore di 50 euro
- Ho bisogno solo della tabella `Prodotti`, quindi non necessito di fare `JOIN`
- Condizione che il `Prezzo` deve essere sopra i `50` euro
	- Dovrò fare una `SELECTION`
- Non necessito di `PROIECTION` perché non è stato specificato

Guardando dall'immagine so che la risposta è solo una colonna specifica, Ovvero quella 

| CodProdotto | Descrizione | Prezzo | CodReparto |
| ----------- | ----------- | ------ | ---------- |
| 5           | Trave       | 56     | 6          |

Per arrivare ad avere questa tabella, la query corrispondente sarà:

$ProdottiCostosi=\sigma Prezzo > 50(Prodotti)$

##### Query 2
Elenco vendite con un numero identificativo  maggiore o uguale a 4
- Necessito solo della tabella `Vendite`
- Condizione che il numero identificativo sia maggiore uguale a 4
	- `SELECTION` o **restrizione**
- Non necessito di **proiezione** non essendo specificato cosa vuole 

La query dovrà quindi essere:
$IdentificativiVendite=\sigma Numero >= 4(Vendite)$

##### Query 3
Elenco  dei prodotti del reparto Panetteria
- Necessito delle tabelle `Reparti` e `Prodotti`
	- Devo fare la `JOIN`
- Nessuna **condizione**
- Proiezione solo delle informazione relative al prodotto
	- Serve fare **Proiezione**

Qui devo prima guardare le relazioni e analizzare gli attributi per poter fare la join:

![[Pasted image 20241107163705.png]]

Vedo che `Prodotti` è legato a reparti tramite `CodReparto` che corrisponderà a `CodReparto` di `Reparto`

La query quindi sarà:
- Prima faccio al join
	- $ProdottiReparto=(\sigma NomeReparto = \text{"Panetteria"} (Reparti)) ◃▹_{CodReparto}(Prodotti)$ 

- Poi faccio la proiezione
	- $ProdottiFinali = \pi_{\text{CodProdotto, Descrizione, Prezzo}}(ProdottiReparto)$

##### Query 4
Elenco vendite del prodotto Filone
- Join tra prodotti e vendite
- nessuna condizione
- voglio solo i dati delle vendite

query:
- Prima faccio la join
	- $VenditePerProdotto=(\sigma Descrizione = \text{"Filone"} (Prodotti)) ◃▹_{CodProdotto}(Vendite)$
- Poi faccio la proiezione
	- $VenditeFinale=\pi_{\text{Quantità, Data, Numero}}(VenditePerProdotto)$


##### Query 5
Elenco dei prodotti con descrizione e prezzo del reparto "Cibo Per Cani"
- Join tra Prodotti e Reparto
- Nessuna condizione
- Voglio solo descrizione e prezzo

Il Principio da seguire è sempre lo stesso con la proiezione di solo due colonne
$ProdottiReparto = (\sigma NomeReparto = \text{"Cibo Per Cani"}(Reparti))◃▹_{\text{CodReparto}}(Prodotti)$ 

Poi proiezione

$ProdottiPerCani = \pi_{\text{Descrizione, Prezzo}}(ProdottiReparto)$ 