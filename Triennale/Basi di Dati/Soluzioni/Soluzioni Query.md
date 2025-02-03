Database 
- Squadre (**Nazione**, Allenatore)
- Partite(**IdP**, Squadra1\*, Squadra2\*)
- Reti (**IdR**, IdG\*, IdP\*, Auto)
- Giocatori(**IdG**, Nome, Nazione*, Nascita)

```sql
WITH RetiNonAutoGoal AS (
	SELECT *
	FROM Reti
	WHERE Auto = 'false'
)

SELECT g.Nome
FROM Giocatori g JOIN Reti ti on g.IdG = t.IdG
WHERE g.Nazione = 'Brasile'
```

```sql
CREATE VIEW SquadraConta (Nome, Allenatore)
AS
	SELECT p.Squadra1, s.Allenatore
	FROM Squadre s JOIN Partite p ON s.Nazione = p.Squadra1
	UNION
	SELECT p.Squadra1, s.Allenatore
	FROM Squadre s JOIN Partite p ON s.Nazione = p.Squadra2

WITH TotalePartite AS (
	SELECT Nome, Allenatore, COUNT(*) as Totale
	FROM SquadraConta
	GROUP BY Nome, Allenatore
)

SELECT Nome, Allenatore
FROM TotalePartite
WHERE Totale = (SELECT MAX(Totale) FROM TotalePartite)
```

```sql
SELECT g.Nome, g.Nazione
FROM Giocatori g JOIN Reti r ON g.IdG = r.IdG
WHERE r.Auto = 'false'
GROUP BY g.Nome, g.Nazione
HAVING COUNT(*) = 1
```

```sql
CREATE VIEW GiocatoriConUnGoal(Nome, Nazione)
AS
	SELECT g.Nome, g.Nazione
	FROM Giocatori g JOIN Reti r ON g.IdG = r.IdG
	WHERE r.Auto = 'false'
	GROUP BY g.Nome, g.Nazione
	HAVING COUNT(*) = 1

SELECT n.Nome, COUNT(*)
FROM Nazioni n LEFT JOIN GiocatoriConUnGoal g ON n.Nome = g.Nazione 
GROUP BY n.Nome
```

```sql
SELECT t1.IdP, t1.Squadra1, t1.goalSq1, t2.Squadra2, t2.goalSq2
FROM (
	SELECT p.IdP, p.Squadra1, count(*) as goalSq1
	FROM Partite p JOIN (Reti r JOIN Giocatori g ON r.IdG = g.IdG AND NOT r.Auto) ON p.IdP = r.IdP
	WHERE g.Nazione = p.Squadra1
	GROUP BY p.IdP, p.Squadra1
) t1 JOIN (
	SELECT p1.IdP, p1.Squadra2, count(*) as goalSq2
	FROM Partite p1 JOIN (Reti r JOIN Giocatori g ON r.IdG = g.IdG AND NOT r.Auto) ON p1.IdP = r.IdP
	WHERE g.Nazione = p1.Squadra2
	GROUP BY p1.IdP, p1.Squadra2
) t2 ON t1.IdP = t2.IdP
WHERE t1.goalSq1 = t2.goalSq2

```

```sql
-- trovare le squadre contro cui ha giocato l'Italia
select Squadra1
from Partite
where Squadra2 = 'Italia'
union -- rimuove in automatico i duplicati!
select Squadra2
from Partite
where Squadra1 = 'Italia'
```

```sql
-- trovare i giocatori della squadra brasiliana che non 
-- hanno segnato nessun autogol
select g.nome
from Giocatori g
where g.Nazione = 'Brasile' and g.IdG <>all (
	select r.IdG
	from Reti r
	where r.Auto = 'true'
)
```

```sql
-- Per ogni squadra trovare i giocatori che hanno segnato un goal escludendo gli autogoal, se una squadra ha segnato 0 goal torna 0
select g.Nazioni, count(distinct r.IdG) as NumG
from Giocatori g left join Reti r on g.IdG = r.IdG and not r.Auto
group by g.Nazioni
```

```sql
-- trova tutte le partite finite in parità ma non 0-0
select p.IdP
	from Parite p join Reti r on p.IdP = r.IdP
```

Database Olimpiadi
- Atleti(IdAtleta, Nome, Cognome, Nazione*, Sesso)
	- Nazione FK(Nazioni) 
- Medaglie(Codice, Tipo, Sport, Disciplina, IdAtleta*, Anno) 
	- IdAtleta FK(Atleti) 
- Nazioni(Nome, Estensione, NumAbitanti)

