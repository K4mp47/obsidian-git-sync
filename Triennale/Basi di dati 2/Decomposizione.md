Se gli schemi sono di scarsa qualità essi soffrono di **anomalie**, che vanno ad ostacolare le operazioni di inserimento, cancellazione ed aggiornamento dei dati
![[Pasted image 20240304162834.png]]
L'eliminazione delle anomalie è tipicamente basata sulla decomposizione di schemi mal definiti in schemi minori ed equivalenti.
![[Pasted image 20240304162927.png]]

#### Decomposizione di Schemi
![[Pasted image 20240304162954.png]]
Sebbene decomporre uno schema possa correggere le anomalie, non tutte le decomposizioni sono desiderabili:
- Potrebbero portare alla perdita di informazione introducendo dati spuri
	- Esempio
	- ![[Pasted image 20240304163215.png]]
	- Qual'è il telefono del proprietario della casa in Via Torino, 155?
	- ![[Pasted image 20240304163316.png]]
	- Come verificare se invece una decomposizione preserva i dati?
	- ![[Pasted image 20240304163452.png]]
	- Esempio **1**:
	- ![[Pasted image 20240304163621.png]]
	- ![[Pasted image 20240304163632.png]]
	- Esempio **2**:
	- ![[Pasted image 20240304163705.png]]
	- ![[Pasted image 20240304163715.png]]
- Potrebbero portare alla perdita di dipendenze funzionali, alterando la semantica
	- Esempio:
	- ![[Pasted image 20240304163805.png]]
	- Come capire quindi, se preservo le dipendenze? Solo se l'unione delle dipendenze **indotte** sui singoli schemi equivale alle dipendenze dello schema originale
	- ![[Pasted image 20240304163928.png]]
	- Verifica dell'equivalenza
	- ![[Pasted image 20240304163955.png]]
	- ![[Pasted image 20240304164013.png]]
	- ![[Pasted image 20240304164028.png]]
	- Esempi pratici:
		- ![[Pasted image 20240304164055.png]]
		- ![[Pasted image 20240304164100.png]]
		- In realtà per calcolare la veridicità si può usare un algoritmo di tempo **polinomiale**:
			- ![[Pasted image 20240304164209.png]]
			- ![[Pasted image 20240304164218.png]]
	- ![[Pasted image 20240304164244.png]]