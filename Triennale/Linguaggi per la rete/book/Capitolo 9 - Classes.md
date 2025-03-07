## **Summary**

Questo capitolo ha introdotto le **classi in JavaScript**, inclusi costruttori, metodi, ereditarietà e campi privati. Le classi offrono un modo più strutturato per definire oggetti e migliorano la leggibilità del codice.

📌 **Suggerimenti per l’esame**:

- ✅ Capire la differenza tra **classi e oggetti**.
- ✅ Sapere come usare **`constructor()`, `extends`, `super()`**.
- ✅ Conoscere i **metodi statici** e le **proprietà private (`#`)**.
- ✅ Praticare con **getters, setters e `instanceof`**.

Le **classi** in JavaScript forniscono un modo strutturato per creare e gestire oggetti. Sono state introdotte con ES6 e rappresentano una sintassi più chiara e organizzata per definire **oggetti e prototipi**.

Le classi in JavaScript non sono una nuova struttura di dati, ma una **sintassi migliorata** per lavorare con il modello basato su prototipi.

---

## **9.1 Introduction to Classes**

Una classe è un **modello** (blueprint) per creare oggetti con proprietà e metodi comuni.

### **Definizione di una classe base**

```js
class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
}

let alice = new Person("Alice", 25);
alice.greet(); // "Hello, my name is Alice"
```

✅ **Le classi sono una sintassi più chiara per definire oggetti con metodi condivisi nel prototipo.**

---

## **9.2 Class Declarations and Class Expressions**

Esistono due modi per definire una classe in JavaScript:

### **9.2.1 Class Declarations**

La dichiarazione classica con la parola chiave `class`:

```js
class Animal {
  constructor(name) {
    this.name = name;
  }
}
```

### **9.2.2 Class Expressions**

Le classi possono essere definite come **espressioni** e assegnate a variabili.

```js
const Animal = class {
  constructor(name) {
    this.name = name;
  }
};
```

⚠️ **A differenza delle function declarations, le classi non vengono hoistate!**

```js
const obj = new Animal("Tiger"); // ❌ Errore: Animal is not defined
class Animal { }
```

---

## **9.3 Constructors**

Il metodo `constructor()` viene eseguito quando si crea una nuova istanza della classe.

```js
class Car {
  constructor(brand) {
    this.brand = brand;
  }
}
let myCar = new Car("Toyota");
console.log(myCar.brand); // "Toyota"
```

⚠️ **Se una classe non definisce un `constructor()`, JavaScript ne crea uno vuoto.**

---

## **9.4 Class Methods**

Le classi supportano due tipi di metodi:

1. **Instance methods** (metodi normali per le istanze)
2. **Static methods** (metodi della classe, non delle istanze)

### **9.4.1 Instance Methods**

Definiti direttamente nella classe, disponibili sulle istanze.

```js
class Person {
  greet() {
    console.log("Hello!");
  }
}
let p = new Person();
p.greet(); // "Hello!"
```

### **9.4.2 Static Methods**

I metodi statici appartengono alla classe e **non alle istanze**.

```js
class MathUtils {
  static square(x) {
    return x * x;
  }
}
console.log(MathUtils.square(4)); // 16
```

⚠️ **I metodi statici non possono accedere alle proprietà `this` dell'istanza!**

---

## **9.5 Getters and Setters**

I metodi `get` e `set` permettono di **controllare l’accesso alle proprietà**.

```js
class Rectangle {
  constructor(width, height) {
    this.width = width;
    this.height = height;
  }

  get area() {
    return this.width * this.height;
  }

  set width(value) {
    if (value > 0) this._width = value;
  }

  get width() {
    return this._width;
  }
}
let rect = new Rectangle(10, 5);
console.log(rect.area); // 50
```

✅ **Usare `get` e `set` evita modifiche dirette non controllate.**

---

## **9.6 Inheritance and Subclasses**

Una classe può ereditare da un'altra classe con `extends`.

```js
class Animal {
  constructor(name) {
    this.name = name;
  }
  makeSound() {
    console.log("Some generic sound");
  }
}

class Dog extends Animal {
  makeSound() {
    console.log("Bark!");
  }
}
let dog = new Dog("Rex");
dog.makeSound(); // "Bark!"
```

### **9.6.1 Calling Superclass Constructors with `super`**

Il metodo `super()` chiama il `constructor()` della classe padre.

```js
class Employee extends Person {
  constructor(name, age, salary) {
    super(name, age);
    this.salary = salary;
  }
}
```

⚠️ **Se una sottoclasse ha un costruttore, deve chiamare `super()` prima di usare `this`!**

---

## **9.7 Class Fields**

Le proprietà possono essere definite direttamente nella classe.

### **9.7.1 Public Fields**

```js
class Person {
  name = "Default";
}
let p = new Person();
console.log(p.name); // "Default"
```

### **9.7.2 Private Fields (`#`)**

Le proprietà private sono accessibili solo all'interno della classe.

```js
class BankAccount {
  #balance = 1000;

  getBalance() {
    return this.#balance;
  }
}
let account = new BankAccount();
console.log(account.getBalance()); // 1000
console.log(account.#balance); // ❌ Errore
```

✅ **I campi privati migliorano l’incapsulamento.**

---

## **9.8 Mixing Classes and Prototypes**

Le classi in JavaScript sono basate su **prototipi**, quindi è possibile modificare il `prototype` di una classe.

```js
Person.prototype.sayBye = function() {
  console.log("Goodbye!");
};
```

⚠️ **Non modificare direttamente `prototype` in codice moderno!**

---

## **9.9 The `instanceof` Operator**

L'operatore `instanceof` verifica se un oggetto appartiene a una classe.

```js
console.log(dog instanceof Dog); // true
console.log(dog instanceof Animal); // true
console.log(dog instanceof Person); // false
```