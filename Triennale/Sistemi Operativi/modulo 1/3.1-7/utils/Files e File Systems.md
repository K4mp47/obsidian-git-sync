-   Un insieme di dati denominati manipolabili come una unità per operazioni come:
    - Open
    - Close
    - Create
    - Destroy
    - Copy
    - Rename
    - List
- I file sono spesso nominati con un estensione, al fine di distinguerne il tipo di utilizzo
- Struttura di un file
	- Sequenza di byte
	- Sequenza di record
	- Albero
- Tipi di File
	- File (Informazioni utente)
	- Directory (Struttura del File System)
- Accesso ai file
	- Sequenziale
		- Legge tutti i bytes dall'inizio
		- Non può fare salti, solo tornare dietro o continuare
	- Casuale
		- Lettura in qualsiasi ordine
		- Indispensabile in DB
		- Prima si sposta il puntatore e poi si legge o viceversa
- I singoli elementi di dati all'interno di un file possono essere manipolati da operazioni come 
	- Create 
	- Append 
	- Delete 
	- Seek 
	- Open 
	- Get attributes 
	- Close 
	- Set attributes 
	- Read 
	- Rename 
	- Write
- Caratteristiche di un file:
    - Locazione
    - Accessibilità
    - Tipo
    - Volatilità
    - Attività
- I file possono includere più record
    - fisico (unità di informazione sul dispositivo di memoria)
    - logico (Insieme di dati trattati dal software come una unità logica)
- Il File System:
    - Organizza i file e gestisce l'accesso ai dati
    - Gestisce la memoria ausiliaria
    - Gestisce i meccanismi di integrità dei dati
    - Gestisce i metodi di accesso
    - Principalmente operano nella memoria su disco, secondaria
    - Dovrebbe essere indipendente dal dispositivo
    - Dovrebbe gestire guasti e sicurezza
	    - Dovrebbe fornire funzionalità di backup e ripristino per prevenire la perdita accidentale o malevola di informazioni
	    - Può fornire funzionalità di crittografia e de-crittografia per rendere più sicure le informazioni

[[Directories]]