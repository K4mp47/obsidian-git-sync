
### Definizione di sistema operativo:
> Un sistema operativo é il software che permette alle applicazioni di interagire con l'hardware. il software che ne contiene i componenti principali é chiamato kernel.
> I sistemi operativi sono principalmente gestori di risorse. Gestiscono le risorse hardware come processori e memorie, ma anche le applicazioni ed altri astrattismi software fisicamente in realtá inesistenti.




### Storia dei sistemi operativi:

- -> Anni '40
	- I primi calcolatori non avevano un SO
	- Programmatori costretti a caricare i programmi in **linguaggio macchina** usando interruttori meccanici
	- Si utilizzavano **schede forate** per caricare i vari programmi
	- Introduzione del linguaggio macchina
	  
- -> '50
	- General Motors realizza il **primo SO** per i computer **IBM 701**
		- I sistemi di questi anni eseguivano un solo job alla volta, spesso in esecuzione per ore o anche giorni
		- Noti anche come macchine **batch-system single-stream** per via dei dati salvati in nastri/dischi ed erano suddivisi in gruppi/lotti
		- Il programmatore é comunque costretto a controllare direttamente le risorse di sistema, vincolanti per la creazione dei programmi, che dovevano essere piccoli
- -> '60
	- Sempre macchina batch ma piú performanti
	- Inclusione delle prime periferiche come lettori e perforatori di schede
	- SO migliorati, ora mentre un job occupa il processore gli altri possono sfruttare le periferiche
	- Sistemi **MULTIPROGRAMMAZIONE**, ovvero sistemi che gestivano job diversi nello stesso tempo. Questo permetteva l'utilizzo concorrente di CPU e periferiche
	- Il principale obbiettivo di questi sistemi é la condivisione di risorse
	- Gli utenti interattivi ora dispongono di un terminale per poter interagire con i job durante l'esecuzione
	- Necessitá di ridurre i tempi di risposta data la presenza degli utenti interattivi, nascita dei sistemi **timesharing** e **realtime** 
	- Primi esempi di **debug**, dati i tempi ridotti tra invio del job e il suo completamento.(Utente poteva inviare al volo il programma, che tornava gli errori di sintassi, correggere gli errori e ripetere il ciclo fino ad avere un programma privo di errori, per poi occuparsi di quelli run-time)
- -> '70
	- Sistemi multiprogrammati supportano ora tutti i tipi di elaborazioni esistenti
	- I sistemi sperimentali del decennio precedente ora sono solidi prodotti commerciali
	- Crescono i **problemi legati alla sicurezza**, facendo si cresca anche l'importanza della **crittografia**
- -> '80
	- Primi personal computer (Personal IBM e Macintosh)
	- Creazione delle GUI per facilitare l'interfaccia utente
	- Primi esempi di comunicazione con elaborazione distribuita, modello client/server

- -> '90
	- Alla fine del decennio precedente un tipico personal computer era in grado di eseguire diverse centinaia di milioni di istruzioni al secondo
	- Crollo del costo della tecnologia ---> **incremento** numero **pc** nelle case
	- La creazione del **WWW** accrebbe la diffusione dell'elaborazione distribuita. L'elaborazione distribuita é diventata una realtá comune tra personal computer
	- SO ora possiede come **standard il supporto al networking**
	- Tecnologie ad oggetti. Gli **OOOS** hanno oggetti come rappresentazione dei componenti del SO e risorse del sistema. I concetti della programmazione orientata agli oggetti, come l'ereditarietá e le interfacce, sono stati sfruttati per creare sistemi operativi modulari piú facili da estendere e avere una manutenzione semplificata
	- **Open Source**. Il movimento Open Source nasce in contrasto al software commerciale di quel tempo, tutto codice venduto solo come oggetto, ovvero senza codice sorgente perché giá compilato, per nascondere segreti industriali/programmazione. Grazie a questo movimento abbiamo la nascita di molte tecnologie gratuite e con codice sorgente reso pubblico come Web Server Apache e Linux. nasce la GNU, tollkit linux libero usato da Linus Torvald per la creazione del primo Linux.
	- **OSI**. Organizzazione nata per la protezione del codice open source e per promuovere i benefici della programmazione open source.
