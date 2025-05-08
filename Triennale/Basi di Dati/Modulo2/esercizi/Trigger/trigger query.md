Exercis reference: [[2023_03Finale 1.pdf]]

**PRIMA QUERY DI TEST PER VEDERE SE PC FUNZIONA. IL TRIGGER AGISCE SOLO SE PRICE IN UPDATE O INSERT SE MODIFICATA LA QUERY SUPERANO IL PRICE 1110**

```sql
create or replace trigger CheckPrices
before insert or update on lab.pc
for each row
execute function check_prices();

create or replace function check_prices() 
returns trigger as $$
begin
	IF NEW.price > 1110 THEN return null;
	end if;
	return new;
end;
$$ language plpgsql;


-- INSERT INTO lab.product VALUES('Asus',1110,'pc');
UPDATE lab.pcIngredienti
set price = 600
where model=1110;

-- delete from lab.pc 
-- where model = 1110;

-- delete from lab.product
-- where model = 1110;

```

**PRENDENDO LE INFORMAZIONI DA UN VECCHIO COMPLETO, DEVO RISOLVERE USANDO LA BASE DI DATI PROPOSTA LA CREAZIONE DI ALCUNI TRIGGER**
- Pizze(codPizza, nome, tempoPrep, prezzo) 
- Ingredienti(codIngrediente, nome, quantitàMagazzino, costoBase) 
- Ricette(codPizza*, codIngrediente*, quantità) 
	- codPizza FK(Pizze) 
	- codIngrediente FK(Ingredienti) 
- Ordini(codOrdine, nomeCliente, indirizzoCliente, oraConsegna, codPizza*) 
	- codPizza FK(Pizze)

1. La ricetta di ciascuna pizza non può includere più di otto ingredienti diversi, indipendentemente dalla loro quantità. 
2. Il costo complessivo dei prodotti contenuti all’ interno del magazzino deve essere sempre compreso fra i 200 ed i 500 euro. 
3. Tutti gli ordini effettuati dallo stesso cliente (identificato da nome ed indirizzo) devono essere consegnati alla stessa ora. 
4. Il costo di ciascuna pizza deve essere maggiore o uguale alla somma dei costi dei suoi ingredienti, tenendo conto della loro quantità

```sql
-- primo punto
CREATE TRIGGER CheckNumIngr
BEFORE INSERT ON Ricette
FOR EACH ROW
EXECUTE FUNCTION check_num_ingr()

CREATE FUNCTION check_num_ingr() RETURNS TRIGGER AS $$
BEGIN
	IF (SELECT COUNT(*) FROM Ricette WHERE codpizza = new.codpizza) > 8 THEN RETURN NULL;
	END IF;
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;

-- ricordo che in postgresql va scritta prima la funzione
-- sotto riportato il codice usato per testare il trigger
INSERT INTO pizze(codpizza, nome, tempoprep, prezzo) 
VALUES (100, 'PizzaMaxi', 15, 10.00);

-- 4. Aggiunta di 8 ingredienti alla pizza (limite massimo)
INSERT INTO ricette(codpizza, codingrediente, quantita) VALUES
(100, 1, 1),  -- Mozzarella
(100, 2, 1),  -- Pomodoro
(100, 4, 1),  -- Prosciutto
(100, 7, 1),  -- Peperoni
(100, 11, 1), -- Parmigiano
(100, 14, 1), -- Ricotta
(100, 17, 1), -- Origano
(100, 22, 1); -- Pomodorini

-- Verifica che abbiamo 8 ingredienti
SELECT COUNT(*) FROM ricette WHERE codpizza = 100; -- Dovrebbe restituire 8

-- 5. Tentativo di aggiungere un 9° ingrediente (dovrebbe fallire)
INSERT INTO ricette(codpizza, codingrediente, quantita)
VALUES (100, 3, 1); -- Gamberetti - Dovrebbe essere bloccato dal trigger

-- DELETE from ricette where codingrediente = 3
```