```sql
--rovare il nome, cognome e la nazione degli atleti cha hanno
-- vinto almeno due medaglie in sport differenti.

-- soluzione prof
SELECT DISTINCT a.IdAtleta, a.Nome, a.Cognome, a.Nazione 
FROM Atleti a NATURAL JOIN Medaglie m1 JOIN Medaglie m2 USING (IdAtleta) 
WHERE m1.Sport <> m2.Sport

-- soluzione alternativa
-- chatgpt conferma
select distinct a.nome, a.cognome, a.nazione
from atleti a join medaglie m on a.idatleta = m.idatleta
group by a.nome, a.cognome, a.nazione
having count(distinct m.sport) >= 2
```

```sql
-- trovare la nazione con il minor numero di abitanti che ha vinto 
-- almeno una medaglia d’oro femminile nello sport Nuoto;
with numAtleteOroSci as (
	select a.nazione
		from atleti a join medaglie m on a.idatleta = m.idatleta
		where m.Sport = 'Sci di fondo' 
			and a.sesso = 'F'
			and m.tipo = 'Oro'
)

select n.nome, n.mumabitanti
from nazioni n
where n.nome in (select * from numAtleteOroSci) 
	and n.mumabitanti = (select min(n.mumabitanti)
		from nazioni n
		where n.nome in (select * from numAtleteOroSci)
	)
```

- Dipendenti(Id, Nome, AnnoNascita, Stipendio) 
- Manager(Id*, Area) Id FK(Dipendenti) 
- Staff(Id*, Cod*) Id FK(Dipendenti) Cod FK(Progetti) 
- Progetti(Cod, Nome, Budget, Responsabile*) Responsabile FK(Manager)

```sql
SELECT p.Nome, p.Budget
FROM Progetti p NATURAL JOIN ( Manager m NATURAL JOIN Dipendenti d)
WHERE m.Area = 'Centro' AND (EXTRACT(YEAR FROM AGE(d.AnnoNascita)) AS Età < 30)
```

- Dottorandi(IdDott, Nome, Disciplina, Relatore*) 
	- Relatore FK(Professore) 
- Professori(CF, Nome, Disciplina) 
- Corsi(Codice, Titolo, Professore*) 
	- Professore FK(Professori) 
- Esami(IdStud*, CodiceCorso*, Data) 
	- IdStud FK(Dottorandi) CodiceCorso FK(Corsi)

```sql
-- Restituire il titolo dei corsi e il codice fiscale dei docenti degli esami sostenuti da Chiara Pugliesi. 
SELECT c.Titolo, c.Professore
FROM Corsi c 
JOIN Esami e ON e.CodiceCorso = c.Codice 
JOIN Dottorandi d ON e.IdStud = d.IdDott
WHERE d.Nome = 'Chiara Pugliesi'
```

```sql
--  Trovare il numero di dottorandi che hanno sostenuto sia l’esame di Intelligenza Artificale che l’esame di Sicurezza.
SELECT COUNT(DISTINCT d.IdDott)
FROM Dottorandi d JOIN Esami e ON d.IdDott = e.IdStud JOIN Corsi c ON e.CodiceCorso = c.Codice 
WHERE c.Titolo IN ('Intelligenza Artificiale','Sicurezza')
GROUP BY d.IdDott
HAVING COUNT(DISTINCT c.Titolo) = 2

-- Prima parte divide le soluzioni per far si che ci siano solo i titoli di Intelligenza Artificiale, Sicurezza,
-- In seguito il GROUP BY filtra per quelli studenti che hanno sostenuto entrambi gli esami tramite l'HAVING
```

```sql
-- Per ogni professore, restituire il nome del professore e il numero di dottorandi di cui `e relatore che sono della sua disciplina e il numero dei dottorandi di cui `e relatore che non sono della sua disci- plina. Se il professore non ha dottorandi in una delle due categorie o in nessuna si deve restituire 0.
SELECT p.Nome, COUNT(d.IdDott), COUNT(d2.IdDott)
FROM Professori p 
LEFT JOIN (
	SELECT *
	FROM Professori p JOIN Dottorandi d ON p.CF = d.Relatore
	WHERE p.Disciplina = d.Disciplina
) d ON p.CF = d.Relatore
LEFT JOIN (
	SELECT *
	FROM Professori p JOIN Dottorandi d ON p.CF = d.Relatore
	WHERE p.Disciplina <> d.Disciplina
) d2 ON p.CF = d2.Relatore
GROUP BY p.Nome

-- La query sopra è la query che ho creato io, mentre quella sotto è quella generata da ChatGpt
SELECT p.Nome,
	COUNT(CASE WHEN d.Disciplina = p.Disciplina THEN d.IdDott END),
	COUNT(CASE WHEN d.Disciplina <> p.Disciplina THEN id.IdDott END)
FROM Professori p
LEFT JOIN Dottorandi d ON P.CF = d.Relatore
GROUP By Nome
```

