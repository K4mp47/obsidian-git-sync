Uno schema può contenere varie tabelle delle quali esistono più tipi:
- tabelle base
	- I metadati appartengono allo schema
	- i dati sono fisicamente memorizzati
- viste
	- i metadati sono presenti nello schema
	- i dati non sono fisicamente memorizzati ma prodotti dalla valutazione di un'espressione

Per creare una tabella all'interno di un database posso usare `CREATE TABLE`
- il tipo di dato può essere 
	- predefinito
	- definito dall'utente (dominio)

per creare un nuovo dominio uso `CREATE DOMAIN`

```sql
CREATE DOMAIN NomeDominio AS TipoDiDato
	[ValoreDiDefault]
	[Vincolo]
```

 **TIPI DI DATI PREDEFINITI**
Tipi di dato predefiniti:
- tipi interi
	- INTEGER, SMALL INT
- valori decimali
	- NUMERIC(p,s)
- virgola mobile
	- REAL, FLOAT(p), double precision
- stringhe di bit
	- BIT(x), BIT VARYING(x)
- booleani
	- BOOLEAN
- stringhe di caratteri
	- CHAR(x), O CHARACTER(x)
- date e ore
	- DATE, TIME, TIMESTAMP
- intervalli temporali
	- INTERVAL{YEAR, MONTH, DAY, HOUR, MINUTE, SECOND}
- testo e oggetti binari
	- BLOB (BINARY LARGE OBJECT), CLOB (CHARACTER LARGE OBJECT)

`SERIAL` serve per creare una colonna con un identificatore unico - simile ad `AUTO-INCREMENT`:

```sql
CREATE TABLE tablename {
	colname SERIAL,
	name VARCHAR(10),
	--...
}
```

per inserire dei valori di default dovrei:

```sql
CREATE TABLE Studenti {
	--...
	Provincia CHAR(2) DEFAULT 'VE',
	--...
}
```

per inserire dei vincoli all'interno degli elementi nella tabella:

```sql
-- INTRARELAZIONALI
PRIMARY KEY
UNIQUE
CHECK

-- INTERRELAZIONALI
FOREIGN KEY
```

modificare una riga usando `ALTER`
- aggiungere tributi

```sql
ALTER TABLE Studenti
	ADD COLUMN Nazionalità VARCHAR(10) DEFAULT 'Italiana';
```

- rimuovere attributi

```sql
ALTER TABLE Studenti
	DROP COLUMN Provincia;
```

- posso anche aggiungere/togliere vincoli e molto altro.
	- Si vedranno meglio in proprio/durante le esercitazioni in classe con **pgAdmin**

posso inizializzare dei valori all'interno delle tabelle:
```sql
CREATE TABLE Nome [AS] ExpressionSelect
```

### Considerazioni varie
- utilizzo del costrutto `WITH` come alternativa per scrivere sottoquery da utilizzare in query più complesse
	- posso pensarla come una **tabella temporanea** che esiste solo per questa query

```sql
WITH ProvinceMedia as(
	SELECT...
	FROM...
	WHERE...
)

SELECT Provincia, Media
FROM ProvinceMedia
WHERE Media = (SELECT MAX(Media) FROM ProvinceMedia)
```