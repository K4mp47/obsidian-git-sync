![[Pasted image 20241114160312.png]]
### 1.
```sql
SELECT p.nome, i.nome, i.costoBase
FROM Pizze p JOIN Ricette r ON p.codPizza = r.codPizza JOIN Ingredienti i ON i.codIngrediente = r.codIngrediente
WHERE p.prezzo > 15 AND p.tempoPrep < 20
```

Creiamo degli esempi di dati per ciascuna delle tabelle coinvolte e poi applichiamo la query per mostrare passo-passo il suo funzionamento.

### Tabelle di Esempio

#### Tabella **Pizze**

|codPizza|nome|tempoPrep|prezzo|
|---|---|---|---|
|1|Margherita|15|10.00|
|2|Diavola|18|16.00|
|3|Capricciosa|25|18.00|
|4|Quattro Stagioni|19|15.50|

#### Tabella **Ingredienti**

|codIngrediente|nome|quantitaMagazzino|costoBase|
|---|---|---|---|
|1|Pomodoro|100|0.50|
|2|Mozzarella|200|1.00|
|3|Salame|50|2.00|
|4|Funghi|30|1.50|
|5|Prosciutto|40|2.50|

#### Tabella **Ricette**

| codPizza | codIngrediente | quantita |
| -------- | -------------- | -------- |
| 1        | 1              | 1        |
| 1        | 2              | 1        |
| 2        | 1              | 1        |
| 2        | 2              | 1        |
| 2        | 3              | 1        |
| 3        | 1              | 1        |
| 3        | 2              | 1        |
| 3        | 4              | 1        |
| 3        | 5              | 1        |
| 4        | 1              | 1        |
| 4        | 2              | 1        |
| 4        | 4              | 1        |

#### Applicazione della Query

La query richiede di restituire:

- il nome delle pizze,
- il nome degli ingredienti,
- e il costo base degli ingredienti.

#### Passo 1: Filtrare le Pizze con le Condizioni Richieste

Dalla tabella **Pizze**, selezioniamo solo le righe che soddisfano entrambe le condizioni:

- `prezzo > 15`
- `tempoPrep < 20`

|codPizza|nome|tempoPrep|prezzo|
|---|---|---|---|
|2|Diavola|18|16.00|
|4|Quattro Stagioni|19|15.50|

#### Passo 2: Collegare con la Tabella **Ricette**

Ora, uniamo queste pizze filtrate con la tabella **Ricette** in base a `codPizza` per ottenere gli ingredienti utilizzati nelle pizze selezionate.

|codPizza|nome|codIngrediente|quantita|
|---|---|---|---|
|2|Diavola|1|1|
|2|Diavola|2|1|
|2|Diavola|3|1|
|4|Quattro Stagioni|1|1|
|4|Quattro Stagioni|2|1|
|4|Quattro Stagioni|4|1|

#### Passo 3: Collegare con la Tabella **Ingredienti**

Infine, colleghiamo questo risultato con la tabella **Ingredienti** utilizzando `codIngrediente` per ottenere il nome e il costo base di ogni ingrediente.

|codPizza|nome_pizza|nome_ingrediente|costoBase|
|---|---|---|---|
|2|Diavola|Pomodoro|0.50|
|2|Diavola|Mozzarella|1.00|
|2|Diavola|Salame|2.00|
|4|Quattro Stagioni|Pomodoro|0.50|
|4|Quattro Stagioni|Mozzarella|1.00|
|4|Quattro Stagioni|Funghi|1.50|

---

#### Risultato Finale

La query restituisce i seguenti risultati:

|nome_pizza|nome_ingrediente|costoBase|
|---|---|---|
|Diavola|Pomodoro|0.50|
|Diavola|Mozzarella|1.00|
|Diavola|Salame|2.00|
|Quattro Stagioni|Pomodoro|0.50|
|Quattro Stagioni|Mozzarella|1.00|
|Quattro Stagioni|Funghi|1.50|

Questo risultato mostra il nome delle pizze, il nome degli ingredienti e il costo base per ciascun ingrediente nelle pizze che rispettano le condizioni richieste.


