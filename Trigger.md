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
