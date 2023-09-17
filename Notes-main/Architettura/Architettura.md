## Modello catena di montaggio
> le operazioni della CPU vengono eseguite simultaneamente, ma applicate a istruzioni successive.
> - trasparente al programmatore
> - ciascuna istruzione impiega lo stesso tempo per essere completata ma il throughput(numero di istruzioni eseguite in un certo lasso di tempo) é superiore
> - Il CPI si abbassa
> 
> In modalitá __pipeline__ il job viene suddiviso in stadi, in modo da usare le unitá funzionali in parallelo.
> La pipeline risulta vantaggiosa se il numero di istruzioni é grande rispetto al numero di stadi,  aumentando quindi il throughput e ricavandone uno speedup significativo! 
>
>Per permettere la corretta implementazione della pipeline, abbiamo bisogno di modificare il datapath, avendo la necessitá di accedere ai valori calcolati dallo stage precedente. Per permettere tutto ció, ad ogni stadio della CPU viene aggiunto un registro chiamato __registro intermedio__, permettendo alle istruzioni di passare fino al completamento.
>Il primo problema che si riscontra é con l'istruzione lw, che obbliga ad implementare un altro registro da passare nei registri intermedi, cosí da poter tornare in un altro posto il risultato della lw senza fare errori.
>Nel processore a singolo ciclo i segnali di controllo permettono di configurare multiplexer e ALU nel modo corretto a seconda dell'istruzione da eseguire.
>- IF e ID devono essere eseguiti sempre, ad ogni ciclo di clock, i loro segnali di controllo non dipendono dal tipo di istruzione
>- il controllo, in corrispondenza di ID, calcola i segnali per tutti e tre gli stadi successivi. I segnali devono essere propagati attraverso i registri intermedi tra gli stadi (allo stesso modo in cui portiamo avanti valori che ci potrebbero servire come il PC).
>
>## Hazard
>Ci sono casi in cui l'esecuzione del'istruzione corrente dipende dai risultati dell'istruzione precedente, e questa situazione é chiamata __hazard__ o  __criticitá__. Ció che produce é lo stallo:
>- Lo stadio della pipeline che ha scoperto la criticitá, assieme agli stadi precedenti, rimangono in stallo,(ovvero rieseguono la stessa istruzione).
>- Vengono introdotte delle __nop__ (dete in gergo bolle d'aria) alle unitá seguenti della pipeline.
>
>Lo stallo si propaga fino a quando la criticitá non é risolta.
>Lo __STRUCTURAL HAZARD__ accade quando un'istruzione ha bisogno della risorsa che é peró occupata da un'istruzione precedente che non é ancora uscita dalla pipeline.
>
>Il __DATA HAZARD__ invece é causato da dati che vengono letti e scritti dalle istruzioni:
>```
>add $s1, $t0, $t1
>sub $s2, $s1, $s3 // Questa istruzione deve entrare in stallo fino a che 
>				  // l'istruzione precedente non ha completato la scrittura 
>				  // di $s1 nel register file
>```
>In questo tipo di criticitá abbiamo la dipendenza sui dati tra coppie di istruzioni, che implica un ordine di esecuzione relativo non modificabile. Ci sono tre possibili dipendenze sui dati:
>- RAW (lettura di un registro dopo che é stato scritto)
>- WAW (scrittura di un registro dopo che é stato scritto)
>- WAR (scrittura di un registro dopo che é stato letto)
>
>Nel caso di una CPU semplice dove l'ordine delle istruzioni viene rispettato, l'unica dipendenza importante da considerare é la RAW:
>- la scrittura di un registro avviene allo stage 5 (WB)
>- la lettura di un registro avviene allo stage 2 (ID)
>
>### Hazard detection unit
>La necessitá di mettere in stallo la pipeline viene individuata nello stadio ID dell'istruzione sub
>- lo stadio ID e lo stadio IF restano in stallo per tre cicli
>- lo stadio ID propaga 3 nop lungo la pipeline
>
>La Hazard detection unit contenuta nello stadio ID confronta i registri dell'istruzione corrente con quelli usati nelle istruzioni precedenti.
>
>Se viene rilevata una dipendenza, l'ID propaga delle nop agli stadi successivi mentre IF e ID continuano ad eseguire la stessa operazione.
>Per mettere in stallo la pipeline, i segnali di controllo devono essere sostituiti con i segnali di controllo di una nop. I registri del PC e IF/ID (registro intermedio tra istruction fetch e istruction decode) non vengono aggiornati.
>Queste dipendenze RAW possono essere risolte senza la Hazard detection unit modificando il codice prima della sua esecuzione.
>- Si inseriscono delle nop manualmente in modo da evitare esecuzioni scorrette
>- Stalli espliciti
>- Compilatore piú complesso, CPU piú semplice(non abbiamo bisogno della hazard detection unit)
>
>Le dipendenze RAW sono molto frequenti e anche unsando il compilatore per minimizzare il numero di nop avremmo una forte perdita di prestazioni. Sappiamo peró che possiamo prendere il valore (per alcune istruzioni) direttamente dallo stadio EXE e non per forza dobbiamo aspettare che l'istruzione venga completata. Basta salvare il valore della EXE della istruzione precedente a quella corrente per poter usare direttamente il dato ritornato. In questo modo sono necessari un minor numero di stalli. Nel caso della istruzione LW, lo __stallo é inevitabile__, anche usando il forwarding.
>
>## Control Hazard
>>finché le istruzioni di branch non hanno calcolato/aggiornato il nuovo PC, lo stadio IF non puó effettuare il fetch dell'istruzione corretta.
>>__Soluzione naive__
>>Il nuovo valore del PC viene calcolato e scritto durante lo stage MEM (quarto ciclo):
>>- nello stage EXE vengono comparati i due registri
>>- nel quarto ciclo c'é la circuiteria che scrive nel PC il valore corretto del branch
>>
>>__Soluzione speculativa__
>>Possiamo, in questo caso, immaginare che il branch sia sempre not taken, in questo modo eseguo le tre istruzioni successive, senza comunque toccare la memoria o i registri. Con questa tecnica abbiamo un risparmio di tempo non da poco, perché se effettivamente é not taken il branch le 3 istruzioni successive stanno giá venendo eseguite, mentre nel caso che sia taken basterá annullare le tre istruzioni e andare alla istruzione tornata dal branch taken. Per non fare alcuna modifica, nel caso sia taken, basta forzare i controlli a zero prima che arrivino allo stadio di MEM o WB.
>
>## Ridurre il delay dei branch
>Possiamo anticipare il calcolo del PC e il confronto dei registri della beq senza complicare troppo l'hardware, usando al posto della ALU un'unitá specializzata che effettua lo XOR bit a bit dei due registri e un OR finale dei bit ottenuti. Usando questo hardware aggiuntivo il confronto possiamo farlo giá nello stadio ID, a valle della lettura tra i registri.
>
>In questo caso, se il branch é taken, solo l'istruzione successiva sará giá nella pipeline e andrá annullata.
>La tecnica si chiama __Delayed Branch__.
>In questo modo non é necessario 'annullare' l'operazione successiva al branch giá entrata nella pipeline in caso di branch taken. Sará compito del compilatore porre successivamente al salto:
>- una nop esplicita, oppure
>- un'istruzione del programma che, anche se completata, non modifica la semantica del programma
>
>Nelle CPU moderne questa tecnica non é piú utilizzata perché il numero di delay slot sarebbe troppo grande.
>Anticipare allo stadio ID il confronto tra i registri implica che il loro valore corretto deve essere disponibile giá al secondo ciclo, non piú al terzo come prima.
>Ma il forwarding permetteva di copiare i valori verso EXE, non verso ID!
>Occorre quindi inserire cicli di stallo.
>
>Nel caso di un operazione come la add, basta inserire un nop, nel caso invece di una lw, sará necessario aggiungerne due, dato che nel caso della lw il dato viene scritto al termine dello stadio MEM, mentre in add allo stadio EXE.
>
>## Previsione dinamica
>Dobbiamo comunque ottimizzare i branch, perché vengono sempre eseguiti troppi cicli usando la strategia del 'sempre not taken', ed é qui che entra in gioco la previsione dinamica. Essa usa una history table:
>- indirizzata tramite gli indirizzi delle istruzioni beq
>- Contenente:
>	- l'indirizzo dell'istruzione successiva al salto in caso di branch taken, calcolato alla prima istruzione
>	- Uno o piú bit di stato per memorizzare il risultato dell'esecuzione di ciascun salto
>
>Ogni volta che si esegue un branch controlliamo la tabella per leggere lo stato associato
>- recuperiamo l'entry della tabella grazie al PC dell'istruzione nello stadio IF
>- se l'indirizzo esiste in tabella allora l'istruzione é un branch ed utilizziamo lo stato come previsione da utilizzare:
> 	 - se taken, allora PC=indirizzo memorizzato in tabella, altrimenti PC+=4.
>
>Questo tipo di predizione riscontra comunque degli errori, quindi occore un unitá per individuare criticitá sul controllo: Hazard detection unit
>
>L'unitá é inserita nello stadio ID, ed inserirá delle nop nel caso si debbano annullare le operazioni giá entrate nello stadio IF della pipeline
>
>## Eccezioni ed interruzioni
>Il flusso normale delle istruzioni puó cambiare non solo per via dei salti, ma anche per __eccezioni__ o __interruzioni__
>eccezioni:
>- evento sincrono
>- generato interamente dal processore
>- provocato da problemi nell'esecuzione di un istruzione, come overflow, page fault, ecc.
>
>Interruzioni:
>- evento asincrono
>- generato esternamente al processore
>- generato da periferiche per comunicare alla CPU il verificarsi di certi eventi
>### Gestione delle eccezioni
>Quando si verifica un eccezione/interruzione, la CPU deve:
>1. Interrompere l'esecuzione
>2. Salvare lo stato di esecuzione del programma corrente
>3. Trasferire il controllo al sistema operativo modificando il PC ad un certo valore specifico. Quando il SO ha gesitto il problema, l'esecuzione puó riprendere utilizzando lo stato salvato
>
>Come possiamo capire il tipo di eccezione che si é verificata?
>1. Si utilizza un registro speciale che contiene un codice numerico corrispondente al tipo di eccezione. Singolo entry point nel sistema operativo (soluzione MIPS)
>2. Vectorized interrupts. L'indirizzo in cui si salta in caso di eccezione dipende dall'eccezione stessa. Diversi entry point nel sistema operativo
>
>Il processore MIPS ha un approccio minimale, salva solo il PC. Oggi le CPU moderne salvano tutto prima di effettuare il salto alla routine dell'OS.
>!! Important !! -> la routine OS da eseguire per gestire le eccezioni si trova all'indirizzo fisso 0xC0000000.
>
>### Eccezioni con Pipeline
>Queste eccezioni costituiscono un'altra forma di Control Hazard:
>- Occorre annullare le istruzioni che sono entrate nella pipeline subito prima che l'eccezione si verificasse inserrendo delle nop
>- A differenza dei branch, le eccezioni aritmetiche vengono rilevate nello stadio EXE. Dobbiamo quindi modificare il controllo della CPU in modo che anche lo stadio EXE possa mettere in stallo la CPU inserendo delle nop.
>Altre problematiche:
>-  Visto che ci sono piú istruzioni contemporaneamente nella pipeline, eccezioni multiple possono essere generate nello stesso ciclo di clock
>	- Nello stadio ID, per esempio, si rileva un'istruzione con opcode non valido e nello stadio EXE un overflow
>	- La soluzione é un sistema di prioritá delle istruzioni
>- Le interruzioni dovute all'IO non sono associate ad un istruzione specifica (asincrone!)
>- Eccezioni possono essere generate nell'handler delle eccezioni del sistema operativo
>	- Possibilitá di disabilitare le eccezioni/interrupt per brevi periodi