- ->'2000
	- Diffusione dei dispositivi **cellulari** come tablet e smartphone
	- Sistemi distribuiti e **cloud computing**
	- Nascita dei **middleware** per collegare due diverse applicazioni
	- Parallelismo spinto, piú processori sulla stessa macchina per eseguire piú operazioni in contemporanea

#### Qualche nozione in piú
- ---> in piú: Piattaforme:
	- general-purpose
	- embedded
	- real-time
		- soft
		- hard
	- mission-critical
	- business-critical
	- virtual machine



### Storia di Internet e del World Wide Web
> Verso la fine degli anni '60 l'ARPA mise a punto un progetto per collegare in rete i sistemi di elaborazione di una dozzina di universitá e centri di ricerca da essi finanziati. Realizzó in poco tempo la "nonna di Internet" ovvero ARPAnet. Forniva principalmente e-mail come forma di comunicazione. ARPAnet funzionava senza un controllo centralizzato, in modo che se una parte della rete fosse divenuta non funzionante, il resto della rete sarebbe comunque rimasto in grado di scambiare i dati.
> Il WWW nasce dalla fusione del funzionamento della ARPAnet con la tecnologia sviluppata da Tim Berners-Lee del CERN, la quale permetteva di condividere documenti testuali con collegamenti ipertestuali all'interno. Per permettere questa tecnologia egli inventó HTML e il protocollo HTTP, gettando le basi per quello che oggi é conosciuto come WWW




### Componenti SO
>I sistemi operativi si sono evoluti negli anni per gestire al meglio il reparto hardware, con conseguente ottimizzazione delle prestazioni delle varie componenti. 
>Il software che contiene i componenti principali del SO é detto kernel. I tipici componenti di un SO sono:
>- scheduler: determina quando e quanto ogni singolo processo sará in esecuzione
>- gestore memoria: determina quando e quanta memoria allocare ai processi
>- gestore I/O: gestisce le richieste di I/O da e verso l'HW
>- gestore interprocess communication (IPC): process communication
>- gestore del file system: organizza raccolte di dati e fornisce interfaccia per accedervi
>
>Quasi tutti i SO oggi offrono supporto ad un ambiente multiprogrammato in cui piú applicazioni sono eseguibili concorrentemente.
>
#### Architettura di un SO
- Architettura monolitica
	- Piú vecchia e comune. Ogni componente fa parte del kernel, permettendo la comunicazione diretta tra di essi. Ció rende il sistema molto efficiente, ma risulta spesso difficile isolare fonti di errore, oltre che essere molto piú esposti a danni derivanti da codice errato o dannoso, essendo tutti i componenti raggruppati nel kernel
- Architettura a strati
	- Tenta di risolvere i problemi della monolitica raggruppando i componenti tra di loro in base alla loro funzione. Ogni strato comunica solo con quello immediatamente superiore o inferiore. Ció permette modifiche ad uno strato senza dover per forza influenzare gli altri strati. Ogni componente nasconde il modo in cui compie il proprio lavoro e fornisce un interfaccia standard per richiedere il servizio. Gli strati hanno comunque accesso al sistema, aumentando le vulnerabilitá, e data la struttura organizzativa,una richiesta per essere servita potrebbe dover passare per molti strati, riducendo quindi le prestazioni
- Architettura microkernel
	- Fornisce solo un piccolo numero di servizi nel tentativo di mantenere il kernel piccolo e scalabile. Questi servizi riguardano in genere la gestione a basso livello del sistema, IPC e cooperazione tra processi. La maggior parte dei componenti del SO, come per esempio lo scheduler, sono eseguiti al di fuori dello spazio del kernel. Risulta essere molto scalabile, portatile ed espandibile, ma data la comunicazione che deve essere presente tra i moduli abbiamo un calo di prestazioni del sistema
