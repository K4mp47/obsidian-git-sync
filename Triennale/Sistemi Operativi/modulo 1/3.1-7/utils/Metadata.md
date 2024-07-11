 - Informazione che protegge l'integrità dei file system
- Non possono essere modificate direttamente dagli utenti
- Molti File System creano un super-blocco per memorizzare le informazioni critiche che proteggono l'integrità del file system. Un super blocco può contenere
    - L'identificatore di sistema di file
    - La posizione di blocchi liberi del dispositivo di memorizzazione
    - Posizione delle directory radice
    - Tempo dell'ultima modifica
- Per ridurre il rischio di perdita di dati, la maggior parte dei file system distribuiscono le copie ridondanti del super-blocco in tutto il dispositivo di memorizzazione
- L'operazione open restituisce un descrittore di file
    - Un indice non negativo alla tabella dei file aperti
    - Da qui, l'accesso al file viene fatto attraverso il descrittore di file
    - Per un rapido accesso, spesso la tabella dei file contiene blocchi di controllo e i file, ovvero alcuni attributi di file come il nome simbolico, posizione, dati di controllo del file.
- L'operazione Mount combina più file system in un unico spazio dei nomi in modo che possano essere riferiti da una singola directory radice. Assegna una directory, chiamato il punto di mount, nel file system nativo alla radice del file system montato
- Il file system gestisce le directory con tabelle di mount, contenenti informazioni sulla posizione dei punti di mount e dei dispositivi ai quali puntano
- Quando il file system nativo incontra un punto di montaggio, usa la tabella di mount per determinare il dispositivo e il tipo di file system montato
- Gli utenti possono creare così soft link ai file nei file system montati
- Non possono gli utenti creare hard links tra i file systems
- ![[Pasted image 20240111222817.png]]

[[Organizzazione e Allocazione dei file]]
