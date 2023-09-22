
# Introduzione


# 18 settembre 2023: introduzione alle basi di dati(DB/DBMS)

> Prima lezione, introduzione al corso. Primo approccio con la terminologia da usare.
> Sistema informativo:
> - Combinazione risorse umane e materiali
> - Raccolta e aquisizione
> - Archiviazione 
> - Elaborazione, produzione, trasformazione
> - Distribuzione comunicazione e scambio informazioni
>
>![[Pasted image 20230918145435.png]]
> - **Definizione di sistema informatico**:
> 	- Insieme di tecnologie e della comunicazione a supporto delle attivitá di un'organizzazione
> - **Definizione sistema informatico automatizzato**:
> 	- Parte del sistema informativo in cui le informazioni sono raccolte, elaborate, archiviate e scambiate usando un sistema informatico
>
>## SIstema informatico nelle Organizzazioni
>![[Pasted image 20230918145726.png]]
>
> **DBMS**:
> - Nascono negli anni '70, consentono il supporto ad ogni livello d'organizzazione dei dati
> - Importante il fatto che permette *integrazione dei dati*: un'unica reccolta di dati comuni e diverse applicazioni che operano accedendo ai dati di loro interesse:
> 	- Disponibilita'
> 	- Limitazione delle ridondanze
> 	- Efficienza
> 	- **Flessibilitá**
> 		- Schema: descrive la struttura della base informativa
> 		- DB auto-descrittiva: i programmi applicativi non sono tenuti a conoscere la struttura della base informativa, in quanto essa é esplicitamente rappresentata, e a tale rappresentazione essi possono accedere
> 
> Anni '90 in poi:
> - Big Data:
> 	- Volume
> 	- Velocitá
> 	- Varietá
> 	- Veridicitá
> 	- Valore
> - Web Services
> - Data Mining & Warehouse
>
>Due diversi sistemi informatici:
>![[Pasted image 20230918150901.png]]
>## **Sistemi informatici operativi**
>- Organizzati in DB
>- Applicazioni usate per le classiche attivitá strutturate e ripetitive(calcolo paghe, emissione fatture)
>- Terminologia anglosassone
>	- Data processing (DP), Electronic Data processing (EDP) 
>	- Transaction Processing Systems (TPS) 
>	- Enterprise Resource Planning (ERP)
>- ![[Pasted image 20230918151044.png]]
>
>#### Elaborazione DB: OLTP
>- Tradizionale elaborazione di transazioni
>	- Operazioni coinvolge pochi dati
>	- Operazioni predefinite
>	- Dati di dettaglio, aggiornati
>- Uso principale dei DBMS 
>![[Pasted image 20230918151329.png]]
>## **Sistemi informatici direzionali**
>- La direzione intermedia e alta necessitano di:
>	- analisi storiche dell'andamento degli affari
>	- produzione interattiva (non programmata) di rapporti di sintesi
>- Le basi di dati operative risultano inadeguate:
>	- contengono solo dati recenti
>	- le operazioni coinvolgono grandi quantitá di dati o sono molto complesse
>- Dati organizzati in **Data Warehouse (DW)**: raccolta di dati orientata ,al soggetto, variabile e non volatile, di supporto ai processi decisionali
>- Gestiti da un opportuno sistema per analisi interattive dei dati
>- Terminologia anglosassone:
>	- Management Information Systems (MIS) 
>	- Decision support systems (DSS), data or model based 
>	- Executive Information System (EIS)
>## **OLAP: Acronimo di On-Line Analytical Processing** 
>- Uso principale dei data warehouse 
>- Caratteristiche Operazioni complesse e casuali 
>- Ogni operazione può coinvolgere moltissimi dati I dati sono letti, ma non modificati 
>- Dati aggregati, storici, anche non attualissimi
>
>![[Pasted image 20230918152201.png]]
>![[Pasted image 20230918152521.png]]



# 22 settembre: definizione DBMS e basi di dati

## basi di dati
- in generale una qualsiasi raccolta di dati permanenti gestiti tramite un elaboratore elettronico, ma per noi
	- E' una raccolta di dati permanenti divisi in due categorie:
		- Metadati: definiscono lo schema della BD, che descrive:
			- Struttura dei dati [e le operazioni eseguibili]
			- Restrizioni sui valori ammissibili (viincoli di integritá)
			- Utenti autorizzati, ecc.
		- Dati: le rappresentazioni di certi fatti conformi alle definizioni dello schema, con le seguenti caratteristiche:
			- Organizzati in insiemi omogenei, fra i quali sono definite delle relazioni. La struttura dei dati e le relazioni sono descritte nello schema usando i meccanismi di astrazione del modello dei dati adottato
			- Sono molti, in assoluto e rispetto ai metadati, e non possono essere gestiti in memoria temporanea
			- Sono permanenti, continuano ad esistere finché non sono rimossi esplicitamente 
			- Sono utilizzabili contemporaneamente da utenti diversi