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

11.  Invocazione di un metodo tramite reflection. SI spieghi come si può ottenere un oggetto di tipo Method e come questo posse essere invocato utilizzando i meccanismi di reflection. Si discutano le tipologie di errori che si possono ottenere in seguito all'invocazione di tale metodo. Sottolineiamo che possibili eccezioni sono date dall'inesistenza di un metodo o la invoke() di un metodo astratto.
```java
Class<?> reflectedClass = MyClass.class;
Object reflectedObject = reflectedClass.getDefaultConstructor().newInstance();

Method method = reflectedClass.getMethod("nomeMetodo", parametro1,2,3,ecc.)

method.invoke(reflectedObject)
```

12. Modificatori di accesso. Si elenchino tutti i modificatori di Java, spiegando quali restizioni sono imposte da ciascuno.
	1. public (accessibile ovunque)
	2. private (accessibile solo all'interno della stessa classe)
	3. protected (accessibile da sottoclassi e dal package)
	4. default (accessibile solo dal package di provenienza)

13. Annotazioni. Si illustri che cos'è un annotazione in Java, come può essere definita, come si possono restringere le componenti del programma ad oggetti a cui applicare una annotazione, e come si può definire se l'annotazione deve essere visibile solo sul codice sorgente, anche all'interno del bytecode, oppure anche durante l'esecuzione.
	1. Una annotazione è un tipo dato che può essere aggiunto a classi o metodi per aggiungere informazioni sul codice stesso. Sopra è riportato un esempio di dichiarazione di Annotazione.
	2. L'Annotazione può essere ristretta usando il tag "@Target"
	3. Per definire un'annotazione all'interno del codice, anche nel bytecode o anche in runtime, bisogna usare il tag "@Retention" con il relativo tipo di restrizione, che sono:
		1. RetentionPolicy.RUNTIME
		2. RetentionPolicy.SOURCE
		3. RetentionPolicy.CLASS
	4. ![[Pasted image 20240904112418.png]]

	
14. Definizione e firma di un metodo. Si illustri in che cosa consiste la definizione di un metodo, la firma di un metodo, e quali sono le differenze. Si spieghi poi in che cosa consiste l'override di un metodo e che rapporto c'è con dichiarazione e firma di un metodo.
	1. La firma è composta dal nome del metodo, i suoi parametri e il tipo
	2. La dichiarazione comprende anche altro, come il tipo di ritorno, le eccezioni lanciate, i modificatori
	3. L'override modifica il comportamento del metodo di cui si fa l'override
	4. L'override non modifica la firma, ma può modificare la dichiarazione, ma deve essere per forza meno restrittivo

15. Getter e Setter. Si spieghi cosa sono i due. Si discutano poi i vantaggi e svantaggi di usarli.
	1. Getter ritorna il valore di un campo
	2. Setter modifica il valore di un campo
	3. Il Setter può controllare che il valore rispetti determinate condizioni
	4. Richiedono l'invocazione del metodo, se fosse ad accesso diretto il campo sarebbe meno costoso operarci.
	5. Potrebbero coinvolgere logica aggiuntiva o manipolazioni più complesse.

16. Boxing  e Unboxing, Si spieghi quali classi sono fornite da Java per poter effettuare operazioni di boxing e unboxing su valori numerici. Si spieghi poi in cosa consiste la conversione implicita di valori numerici, e quale comportamento si ha invece con valori boxed. Si individui poi un contesto in cui tali operazioni risultano essenziali.
	1. Si chiamano classi Wrapper, sono una per ogni tipo primitivo
	2. La conversione implicita consiste nel fatto che in automatico Java può passare da un primitivo alla corrispettiva classe oggetto e viceversa, senza doverlo specificare tramite istruzioni
	3. Un contesto in cui sono essenziali sono per esempio, le collezioni, che accettano solo oggetti.
	4. Non posso convertire in maniera implicita tra una classe e l'altra, e non posso passare ad un tipo con una maggiore precisione.

17. Tipaggio forte e statico, sottotipaggio. Si spieghi cosa significa che un linguaggio di programmazione come Java applica un tipaggio forte e statico, si spieghi il sottotipaggio e come Java permette di definire che una classe è sottotipo di un altro tipo.
	1. Tipaggio statico: il tipo di ogni espressione o variabile è conosciuto in tempo di compilazione
	2. Tipaggio strongly: un'espressione può essere assegnata ad un'altra solo se compatibile(sottotipo)
	3. Il subtyping è una tecnica che permette ad un sottotipo di sostituirsi con un altro medesimo
	4. una classe che estende un'altra classe o un interfaccia è sottotipo

18. abstract. Si speghi dove si usa e cosa comporta.
	1. Si usa sulle classi
	2. Si usa sui metodi di una classe
	3. La classe abstract non può essere istanziata
	4. Un metodo abstract deve essere all'interno di una classe abstract
	5. Non è necessario che una classe abstract abbia dei metodi abstract
19. 
```java
abstract class Esempio {
	String campo1;
	
	void Metodo0(){
		System.out.println("Meotdo0");
	}
	
	abstract double Metodo1(); // deve essere implementata dalle sottoclassi
	
}

class EstendiEsempio extends Esempio {
	...
	...
}
```

19. static. Si spieghi l'utilizzo del modificatore, e in particolare su quali elementi di un programma Java può essere applicato e con quali effetti
	1. L'utilizzo del modificatore static si usa per creare un membro di classe appartenente alla classe stessa e non ad una sua istanza.
	2. Si può applicare ai metodi
	3. Ai campi
	4. Alle classi nidificate in altre classi

20. Spiegare le keyword implements e extends
	1. implements: utilizzato per aggiungere funzionalità ad una classe tramite interfacce. La classe figlia deve implementare concretamente tutti i metodi dell'interfaccia.
	2. extends: stessa cosa della implements ma per le classi. Al contrario delle interfacce, la extends si può usare una sola volta per classe

21. Tipi di referenza. tipi valore. Si elenchino e si differenzino
	1. Tipi referenza: in Java sono semplicemente quando il tipo è definito da una classe o un interfaccia
	2. Tipi valore: tutti i valori primitivi, int float boolean char double ecc., con i quali si passa direttamente il valore e non la reference di esso.
	3. I tipi referenza sono tutti sottotipo di Object
211. 
```java
public class Esempio {
	String stringa1;
	Integer int1;
	Boolean boolean1;
	int i = 0;
	char a = "b";
	boolean x = true;
}
```

22. Eccezioni. Cosa sono, come si può definire la propria eccezione, i costrutti di Java per gestire le eccezioni.
	1. Le eccezioni sono un tipo di classe in Java, utilizzate per quando si ferma per un errore l'esecuzione di un programma
	2. Si possono definire come classi che estendono Exception/Throwable
	3. Per gestire le eccezioni Java usa il costrutto try/catch e le keywords throw/throws
221. 
```java
class MyException extends Exception {
	public myException(String message){
		super(message);
	}
}

public class Esempio {
	...
	...
	
	public void Metodo1() throws MyException {
		throw new MyException("Stringa di Errore");
	}
}

public static void Main(String[] args){
	...
	...
	
	try {
		...
		...
	} catch (MyException e){
		System.out.println(e.getMessage());
	}
}
```

23. final. Si elenchino tutti i suoi possibili usi
	1. Si può usare su classi metodi e campi
	2. Un campo final non può essere assegnato nei metodi
	3. Un campo final può essere assegnato solo nel costruttore o nella dichiarazione del campo stesso
	4. Una classe final non può essere estesa
	5. Un metodo final non può subire override

24. È possibile implementare un metodo all'interno di un'interfaccia? Come? E un campo? Ci sono restrizioni rispetto a quello che si può dichiarare in una classe?
	1. Si, si possono implementare metodi
	2. I metodi devono essere definiti di default(keyword default, letteralmente)
	3. Anche i campo possono essere implementati
	4. I campi devono essere static e final, i metodi non per forza

25. Si spieghi cosa si intende, all’interno dell’approccio design per contratti (design by contract) della programmazione orientata ad oggetti, con contratto di una classe, e in che cosa consistono precondizioni (precondition), postcondizioni (postcondition), e invarianti di oggetti (object invariants).
	1. Con contratto si intende la definizione della classe stessa, specificando di cosa richiede e di cosa ritorna
	2. Viene fatta tramite gli opportuni tag del JavaDoc
	3. Precondition si riferisce a ciò che deve essere esaudito, una condizione che deve essere soddisfatta, prima di chiamare un metodo
	4. Postcondition si riferisce invece a ciò che comporterà la chiamata del metodo stesso
	5. Object invariants: si riferisce ad una condizione sempre soddisfatta all'interno dell'oggetto

27. Si spieghi cosa sono le interfacce in Java e cosa possono contenere, come una classe può implementare un’interfaccia, e in che cosa consistono le implementazioni di default all’ interno delle interfacce.
	1. Le interfacce in Java sono un tipo di costrutto che permette di dare una struttura di default agli oggetti. 
	2. Posso contenere metodi e variabili
	3. Le variabili devono essere static e final
	4. I metodi solo dalle ultime versioni di Java è possibile dargli delle istruzioni all'interno dello scope
	5. la keyword default viene usata per i metodi, identificando che esso ha già uno scope di default implementato
	6. Per implementare una interfaccia, si usa il costrutto sintattico `implements` e ne deve implementare tutti i metodi

29. Si spieghi che funzionalità offrono le interfacce Collection, List e Set, e che rapporto c’e’ tra di loro.
	1. Queste tre interfacce servono per contenere 'collezioni' di oggetti
	2. List e Set implementano la Collection
	3. List può contenere duplicati
	4. Set non può contenere duplicati
	5. Offrono funzionalità per il accesso, aggiunta e rimozione dei dati

30. Si spieghi che cos’è una classe, da che cosa è composta, che cos’è un oggetto, da che cos’è composto, e che relazione c’è tra classi e oggetti.
	1. Classe: costrutto sintattico con cui si definisce un insieme di campi e metodi per eseguire un azione
	2. Oggetto: classe, ma istanziata, ovvero presente in memoria, contiene gli effettivi valori dei campi
	3. Una classe quando viene caricata in memoria diventa un oggetto

31. Si spieghi cosa sono i tipi generici (generics) in Java, come i tipi generici possono essere limitati (bounded) rispetto ai valori che possono assumere, che cosa sono le wildcard in Java e che differenza c’è tra tipi generici e wildcard.
	1. I generics sono un costrutto di Java per permettere alle classi una maggiore generalizzazione dei tipi utilizzati, ottimo per il concetto di ereditarietà
	2. I generics possono essere limitati tramite l'utilizzo delle wildcard
	3. Wildcard: costrutto di Java per permettere di accettare come tipo solo sottipi o supertipi di una determinata classe data, per il concetto del polimorfismo

32. Si spieghi che cosa sono le eccezioni in Java e come possono essere utilizzate, come è strutturata la gerarchia dei tipi delle principali eccezioni, quali sono le differenze principali tra eccezioni, e come.
	1. Le eccezioni servono per non catturare durante l'esecuzione del programma un errore. 
	2. Java ha delle classi specifiche per vari tipi di errori, inoltre permette di creare le proprie classi specializzate
	3. Exception estende Throwable
	4. Le principali sono Throwable, Error, RuntimeException ed Exception
	5. Vengono specificati metodi che catturano un determinato tipo di errore tramite la `throws` keyword. costrutto `try/catch` per gestire eccezioni
	6. Nuove Istanze delle classi vengono lanciate tramite la `throw`