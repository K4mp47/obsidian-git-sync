## **6.11 Summary**

Questo capitolo copre la creazione, la manipolazione e l’estensione degli **oggetti** in JavaScript. Sono stati analizzati i metodi per accedere, modificare e eliminare proprietà, oltre alle funzionalità avanzate come i **getter/setter**, la **serializzazione JSON** e l'**uso dei simboli**.

📌 **Suggerimento per l'esame**: pratica con `Object.create()`, `Object.assign()`, i metodi `toString()`, `getters/setters` e `spread operator`. 🚀

Gli **oggetti** in JavaScript sono collezioni di **proprietà**, dove ogni proprietà è una coppia **chiave-valore**. Gli oggetti sono alla base della programmazione in JavaScript, poiché quasi tutto nel linguaggio è un oggetto o può comportarsi come tale.

---

## **6.1 Introduction to Objects**

Un **oggetto** è un insieme di proprietà e metodi. Ogni proprietà ha un **nome (chiave)** e un **valore**.  
Esempio di oggetto:

```js
let person = {  
  name: "Alice",  
  age: 25,  
  greet: function() { console.log("Hello!"); }  
};
```

Le proprietà possono contenere qualsiasi tipo di valore, inclusi numeri, stringhe, array e funzioni.

---

## **6.2 Creating Objects**

### **6.2.1 Object Literals**

Il metodo più semplice per creare un oggetto è l’uso della **notazione letterale**:

```js
let car = { brand: "Toyota", model: "Corolla", year: 2020 };
```

### **6.2.2 Creating Objects with `new`**

Un altro modo è usare il costruttore `new Object()`, anche se meno comune:

```js
let car = new Object();
car.brand = "Toyota";
car.model = "Corolla";
```

### **6.2.3 Prototypes**

Gli oggetti possono ereditare proprietà e metodi da altri oggetti tramite il **prototype**:

```js
let obj = Object.create({ inheritedProp: "value" });
console.log(obj.inheritedProp); // "value"
```

### **6.2.4 `Object.create()`**

Permette di creare un oggetto specificando il suo prototype:

```js
let parent = { greet() { console.log("Hello!"); } };
let child = Object.create(parent);
child.greet(); // "Hello!"
```

---

## **6.3 Querying and Setting Properties**

### **6.3.1 Objects As Associative Arrays**

Le proprietà di un oggetto possono essere accessibili sia con la **notazione punto** che con la **notazione con parentesi quadre**:

```js
let obj = { name: "Alice" };
console.log(obj.name);  // "Alice"
console.log(obj["name"]);  // "Alice"
```

La notazione `[]` è utile quando la chiave è dinamica:

```js
let key = "name";
console.log(obj[key]);  // "Alice"
```

### **6.3.2 Inheritance**

Gli oggetti possono ereditare proprietà dal loro **prototype**.

### **6.3.3 Property Access Errors**

Se si accede a una proprietà inesistente, il risultato sarà `undefined`:

```js
let obj = {};
console.log(obj.missingProp); // undefined
```

---

## **6.4 Deleting Properties**

L'operatore `delete` rimuove una proprietà da un oggetto:

```js
let obj = { x: 10 };
delete obj.x;
console.log(obj.x); // undefined
```

---

## **6.5 Testing Properties**

Per verificare se una proprietà esiste in un oggetto:

- **L’operatore `in`**:
    
    ```js
    let obj = { x: 10 };
    console.log("x" in obj); // true
    ```
    
- **`hasOwnProperty()`** (ignora le proprietà ereditate):
    
    ```js
    console.log(obj.hasOwnProperty("x")); // true
    ```
    

---

## **6.6 Enumerating Properties**

### **6.6.1 Property Enumeration Order**

Si possono scorrere le proprietà di un oggetto con `for...in`:

```js
for (let key in obj) {
  console.log(key, obj[key]);
}
```

Oppure ottenere un array di chiavi o valori con:

```js
Object.keys(obj);   // Array delle chiavi
Object.values(obj); // Array dei valori
Object.entries(obj); // Array di coppie [chiave, valore]
```

---

## **6.7 Extending Objects**

Aggiungere proprietà a un oggetto:

```js
obj.newProp = "valore";
```

Copiare proprietà tra oggetti con `Object.assign()`:

```js
let target = {};
let source = { a: 1, b: 2 };
Object.assign(target, source);
console.log(target); // { a: 1, b: 2 }
```

---

## **6.8 Serializing Objects**

Convertire un oggetto in stringa JSON:

```js
let json = JSON.stringify(obj);
```

Convertire una stringa JSON in oggetto:

```js
let obj2 = JSON.parse(json);
```

---

## **6.9 Object Methods**

### **6.9.1 The `toString()` Method**

Converte un oggetto in stringa:

```js
let obj = { toString() { return "My Object"; } };
console.log(obj.toString()); // "My Object"
```

### **6.9.2 The `toLocaleString()` Method**

Usato per la localizzazione delle stringhe.

### **6.9.3 The `valueOf()` Method**

Restituisce il valore primitivo di un oggetto.

### **6.9.4 The `toJSON()` Method**

Definisce la conversione in JSON.

---

## **6.10 Extended Object Literal Syntax**

### **6.10.1 Shorthand Properties**

Quando il nome della proprietà coincide con il nome della variabile:

```js
let name = "Alice";
let person = { name }; // Equivalente a { name: name }
```

### **6.10.2 Computed Property Names**

Si possono usare **espressioni** per definire i nomi delle proprietà:

```js
let key = "dynamicKey";
let obj = { [key]: "value" };
console.log(obj.dynamicKey); // "value"
```

### **6.10.3 Symbols as Property Names**

Gli oggetti possono avere **proprietà simboliche** per evitare conflitti:

```js
let sym = Symbol("id");
let obj = { [sym]: 123 };
console.log(obj[sym]); // 123
```

### **6.10.4 Spread Operator**

Permette di copiare proprietà in un nuovo oggetto:

```js
let obj1 = { a: 1, b: 2 };
let obj2 = { ...obj1, c: 3 }; // { a: 1, b: 2, c: 3 }
```

### **6.10.5 Shorthand Methods**

Permette di definire metodi in modo compatto:

```js
let obj = {
  greet() { console.log("Hello!"); }
};
```

### **6.10.6 Property Getters and Setters**

Si possono definire metodi getter e setter:

```js
let person = {
  firstName: "Alice",
  lastName: "Smith",
  get fullName() { return `${this.firstName} ${this.lastName}`; }
};
console.log(person.fullName); // "Alice Smith"
```