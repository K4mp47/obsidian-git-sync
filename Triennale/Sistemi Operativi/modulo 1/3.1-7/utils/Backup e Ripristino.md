- Tecniche di backup per conservare le copie ridondanti
	- Backup periodici
	-  Backup fisico 
		- Duplicare i dati di un dispositivo di memoria a livello di bit 
		- Senza informazioni logiche 
		- compatibilità limitata 
		- Semplice tecnica di backup 
	- Backup logico 
		- Memorizzare i dati del file system e la sua struttura logica 
		- Controlla la struttura delle directory per determinare quali file devono essere sottoposti a backup, quindi scrive questi file su un dispositivo di backup in un formato di archiviazione, spesso compresso 
			- Esempio: formato tar in Unix 
		- I backup incrementali sono backup logici che memorizzano solo i dati del file system che sono stati modificati rispetto al backup precedente 
		- Possibile maggior frequenza di backup
- Tecniche di Ripristino per ripristinare il sistema e i suoi dati dopo un errore di sistema
- ![[Pasted image 20240112122438.png]]
- ![[Pasted image 20240112122446.png]]
[[Integrità]]