```sql
WITH EsamiPerCorso AS(
	SELECT p.Nome AS DocenteNome, 
		c.Titolo CorsoNome, 
		COUNT(e.*) as EsamiTot
	FROM Professori p
	JOIN Corsi c ON p.CF = c.Professore
	LEFT JOIN Esami e ON c.Codice = e.CodiceCorso
	GROUP BY p.Nome, c.Titolo
	HAVING COUNT(e.*) > 0
)

SELECT e1.DocenteNome, e1.CorsoNome, e1.EsamiTot
FROM EsamiPerCorso e1
WHERE e1.EsamiTot = (
	SELECT MAX(e2.EsamiTot)
	FROM EsamiPerCorso e2
	WHERE e2.DocenteNome = e1.DocenteNome
)
```

```sql
-- Modificare il relatore di un dottorando se il relatore non `e della sua stessa disciplina e inserire come nuovo relatore il primo docente avente la sua stessa disciplina con cui il dottorando ha sostenuto un esame. Se non ha sostenuto nessun esame con professori della sua disciplina mettere il relatore a NULL. Si assuma che un dottorando svolga al pi`u un esame in un giorno.
UPDATE Dottorandi
SET Relatore = (CASE WHEN Relatore IN (
						SELECT CF
						FROM Professori p 
						WHERE p.CF = Dottorandi.Relatore
						AND Dottorandi.Disciplina = p.Disciplina
					) THEN Relatore
						
					WHEN EXISTS (
						SELECT 1
						FROM Esami e
						JOIN Corsi s ON e.CodiceCorso = s.Codice
						JOIN Professori p ON p.CF = c.Professore
						WHERE e.IdStud = Dottorandi.IdDott
							AND p.Disciplina = Dottorandi.Disciplina
					) THEN (
						SELECT p.CF 
						FROM Esami e 
						JOIN Corsi c ON e.CodiceCorso = c.Codice 
						JOIN Professori p ON c.Professore = p.CF 
						WHERE e.IdStud = Dottorandi.IdDott 
							AND p.Disciplina = Dottorandi.Disciplina 
						ORDER BY e.Data ASC 
						LIMIT 1
					)
					ELSE NULL
				END
				)

```

- Pizze(codPizza, nome, tempoPrep, prezzo) 
- Ingredienti(codIngrediente, nome, quantitàMagazzino, costoBase)
- Ricette(codPizza*, codIngrediente*, quantità) 
	- codPizza FK(Pizze) 
	- codIngrediente FK(Ingredienti) 
- Ordini(codOrdine, nomeCliente, indirizzoCliente, oraConsegna, codPizza*) 
	- codPizza FK(Pizze)

```sql
-- trovare il nome delle pizze in cui almeno un ingrediente ha quantit`aMagazzino uguale a 0;
SELECT DISTINCT p.Nome
FROM Pizze p 
JOIN Ricette r ON r.codPizza = p.codPizza
JOIN Ingredienti i ON r.codIngrediente = i.codIngrediente
WHERE i.quantitàMagazzino = 0
```

```sql
-- trovare il nome e il prezzo delle pizze che contengono sia rucola che pomodori freschi;

SELECT p.Nome, p.prezzo
FROM Pizze p 
JOIN Ricette r ON r.codPizza = p.codPizza
JOIN Ingredienti i ON r.codIngrediente = i.codIngrediente
WHERE i.nome IN ('rucola','pomodori freschi')
GROUP BY p.nome, p.prezzo
HAVING COUNT(*) = 2

-- Potevo anche fare così
SELECT p.Nome, p.Prezzo
FROM Pizze p 
JOIN Ricette r ON r.codPizza = p.codPizza 
JOIN Ingredienti i ON r.codIngrediente = i.codIngrediente AND i.Nome = 'rucola'
JOIN Ricette r2 ON r2.codPizza = p.codPizza
JOIN Ingredienti i2 ON r2.codIngrediente = i2.codIngrediente AND i2.Nome = 'pomodori freschi'
```

```sql
-- per ogni pizza, trovare il nome e quante volte `e stata ordinata da Leo Ortolani. Se una pizza non `e mai stata ordinata da Ortolani restituire 0;
SELECT p.nome, COUNT(*)
FROM Pizze p 
LEFT JOIN Ordini o ON p.codPizza = o.codPizza AND o.nomeCliente = 'Leo Ortolani'
GROUP BY p.nome

