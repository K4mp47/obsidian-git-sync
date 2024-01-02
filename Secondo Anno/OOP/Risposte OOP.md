1. Differenza tra "reference type" e "value type" in Java?
	1. La differenza tra reference type e value type consiste nel dato che stiamo andando a rappresentare. Il reference type viene sopratutto usato per rappresentare le varie classi come String, Integer ecc. e non viene passato direttamente il valore a cui si fa riferimento ma un puntatore ad esso. Inoltre se viene passato come parametro di una funzione, esso non viene passato per copia ma per reference. Nel caso invece del value type, i dati di riferimento sono quelli primitivi, come int, float, boolean, i quali non sono vengono passati per copia come parametri nelle chiamate di funzione, ma sono passati direttamente i loro valori all'interno delle variabili, come per esempio int a = 4, a al suo interno avrà il valore 4.
2.  Cosa significa "override" e quali sono le sue regole?
	1. Con il termine override si fa riferimento a quella tecnica informatica che permette ad una classe figlia di estendere/modificare/personalizzare il comportamento di una funzione già esistente nella superclasse. La funzione avrà la stessa firma, e tramite l'istruzione super() opportunatamente usata, potranno essere chiamati i rispettivi metodi della superclasse. È solito poi evidenziare un override tramite il Javadoc con @Override. Ci sono casi in cui però l'override non è possibile, per esempio quando viene creata una funzione final, infatti questo modificatore ha lo scopo di impedire l'override di un metodo. Il modificatore non può essere più restrittivo rispetto a quello della superclasse e il tipo di ritorno deve essere covariante.
3. Come si scrive un commento in Javadoc e quali sono alcuni dei tag comuni?
	1. I commenti in Javadoc iniziano con /** e finiscono con \*/, in modo da non poter essere scambiati coi normali commenti. Il Javadoc è un ottimo metodo per fornire documentazione e spiegazione delle implementazioni e strutture all'interno del codice. tag comuni sono:
		- @param
		- @return
		- @throws
		- @deprecated
4. Utilizzo principale del blocco "finally" in Java?
	1. Viene usato per eseguire delle istruzioni alla fine di un costrutto try/catch, indipendentemente dal fatto che si sia entrati nell'eccezione o meno.
5. Come si dichiara un metodo che può dichiarare eccezioni in Java?
	1. Si inserisce dopo la firma della funzione un blocco di istruzioni come segue:
		- throws Eccezione1, Eccezione2, ecc.	
	da qui in poi sarà compito del chiamante gestire le eccezioni
6. Costrutto utilizzato per semplificare la gestione delle risorse come file o connessioni al database in Java?
	1. Costrutto try-with-resources. Questo costrutto try/catch inserisce all'interno del try una "risorsa" da poter utilizzare per avere accesso semplificato ad, per esempio, un file.
 ```java
 try(BufferedReader reader = new BufferedReader(new FileReader("file.txt"))){
	 String line = reader.readLine();
	 while (line != null){
		 System.out.println(line);
		 line = reader.readLine();
	 }
 } catch (IOException e) {
	 // Gestione della eccezione
 }
```

7. Come si accede ai metodi di una classe astratta estesa da una sottoclasse in Java?
	1. Si accede tramite l'istruzione super seguita dal nome del metodo che si vuole chiamare: super.metodo()
8. Cosa rappresenta la parola chiave "abstract" nella dichiarazione di una classe in Java?
	1. Rappresenta il fatto che la classe non è istanziabile, ovvero che per essere istanziata deve essere per forza all'interno di una sottoclasse che la estende. Viene usata molto per il concetto di polimorfismo ed ereditarietà.
9. Qual'è la differenza tra una classe astratta e un'interfaccia in Java?
	1. L'interfaccia ha i metodi che possono essere solo dichiarati, non contiene campi, e più interfacce possono essere implementate dalla stessa classe. La classe astratta invece può avere campi, implementazioni dei metodi e non solo la loro dichiarazione, sottoclassi, inoltre possiede costruttore. Una classe può estendere una sola classe
10. Spiega il concetto di "overloading" dei metodi in Java
	1. L'overloading è una tecnica che permette di avere la stessa funzione con comportamento diverso in base ai parametri che gli vengono forniti, in modo da poter rispondere in maniera diversa e più completa in base all'input fornitogli.
	2. Per esempio il costruttore di una classe potrebbe avere tre parametri richiesti in ingresso, ma il programmatore per sviare il problema di quando la classe viene istanziata usando solo due parametri o meno, procede con l'overloading.