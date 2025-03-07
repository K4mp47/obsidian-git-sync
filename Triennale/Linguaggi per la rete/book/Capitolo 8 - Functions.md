## **8.8 Summary**

Le **funzioni** in JavaScript sono blocchi di codice riutilizzabili che eseguono operazioni specifiche. Sono **oggetti di prima classe**, il che significa che possono essere assegnate a variabili, passate come argomenti e restituite da altre funzioni.

Questo capitolo copre **definizione, invocazione, parametri, scope e funzioni di ordine superiore**. Le funzioni sono un concetto centrale di JavaScript e vengono usate per organizzare il codice in modo modulare e riutilizzabile.

📌 **Suggerimenti per l’esame**:

- Capire le **differenze tra function declaration, expression e arrow function**.
- Praticare con **`call()`, `apply()`, `bind()`**.
- Comprendere **closures e higher-order functions**.

---

## **8.1 Defining Functions**

Esistono diversi modi per dichiarare una funzione in JavaScript.

### **8.1.1 Function Declarations**

Una funzione dichiarata con `function` viene **hoisted**, cioè può essere chiamata prima della sua dichiarazione.

```js
greet(); // funziona

function greet(name) {
  return `Hello, ${name}!`;
}
```

### **8.1.2 Function Expressions**

Le funzioni possono essere assegnate a variabili. Queste funzioni **non vengono hoistate**.

```js
greet(); // non funziona

const greet = function(name) {
  return `Hello, ${name}!`;
};
```

### **8.1.3 Arrow Functions (`=>`)**

Una sintassi più breve per le funzioni anonime, introdotta con ES6.

```js
const greet = name => `Hello, ${name}!`;
```

⚠️ **Le arrow functions non hanno il proprio `this` e non possono essere usate come costruttori.**

---

## **8.2 Invoking Functions**

Esistono diversi modi per chiamare una funzione.

### **8.2.1 Function Invocation**

La chiamata diretta è il metodo più comune.

```js
greet("Alice"); 
```

### **8.2.2 Method Invocation**

Quando una funzione è una proprietà di un oggetto, è chiamata **metodo**.

```js
let obj = {
  sayHi() { console.log("Hi!"); }
};
obj.sayHi();
```

### **8.2.3 Constructor Invocation (`new`)**

Se una funzione viene chiamata con `new`, crea un nuovo oggetto.

```js
function Person(name) {
  this.name = name;
}
let alice = new Person("Alice");
```

### **8.2.4 Indirect Invocation (`call()` e `apply()`)**

- `call()` chiama la funzione specificando il valore di `this` e gli argomenti separati da virgola.
- `apply()` è simile ma accetta un array di argomenti.

```js
function greet() { console.log(this.name); }
let person = { name: "Alice" };
greet.call(person); // "Alice"
```

### **8.2.5 Arrow Functions and `this`**

Le arrow functions **non legano `this`**, ma ereditano quello dell’ambiente circostante.

```js
const obj = {
  name: "Alice",
	  greet: () => console.log(this.name) // `this` si riferisce al contesto esterno
};
obj.greet(); // undefined
```

---

## **8.3 Function Arguments and Parameters**

### **8.3.1 Default Parameters**

Le funzioni possono avere valori predefiniti per i parametri.

```js
function greet(name = "Guest") {
  console.log(`Hello, ${name}!`);
}
```

### **8.3.2 The `arguments` Object**

Le funzioni normali hanno accesso all’oggetto **`arguments`**, che contiene tutti gli argomenti passati.

```js
function sum() {
  return [...arguments].reduce((a, b) => a + b, 0);
}
console.log(sum(1, 2, 3)); // 6
```

⚠️ **Le arrow functions non hanno `arguments`!**

### **8.3.3 The Rest Parameter (`...`)**

Consente di raccogliere gli argomenti in un array.

```js
function sum(...numbers) {
  return numbers.reduce((a, b) => a + b, 0);
}
console.log(sum(1, 2, 3)); // 6
```

---

## **8.4 Functions as Values**

Le funzioni possono essere assegnate a variabili, passate come argomenti e restituite da altre funzioni.

### **8.4.1 Higher-Order Functions**

Le funzioni che accettano altre funzioni come argomenti o le restituiscono sono chiamate **funzioni di ordine superiore**.

```js
function operate(operator, a, b) {
  return operator(a, b);
}
console.log(operate((x, y) => x + y, 2, 3)); // 5
```

---

## **8.5 Scope and Closures**

### **8.5.1 Function Scope and Hoisting**

Le variabili dichiarate con `var` hanno **scope di funzione** e vengono **hoistate**.

```js
console.log(x); // undefined
var x = 10;  
```

### **8.5.2 Lexical Scoping**

Le funzioni **annidate** possono accedere alle variabili della loro funzione esterna.

```js
function outer() {
  let x = 10;
  function inner() {
    console.log(x);
  }
  inner(); // 10
}
```

### **8.5.3 Closures**

Una funzione può **ricordare** le variabili del contesto in cui è stata definita, anche dopo che la funzione esterna ha terminato l'esecuzione.

```js
function counter() {
  let count = 0;
  return () => count++;
}
let c = counter();
console.log(c()); // 0
console.log(c()); // 1
```

---

## **8.6 Function Properties, Methods, and Constructors**

### **8.6.1 The `length` Property**

Restituisce il numero di parametri della funzione.

```js
function f(a, b) {}
console.log(f.length); // 2
```

### **8.6.2 The `name` Property**

Restituisce il nome della funzione.

```js
function myFunc() {}
console.log(myFunc.name); // "myFunc"
```

### **8.6.3 The `call()`, `apply()`, and `bind()` Methods**

- `call()`: chiama la funzione con un valore di `this` specifico.
- `apply()`: uguale a `call()`, ma accetta gli argomenti in un array.
- `bind()`: crea una nuova funzione con `this` preimpostato.

```js
let obj = { x: 10 };
function show() { console.log(this.x); }
let boundShow = show.bind(obj);
boundShow(); // 10
```

### **8.6.4 The `toString()` Method**

Restituisce il codice sorgente della funzione.

---

## **8.7 Functional Programming**

### **8.7.1 Functions That Modify Their Arguments**

Alcune funzioni modificano i parametri passati come riferimento.

### **8.7.2 Pure Functions**

Le **funzioni pure** non modificano il loro stato esterno e restituiscono sempre lo stesso valore per gli stessi input.