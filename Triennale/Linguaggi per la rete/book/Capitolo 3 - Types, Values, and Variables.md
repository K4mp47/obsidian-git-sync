## **Summary**

Il capitolo introduce i **tipi di dati** in JavaScript, le differenze tra **valori primitivi e oggetti**, la conversione di tipo e le **dichiarazioni di variabili**. Un’attenzione particolare viene data a `BigInt`, `Symbol`, e alla gestione delle conversioni implicite ed esplicite.

---
## **3.1 Overview and Definitions**

JavaScript è un linguaggio con **tipizzazione dinamica**, il che significa che i tipi delle variabili vengono determinati a runtime. Esistono due grandi categorie di tipi:

- **Tipi primitivi** (immutabili): `number`, `string`, `boolean`, `null`, `undefined`, `symbol`, `bigint`.
- **Tipi oggetto** (mutabili): array, funzioni, oggetti.

---

## **3.2 Numbers**

I numeri in JavaScript sono rappresentati internamente come **floating-point a 64 bit (IEEE 754)**. Non esiste un tipo distinto per gli interi.

### **3.2.1 Integer Literals**

Gli interi possono essere espressi in **diversi formati**:

- **Decimale**: `42`
- **Esadecimale**: `0x2A`
- **Ottale**: `0o52`
- **Binario**: `0b101010`

### **3.2.2 Floating-Point Literals**

I numeri decimali con la virgola mobile possono essere scritti con o senza **notazione scientifica**:

```js
let x = 3.14;
let y = 2.5e3; // 2500
```

### **3.2.3 Arithmetic in JavaScript**

JavaScript supporta le operazioni aritmetiche standard: `+`, `-`, `*`, `/`, `%` (modulo), `**` (esponenziazione).  
Esempi:

```js
let a = 10 % 3; // Resto della divisione (1)
let b = 2 ** 3; // 2 elevato alla 3 (8)
```

### **3.2.4 Binary Floating-Point and Rounding Errors**

Poiché JavaScript utilizza la rappresentazione floating-point, possono verificarsi errori di arrotondamento:

```js
0.1 + 0.2 === 0.3 // false, a causa dell'imprecisione binaria
```

### **3.2.5 Arbitrary Precision Integers with BigInt**

Il tipo `BigInt` consente di lavorare con numeri interi **arbitrariamente grandi**, utilizzando il suffisso `n`:

```js
let big = 123456789012345678901234567890n;
```

### **3.2.6 Dates and Times**

JavaScript fornisce l'oggetto `Date` per gestire date e orari:

```js
let now = new Date(); // Data e ora attuali
```

---

## **3.3 Text (Stringhe)**

Le stringhe in JavaScript sono **sequenze di caratteri Unicode**.

### **3.3.1 String Literals**

Le stringhe possono essere definite con apici doppi `"..."`, singoli `'...'` o **backtick** `` `...` `` per i template literals.

### **3.3.2 Escape Sequences in String Literals**

Caratteri speciali possono essere rappresentati con sequenze di escape, come `\n` (nuova riga) e `\t` (tabulazione).

### **3.3.3 Working with Strings**

Alcuni metodi comuni per manipolare le stringhe:

```js
"hello".toUpperCase(); // "HELLO"
"hello".includes("ell"); // true
```

### **3.3.4 Template Literals**

I **template literals** permettono di inserire variabili direttamente nella stringa:

```js
let name = "Alice";
console.log(`Hello, ${name}!`); // "Hello, Alice!"
```

### **3.3.5 Pattern Matching**

Per il pattern matching si usano le **espressioni regolari** (`RegExp`):

```js
let pattern = /hello/;
pattern.test("hello world"); // true
```

---

## **3.4 Boolean Values**

JavaScript ha due valori booleani: `true` e `false`. I valori **falsy** includono: `false`, `0`, `""`, `null`, `undefined`, `NaN`.

---

## **3.5 null e undefined**

- `null` rappresenta **l'assenza intenzionale di valore**.
- `undefined` indica una variabile **non inizializzata**.

```js
let x; // x è undefined
let y = null; // y è null
```

---

## **3.6 Symbols**

Il tipo `Symbol` rappresenta **valori unici** e immutabili. È usato per definire **proprietà uniche negli oggetti**.

```js
let sym = Symbol("descrizione");
```

---

## **3.7 The Global Object**

Il **global object** dipende dall’ambiente:

- In **browser** è `window`.
- In **Node.js** è `global`.  
    Esempio:

```js
console.log(window.Math.PI); // 3.141592653589793
```

---

## **3.8 Immutable Primitive Values and Mutable Object References**

I **tipi primitivi** sono immutabili:

```js
let a = "hello";
a.toUpperCase(); // "HELLO" ma a rimane "hello"
```

Gli **oggetti** sono mutabili e vengono passati **per riferimento**:

```js
let obj = { value: 10 };
let copy = obj;
copy.value = 20; // Anche obj.value diventa 20
```

---

## **3.9 Type Conversions**

### **3.9.1 Conversions and Equality**

L'operatore `==` esegue conversioni di tipo implicite, mentre `===` confronta i valori senza conversioni:

```js
console.log(5 == "5"); // true (converte la stringa in numero)
console.log(5 === "5"); // false (tipi diversi)
```

### **3.9.2 Explicit Conversions**

Si possono effettuare conversioni con funzioni come `Number()`, `String()`, `Boolean()`:

```js
Number("42"); // 42
Boolean(""); // false
```

### **3.9.3 Object to Primitive Conversions**

Gli oggetti possono essere convertiti in primitivi con i metodi `toString()` e `valueOf()`.

---

## **3.10 Variable Declaration and Assignment**

### **3.10.1 Declarations with let and const**

- `let`: variabili mutabili
- `const`: variabili costanti

```js
let x = 10; // Può essere modificato
const y = 20; // Non può essere riassegnato
```

### **3.10.2 Variable Declarations with var**

- `var` ha **hoisting** e **scope globale/funzionale**, quindi meno sicuro di `let` e `const`.

```js
var z = 30; 
```

### **3.10.3 Destructuring Assignment**

Permette di estrarre valori da array o oggetti:

```js
let [a, b] = [1, 2]; 
let { name, age } = { name: "Alice", age: 25 };
```
