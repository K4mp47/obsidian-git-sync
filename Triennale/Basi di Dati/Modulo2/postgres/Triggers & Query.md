## Query 1
```sql
SELECT *
FROM Movies
WHERE studio = 'Disney' AND year = 2012;
```

Se il nostro **database** contiene 10.000 film ma la Disney ha prodotto solo 5 film nel 2012, siamo costretti ad ispezionare 10.000 tuple per ritornare alla fine solo 5 risultati!

Per ovviare questo calo di prestazioni utilizziamo gli **indici**, strutture dati ausiliarie che ci permettono di accedere in maniera più efficiente alle tuple di una relazione che soddisfano una determinata proprietà.

