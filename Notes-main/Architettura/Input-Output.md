i sistemi di input output sono usati per collegare il calcolatore a dispositivi esterni chiamati periferiche. Es. tastiera, mouse, rete wifi, etc.

I vari sottosistemi di un calcolatore comunicano attraverso interfacce predefinite.
Questo collegamento é solitamente realizzato mediante un bus, che implementa un canale di comunicazione condiviso di piú sottosistemi.
Vantaggi:
- Versatilitá
- Basso costo

Svantaggi:
- Puó diventare un collo di bottiglia

Sono fisicamente composti da un insieme di fili che veicolano i segnali elettrici.
- Fili di controllo
	- Richiesta di un' operazione IO
- Fili per dati
	- Dati per effettuare la richiesta o trasferire i risultati

Esempi di Bus:
- System bus (Corti, connettono memoria e CPU, corti veloci e proprietari)
- Backplane (Interconnettono dispositivi diversi con bande di trasferimento diverse)
- IO (Sata)

Il Bus puó poi essere:
- Sincrono
	- Vi é una linea di clock condivisa tra gli elementi connessi al bus
	- Con il clock si arbitrano gli accessi al bus
	- Limitato ai bus corti, altrimenti clock skew
- Asincrono
	- Clock non condiviso
	- Permette comunicazione tra periferiche con diverse velocitá
	- Necessitá di handshaking iniziale per sincronizzare i bus
	- Utilizza un principio di comunicazione molto simile al TCP (req e ack per comunicare)

Si necessita comunque di arbitrare gli accessi nel momento in cui piú dispositivi accedono allo stesso bus. Essi si connettono all'arbitro tramite delle linee aggiuntive.

### Tipi di arbitraggio
- Daisy Chain
- Completamente distribuiti (Ethernet)
- Centralizzato ma con linee multiple di richiesta/rilascio

Un operazione di IO non é altro che un trasferimento di dati che puó avvenire.
Per effettuare questi traferimenti occorre comunicare con il __controller__, con cui ci si interfaccia con la periferica.

Il controller contiene registri, tra i piú importanti:
- Command
- Status
- Data Write 
- Data Read


### Comunicazione con il controller
Due approcci:
- Memory Mapped IO 
	- i registri del controller sono visti come locazioni di memoria speciali a cui la CPU accede tramite lw e sw, Con La MMU che si incarica di mandare le richieste ai dispositivi e non in RAM
- Istruzioni Speciali
	- L'ISA della CPU comprende delle istruzioni speciali per leggere i registri di determinati controller

Un' operazione di IO tipica consiste nel:
- Verificare lo stato del dispositivo
- Dare dei comandi
- Scrivere/leggere i dati presenti nei registri dati

La CPU puó essere o no coinvolta in queste operazioni.

### Programmed IO (Polling)
Il processore é sempre coinvolto in tutti i singoli trasferimenti, e controlla periodicamente lo stato del dispositivo per capire se ci sono dati da trasferire.
Questa tecnica di IO ha il vantaggio di essere utile nelle applicazioni real-time e nei casi di frequenza di trasferimento molto alta, ma si spreca molto tempo per verificare se ci sono dati disponibili e si spreca tempo nel caso di lettura di dati dal dispositivo per scriverla in RAM.

### Interrupt-diven IO
Il dispositivo utilizza le interruzioni per segnalare alla CPU degli eventi come la presenza di dati da leggere.
la CPU gestisce l'interruzione per comunicare con il dispositivo.
Piú vantaggioso del Programmed IO se il dispositivo comunica raramente o a intervalli non predicibili, ma é piú dispendioso se si hanno frequenti comunicazioni e comunque questa tecnica presenta un overhead piú alto.

Per velocizzare l'esecuzione dei programmi, dato che finora l'accesso alla memoria é effettuato esclusivamente dalla CPU é stato introdotto il DMA(Direct Memory Access), un controller esterno alla CPU che si occupa del trasferimento dei dati, avvertendola del trasferimento quando concluso tramite un interrupt

Se il dispositivo trasferisce molti dati di continuo, é consigliato l'uso della DMA, Che deve peró essere implementato correttamente.
Infatti il DMA accedendo direttamente alla memoria potrebbe trovarsi con dati diversi nella stessa locazione rispetto alla CPU. Per sviare questi problemi si puó:
- Far passare tutta l'attivitá IO attraverso la cache risolvendo i problemi di coerenza dei dati ma avendo un impatto negativo sulle prestazioni
- Forzare write back in scrittura e invalidare selettivamente la cache per richieste IO di lettura
- Invalidare selettivamente alcuni blocchi della cache tramite l'hardware

Ma non solo, La DMA ha problemi anche con le PT e la TLB dato che utilizzano indirizzi virtuali. Le soluzioni sono
- Far intervenire il SO che fornisce le tabelle di traduzione necessarie
- Far lavorare DMA con indirizzi fisici frammentando il trasferimento in molteplici sotto-trasferimenti vincolati alla dimensione delle pagine

Tutto ció comporta un forte impatto Dell'IO sulle prestazioni!