- Architettura di rete e distribuiti
	- SO che permette di accedere a risorse presenti su altri computer in rete. In questa architettura bisogna prestare molta attenzione alle problematiche di gestione dei dati e delle comunicazioni tra computer. Un sistema distribuito é un singolo SO in grado di gestire risorse distribuite su piú sistemi di elaborazione. Sono molto difficili da realizzare e richiedono algoritmi complessi per condivisione e comunicazione dei dati tra processi



### Componenti HW/SW

> Le componenti hardware per essere chiamate da un processo dispongono di un componente software chiamato driver che si occupa di gestire le varie chiamate. Il driver avendo forti dipendenze in base al dispositivo HW chiamato, deve essere prima installato sulla macchina. Per inserire un driver nel SO ci sono diversi metodi, il piú utilizzato oggi é noto come plug-and-play che permette di installare il driver senza riavviare la macchina.
#### Schede Madri:
- Per permettere ai dispositivi indipendenti di comunicare tra loro, i PC sono dotati di una o piú schede a circuito stampato o PCB. Essa fornisce alcuni slot per connetterci altri componenti come la memoria centrale o la cpu. In genere dispongono di un circuito integrato chiamato BIOS che memorizza le istruzioni di base per l'inizializzazione e gestione dell'hardware. Dispongono spesso di altri chip che fungono da controller, per le cose piú disparate, dalla gestione del sistema RAID a quella del trasferimento di dati tramite bus.
##### CPU: 
- Cervello del PC, esegue un flusso di istruzioni in linguaggio macchina. I processori dei computer possono essere di diverso tipo. Le istruzioni che esso esegue sono definite all'interno di un istruction set, differente in base al processore. Le istruzioni hanno una dimensione che puó anch'essa differire in base all'architettura. Da essa dipende anche la quantitá di dati elaborabile contemporaneamente. Alcuni componenti sono comuni a tutti i processori moderni, come l'unitá di caricamento delle istruzioni, il revisore dei salti, i registri, le memorie cache, ecc.
- Cache L1,L2  contenute all'interno della cpu, permettendo un rapido accesso alle istruzioni piú usate
- I registri invece sono memorie ad alta velocitá situate nel processore che contengono dati per utilizzo immediato. I dati vanno memorizzati nei registri prima che un processore possa operare su di loro. Memorizzare le istruzioni in un qualunque tipo di memoria piú lenta sarebbe inefficiente, in quanto il processore rimarrebbe inutilizzato durante l'attesa dei dati. Esistono registri dedicati all'esecuzione dei programmi. Questi di solito vengono chiamati general-purpose. Altri tipi di registri, chiamati di controllo, memorizzano specifiche informazioni sul sistema, come il contatore del programma in esecuzione, o program counter, utilizzato per sapere l'indirizzo di memoria della prossima istruzione da eseguire. Alcuni registri sono poi visibili al programmatore come il program counter, lo stack pointer o il Program status word. Se ci troviamo nel momento in cui un operazione viene fatta in modalitá utente ma necessita dei permessi che solo la mod. nucleo offre, viene attivata la cosiddetta chiamata di sistema, dove un istruzione TRAP cambia la modalitá da utente a nucleo.
- Il tempo nei calcolatori é spesso misurato in cicli, chiamati clock. Essi fungono da direttori all'interno dell'intero sistema, determinando la frequenza con cui le operazioni vengono fatte.
- CPU pipeline VS CPU superscalare:
	- La CPU pipeline si occupa di dividere l'istruzione da eseguire in fasi, in modo da poter eseguire piú istruzioni contemporaneamente.
	- La CPU superscalare si occupa di eseguire piú operazioni contemporaneamente ma in modo piú avanzato rispetto alla pipeline, andando ad eseguire le istruzioni anche in base alle dipendenze, opportunitá, raggiungendo un maggiore numero di istruzioni per ciclo, anche se richiedono complessitá aggiuntiva rispetto alle pipeline
