Le forme normali hanno l'obbiettivo di garantire che uno schema sia di buona qualità e viene spesso ottenuto tramite un processo di **normalizzazione** basato su una decomposizione dello schema di partenza.
![[Pasted image 20240304164546.png]]
Le due forme di maggior interesse sono:
- **Boyce-Codd Normal Form (BCNF)**
	- ![[Pasted image 20240304164639.png]]
	- Si può dimostrare che è possibile sostituire $F^+$ con $F$ nella definizione: perciò il costo è **polinomiale**
	- ![[Pasted image 20240304164736.png]]
	- ![[Pasted image 20240304164758.png]]
	- L'algoritmo di conversione in BCNF è anche detto algoritmo di **analisi** perché decompone lo schema originale fino a normalizzazione
	- Sia $R(T,F)$ lo schema di partenza:
		- ![[Pasted image 20240304164908.png]]
		- ![[Pasted image 20240304165146.png]]![[Pasted image 20240304164954.png]]
	- La conversione in BCNF Preserva i dati
	- Garantisce l'assenza di anomalie
	- La verifica ha costo polinomiale ma la conversione **esponenziale**
	- Non preserva le **dipendenze** nel caso generale
	- ![[Pasted image 20240304165824.png]]
- **Terza Forma Normale (3FN)**
	- ![[Pasted image 20240304165403.png]]
	- Si può dimostrare che è possibile sostituire $F^+$ con $F$ nella definizione, ma verificare ha costo **esponenziale**, perché il calcolo degli attributi primi richiede di trovare tutte le chiavi
	- ![[Pasted image 20240304165843.png]]