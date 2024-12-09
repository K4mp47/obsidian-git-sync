Tables:
- atleti
- medaglie
- nazioni

Ottimizzazione
- Scegliere meno tabelle possibile per il from
- usare distinct per ridurre i duplicati nella select
- Non usare sempre * in `COUNT` per non contare il numero di righe
##### Query 1
```sql
-- trovare il nome e cognome degli atleti italiani e tedeschi che 
-- hanno vinto una medagli di bronzo nello sport slittino
SELECT DISTINCT a.nome, a.cognome
FROM atleti a NATURAL JOIN medaglie m
WHERE (a.nazione = 'Italia' OR a.nazione = 'Germania') AND m.tipo = 'Bronzo' AND m.sport = 'Slittino'
```

- Importante le parentesi, altrimenti il risultato esce errato (`AND` è un operatore più forte di `OR`)

##### Query 2
```sql
-- trovare il numero di medaglie vinte dall'italia nel 2022
SELECT COUNT(*)
FROM atleti a NATURAL JOIN medaglie m 
WHERE a.nazione = 'Italia' AND m.anno = 2022
```

- Basta contare le righe della tabella, corrispondono alle medaglie

##### Query 3
```sql
-- trovare gli atleti che non hanno vinto una medaglia d'oro
SELECT *
FROM atleti a 
WHERE NOT EXISTS (
	SELECT *
	FROM medaglie m
	WHERE m.tipo = 'Oro' AND a.idatleta = m.idatleta
)
```

- No natural join con medaglie, perché sarebbe come dire che almeno una ce l'hanno
- Universale non esistenziale
- Correlazione con query esterna dalla `sottoselect`  nel `where not exists`
- Non serve il `DISTINCT` perché la tabella atleti è singola e senza duplicati

##### Query 3.2
```sql
-- alternativa al punto precedente
SELECT *
FROM atleti a
WHERE a.idatleta NOT IN (
	SELECT idatleta
	FROM medaglie
	WHERE tipo = 'Oro'
)
```

##### Query 3.3
```sql
SELECT *
FROM atleti
EXCEPT
SELECT a.*
FROM medaglie m NATURAL JOIN atleti a 
WHERE m.tipo = 'Oro'
```

##### Query 4
```sql
-- trovare il nome cognome e la nazione degli atleti che hanno vinto almeno due medaglie in discipline differenti
SELECT DISTINCT a.idatleta, a.nome, a.cognome, a.nazione
FROM atleti a JOIN medaglie m USING(idatleta) JOIN medaglie m2 USING(idatleta)
WHERE m.disciplina <> m2.disciplina
```

- m, m2 possono essere invertite, serve il `DISTINCT` 
- non possono esserci due `NATURAL JOIN` perché non funziona
- potrei metterne una, ma non due!

##### Query 5
```sql
-- trovare gli atleti che hanno vinto almeno una medaglia per tipo restituire il nome, cognome, la nazione e il numero di medaglie totale vinte.

SELECT a.idatleta, a.nome, a.cognome, a.nazione, COUNT(*)
FROM atleti a NATURAL JOIN medaglie m 
GROUP BY a.idatleta, a.nome, a.cognome, a.nazione
HAVING COUNT(DISTINCT m.tipo) = 3
```

- mi serve il `GROUP BY` per poter sommare le varie medaglie
- `NATURAL JOIN` perché solo tra due tabelle
- atleti serve per nome cognome e nazione
- quando si fa un raggruppamento ricordo che devo in maniera univa distinguere, in questo caso uso l'id dell'atleta
- il where seleziona quali righe hanno una determinata condizione
	- in questo caso la condizione è sul gruppo, divisi l'un l'altro da atleta
- serve una condizione sul gruppo per dire che l'atleta ha vinto una medaglia per tipo
- `DISTINCT` necessario per distinguere le medaglie
- devo scrivere nel `GROUP BY` le colonne che voglio passare al chiamante
	- se lascio `a.idatleta` e basta, il DBMS riconosce che è una chiave, per cui funziona comunque
	- se invece mettessi `m.idatleta` il DBMS torna errore nella `SELECT` perché non fanno parte della `GROUP BY`
- `COUNT(*)` mi basta, corrisponde a contare le righe ;)

##### Query 5
```sql
-- trovare per ogni atleta il numero di edizioni in cui ha vinto una medaglia nello sport sci alpino e restituire anche il nome e il cognome dell'atleta. Se l'atleta non ha vinto alcuna medaglia in tale sport, restituire 0 per quell'atleta
-- ordinare il risultato in ordine non crescente per numero di edizioni

SELECT a.nome, a.cognome, COUNT(DISTINCT m.edizione) AS num_edizioni
FROM atleti a LEFT JOIN medaglie m ON a.idatleta = m.idatleta AND m.sport = 'Sci Alpino'
GROUP BY a.idatleta, a.nome, a.cognome
ORDER BY num_edizioni DESC
```

- `Se l'atleta non ha vinto alcuna medaglia in tale sport, restituire 0`
	- questa riga ci fa capire che serve un `LEFT JOIN`, ho la necessità anche di avere chi non ha vinto nessuna medaglia
-  La condizione per disciplina non va nel `WHERE` ma nel `FROM` , in questo modo fa la giunzione con la medaglia nella disciplina alpina, e tutte le righe che non combaciano hanno il valore a NULL, per cui con il `GROUP BY` e il `COUNT` torna 0!

##### Query 6
```sql
-- trovare gli atleti che hanno vinto meno di 4 medaglie e restituire il nome, cognome e la nazione e il numero di medaglie vinte
SELECT a.nome, a.cognome. a.nazione, COUNT(m.codice) AS num_med
FROM atleti a NATURAL LEFT JOIN medaglie m
WHERE
GROUP BY a.idatleta, a.nome, a.cognome, a.nazione, 
HAVING COUNT(*) < 4
```

- Errore se non metto `NATURAL LEFT JOIN`
- `COUNT` non funziona con `*` non torna chi ha 0 medaglie ma `m.codice` funziona perfettamente per distinguere anche gli zeri

##### Query 7
```sql
-- Trovare per ogni nazione che ha vinto almeno una medaglia
-- l'atleta/i più giovane che ha vinto una medaglia e 
-- restituire anche l'età di tale atleta/i.
-- L'età deve essere calcolata rispetto all'anno 
-- in cui ha vinto la medaglia.

SELECT DISTINCT a.nome, a.cognome, a.nazione, m.anno - a.annonascita
FROM atleti a NATURAL JOIN medaglie m
WHERE m.anno - a.annonascita = (
				SELECT MIN(m1.anno - a1.annonascita)
				FROM atleti al NATURAL JOIN medaglie ml
				WHERE a1.nazione = a.nazione
			);
```