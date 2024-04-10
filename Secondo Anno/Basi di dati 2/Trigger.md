I trigger sono lo standard de facto per il mantenimento di invarianti **globali** nei DBMS, perché possono essere implementati efficientemente.

Paradigma di tipo Evento - Condizione - Azione:
- Un trigger è associato ad un **evento** che ne determina l'attivazione
- Quando un trigger viene attivato può controllare una certa **condizione**. Se la condizione è falsa, il trigger termina.
- Se la condizione è vera invece viene eseguita la cosiddetta **azione** associata al trigger

Esistono due tipi ti trigger:
- Trigger per riga
	- Eseguiti per ognuna delle righe coinvolte dall'evento scatenante. `NEW ROW` e `OLD ROW` sono usati per riferirsi alla tupla coinvolta dall'evento prima e dopo la sua occorrenza.
- Trigger per statement 
	- Eseguiti una volta sola per evento scatenante. `OLD TABLE` e `NEW TABLE`

- BEFORE trigger:
	- Attivati prima dell'evento scatenante. Di solito vengono utilizzati per impedire l'esecuzione di un'operazione o per modificarne preventivamente il comportamento.
- AFTER trigger:
	- Attivati dopo. Hanno visibilità dello stato della base di dati dopo l'esecuzione di un'operazioni e quindi sono talvolta necessari per motivi di espressività.

Metodologia per il mantenimento di invarianti tramite trigger:  
- Quali operazioni possono violare l’invariante?  
- Il mantenimento dell’invariante può essere controllato per ogni riga coinvolta tramite l'operazione oppure no? 
- Cosa bisogna fare prima o dopo dell’operazione per garantire il mantenimento dell’invariante?(maggiore libertà)

Proibire qualsiasi abbassamento di stipendio:

```sql
CREATE TRIGGER NetWorthTrigger 
AFTER UPDATE OF netWorth ON MovieExec 
REFERENCING OLD ROW AS OldTuple, NEW ROW AS NewTuple 
FOR EACH ROW 
WHEN (OldTuple.netWorth > NewTuple.netWorth) 
	UPDATE MovieExec 
	SET netWorth = OldTuple.netWorth 
	WHERE code = NewTuple.code;
```

La data di uscita di un film non può mai essere NULL (default a 1915): 

```sql
CREATE TRIGGER FixYearTrigger 
BEFORE INSERT ON Movies 
REFERENCING NEW ROW AS NewRow, NEW TABLE AS NewStuff 
FOR EACH ROW 
WHEN NewRow.year IS NULL 
UPDATE NewStuff SET year = 1915;
```

Serve un trigger analogo UPDATE

Trigger in postgres:
![[Pasted image 20240313104131.png]]
- possibile usare `OR` per associare uno stesso trigger a più eventi
- il corpo del trigger viene definito in una **funzione separata**
	- tramite trigger function
	- ![[Pasted image 20240313104237.png]]
	- **non ha argomenti** in questo caso, ma si possono passare tramite
		- `NEW`: la nuova riga per operazioni di INSERT/UPDATE all’interno di un trigger per riga (NULL nel caso di DELETE) 
		- `OLD`: la vecchia riga per operazioni di DELETE/UPDATE all’interno di un trigger per riga (NULL nel caso di INSERT) 
		- `TG_NARGS`: numero di argomenti passati tramite la CREATE TRIGGER 
		- `TG_ARGV`: vettore di argomenti passati tramite la CREATE TRIGGER
	- trigger come tipo di ritorno
		- se associato ad un `BEFORE` può
			- ritornare NULL per indicare che l’operazione (INSERT, UPDATE o DELETE) sulla riga deve essere abortita 
			- nel caso di INSERT o UPDATE: ritornare una riga, che diverrà la nuova riga che sarà inserita o sostituirà la riga aggiornata 
			- se non si vuole interferire con l’operazione: ritornare NEW nel caso di INSERT o UPDATE, ritornare OLD nel caso di DELETE
	- trigger per riga
		- ![[Pasted image 20240313104546.png]]
	- trigger per statement
		- ![[Pasted image 20240313104647.png]]
	- i `BEFORE` vengono eseguiti prima di tutti
		- si attivano prima di operare sulla riga coinvolta
	- `AFTER` vengono eseguiti alla fine dell'evento, ma prima degli `AFTER` trigger per statement
	- after trigger statement eseguiti sempre per ultimi
	- Esempio trigger per dipendenze funzionali
		- ![[Pasted image 20240313104859.png]]
	- un trigger per riga ha visibilità dei cambiamenti precedenti ma l'ordine di visita delle righe non è predicibile
	- se più trigger si trovano sulla stessa riga sono eseguiti in ordine alfabetico
	- un trigger può ricorsivamente attivare altri trigger con rischio di ricorsione infinite