### Operatori insiemistici ed espressioni regolari
- Prestare molta attenzione al tipo, se le operazioni vengono fatte tra tipi diversi, esse non sono possibili
- Operazioni:
	- **UNION**
	- **INTERSECT**
	- **EXCEPT** (Differenza)
- Esempi:
	- **SELECT** Nome, Cognome, Matricola **FROM** Studenti **WHERE** Provincia='VE' **UNION** **SELECT** Nome, Cognome, Matricola **FROM** Studenti **JOIN** Esami **ON** Matricola=Candidato **WHERE** Voto>28
	- **SELECT** Matricola **FROM** Studenti **EXCEPT** **SELECT** Tutor **AS** Matricola **FROM** Studenti
	- Posso usare EXCEPT **ALL**, in questo modo i duplicati non vengono rimossi
	- **IS** per verificare che sia il valore **NULL**, non voglio usare l'uguale, torna unknown!!
	- **SELECT** Nome, Cognome, Matricola **FROM** Studenti **JOIN** Esami **ON** Matricola=Candidato **WHERE** Voto = 18 **INTERSECT ALL** **SELECT** Nome, Cognome, Matricola **FROM** Studenti **JOIN** Esami **ON** Matricola=Candidato **WHERE** Voto=30 
	  
	  (Restituisce il minimo tra le due **SELECT**, le due query)
	-  **SELECT DISTINCT** Nome, Cognome, Matricola **FROM** Studenti **JOIN** Esami **ON** Matricola = Candidato **JOIN** Esami **ON** Matricola = Candidato **WHERE** Voto = 18 **AND** Voto = 30 (Serve per forza la doppia join, sto usando i valori dentro la doppia condizione, non posso farlo sempre sulla stessa tabella, corrisponde ai valori doppi )
	- **SELECT** Nome, Cognome, Matricola **FROM** Studenti **WHERE** Nome **LIKE** 'A_%'
		- % = 0 o più caratteri possibili
		- _ = un carattere qualsiasi 
		- A = lettera iniziale
		- **LIKE** = operatore per eseguire il controllo a stringa
	- **SELECT** Nome, Cognome, Matricola **FROM** Studenti **WHERE** Nome **LIKE** 'A_%' **SELECT** Nome, Cognome, Matricola **FROM** Studenti **WHERE** Nome **LIKE** 'A%i' **OR** Nome **LIKE** 'A%a'