### 2.
```sql
SELECT COUNT(DISTINCT r.codPizza) 
FROM Ricette r JOIN Ingredienti i ON r.codIngrediente = i.codIngrediente
WHERE i.nome = "prosciutto" 
	AND r.codPizza NOT IN (
		SELECT r2.codPizza
		FROM Ricette r2 
		JOIN Ingredienti i2 ON r2.codIngrediente = i2.codIngrediente
		WHERE i2.nome = "pomodoro"
	);
```

### Spiegazione della Query

1. **JOIN tra Ricette e Ingredienti** (alias `r1` e `i1`): individuiamo le pizze che contengono l'ingrediente "Prosciutto" collegando `codIngrediente` tra le tabelle **Ricette** e **Ingredienti**.
2. **Filtro `i1.nome = 'Prosciutto'`**: seleziona solo le righe in cui l'ingrediente è "Prosciutto".
3. **Subquery per trovare le pizze con "Pomodoro"**:
    - La subquery individua tutte le `codPizza` che contengono "Pomodoro".
    - La condizione `r1.codPizza NOT IN (...)` esclude dal risultato tutte le pizze che contengono anche "Pomodoro".
4. **COUNT(DISTINCT r1.codPizza)**: conta il numero di pizze distinte che contengono "Prosciutto" ma non "Pomodoro".

#### Esempio di Applicazione con Dati

Rivediamo i dati di esempio per verificare il risultato.

#### Tabella **Ingredienti**

|codIngrediente|nome|
|---|---|
|1|Pomodoro|
|2|Mozzarella|
|3|Salame|
|4|Funghi|
|5|Prosciutto|

#### Tabella **Ricette**

|codPizza|codIngrediente|
|---|---|
|1|1|
|1|2|
|2|1|
|2|3|
|3|4|
|3|5|
|4|1|
|4|2|
|4|5|

#### Passo 1: Trovare le Pizze con Prosciutto

Dal filtro `i1.nome = 'Prosciutto'`, otteniamo le seguenti pizze:

- Pizza **3** (Capricciosa)
- Pizza **4** (Quattro Stagioni)

#### Passo 2: Escludere le Pizze con Pomodoro

Dalla subquery `NOT IN`, escludiamo le pizze che contengono "Pomodoro":

- La pizza **4** (Quattro Stagioni) contiene "Pomodoro", quindi viene esclusa.

#### Risultato Finale

Rimane solo la pizza **3** (Capricciosa), quindi il risultato della query è:

|numero_pizze|
|---|
|1|

#### Conclusione

Il numero di pizze che contengono **Prosciutto** ma non **Pomodoro** è **1**.

### 3.
```sql
SELECT p.nome, (p.prezzo - SUM(r.quantità * i.costoBase)) AS differenza
FROM 
	Ricette r JOIN Pizze p ON r.codPizza = p.codPizza 
	JOIN Ingredienti i ON r.codIngredienti = i.codIngredienti
GROUP BY p.codPizza, p.nome, p.prezzo
HAVING SUM(i.codBase * r.quantità) < 0.5 * p.prezzo
```

### 4.
```sql
SELECT o.nomeCliente
FROM Ordini o
WHERE o.nomeCliente IS IN (
	SELECT o.nomeCliente
	FROM Ordini o JOIN Pizze p ON o.codPizza = p.codPizza
	WHERE p.prezzo > 10
)
```

```sql
WITH PizzaOrdini AS (
	SELECT 
		o.codPizza, 
		o.nomeCliente, 
		COUNT(o.codOrdine) AS numOrdini
	FROM Ordini o JOIN Pizze p ON o.codPizza = p.codPizza
	WHERE p.prezzo > 10
	GROUP BY o.codPizza, o.nomeCliente
)

WITH MaxOrdini AS (
	SELECT codPizza, MAX(numOrdini) AS maxNumOrdini
	FROM PizzaOrdini po 
	GROUP BY codPizza
)

SELECT p.nome AS nomePizza, po.nomeCliente, po.numOrdini 
FROM 
	PizzaOrdini po 
	JOIN MaxOrdini mo ON po.codPizza = mo.codPizza AND po.numOrdini = mo.maxNumOrdini 
		JOIN Pizze p ON po.codPizza = p.codPizza 
```