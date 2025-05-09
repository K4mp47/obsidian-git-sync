
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
			- Sono protetti da accesso da parte di utenti non autorizzati, sia da corruzioni dovuta  a malfunzionamenti hardware e software

- DBMS: é un sistema centralizzato o distribuito che offre strumenti per:
	- Definire lo schema della BD(definito prima di creare dati)
		- definito usando il modello dei dati adottato del DBMS
		- interrogabile con le stesse modalitá previste per i dati
	- Scegliere le strutture dati per la memorizzazione dei dati
	- memorizzare i dati rispettando i vincoli definiti nello schema
	- recuperare e modificare i dati interattivamente (linguaggio query) o da altri programmi

## Architettura dei DBMS Centralizzati

![[Pasted image 20230922090332.png]]

### Modello relazionale (modello piú diffuso ancora oggi)
>Il meccanismo di astazione fondamentale é la relazione (tabella) con campi di tipo elementari (stringhe, caratteri, interi, ore, invece di liste o oggetti)
>
>![[Pasted image 20230922090610.png]]
>Lo schema specifica le tabelle
>	- nome
>	- struttura degli elementi (nome e tipo di attributi)
>	- Vincolo chiave primaria, con essa non possono esistere due elementi con lo stesso valore scelto come chiave primaria (nella tabella é Matricola)

Definizione schema:
![[Pasted image 20230922091556.png]]
```sql
CREATE DATABASE EsempioEsami;

CREATE TABLE Studenti (
	Nome char(8), 
	Matricola int NOT NULL, 
	Citta char(10), 
	AnnoNascita int, 
	PRIMARY KEY (Matricola)
);

CREATE TABLE ProveEsami ( 
	Materia char(5), 
	Matricola int, 
	Data char(6), 
	Voto int, 
	Lode char(1), 
	PRIMARY KEY (Materia,Matricola) 
);

# inserizione dati

INSERT INTO ProveEsami 
VALUES ('BD', 71523,'28.12.06',30, 'S');

# interrogazione dati

SELECT Matricola # campo da estrapolare
FROM ProveEsami # da quale tabella estraggo il dato
WHERE Materia = ‘BD’ AND Voto = 30;  # condizioni extra

Matricola 71523
```

>Chiave: individua in maniera univoco in uno schema minimale(meno attributi di quelli scelti non permetto la distinzione univoca degli elementi)
>Super chiave: insieme di attributi che identificano in maniera univoca un elemento

> - Linguaggio per la definizione della base di dati (DDL)
> - Linguaggi per l'uso dei dati (DML)
> - Meccanismi per il controllo dei dati
> - Studenti per il responsabile della base di dati
> - Strumenti per lo sviluppo delle applicazioni
> ![[Pasted image 20230922092715.png]]
> ## Schema logico: 
> - Descrive la struttura degli insiemi di dati e delle relazioni fra questi, secondo un certo modello dei dati, senza nessun riferimento alla loro organizzazione fisica nella memoria permanente.
> - Esempio:
> 
> ![[Pasted image 20230922092818.png]]
> 
> ## Livello fisico:
> - Descrive lo schema fisico o interno:
> 	- Come vanno organizzati fisicamente i dati nelle memorie permanenti
> 	- Strutture dati ausiliarie per l'uso (es. indici)
> - Esempio:
> 
> ![[Pasted image 20230922093247.png]]
>
>## Livello vista logica:
>- Descrive come deve apparire la struttura della base di dati ad una certa applicazione (schema esterno o vista)
>- Esempio:
>
>![[Pasted image 20230922093413.png]]
>
>## Indipendenza logica e fisica
>- Indipendenza fisica: i programmi applicativi non devono essere modificati in seguito a modifiche dell'organizzazione fisica dei dati
>	- strutture ausiliarie
>	- modifica della distribuzione
>- Esempio:
> 
> ![[Pasted image 20230922093727.png]]
> 
> - Indipendenza logica: i programmi applicativi non devono essere modificati in seguito a modifiche dello schema logico
> 	- difficile da ottenere
> 	- richiederá la ridefinizione dello schema esterno
> 
>- Esempio: per suddividere la collezione degli studenti in part-time e full-time
> 	  
>![[Pasted image 20230922093933.png]]


