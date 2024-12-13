##### Query 1
```sql
-- Trovare l'aspettativa di vita della nazione in cui
-- si trova la città di Yangor

select c.lifeexpectancy
from country c left join city i on c.code = i.countrycode
where i.name = 'Yangor'

-- 60.8
```

##### Query 2
```sql
--- Trovare il numero di lingue ufficiali parlate da più del 50% della popolazione (percentage > 50) 
-- di una nazione nei continenti americani. 
-- Se una lingua è ufficiale e parlata da più del 50% della popolazione in più nazioni deve comparire una sola volta

select count(distinct lang.language)
from countrylanguage lang left join country c on countrycode = code
where (lang.percentage > 50 AND lang.isofficial = 'TRUE') AND (c.continent = 'North America' OR c.continent = 'South America')

-- 5
```

##### Query 3
```sql
-- Trovare il nome della capitale della nazione in cui si trova la città di Nukus

select c.name
from city c
where c.id = (
	select c.capital
	from country c left join city ci on c.code = ci.countrycode
	where ci.name = 'Nukus'
)

-- Toskent
```

##### Query 4
```sql
-- Numero di nazioni per cui non si conosce la capitale
select count(*)
from country c
where c.capital is null

-- 7
```

##### Query 5
```sql
-- Trovare il nome della nazione che ha raggiunto per prima l’indipendenza in Europa
select c.name
from country c
where c.indepyear = (select min(c.indepyear)
						from country c
						where c.continent = 'Europe'
) 

-- Denmark
```

##### Query 6
```sql
-- Contare le forme di governo in cui compare la parola Monarchy

select count(distinct c.governmentform)
from country c
where c.governmentform like '%Monarchy%'
-- 7
```

##### Query 7
```sql

```