```sql
-- secondo punto

-- function for insert operation
-- value of 200 500 changed in order to work with the
-- pizzeria database already used on module 1
create or replace function check_max_mag_ins() returns trigger as $$
begin
	if ((select sum(quantitamagazzino * costobase) as costototale from ingredienti) + (new.costobase*new.quantitamagazzino)) > 8000 
		then return null;
	end if;
	if ((select sum(quantitamagazzino * costobase) as costototale from ingredienti) + (new.costobase*new.quantitamagazzino)) < 6000 
		then return null;
	end if;
	return new;
end;
$$ language plpgsql;

create or replace trigger CheckMaxMagIns
before insert on ingredienti
for each row
execute function check_max_mag_ins();

-- function for update operation
create or replace function check_max_mag_upd() returns trigger as $$
begin
	if ((select sum(quantitamagazzino * costobase) as costototale from ingredienti) + (new.costobase*new.quantitamagazzino) - (old.costobase * old.quantitamagazzino)) > 8000 
		then return null;
	end if;
	if ((select sum(quantitamagazzino * costobase) as costototale from ingredienti) + (new.costobase*new.quantitamagazzino) - (old.costobase * old.quantitamagazzino)) < 6000 
		then return null;
	end if;
	return new;
end;
$$ language plpgsql;

create or replace trigger CheckMaxMagUpd
before update on ingredienti
for each row
execute function check_max_mag_upd();

-- operation put together
-- i was questioning myself: What if i delete and i go under 6000?·
CREATE FUNCTION check_max_mag()
RETURNS TRIGGER AS $$
BEGIN
	DECLARE
		current_total NUMERIC := (SELECT SUM(quantitamagazzino * costobase) AS costototale FROM ingredienti);
		
		new_value NUMERIC;
	BEGIN
		IF TG_OP = 'INSERT' THEN
			new_value := current_total + (new.costobase * new.quantitamagazzino);
		ELSIF TG_OP = 'UPDATE' THEN
			new_value := current_total + (new.costobase * new.quantitamagazzino) - (old.costobase * old.quantitamagazzino);
		END IF;
		
		IF new_value > 8000 THEN
			RETURN NULL;
		ELSIF new_value < 6000 THEN 
			RETURN NULL;
		END IF;
		
		RETURN NEW;
	END;
END;
$$ language plpgsql;

CREATE TRIGGER CheckMaxMag
BEFORE UPDATE OR INSERT ON ngredienti
FOR EACH ROW
EXECUTE FUNCTION check_max_mag();


-- testin values
insert into ingredienti (codingrediente, nome, quantitamagazzino, costobase) values
(30, 'ingredientetest', 400, 1);

select *, quantitamagazzino * costobase as costototale from ingredienti

update ingredienti
set costobase = 11.5
where codingrediente = 15;

-- select *, quantitamagazzino * costobase as costototale from ingredienti
-- select sum(quantitamagazzino * costobase) as costototale from ingredienti

```


```sql
-- terzo punto

-- insert & update
CREATE FUNCTION check_order_time() 
RETURNS TRIGGER AS $$
BEGIN
	IF (
		SELECT oraConsegna 
		FROM Ordini 
		WHERE nomeCliente = new.nomeCliente AND indirizzoCliente = new.indirizzoCliente
		LIMIT 1
	) IS NOT NULL AND (
		SELECT oraConsegna 
		FROM Ordini 
		WHERE nomeCliente = new.nomeCliente AND indirizzoCliente = new.indirizzoCliente
		LIMIT 1
	) <> NEW.oraConsegna THEN
		RAISE EXCEPTION 'Tutti gli ordini devono avere la stessa ora di consegna';
		RETURN NULL;
	END IF;
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER ordertimechecker
BEFORE INSERT OR UPDATE ON Ordini
FOR EACH ROW
EXECUTE FUNCTION check_order_time();
```

- Pizze(codPizza, nome, tempoPrep, prezzo) 
- Ingredienti(codIngrediente, nome, quantitàMagazzino, costoBase) 
- Ricette(codPizza*, codIngrediente*, quantità) 
	- codPizza FK(Pizze) 
	- codIngrediente FK(Ingredienti) 
- Ordini(codOrdine, nomeCliente, indirizzoCliente, oraConsegna, codPizza*) 
	- codPizza FK(Pizze)

```sql
-- punto quattro

CREATE FUNCTION check_pizza_price()
RETURNS TRIGGER AS $$
BEGIN
	DECLARE
		pizza_total NUMERIC := (SELECT sum(costobase*quantita) FROM Ricette JOIN ingredienti ON ricette.codingrediente = ingredienti.codingrediente WHERE new.codPizza = ricette.codPizza);
	BEGIN
		IF NEW.price < pizza_total THEN
			RAISE EXCEPTION 'La pizza deve costare più degli ingredienti messi dentro';
			RETURN NULL;
		END IF;
		RETURN NEW;
	END;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER checkPizzaPrice
BEFORE INSERT OR UPDATE ON pizze
FOR EACH ROW
EXECUTE FUNCTION check_pizza_price();
```