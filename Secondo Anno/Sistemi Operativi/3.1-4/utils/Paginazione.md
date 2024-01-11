- Usa il mapping di blocchi a dimensione fissa
- L'indirizzo virtuale nel sistema di paginazione è una coppia ordinata

![[Pasted image 20240111183250.png]]

- La memoria principale viene divisa in page frame di grandezza fissa, ed il SO può posizionare le pagine in qualunque posizione libera
- Non tutte le pagine risiedono in memoria libera, ma anche nella PTE(Page Table Entry)
    - L'indirizzo virtuale contiene un bit di _residenza_, per identificare se si trova in memoria secondaria (0) o principale (1)
- ##### Mapping diretto
    
    - Traduzione degli indirizzi da virtuali a fisici con paginazione
    - La tabella delle pagine contiene una riga per ogni pagina dello spazio virtuale
    - Richiede l'accesso alla memoria per ogni mapping
    - L'indirizzo virtuale contiene sempre il numero della pagina e lo spostamento da effettuare v = (p,d)
    - Si aggiunge p all'indirizzo di base b per trovare la pagina, chiamata p', a cui verrà poi sommato lo spostamento d per trovare l'indirizzo reale r
    - ![[Pasted image 20240111183316.png]]
- ##### Mapping associativo
    
    - L'intera tabella delle pagine viene posizionata nella memoria associativa con indirizzamento per contenuto, permettendo di cercare la page frame contemporaneamente in tutte le posizioni, permettendo una traduzione dinamica più veloce degli indirizzi. Questo metodo aumenta le prestazioni ma aumenta i costi di memoria in confronto al mapping diretto
    - ![[Pasted image 20240111183329.png]]
- ##### Mapping diretto/associativo
    
    - Misto delle due tecniche precedenti, nella memoria associativa, o TLB(Translation Lookaside Buffer) vengono salvate e aggiornate le PTE più utilizzate, mentre le altre rimangono in memoria RAM. Altissime prestazioni con un TLB relativamente piccolo, per via del principio di località spaziale
    - ![[Pasted image 20240111183343.png]]
- ##### Mapping multilivello
    
    - Questo tipo di mapping permette di memorizzare locazioni di memoria non contigue che il processo sta utilizzando
    - Riducendo il numero di righe della tabella in memoria, si ha una riduzione dell'overhead
    - Si crea una gerarchia a livelli della pagina, ogni livello contiene una tabella a sua volta con i puntatori alle tabelle di livello inferiore. I livelli più bassi hanno le traduzioni degli indirizzi al loro interno
    - Richiede ulteriori accessi alla memoria, limitabili per località o con la TLB
    - ![[Pasted image 20240111183408.png]]
- ##### Mapping a tabella inversa
    
    - La tabella multilivello riduce il numero di righe della tabella in memoria, ma questo è utile solo se il processo non una tutto lo spazio di indirizzamento
    - La tabella inversa salva un PTE per ogni page frame del sistema, ed il numero dipende dal numero di page frame (memoria fisica)
    - Come rappresentato nella tabella sotto riportata, la tabella abbina il frame virtuale a quello fisico e non viceversa, in questo modo, quando ci troviamo di fronte ad un indirizzo virtuale, quello che verrà fatto sarà:
        - Si prende la parte b dell'indirizzo virtuale e la si va a cercare nella IPT(Inverted Page Table), per esempio 0x008000
        - Si cerca la corrispondenza all'interno della IPT, da cui si prende "l'index" del corrispondente frame fisico
        - Si aggiunge il displacement d, e si trova l'indirizzo fisico corrispondente
    - Da notare che nella tabella l'indirizzo viene mappato tramite funzioni di hashing! Ed esso può causare collisioni!! (più virtuali possono comunque puntare allo stesso frame fisico)
        - Esse vengono gestite tramite la Hash Anchor Table (HAT), che aggiunge una tabella, o livello, per ridurre il numero di collisioni
        - Essa è molto difficile da implementare, dato che bisogna bilanciare la frammentazione della tabella, l'overhead e le prestazioni
    - ![[Pasted image 20240111183527.png]]
    - Hashing può causare collisioni che aumentano il tempo di traduzione dell'indirizzo aumentando il numero di accessi alla memoria
	    - Collisione: quando più indirizzi virtuali tradotti con hash danno lo stesso valore
	    - Concatenamento per evitare sovrascritture di elementi in collisione, si potrebbe diminuire aumentando l'intervallo dei valori della funzione hash
	    - Non si può aumentare la dimensione della tabella inversa delle pagine, quindi si aumenta l'intervallo della Hash Anchor Table (HAT) con un ulteriore livello indiretto
    - ![[Pasted image 20240111183540.png]]

|frame fisico|indirizzo virtuale|
|:-:|:-:|
|0x1000|0x00400000|
|0x2000|0x00800000|
|0x3000|0x00C00000|
|....|....|

- ##### Condivisione
    
    - Avviene nei sistemi multiprogrammati
    - Riduce la memoria consumata dai programmi che utilizzano dati e/o istruzioni in comune
    - Ogni pagina deve essere riconosciuta come condivisibile o non
    - Esempio banale quello della fork() nei sistemi unix, dove solo quando il processo figlio apporta una modifica allora viene creata una copia dei dati, ovvero delle page table, fino ad allora è condivisa
- ##### Sostituzione
    
    - Fatto da un sistema per selezionare le pagine da sostituire, serve per determinare dove caricare una pagina in memoria principale
    - Avviene quando si ha un _page fault_, ed il gestore della memoria deve
        - Individuare la pagina in memoria secondaria corrispondente
        - Caricarla nella memoria principale
        - Aggiornare la riga nella tabella delle pagine del processo
    - Esistono vari tipi di Sostituzione
        - RAND
        - FIFO
        - LRU
        - NFU
- ##### Fetch
    - Determina quando la pagina/segmento deve essere caricato nella memoria principale
    - Strategia **a richiesta**
        - Quando un processo inizia l'esecuzione, il sistema carica in memoria principale la pagina che contiene la sua prima istruzione, un'altra pagina viene caricata solo quando il processo vi fa esplicito riferimento
        - Vengono quindi caricate una alla volta
    - Strategia **a previsione**
        - Il SO cerca di prevedere di quali pagine il processo avrà bisogno e pre-carica queste pagine quando vi è spazio in memoria principale
        - Difficile progettazione, bisogna prestare attenzione a quanta memoria pre-allocare, quante pagine pre-caricare e a quali politiche bisogna affidarsi
[[Modello Working Set]]
[[Segmentazione e Paginazione]]