#### Gerarchie di memoria:
- Le memorie, in base alla loro grandezza e velocitá di accesso, vengono inserite in una gerarchia, che é organizzata come segue"
	- Registri (1ns, <1kB)
	- Cache (2ns, 4MB)
	- Memoria centrale (10ns, 1-8GB)
	- Disco magnetico (10ms, 1-4TB)
#### Memoria Centrale:
- Consiste in memoria ad accesso casuale volatile, nota come RAM. Essa poi si divide in due sottocategorie, la DRAM e la SRAM, la prima dove é presente un circuito di refresh che periodicamente rilegge i dati che altrimenti andrebbero persi(invia un impulso), la seconda che invece non necessitá di refresh. Esistono altri tipi di memoria, anche non volatile, come le ROM, EEPROM (una ROM peró riprogrammabile) e la CMOS.
#### Memoria Secondaria:
- Le memorie principali non sono adatte alla memorizzazione di grandi quantitá di dati, essendo dalla capacitá limitata e volatili. Gli elaboratori usano quindi dispositivi di memorizzazione secondari, capaci di mantenere salvato il dato anche in assenza di alimentazione. Sono comunque decisamente piú lente per quanto riguarda l'accesso al dato, motivo per cui non possono essere utilizzate come memorie principali. Oggigiorno le tecnologie piú diffuse di memoria secondaria sono i HDD SSD. Altre unitá secondarie rimovibili come i DVD, CD, memorie flash, permettono di facilitare operazioni come il backup e il trasferimento di dati
#### Accesso diretto alla memoria (DMA):
- Tipo di accesso alla memoria fatto dal I/O in memoria, che permette di trasferire interi blocchi di dati mentre il processore continua ad eseguire istruzioni software. Un canale DMA utilizza un controller I/O per gestire il trasferimento. Per comunicare al processore l'avvenuto trasferimento invia un segnale d'interruzione al termine dell'operazione. La tecnica descritta é compatibile con diverse architetture di bus.

#### Dispositivi periferici:
- Qui rientrano tutti i dispositivi hardware che non sono strettamente necessari per il calcolatore al fine di eseguire istruzioni software. Ne fanno parte tastiere, mouse, stampanti, schede di rete o dispositivi di memorizzazione. Generalmente si collegano tramite cavo USB, che funge sia da canale di comunicazione sia da alimentatore.
- La gestione dei dispositivi I/O avviene tramite busy waiting, interrupt o DMA.
	- Busy waiting
		- Si richiede tramite system call l'accesso al dispositivo, che il kernel elabora in una procedura per il driver appropriato. Il driver allora comincia la chiamata al dispositivo ed entra in un loop continuo in cui chiede al dispositivo I/O se ha finito l'operazione. Questo metodo blocca la CPU fino a che il dispositivo non ha finito.
	- Interrupt
		- Metodo piú complesso. Qui viene effettuata la chiamata al dispositivo che viene inviata al controller del dispositivo(driver), il quale avvia e conclude l'operazione di I/O. Quando l'operazione si conclude, il controller invia un segnale di interrupt all'interrupt controller. Se questo risulta libero, invia subito alla CPU un segnale tramite un pin per avvertirla dell'arrivo di un interrupt, per poi inviare al processore il numero del dispositivo, cosí da avvisare quale dispositivo ha appena finito l'operazione.
	- DMA
		- HW speciale che controlla il flusso di dati tra memoria e controller senza CPU intervention. Esso comunque avvisa tramite interrupt quando ha finito

- Dato il forte avanzamento tecnologico, l'utilizzo di un singolo bus per il trasferimento dei dati non era piú ottimale, per questo sono stati inseriti dei bus aggiuntivi per dispositivi I/O piú veloci e per il traffico dati CPU-to-memory.

