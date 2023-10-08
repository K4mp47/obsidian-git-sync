> - Indicare le due funzioni principali di un sistema operativo.?
>	- le due funzioni sono:
>		- gestione delle risorse verso hd
>		- macchina astratta, ovvero mascheramento e trasparenza

>- Descrivere i diversi tipi di sistema operativo e dare un esempio di applicazione per ciascuno.
>	- Batch
>	- Time sharing
>	- Pc
>	- realtime
>	- multimedia
>	- transazionali
>	- per dispositivi mobili
>	- Embedded
>	- smart-card
>	- sensori

> - In cosa differiscono i sistemi timesharing e i sistemi multiprogrammazione?
> 		- I sistemi multiprogrammazione si abbinano alla prima generazione di OS, attorno agli anni 50', permettevano di elaborare piu' job contemporaneamente, sfruttando anche le periferiche e facendo il partizionamento della memoria. Abbiamo anche i primi circuiti integrati, con una conseguente riduzione dei costi di aquisto. I sistemi timesharing si differiscono da quelli multiprogrammati, in quanto abbiamo i primi scheduler, per migliorare le performance del processore, viene creato per essere usato da molti utenti interattivi contemporaneamente, abbiamo per la prima volta il concetto di memoria virtuale e di protezione delle risorse.

>- Cosa si intende per DMA, come viene utilizzato e che vantaggi può portare in un sistema operativo?
>	- Per DMA si invende DIRECT MEMORY ACCESS, una tecnica usata per il trasferimento dei dati fra la memoria e le periferiche I/O. Le periferiche trasferiscono i dati direttamente alla memoria ed il canale DMA usa un controllore I/O per avvertire il processore quando una operazione e' terminata, in modo da poter riprendere controllo del bus usato dalla DMA. Questo componente migliora notevolmente le prestazioni del sistema nel caso di un elevato numero di operazioni che richiedono i dispositivi I/O.

> ## TO DO
> - Indicare i principali obbiettivi dei sistemi operativi e indicarne due che possono essere in contrasto.

>- Definire modalità utente e modalità nucleo in un sistema operativo e spiegarne l’utilizzo e la motivazione.
>	- Queste due modalita' vengono utilizzate per permettere al processo eseguito piu' o meno privilegi in merito all'accesso alle risorse e a le operazioni da poter eseguire. Il SO viene eseguito prevalentemente in modalita' nucleo, dato il fatto che spesso ha bisogno di operare a livello kernel. I processi utente invece vengono prevalentemente usati con la modalita' utente per il motivo opposto, ovvero che non devono poter operare a livello kernel.