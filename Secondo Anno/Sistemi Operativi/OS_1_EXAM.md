
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


