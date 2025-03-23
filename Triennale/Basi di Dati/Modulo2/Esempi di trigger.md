```sql 
CREATE OR REPLACE FUNCTION price_fn() RETURNS trigger AS $$
BEGIN
END;
$$ language plpgsql;

CREATE OR REPLACE TRIGGER price_tg()
BEFORE UPDATE ON lab.pc
FOR EACH ROW 
WHEN (new.price < old.price)
EXECUTE FUNCTION price_fn();
```

```sql
SELECT * FROM lab.pc
```

```sql
UPDATE lab.pc SET price=400 WHERE model=1233
-- whit the trigger this line shouldn't work
```