-- Posso anche mettere la condizione nel WHERE
SELECT p.nome, COUNT(*)
FROM Pizze p 
LEFT JOIN Ordini o ON p.codPizza = o.codPizza
WHERE o.nomeCliente = 'Leo Ortolani'
GROUP BY p.nome
```

```sql
WITH pizzeSenzaAcciuga AS (
	SELECT *
	FROM pizze p
	WHERE NOT EXISTS (
		SELECT 1
		FROM Ricette r
		JOIN Ingredienti i ON i.codIngrediente = r.codIngrediente
		WHERE i.nome = 'acciuga' AND r.codPizza = p.Pizza
	)
)
```

```sql
UPDATE Pizze p
SET p.prezzo
WHEN p.codPizza IN (
	SELECT p.codPizza
	FROM Pizze p
	JOIN Ricette r ON (codPizza)
	JOIN Ingredienti i ON (codIngredienti)
	GROUP BY p.CodPizza
	HAVING SUM (
		(r.quantita * i.costoBase) 
		< (p.prezzo * 0.5)
	)
)
```


- City(id, name, countrycode*, population) 
	- countrycode FK(Country) 
- Country(code, name, continent, capital*, population, indepyear, governmentform) 
	- capital FK(City) 
- Countrylanguage(countrycode*, language, isofficial, percentage) 
	- countrycode FK(Country)

```sql
SELECT COUNT(*)
FROM Country co
JOIN Countrylanguage l ON co.code = l.countrycode
WHERE continent = 'Europa'
	AND co.population > 20000000 
	AND l.language = 'Tedesco'
	AND NOT l.isofficial 
```

```sql
SELECT governmentform, COUNT(c.code) AS nazioni, COUNT(DISTINCT c.continent)
FROM Country c
GROUP BY governmentform
HAVING COUNT(c.code) > 3
ORDER BY nazioni DESC
```

```sql
SELECT n.continent, COUNT(DISTINCT n.code) AS nazioni
FROM Country n
LEFT JOIN City cap ON n.capital = cap.id
LEFT JOIN City c ON c.countrycode = n.code AND c.population > cap.population
GROUP BY n.continent
```

```sql
WITH percentualiISC AS (
	SELECT *
	FROM Country c
	JOIN Countrylanguage l ON c.code = l.countrycode
	AND l.language IN ('Inglese','Spagnolo','Cinese')
	AND c.continent = 'Asia'
)

```

```sql
SELECT v.CittaPart
FROM Voli v 
JOIN Aereoporti a ON a.Citta = v.CittaArr AND a.Nazione = 'Italia'
JOIN Aereoporti a2 ON a2.Citta = v.CittaPart AND a2.Nazione = 'Francia'
GROUP BY v.CittaPart
HAVING COUNT (*) > 20

```

 - Produttori(IdProduttore, Nome, Paese, Continente) 
 - Prodotti(IdProdotto, Nome, Prezzo, IdProduttore*) 
	 - IdProduttore FK(Produttori)

```sql
WITH PrezziProdottoPerProduttore (IdProduttore, Nome, Paese, Continente, Totale) AS (
	SELECT pr.IdProduttore, 
		   pr.Nome, 
		   pr.Paese, 
		   pr.Continente, 
		   SUM(Prezzo) AS Totale
	FROM Produttori pr JOIN Prodotti p ON pr.IdProduttore = p.IdProduttore
	GROUP BY pr.IdProduttore, 
			 pr.Nome, 
			 pr.Paese, 
			 pr.Continente
)

SELECT ppr.Nome, ppr.Totale
FROM PrezziProdottoPerProduttore
WHERE ppr.Totale > (
			 SELECT AVG(ppr2.Totale)
			 FROM PrezziProdottoPerProduttore ppr2
			 WHERE ppr2.Continente = ppr.Continente 
		 )
```

 - City(id, name, countrycode*, district, population) 
	 - countrycode FK(Country) 
 - Country(code, name, continent, capital*, population) 
	 - capital FK(City) 
 - Countrylanguage(countrycode*, language, isofficial, percentage) 
	 - countrycode FK(Country)

```sql
SELECT l.language
FROM Countrylanguage l JOIN Country c ON l.countrycode = c.code
	AND c.continent = 'Europa'
WHERE l.percentage > 50 AND l.isofficial = true
```

```sql
SELECT c.name
FROM City c 
WHERE c.id = (SELECT co.capital
			  FROM Country co 
				  JOIN City c2 ON c2.countrycode = co.code
			  WHERE c2.name = 'Fortaleza'
			 )
```

```sql
SELECT co.name
FROM Country co 
WHERE co.continent LIKE '%America%'
AND (
	SELECT SUM(c.population)
	FROM City c
	WHERE c.countrycode = co.code
) > co.population * 0.4
```