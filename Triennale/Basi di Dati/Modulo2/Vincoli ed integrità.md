Molto spesso i dati salvati all'interno di un database devono soddisfare determinati **vincoli di integrità**, dipendenti dalla semantica dei dati
- Garantire che certi attributi abbiamo sempre un valore
	semplice vincolo per esprimere che un valore non deve essere nullo è `NOT NULL`
	```sql
	CREATE TABLE Movies ( 
		title CHAR(100) NOT NULL, /* <-- */
		year INT, 
		length INT, 
		genre CHAR(10) 
	)
	```
- Garantire che un gruppo di attributi sia la chiave
	Data una tabella $R(T)$ ed un insieme $X$ di attributi appartenenti a $T$, possiamo specificare che nessuna coppia di tuple coincida su tutti gli attributi di $X$, a meno che almeno uno di essi sia `NULL` usando `UNIQUE`
	```sql
	CREATE TABLE Movies ( 
		title CHAR(100) NOT NULL, 
		year INT, 
		length INT, 
		genre CHAR(10), 
		UNIQUE (title, year) /* <-- */
	)
	```
	Il vincolo `PRIMARY KEY` si comporta come `UNIQUE`, ma impone in aggiunta il vincolo `NOT NULL`
	```sql
	CREATE TABLE Movies ( 
		title CHAR(100), 
		year INT, 
		length INT, 
		genre CHAR(10), 
		PRIMARY KEY (title, year) /* <-- */
	)
	```
- Garantire l'integrità referenziale
	Tramite l'utilizzo della `FOREIGN KEY`. Possiamo indicare che un attributo è una chiave esterna subito dopo la dichiarazione di un attributo:
	`REFERENCES <table> (<attribute>)`
	oppure alla fine di tutte le dichiarazioni:
	`FOREIGN KEY (<attributes>) REFERENCES <table> (<attributes>)`
	esempio:
	```sql
	CREATE TABLE MovieExec ( 
		name CHAR(50), 
		address VARCHAR(255), 
		code INT PRIMARY KEY, /* <-- */
		netWorth INT 
	)
	```
	collegato tramite foreign key verso `code`:
	```sql
	CREATE TABLE Studio ( 
		name CHAR(30) PRIMARY KEY, 
		address VARCHAR(255), 
		president INT, 
		FOREIGN KEY (president) /* <-- */
		REFERENCES MovieExec(code) /* <-- */
	)
	```
	è possibile avere uno studio senza presidente, ma non è ammissibile avere un presidente che non sia anche un produttore esecutivo
	
	Queste operazioni su `Studio` sono impedite: 
	- inserimento di una tupla il cui attributo president non è NULL e non coincide con l’attributo code di una tupla in `MovieExec` 
	- aggiornamento di una tupla per cambiare il suo attributo president ad un valore non NULL che non coincide con l’attributo code di una tupla in `MovieExec`
	
	Queste operazioni sono pericolose su `MovieExec`:
	- cancellazione di una tupla il cui attributo code coincide con l’attributo `president` di qualche tupla in `Studio`
	- aggiornamento di una tupla per cambiare il suo attributo `code` in modo tale che non coincida più con l’attributo `president` di qualche tupla in `Studio`
	 
	 In questi casi si usano le **politiche di integrità**, messi a disposizione da SQL tramite:
	 - `Default` che rifiuta la modifica
	 - `CASCADE` che applica la modifica su tutte le tuple che fanno uso della chiave esterna(se cancello/modifico `president`, uno studio con il codice del presidente viene cancellato/modificato il codice del `president`, "a cascata")
	 - `SET NULL` la chiave esterna viene messa a `NULL`
	 
	 ```sql
	 CREATE TABLE Studio ( 
		 name CHAR(30) PRIMARY KEY, 
		 address VARCHAR(255), 
		 president INT, 
		 FOREIGN KEY (president) 
		 REFERENCES MovieExec(code) 
			 ON DELETE SET NULL 
			 ON UPDATE CASCADE 
	)
	```
- Garantire determinati vincoli sui valori degli attributi, anche in relazione tra loro
	È possibile specificare vincoli complessi sul valore di un attributo, usando la sintassi `CHECK` seguita da un'espressione booleana fra parentesi:
	- Si può usare qualsiasi espressione ammessa da `WHERE`
	- Standard SQL: si possono riferire altre relazioni tramite sotto-query 
	- Il singolo vincolo è controllato ogni volta che una tupla assume un nuovo valore per quell'attributo
	
	Esempio di  check sugli attributi
	```sql
	CREATE TABLE MovieExec ( 
		name CHAR(50), 
		address VARCHAR(255), 
		code INT PRIMARY KEY CHECK (code >= 100000), 
		netWorth INT CHECK (netWorth >= 0) 
	) 
	
	CREATE TABLE Studio ( 
		name CHAR(30) PRIMARY KEY, 
		address VARCHAR(255), 
		president INT, 
		FOREIGN KEY (president) REFERENCES MovieExec(code) 
	)
	```
	![[Pasted image 20240306112632.png]]
	![[Pasted image 20240306112643.png]]

## Limitazioni dei vincoli
Si considerino questi schemi, dove `president` è chiave esterna per `code`:
```
MovieExec(name, address, code, netWorth) 
Studio(name, address, president)
```

![[Pasted image 20240311085343.png]]

```sql
CHECK (100000 <= ALL(SELECT netWorth 
					 FROM Studio, 
					 MovieExec WHERE president = code)
```

## Asserzioni
Le asserzioni esprimono **invarianti globali** sull'intero schema relazionale:
```
CREATE ASSERTION <name> CHECK (<condition>)
```

La condizione deve essere vera quando l'asserzione è creata e continuare a rimanere tale dopo ogni modifica del database.
Le asserzioni sono strettamente più potenti dei CHECK, ma molto più complicate da implementare efficientemente.
Inoltre sono inefficienti!


Esempio: 
Nessuno può essere un presidente di uno studio senza avere un reddito di almeno 100.000:
```sql
CREATE ASSERTION RichPresident CHECK( 
	NOT EXISTS( 
		SELECT Studio.name 
		FROM Studio, MovieExec 
		WHERE Studio.president = MovieExec.code AND 
			MovieExec.netWorth < 100000 
	) 
);
```

La durata complessiva dei film prodotti da ogni studio deve essere di almeno 500 minuti:
```sql
CREATE ASSERTION SumLength CHECK( 
	500 <= ALL( 
		SELECT SUM(length) 
		FROM Movies 
		GROUP BY studio 
	) 
);
```

Altro esempio:
Partendo da questi oggetti:
```sql
Product(maker, model, type) 
PC(model*, speed, ram, hd, price) 
Laptop(model*, speed, ram, hd, screen, price) 
Printer(model*, color, type, price)
```

Se un Laptop ha più ram di un PC allora deve anche costare di più di tale PC

```sql
CREATE ASSERTION NoCheapLaptop CHECK (NOT EXISTS( 
	SELECT * 
	FROM Laptop, PC 
	WHERE Laptop.ram > PC.ram AND 
		Laptop.price <= PC.price 
	) 
);
```

Nessun produttore di PC può produrre anche Laptop:

```sql
CREATE ASSERTION NoPCLaptop CHECK (NOT EXISTS( 
	SELECT * 
	FROM Product p1, Product p2 
	WHERE p1.type = ’PC’ AND p2.type = ’Laptop’ 
		AND p1.maker = p2.maker 
	) 
);
```

