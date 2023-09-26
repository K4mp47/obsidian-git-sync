# Introduzione
> - Due compiti intermedi per non dover per forza fare il modulo 1
> - Modulo 2: solo se modulo 1 é stato passato
> - 


# Esercizi
>- Tre differenze tra personal computer e mainframe
>- Differenza modalitá utente e modalitá nucleo
>- Perché due modalitá rendono la creazione dell'OS piú semplice
# 19 settembre 2023: introduzione a sistemi operativi

## Cos'é un sistema operativo:
>- macchina astratta
>- gestore di risorse
>	- bisogna ottimizzare la gestione delle risorse per migliorare le performance della macchina

```
utenti(applicazioni)
------------
SO (macchina astratta, astrazione della macchina reale per l'utente)
(si occupa anche di gestire le risorse HW)
------------
HW(componenti fisici, HDD, SSD, RAM, I/O, ecc.)
```
## Struttura del sistema operativo:
>- Monolitica
>- a livelli
>- MicroKernel

#### Definizione di SO: software che controlla l'HW
> SO funziona da interfaccia tra utente/applicazioni ed HW, inoltre si occupa di gestire le risorse della macchina

![[Pasted image 20230919145405.png]]

```
Software:
[
	User mode:
	[
		User Interface,
		Other programs(web browser ecc.)
	]
	Kernel mode:
	[
		Operating System
	]
]
HW:[]
```

>SO: principalmente usa i sistemi in modalitá nucleo (Kernel), le applicazioni invece sono invece principalmente in modalitá kernel

![[Pasted image 20230919145526.png]]
> Con il termine *programmi di sistema* ci riferiamo a quei programmi usati per eseguire le operazioni (Compilatori, editor, ecc.)

> I'OS é una macchina estesa che:
> - Nasconde i dettagli delle operazioni eseguite (**MASCHERAMENTO**)
> - Presenta all'utente il sistema con un interfaccia semplice da usare (**TRASPARENZA**)
> - Gestisce le risorse, perché:
> 	- Ogni programma richiede tempo e spazio per le risorse

>**SISTEMI BATCH**:
>- I programmi e i dati caricati in sequenza su un nastro
>- Spostati sul computer ed eseguiti a lotti (batch)
>- Output stampato su nastro
>- Altri computer piú piccoli per lettura/scrittura da/verso nastro
>
>![[Pasted image 20230920104702.png]]

> Schedulatore si occupa nei sistemi multiprogrammati si occupa di gestire l'ordine di esecuzione dei processi
> **MULTIPROGRAMMAZIONE**: un job puó usare il processore, mentre altri job usano le unitá periferiche. Partizione della memoria, assegnando le parti ai diversi job.
> 
# 20 settembre 2023: scheduling

> lo scheduler sceglie quali programmi dare in pasto alla CPU, tramite algoritmi di scheduling
> 
> ![[Pasted image 20230920105428.png]]
> - [x] si parla nell'immagine ancora di sistemi batch e non multiprogrammati
> 
> I sistemi di terza generazione invece:
> - Scompare l'operatore
> - Linguaggi di alto livello
> - Editor testuali
> - Accesso da terminale
> - *Multiprogrammazione*
> - Protezione
> - Scheduling
> - Allocazione risorse I/O
> - SPOOL (Simultaneous Peripheral Operation On Line)
> 	- Operazioni concorrenti, esecuzione di job parallela ad operazioni I/O
> 	- Trasferimento dati
>
>Sistemi timesharing:
>- Variante dei multiprogrammati, sviluppata per supportare molti utenti interattivi simultanei
>- Tempo di CPI diviso in quanti di tempo
>- Al termine del quanto il job viene interrotto e se ne assegna uno nuovo alla CPU
>- Memorie virtuali
>- Tempo di risposta ridotto a minuti o secondi
>- Progettazione dei sistemi timesharing:
>	- Gestione del processore
>	- Gestione della memoria
>	- Protezione delle risorse
>
>Sistemi real-time:
>- Hard real-time e soft real-time

>Le generazioni successive di sistemi invece(anni '70):
>- Supportano l'elaborazione di applicazioni batch, timesharing e in tempo reale
>- Sistemi come:
>	- Unix
>- Sviluppo di primi semplici personal computer
>- Sviluppo di Internet, sviluppo protocollo TCP/IP
>	- Protocollo di comunicazione standard
>	- Usato soprattutto in ambito militare
>	- Problemi di sicurezza 

>Negli anni successivi invece:
>- Decenni dello sviluppo dei personal computer e workstation
>- PC per singoli utenti
>- Elaborazine distribuita ai siti in cui é richiesta
>- I personal computer diventano relativamente facili da imparare e da usare
>	- Sviluppo di interfacce grafiche
>- trasferimento dati internet/computer diventa molto piú economico e a portata di tutti


> Generazione anni 80:
> - Diffusione modello client/server
> - Sviluppo ed evoluzione dell'area dell'ingegneria del software
> 	- Reusable Code
> 	- Multithreading
> 	- Astrazione linguaggi di programmazione

> #### Cenni sulla storia di internet e del WWW
> - Advanced Research Projects Agency (ARPA)
> 	- Dipartimento della difesa
> 	- fine anni '60, implementa ARPAnet
> 		- Predecessore di Internet
> 		- Capace di comunicazione quasi istantanea(email)
> 		- Progettata per operare senza un controllo centralizzato
>
>- TCP/IP
>	- Insieme di regole per comunicare in ARPAnet
>	- gestisce la comunicazione tra applicazioni
>	- Si assicura che i messaggi siano instradati correttamente dal mittente al destinatario
>	- Usato poi a livello commerciale
>
>- WWW (World Wide Web)
>	- Individuare e visualizzare documenti multimediali su qualsiasi argomento
>	- Primi sviluppi nel 1989
>	- La tecnologia per la condivisione di informazioni
>		- Hypertext Transfer Protocol (HTTP)
>			- Protocollo di comunicazione
>		- Hypertext Markup Language (HTML)
>			- Definizione del formato dei documenti del WWW



# 26 settembre 2023:
>