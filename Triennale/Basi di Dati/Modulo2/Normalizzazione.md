- Quando una rappresentazione è di buona qualità?
- Quando due diverse rappresentazioni sono equivalenti?
La teoria della normalizzazione si occupa di formalizzare questi concetti e dare una risposta rigorosa a tali domande

![[Pasted image 20240212092301.png]]
rappresentazione della biblioteca:
- Ogni libro ha un codice di riconoscimento
- Posso essere presi da un determinato utente, con data di prestito e numero di telefono 

Problemi di questa rappresentazione:
 - Ridondanza, se un utente prende più libri deve essere inserito in più righe differenti
	 - Può causare problemi per la presenza di aggiornamento parziale dei dati
	 - ![[Pasted image 20240212092510.png]]
	 - Problema di inserimento e cancellazione, dovuti ad una cattiva progettazione della base di dati
		 - Un utente si registra ma non ha nessun libro preso, come lo salvo?? (ipotizziamo che la base di dati voglia salvare un utente con almeno un libro in prestito)
 - Scarsa espressività, rappresentabili solo gli utenti con almeno un libro
 
**Modellazione Alternativa**
![[Pasted image 20240212092826.png]]

**Esempio modellazione errata**
![[Pasted image 20240212093053.png]](Due utenti hanno lo stesso numero, come posso sapere a chi ha in prestito il libro? **Perdita di informazione**)

In lezione useremo la seguente notazione: 
- Lettere maiuscole all’inizio dell’alfabeto, es. A, B, C : attributi 
- Lettere maiuscole alla fine dell’alfabeto, es. T , X , Y : insiemi di attributi 
- R(T): schema di relazione costruito sull’insieme di attributi T 
- r : istanza(schema relazionale popolato da alcune righe) dello schema di relazione R(T), cioè un insieme di ennuple(righe) 
- t, u, v : ennuple di un’istanza di un dato schema di relazione 
- t\[X]: ennupla ottenuta da t considerando i soli attributi in X

**Definizione di Dipendenza Funzionale**
Sia R(T ) uno schema di relazione e siano $X , Y$ due insiemi di attributi non vuoti tali che $X ∪ Y ⊆ T$ , una dipendenza funzionale è un qualsiasi vincolo della forma $X → Y$ .

**Soddisfacibilità**
Un’istanza r di R(T ) soddisfa la dipendenza funzionale $X → Y$ se e solo se ogni coppia di ennuple in $r$ che coincide su $X$ coincide anche su $Y$ . Formalmente chiediamo $$∀t1, t2 ∈ r : t1[X ] = t2[X ] ⇒ t1[Y ] = t2[Y ]$$
![[Pasted image 20240212095053.png]]
**Dipendenze derivate**
Sia R(T , F) uno schema di relazione. Diciamo che $F$ implica logicamente la dipendenza funzionale $X → Y$ , indicato con $F |= X → Y$ , se e solo se ogni istanza valida di R(T , F ) soddisfa anche $X → Y$.
![[Pasted image 20240212095241.png]]
$$F |= X → Y$$ come dimostare la precedente formula?
![[Pasted image 20240212100028.png]]$|=$ derivazione certa
$|-$ derivazione personale, non per forza corretta
se $|-$ non rispetta tutte e tre le regole di inferenza allora
$$|- \neq |=$$
invece come posso dimostrare la seguente formula: $F|- X \rightarrow Y$?
![[Pasted image 20240212100745.png]]
**Regola derivata: Unione**
![[Pasted image 20240212100955.png]]
(AUGM) (arricchimento)
(TRANS) (transitività)
**Regola derivata: Decomposizione**
![[Pasted image 20240212101329.png]]
**Regola derivata: Indebolimento**
![[Pasted image 20240212101350.png]]
**Problema dell'implicazione**
Le dipendenze funzionali che ci interessano veramente sono tutte quelle che possiamo derivare (e quindi implicare logicamente)
![[Pasted image 20240216122011.png]]
Notiamo che calcolare $F^+$ applicando gli assiomi di Amstrong ha costo **esponenziale**.
Calcolarlo quindi è algoritmicamente inefficiente per risolvere l'implicazione.
![[Pasted image 20240216122148.png]]
Tutto ciò permette di calcolare $X \rightarrow Y \in F^+$ controllando se $Y \subseteq X^+_F$ che vedremo essere calcolabile in tempo **polinomiale**, risolvendo l'implicazione in modo efficiente!!

esiste una dipendenza funzionale in $F$ che ha nella parte sinistra un sottoinsieme degli attributi di $X$? Calcoliamo allora $X^+_F$
> Vediamo un esempio con 
> $X = AB$     ($X$ contiene gli attributi $A$ e $B$)  
> $F = {A → C , AC → D, E → F }$    (Dipendenze funzionali, esempio $C$ dipende da $A$ ecc):
>![[Pasted image 20240216124610.png]]
> Iniziamo supponendo
> 1. $X^+_0 = AB$
> 2. Cerchiamo nelle dipendenze funzionali una che abbia alla sinistra un sottoinsieme degli attributi di $X^+_0$ ( $X^+_1 = AB \cup C = ABC$)
> 3. Ripetiamo e troviamo  $X^+_2 = ABC \cup D= ABCD$ 
> 4. Non ci sono altre dipendenze funzionali con a sinistra un sottoinsieme degli attributi di $X^+_2$ quindi ci si ferma
> ![[Pasted image 20240216125718.png]]

![[Pasted image 20240216125833.png]]


