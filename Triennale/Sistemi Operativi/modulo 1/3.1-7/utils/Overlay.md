-  Tecnica di programmazione per superare i limiti di allocazione contigua
	- Il programma è diviso in sezioni logiche
	- Si memorizzano soltanto le sezioni attive al momento
	- Difficile organizzazione 
	- Complica la modifica ai programmi
- L'overlay fornisce protezione a livello utente impedendo la sovrascrittura in memoria dell'OS
	- Per farlo usa dei registri limite (boundary) che contiene l'indirizzo dove inizia lo spazio di memoria del programma
	- Ogni accesso oltre al registro limite è vietato
	- Può essere impostato questo tipo di registro solo da istruzioni privilegiate
	- Rilocazione dinamica
- I primi sistemi richiedevano un tempo di setup rilevante con un conseguente spreco di risorse e di tempo. Automatizzare setup e teardown porta ad una miglior efficienza
- Batch processing
	- Processore con flusso di job stream letti in job control language
		- Definisce ogni job e come configurarlo

![[Pasted image 20240111175819.png]]