# 25 settembre: DBMS(parte 2)

> Strumenti per l'amministrazione della base di dati
> 	- Linguaggio per la definizione e la modifica degli schemi della base di dati
> 		- Logico, esterno e fisico
> 	- Strumenti per il controllo e messa a punto del funzionamento del sistema
> 	- Strumenti per stabilire i diritti di accesso ai dati
> 	- Strumenti per ripristinare la base di dati in caso malfunzionamenti di sistemi o disastri
> 
> - Riepilogo vantaggi DBMS
> 	- Indipendenza fisica e logica
> 	- Gestione efficiente dei dati
> 	- Integritá e sicurezza dei dati
> 	- Accessi interattivi, concorrenti e protetti dai malfunzionamenti
> 	- Amministrazione dei dati
> 	- Riduzione dei tempi di sviluppo delle applicazioni
> 
> - Svantaggi 
> 	- Possono essere costosi e complessi da installare e mantenere in esercizio
> 	- RIchiedono personale qualificato
> 	- Le applicazioni sviluppate possono essere trasferite con difficoltá su sistemi diversi se vengono usati linguaggi troppo "legati" al DBMS usato
> 
> 	MA
> 	- La riduzione dei costi della tecnologia e i possibili di DBMS disponibili sul mercato facilitano la loro diffusione
> 	  

# 25 settembre: Progettazione di una BD
> - Progettare una BD significa
> 	- Progettare la struttura dei dati
> 	- Progettare le applicazioni
> - Progettazione di un modello
> 	- Cosa significa definire un modello
> 	- Cosa si modella
> 	- Come si modella
> 	- Come si procede nella costruzione del modello
>
>
>**Modello astratto**=> rappresentazione formale di idee e conoscenze relative a un fenomeno 
> ## Modelli Informatici
> Aspetti di un modello:
> - Il modello é una rappresentazione di certi fatti
> - La rappresentazione é data con un linguaggio formale
> - Il modello é il risultato di un processo di interpretazione, guidato dalle idee e conoscenze possedute dal soggetto che interpreta
>  ![[Pasted image 20230925142014.png]]
>  Ogni fase é centrata sulla modellazione.
>  La modellazione verrá discussa quindi con riferimento alla problematica della progettazione delle basi di dati
>  ## Modellazione concettuale, aspetti del problema
>  - Quale conoscenza del dominio del discorso si rappresenta? (ontologico)
>  - Con quali meccanismi di astrazione si modella? (logico)
>  - Con quale linguaggio formale si definisce il modello? (linguistico)
>  - Come si procede per costruire un modello? (pragmatico)
>  **Cosa si modella?**
>  - I fatti
>  - Struttura e vincoli sulla conoscenza concreta
>  - Le operazioni di base
>  - Le operazioni degli utenti
>  - Come si comunicherá con il sistema informatico


# 29 settembre: Oggetti del DB
> - Ad ogni entitá del dominio corrisponde un oggetto del modello informatico
> - Un oggetto é un'entitá software con stato, comportamento ed identitá
> 	- stato: modellato da un insieme di costanti o variabili
> 	- comportamento: modellato da un insieme di procedure chiamate metodi
> 	- identitá: associazione fatta con l'oggetto dalla creazione e non viene modificata da aggiornamenti dello stato
> - Il primo passo nela costruzione di un modello é  la definizione dei tipi di oggetti per classificare le entitá del dominio. Il tipo definisce:
> 	- componenti dello stato
> 	- metodi
> ![[Pasted image 20230929090535.png]]
> i tipi di attributi:
> - primitivi (int, bool, real, date, ecc.)
> - non primitivi
> 	- ottenuto applicando anche degli operatori come:
> 	 ![[Pasted image 20230929090654.png]]
> 	- 