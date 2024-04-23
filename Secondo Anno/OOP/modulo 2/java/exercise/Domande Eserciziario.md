## Design pattern
- [[Command]]
- [[Factory]]
- [[Singleton]]
---

## 1.1 Design Patterns
- Si prenda in considerazione il seguente codice Java
```java
public class MyClass { 
	private static MyClass instance; 
	public static MyClass get() { 
		if (instance == null) instance = new MyClass(); 
		return instance; 
	} 
}
```

Quale design pattern è all'opera??
- [ ] Command
- [ ] Factory
- [ ] nessun pattern
- [x] Singleton

- Perché il design pattern denominato *factory* è utile in Java ed in altri linguaggi ad oggetti simili?
- [x] Perché i costruttori non sono metodi soggetti al dynamic dispatching, quindi non è possibile sfruttare il polimorfismo per costruire oggetti se non tramite un metodo non-statico che incapsula la costruzione.
- [ ] Perché la costruzione degli oggetti va nascosta dentro metodi statici al fine di poter rendere privati i costruttori, applicando così i principi di information hiding e di incapsulamento tipici della programmazione ad oggetti anche alla creazione di istanze. 
- [ ] Siccome le sottoclassi non hanno accesso ai super-costruttori, è necessario dotare le superclassi di metodi wrapper protected dei propri costruttori, permettendo alle classi derivate di accedervi indirettamente. 
- [ ] Perché non è possibile costruire array con tipi generici in Java, pertanto è preferibile mascherare gli inevitabili cast dentro un metodo statico che funge da wrapper per il costruttore.
--- 
## 1.2 Riuso di codice e Type system di Java
- Java versione 10 supporta l'ereditarietà multipla?
	- No, però non c'è un limite al numero di interfacce che una classe può implementare
- In generale, a cosa servono le due forme di polimorfismo (subtyping e generics) che offre Java oggi?
	- A riusare lo stesso codice, ovvero chiamare un metodo, con parametri di tipo differente
-  ![[Pasted image 20240417121852.png]]
	- Risposta:
		- ![[Pasted image 20240417121913.png]]
 - L'ereditarietà è una forma di polimorfismo?
	 - Definizione di polimorfismo: ci riferiamo ad esso come un modo per rispondere in maniera diversa alla stessa domanda. Nel codice, questo si traduce nell'uso dell'overloading e/o dell'override dei metodi. si dice polimorfismo statico nel 1 caso e dinamico nel secondo.
	 - Definizione di ereditarietà: con ereditarietà intendiamo quella capacità delle classi nella OOP di poter ereditare i metodi dalla classe padre, nota come superclasse. Difatti le classi figlie ereditano tutti i metodi pubblici delle superclassi ad esse superiori
	- In conclusione, l'ereditarietà non è una forma di polimorfismo, ma lo rende possibile, poichè permette il polimorfismo subtype.
		- subtyping: Si riferisce alla relazione che si verifica quando un tipo (noto come il tipo supertipo) può essere sostituito da un altro tipo (noto come il tipo sottotipo) in una determinata situazione senza causare errori semantici o comportamentali. In generale, il subtyping indica che il tipo sottotipo è un tipo più specifico del tipo supertipo e quindi possiede tutte le caratteristiche del tipo supertipo, oltre a eventuali caratteristiche aggiuntive specifiche del tipo sottotipo.

- In un overloading, quali parti della firma di un metodo sono coinvolte?
	- Il tipo ed il numero dei parametri, senza tipo di ritorno né eccezioni.

- Si prenda in considerazione il seguente codice Java 8+ contenente una semplice gerarchia di classi ed un metodo generico di nome `map`: 

```java
public class Rpg { 
	public static <A, B> Collection<B> map(Collection<A> c, Function<A, B> f) { 
		List<B> r = new ArrayList<>(); 
		for (A a : c) { 
			r.add(f.apply(a)); 
		} 
		return r; 
	} 
	
	//public static int normalizeAttack(Character c) { 
	//	return 1 + (int) c.attack(); 
	//} 

	//public static Float normalizeAttack(Paladin c) { 
	//	return c.attack(); 
	//}
	public static abstract class Character<R extends Number> { 
		public int level; 
		public final String name; 
		protected Character(int level, String name) { 
			this.level = level; 
			this.name = name; 
		} 
		
		public abstract R attack(); 
	} 
	
	public static class Paladin extends Character<Float> { 
		public float mana; 
		public Paladin(int level, String name) { 
			super(level, name); 
			mana = 100.f; 
		} 
		
		@Override 
		public Float attack() { 
			return mana * level / 2.f; 
		} 
	} 
	
	public static class Rogue extends Character<Number> { 
		public int energy; 
		public Rogue(int level, String name) { 
			super(level, name); 
			energy = 50; 
		} 
		
		@Override 
		public Integer attack() { 
			return (energy -= 35) > 20 ? level * 2 : 0; 
		} 
	} 
}
```

-  Gli override del metodo `attack()` sono validi?
	- Sì, anche se le sottoclassi Paladin e Rogue specializzano il tipo di ritorno rispetto al type argument passato alla superclasse, la specializzazione del tipo di ritorno è supportata dall'overriding in Java.

- Immaginiamo ora il seguente codice nel main:

```java
List<Paladin> retadins = new ArrayList<>(); 
retadins.add(new Paladin(60, "Leeroy Jenkins")); 
retadins.add(new Paladin(80, "Arthas"));
```

```java
Collection<Number> r1 = map(retadins, new Function<Character, Float>() { 

	@Override 
	public Float apply(Character c) { 
		return 1.3f * (float) c.attack(); 
	} 
});
```

- Che modifiche devo apportare alla firma di map per far si che il codice compili?
- [x] `static <A, B> Collection<B> map(Collection<A> c, Function<? super A, ? extends B> f)`
- [ ] `static <A, B> Collection<B> map(Collection<A> c, Function<? extends A, ? super B> f)`
- [ ] `static <A, B> Collection<B> map(Collection<? super A> c, Function<A, B> f)`
- [ ] `static <A, B> Collection<B> map(Collection<? extends A> c, Function<A, ? extends B> f)`

- Si prendano ora in considerazione i due seguenti metodi in overload:

```java
public static int normalizeAttack(Character c) { 
	return 1 + (int) c.attack(); 
} 

public static Float normalizeAttack(Paladin c) { 
	return c.attack(); 
}
```

- Se inseriti dentro a Rpg, sarebbero validi?
	- Si, hanno parametri di tipo differente, anche se `Character` è il supertipo di `Paladin` il compilatore riesce a discriminarli.

- Dato il seguente codice Java

```java
public class Random { 
	public Random() { ... } 
	public Random(int seed) { ... } 
	public boolean nextBoolean() { ... } 
	public int nextInt() { ... } 
	public double nextDouble() { ... } 
}
```

- Era possibile chiamare tutte le funzioni con lo stesso nome, senza alterare in un altro modo semantica e firme del codice?
	- No, non è possibile eseguire l'overloading dei metodi cambiando solo il valore di ritorno.
	- Se si voleva sarebbe stato possibile, ma bisognava modificare i parametri dati in input ai metodi, per fare un esempio