#### Sistemi Operativi
> Sistemi operativi pensati per alto livello di astrazione, occorre definire speciali requisiti di progetto e supporto hw
> - Grande memoria principale
> - HW per usi speciali
> - Grande numero di processi
- Sistemi integrati, caratterizzati da un insieme limitato di risorse specializzate. Forniscono funzionalitá per vari tipi di dispositivi come telefoni cellulari e PDA
- SO per mainframe, grandi capacitá di I/O, per servizi batch, time-sharing, transazioni
- SO per server, gestione di molti utenti, per servizi di archiviazione, web server, ISP
- SO per multiprocessore, computer parallei, multiprocessi, coerenza nella connessione
- SO per PC, multiprogrammazione, un utente
- SO per palmari(pda), molte app al loro interno, attenzione per sensori, fotocamera, CPU multicore
- SO integrati(embedded), per il controllo di dispositivi, accezzione eccezionale dei dispositivi
- SO per sensori
- SO real-time, ovvero con processi in scadenza, soft o hard
- SO smart-card, ovvero pagamento elettronico, trasporto, amministrativi
 
- Esempi SO:
	- Batch 
	- Interattivi in time sharing (es. Unix) 
	- Per P.C. (es. Windows, Mac OSX, Linux) 
	- Real-time (es. telefonia, sistemi di controllo) 
	- Multimedia (es. video on demand) 
	- Transazionali (es. operazioni brevi, banche dati) 
	- Per dispositivi mobili (es. smartphone, PDA, tablet) 
	- Embedded (integrati, elettrodomestici, automazione






### Processi
#### Modello
- Immaginiamo una macchina che sta eseguendo 4 programmi contemporaneamente. Questi 4 processi agiscono indipendenti uno dall'altro (concetto di multiprogrammazione), ovviamente é peró presente solo un vero e proprio program counter, quindi quando un processo é in esecuzione, il suo program counter logico viene caricato in quello reale. Da qui si puó poi accedere al vero indirizzo di memoria.
- I SO forniscono servizi per i processi:
	- Creazione
		- La creazione di un processo avviene quando: 
			- si inizializza il sistema 
			- dopo una chiamata di sistema di creazione 
			- dopo una richiesta di utente di creazione 
			- per servire batch jobs. 
		I processi possono essere attivi(foreground) o agenti in background(daemon).
		- Per creare un Processo:
			- In UNIX si usa la fork
				- Si crea un clone del processo chiamante
				- I due processi condividono l'immagine di memoria, ambiente e file aperti
				- Il processo figlio di solito esegue execve per cambiare la propria immagine ed eseguire un nuovo programma
			- In Windows si usa la CreateProcess
				- Una sola chiamata di Win32, con 10 parametri
				- Win32 ha oltre 100 altre funzioni per gestire e sincronizzare i processi
			- Dopo la creazione di un nuovo processo, sia UNIX che Windows, il processo padre e figlio hanno spazi di indirizzi separati. In ambiente UNIX il figlio e il padre condividono memoria non scrivibile dal figlio, oppure siamo in una condivisione copy-on-write, ovvero i due processi condividono la stessa memoria, fino a che uno dei due non tenta di effettuare una modifica. In questo momento allora viene creata una copia delle pagine di memoria fisica e assegnata al processo che vuole eseguire una modifica, mentre l'altro processo continua ad operare sugli stessi indirizzi di prima. I sistemi Windows invece creano da subito un figlio con uno spazio separato
	- Chiusura
		- Un processo prima o poi deve concludere il suo ciclo di vita. Solitamente succede quando si ha: 
			- Uscita normale volontaria
			- Uscita per errore volontaria
			- Errore critico non volontario
			- Uscita forzata da un altro processo, non volontaria
		- La chiamata in ambiente UNIX si chiama exit mentre in ambiente Windows si chiama ExitProcess
		- Quando peró abbiamo una uscita forzata da un altro processo, é quest'ultimo che effettua una chiamata kill o TerminateProcess per terminare un altro processo
	- Gerarchia dei processi
		- Presente solo sui sistemi UNIX (Window gestisce i processi creati da altri processi dando al padre un token speciale usabile per controllare il processo figlio)
		- In UNIX ogni processo e tutti i suoi figli sono raggruppati in gruppi. Quando un utente invia un segnale dalla tastiera (es. Ctrl-C), il segnale viene inviato a tutti i processi appartenenti al gruppo associato alla tastiera. Poi, ogni processo gestisce il segnale individualmente. Un altro esempio di gerarchia in sistemi UNIX é che tutti i processi sono discendenti da un processo padre speciale, creato all'avvio della macchina, chiamato *init*. Da esso, partono tutti i processi.
	- Distribuzione
	- Sospensione
		- Rimuovere il processo dalla contesa per il tempo sul processore senza distruggerlo
		- Utile per effettuare controlli di sicurezza
		- Puó essere richiesta dal processo stesso come da un altro
		- Due stati di sospensione che sono *suspendedready* e *suspendedblocked*
		- Per uscire dallo stato di sospeso deve essere riavviato da un altro processo
	- Ripresa
	- Modifica prioritá
	- Risveglio
	- Dispatching
		- Assegnare un processore per il primo processo della lista pronta
	- IPC
#### Stati di un processo
- Un processo si sposta attraverso una successione di stati:
	- Stato Running
		- Processo in esecuzione
	- Stato Ready
		- Processo pronto per l'esecuzione
	- Stato Blocked
		- Processo in attesa di qualche evento prima di poter proseguire
#### PCB
- Process Control Blocks, descrive un processo. Tipicamente contiene informazioni come:
	- PID
	- Stato del processo
	- Contatore
	- Stack pointer
	- Proritá
	- Diritti
	- Puntatore al padre
	- Puntatore ai processi figli
	- Puntatore per localizzare dati ed istruzioni del processo in memoria
	- Puntatore alle risorse allocate
- Il SO mantiene i puntatori ai PCB di ogni processo in una tabella di sistema o una tabella di processo per utente, permettendone un rapido accesso. Quando un processo termina, il SO si occupa di rimuovere il processo dalla tabella e liberare tutte le risorse
- Il processore usa il PCB per effettuare il context switching, ovvero per cambiare il processo in esecuzione, salvando il "contesto" di esecuzione del processo in stato *running* nel PCB assegnato e caricare il nuovo da un processo *ready*. Tutto questo avviene in maniera trasparente ai processi.

#### Interrupt
- Abilitano il software a rispondere ai segnali hardware. Puó essere inizializzato da un processo in esecuzione tramite la *trap*. In questo caso sono sincrone con le operazioni del processo. Possono anche essere avviate da qualche evento che non per forza é correlato a qualche processo. In questo caso sono asincroni con le operazioni del processo. Si ha un basso overhead. Si potrebbe anche usare il Polling, ma risulta molto meno efficiente, avendo un alto overhead in base alla complessitá.
- Vengono gestiti in maniera semplice dalla CPU. Appena riceve un interrupt, conclude l'esecuzione dell'istruzione corrente per poi interrompere il processo, esegue la funzione di interrupt di gestione del kernel, il gestore di interrupt determina come dovrebbe rispondere (i gestori sono salvati in un array di puntatori chiamato interrupt vector), per poi al termine della chiamata, ritornare all'esecuzione del processo.
- Esistono sia gli interrupts che le eccezioni. quest'ultime al contrario degli interrupts indicano che si é verificato un errore, sia hardware che come risultato di un'istruzione software
- Gli interrupt si dividono in:
	- I/O
	- Timer
	- Interruzione per comunicazione interprocessor
	
	Mentre le eccezioni si dividono in:
	- Fault
	- Trap
	- Abort

