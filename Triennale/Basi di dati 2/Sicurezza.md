Importanti in un database sono **autenticazione** e **autorizzazione**. L'autenticazione viene fatta solitamente tramite password e nome utente
```sql
CREATE USER NomeUtente WITH PASSWORD NuovaPwd
```

- `SUPERUSER`: L'utente ignora tutti i controlli di sicurezza
- `CREATEDB`: consente alla creazione di nuovi database
- `VALID UNTIL`: specifica la durata massima della password

---
#### Autenticazione
- Password
	- Fatta in fase di creazione utente
	- salvata nel server
	- se il canale di comunicazione client-server non è cifrato la password passa in chiaro, un problema per la sicurezza
		- Si risolve inserendo crittografia, solitamente SSL/TLS
		- La password rimane in chiaro salvata nel server, esposta quindi a chiunque esegua con successo un attacco malevolo al server
- MD5
	- Fatta in fase di creazione
	- Il server richiede un MD5 e propone un **salt** da aggiungere all'hash
	- il client calcola l'hash usando utente+password+salt
		- lo invia al server
		- il server verifica che l'hash sia uguale e autorizza
	- sconsigliato, hash poco sicuro
- Oggi si usa il protocollo SCRAM, ma non lo approfondiremo

- SQL comunque controlla i permessi dati ad ogni utente per permettere le azioni autorizzate all'interno del database
	- `SELECT`su una tabella (opz. ristretta ad un set di attributi X ) 
	- `INSERT`su una tabella (opz. ristretta ad un set di attributi X ) 
	- `UPDATE` su una tabella (opz. ristretta ad un set di attributi X ) 
	- `DELETE` su una tabella (SELECT richiesto per DELETE non banali) 
	- `TRIGGER`, necessario per definire un trigger su una tabella 
	- `EXECUTE`, necessario per eseguire una funzione o procedura

![[Pasted image 20240320110041.png]]
$\uparrow$ richiede i seguenti permessi
- `INSERT(name)` su Studio
- `SELECT(Studioname)` su Movies
- `SELECT(name)` su Studio
---

#### Permessi sui trigger
I permessi di gestione dei trigger sono più delicati
- il permesso `TRIGGER` per una tabella abilita la definizione di trigger arbitrari
- il creatore del trigger deve avere il permesso `TRIGGER` sulla tabella e tutti i permessi richiesti per eseguire l'azione del trigger
- quando un trigger viene attivato, esso viene eseguito con i permessi del suo creatore, indipendentemente da chi ha indotto l'attivazione

Quando una funzione viene dichiarata, è possibile specificarne i permessi di esecuzione tramite le opzioni: 
- SECURITY INVOKER: la funzione viene eseguita con i permessi dell’utente chiamante (default) 
- SECURITY DEFINER: la funzione viene eseguita con i permessi dell’utente che l’ha definita

Il proprietario di uno schema relazionale ha tutti i permessi possibili sulle tabelle e gli altri elementi di tale schema. Tali permessi possono essere concessi ad altri utenti usando la sintassi:

```sql
GRANT ListaPermessi ON Elemento TO ListaUtenti
```

> Possibilità di usare `ALL PRIVILEGES` per indicare tutti i permessi

> Possibilità di usare `PUBLIC` per autorizzare tutti gli utenti, compresi quelli non ancora esistenti

I permessi possono comunque essere revocati usando il comando `REVOKE` tramite la sintassi:
```sql
REVOKE ListaPermessi ON Elemento FROM ListaUtenti
```

> `CASCADE`: il permesso viene revocato ricorsivamente a tutti gli utenti che lo hanno ricevuto solamente tramite il target della revoca

> `RESTRICT`: fa fallire la revoca se essa comporterebbe la revoca di ulteriori permessi secondo la politica `CASCADE`

![[Pasted image 20240320111920.png]]
![[Pasted image 20240320111902.png]]

---

![[Pasted image 20240320112009.png]]

--- 

![[Pasted image 20240320112111.png]]

---

![[Pasted image 20240320112316.png]]

> È possibile che un utente possieda sia un permesso p che una sua variante meno generale $p^-$ sullo stesso oggetto. Normalmente togliere $p^-$ non ha alcun effetto su p. Al contrario invece dipende (p->$p^-$) decide il DBMS.  
> Postgres per esempio se ne sbatte i coglioni e revoca anche $p^-$. Solitamente non succede


I permessi possono essere gestiti tramite i **ruoli**, che fungono da collettori di permessi.
```sql
CREATE ROLE NomeRuolo;
```

I ruoli assegnati ad un utente però non sono attivi di default. L'attivazione per ottenere permessi avviene con la seguente sintassi:
```sql
SET ROLE NomeRuolo;
```

![[Pasted image 20240320113029.png]]

I ruoli:
- i ruoli raggruppano insiemi di permessi logicamente collegati 
- è molto meno costoso assegnare ruoli che permessi, visto che ci sono molti meno ruoli che permessi 
- è molto più difficile sbagliare l’assegnazione di un ruolo che di un insieme di permessi 
- le operazioni di revoca sono analogamente semplificate 
- i ruoli non sono attivi di default, contrariamente ai permessi: questo è più fedele al principio del **minimo privilegio**

