### Schema:
```
Product(maker, _model_, type)
Pc(_model_*, speed, ram, hd, price)
Laptop(_model_*, speed, ram, hd, screen, price)
Printer(_model_*, color, type, price)
```

1. **Nessun produttore di Pc può anche produrre laptop**
	1. Operazioni di `INSERT` e `UPDATE`
	2. Interessa delle singole righe non la tabella
	3. Posso farlo `BEFORE`

```sql
CREATE TRIGGER CheckProducer
BEFORE INSERT OR UPDATE ON Product
FOR EACH ROW
EXECUTE FUNCTION check_maker()

CREATE FUNCTION check_maker() 
RETURNS trigger AS $$
BEGIN
	IF (NEW.type = 'pc' AND NEW.maker in (SELECT maker FROM Product WHERE type='laptop'))
		THEN RETURN NULL;
	END IF;
	IF (NEW.type = 'laptop' AND NEW.maker in (SELECT maker FROM Product WHERE type='pc'))
		THEN RETURN NULL;
	END IF;
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;
```

> Questa sopra è la generazione di un trigger in linguaggio postgresql. Ricordiamo come la funzione debba ritornare NULL per annullare,  altrimenti NEW per insert e update  e OLD per delete. plpgsql sempre per far capire che linguaggio si sta usando

2. **Se un Laptop ha più di un Pc, allora deve anche costare di più di tale Pc**
	1. Potrebbe portare problemi per le operazioni di `INSERT` o `UPDATE`
	2. interessa una riga sola/ condizione è però per statement
	3. `BEFORE`

```sql
CREATE TRIGGER LowerPcThanLaptopTrigger
BEFORE INSERT OR UPDATE ON Laptop
FOR EACH ROW
EXECUTE FUNCTION no_cheap_laptop()

CREATE FUNCTION no_cheap_laptop() 
RETURN trigger AS $$
BEGIN
	IF EXISTS(SELECT * FROM Pc WHERE NEW.ram > ram AND NEW.price <= price) THEN RETURN NULL;
	END IF;
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;
```

3. **Il modello di un prodotto deve essere anche il modello di un Pc, di un Laptop oppure di una stampante**
	1. `INSERT` o `UPDATE` da Product `DELETE` dalle altre tabelle
	2. Interessa una singola riga
	3. `BEFORE`, `AFTER` se è delete

```sql
CREATE TRIGGER CheckModel
BEFORE INSERT OR UPDATE IN Product
FOR EACH ROW
EXECUTE FUNCTION check_model()

CREATE FUNCTION check_model()
RETURN trigger AS $$
BEGIN
	IF NEW.model IN(
		SELECT model FROM Pc UNION
		SELECT model FROM Laptop UNION
		SELECT model FROM Printer
	) THEN 
		RETURN NEW;
	ENDIF;
	RETURN NULL;
END;
$$ LANGUAGE plpgsql;

```

Situazione delicata per quanto riguarda la `DELETE` perché devo avere prima quel modello di Product