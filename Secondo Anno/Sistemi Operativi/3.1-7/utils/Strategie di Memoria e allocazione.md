- Strategie fetch
	- Quando devo spostare la prossima sezione di programma
- Strategie di posizionamento
	- Dove devo inserire i dati in memoria (Best, Worst, First fit)
- Strategie di sostituzione
	- Quali dati o programmi devo rimuovere per creare spazio

## Allocazione
- Contigua
	- Un programma deve essere memorizzato come un unico blocco
	- Può essere impossibile trovare un blocco abbastanza grande
	- Basso overhead

- Non Contigua
	- Il programma è diviso in segmenti
	- Ogni segmento può essere allocato in diverse parti della memoria 
	- Maggiore overhead compensato da un maggior numero di programmi in memoria contemporaneamente

- Contigua mono utente
	- Un utente ha il controllo dell'intero sistema
	- 