##### Query 1
Persone(*CodiceFiscale*, Nome, AnnoNascita)
Animali(*Codice*, Nome, Padrone, Specie, Razza, Sesso) con Padrone(FK, Persone)
```sql
-- trovare le specie possedute da Mario Rossi

SELECT DISTINCT a.Specie 
FROM Persone p JOIN Animali a ON p.CodiceFiscale = a.Padrone
WHERE p.Nome = 'Mario Rossi'
```

- `DISTINCT` per evitare i duplicati (Ricordo di usarlo con attenzione essendo un'operazione costosa, $O(nlogn)$)

##### Query 2 
```sql

SELECT a.Specie 
FROM Persone p JOIN Animali a ON p.CodiceFiscale = a.Padrone
WHERE p.Nome = 'Mario Rossi'
GROUP BY a.Specie
```

- È un' alternativa alla **Query 1** ma non risulta essere efficiente, meglio il `DISTINCT` per eliminare duplicati

##### Query 3
```sql
-- trovare il codice fiscale di chi possiede un gatto
SELECT DISTINCT p.CodiceFiscale 
FROM Persone p JOIN Animali a ON p.CodiceFiscale = a.Padrone
WHERE a.Specie = 'gatto'

```

- Questa query è sbagliata, è inutile congiungere con la tabella persone, essendo `p.CodiceFiscale` == `a.Padrone`

```sql
SELECT DISTINCT a.Padrone 
FROM Animali a 
WHERE a.Specie = 'gatto'
```


##### Query 4
```sql
-- trovare il nome  il codice fiscale delle persone che possiedono un gatto e un cane

SELECT DISTINCT p.CodiceFiscale, p.Nome
FROM Persone p JOIN Animali a ON p.CodiceFiscale = a.Padrone
WHERE a.Specie = 'gatto' AND a.Specie = 'cane'
```

- Questa query per via del `WHERE`, un animale non può essere due Specie allo stesso momento
- Soluzione: ulteriore giunzione con animali

```sql
SELECT DISTINCT p.CodiceFiscale, p.Nome
FROM Persone p 
	JOIN Animali a 
		ON p.CodiceFiscale = a.Padrone
	JOIN Animale c 
		ON p.CodiceFiscale = c.Padrone
WHERE a.Specie = 'gatto' AND c.Specie = 'cane'
```

- Non uso `OR`, non funziona, potrei avere una persona che ha o solo il cane o solo il gatto

##### Query 5
```sql
-- trovare quanti animali possiede per specie la persona con codice fiscale RFFLSN

SELECT Specie, COUNT(Codice) AS Numero
FROM Animali
WHERE Padrone = 'RFFLSN'
GROUP BY Specie
```

- Inefficienza della query, `Codice`, 
	- Meglio `*` perché mi interessa solo il numero delle righe

##### Query 6
```sql
-- trovare il codice fiscale delle persone che non possiedono criceti

SELECT CodiceFiscale
FROM Persone p
WHERE NOT EXISTS (SELECT *
				 FROM Animali a
				 WHERE Specie = 'criceto' AND a.Padrone = p.CodiceFiscale)
```


- Alternativa senza correlazione (necessaria se si usa il `NOT EXISTS`)

```sql
SELECT CodiceFiscale
FROM Persone p
WHERE COdiceFiscale NOT IN (SELECT *
				 FROM Animali a
				 WHERE Specie = 'criceto')
```

##### Query 7
```sql
-- restituire il nome degli animali
SELECT Nome
FROM Animali
-- WHERE Codice IS NOT NULL 
```

- La riga commentata è un errore, `Codice == PK` è sempre `NOT NULL`

##### Query 8
```sql
-- restituire il nome, codice fiscale di una persona e il nome  e il codice di tutti gli animali che possiede

SELECT DISTINCT p.CodicecFiscale, p.Nome, a.Codice, a.Nome
FROM Persone p JOIN Animali a ON p.CodiceFiscale = a.Padrone
```

- Il `DISTINCT` non  è necessario, comporta inefficienza

##### Query 9

```sql
-- contare quanti cani sono presenti in Animali
SELECT COUNT(*)
FROM Animali
WHERE Specie = 'cane'
-- GROUP BY Specie
```

- Ultima riga è l'errore, mi interessa solo la Specie `cane` , non serve raggruppare

##### Query 10
```sql
-- Attenzione a questo errore, nella ricerca del minimo
-- Restituire il nome codice fiscale e la persona più giovane
SELECT COdiceFiscale, Nome, MIN(EXTRACT(year from currentdate) - AnnoNascita)
FROM Persone
GROUP BY CodiceFiscale, Nome
```

- Altro errore con la `GROUP BY`, crea gruppi composti da una sola persona

```sql
SELECT CodiceFiscale, Nome, (EXTRACT(year from currentadate) - AnnoNascita)
FROM Persone 
WHERE AnnoNascita = (SELECT MAX(AnnoNascita)
					FROM Persone)
```

##### Query 11
- Trovare la percentuale di paesi ricchi rispetto al  numero di nazione con popolazione > 0
```sql
SELECT (COUNT(pr.code)*100)/ COUNT(*)
FROM country co LEFT JOIN paesiricchi pr USING(code)
WHERE co.population > 0
```

- `pr.code` nel `COUNT` serve perché per via della left join potrebbero esserci dei valori a null

##### Query 12
- Trovare la media delle popolazioni massime delle città presenti nei vari continenti

```sql
SELECT AVG(pop-max-cont)
FROM (SELECT co.continent, MAX(ci.population) AS maxpop
	 FROM city ci JOIN country co ON co.code = ci.countryCode
	 GROUP BY co.continent) pop-max-cont
WHERE
```