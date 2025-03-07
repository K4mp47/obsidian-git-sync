## **Summary**

Questo capitolo copre **tutti i tipi di istruzioni**, inclusi cicli, condizionali, salti e dichiarazioni.

📌 **Suggerimento per l’esame**: pratica con `if`, `for`, `while`, `try/catch` e `"use strict"`. 🚀

---

## **5.1 Expression Statements**

Un'**expression statement** è un’espressione eseguita come istruzione. Sono comuni nelle assegnazioni e nelle invocazioni di funzioni.

Esempi:

```js
x = 3 * 5;     // Assegnazione
console.log(x); // Chiamata di funzione
```

---

## **5.2 Compound and Empty Statements**

- Un **compound statement** è un blocco di istruzioni racchiuso tra `{}`.
- Un **empty statement** è semplicemente un punto e virgola (`;`) e non esegue nulla.

Esempi:

```js
{  
  let a = 5;  
  let b = 10;  
} // Compound statement

; // Empty statement (non ha effetto)
```

---

## **5.3 Conditionals**

Le **istruzioni condizionali** controllano il flusso del programma in base a espressioni booleane.

### **5.3.1 `if` Statement**

Esegue il blocco solo se la condizione è `true`.

```js
if (x > 10) {
  console.log("x è maggiore di 10");
}
```

### **5.3.2 `else if` Statement**

Permette di valutare più condizioni.

```js
if (x > 10) {
  console.log("x è maggiore di 10");
} else if (x === 10) {
  console.log("x è esattamente 10");
} else {
  console.log("x è minore di 10");
}
```

### **5.3.3 `switch` Statement**

Sostituisce più `if/else` confrontando un valore con più casi.

```js
switch (fruit) {
  case "apple":
    console.log("È una mela");
    break;
  case "banana":
    console.log("È una banana");
    break;
  default:
    console.log("Frutto sconosciuto");
}
```

⚠️ Senza `break`, i casi successivi verranno eseguiti.

---

## **5.4 Loops**

I cicli eseguono un blocco di codice più volte fino a quando una condizione è falsa.

### **5.4.1 `while` Loop**

Esegue il blocco **finché** la condizione è vera.

```js
let i = 0;
while (i < 5) {
  console.log(i);
  i++;
}
```

### **5.4.2 `do/while` Loop**

Il blocco viene eseguito almeno **una volta**, poi continua finché la condizione è vera.

```js
let i = 0;
do {
  console.log(i);
  i++;
} while (i < 5);
```

### **5.4.3 `for` Loop**

Utilizzato per cicli con contatore.

```js
for (let i = 0; i < 5; i++) {
  console.log(i);
}
```

### **5.4.4 `for/of` Loop**

Itera sugli **elementi** di un array.

```js
let colors = ["red", "green", "blue"];
for (let color of colors) {
  console.log(color);
}
```

### **5.4.5 `for/in` Loop**

Itera sulle **proprietà** di un oggetto.

```js
let obj = { name: "Alice", age: 25 };
for (let key in obj) {
  console.log(key, obj[key]);
}
```

---

## **5.5 Jumps**

Le istruzioni di salto alterano il normale flusso di esecuzione.

### **5.5.1 Labeled Statements**

Permettono di etichettare un blocco di codice.

```js
outerLoop: for (let i = 0; i < 3; i++) {
  for (let j = 0; j < 3; j++) {
    if (i === j) continue outerLoop; // Salta all'iterazione successiva dell'outerLoop
    console.log(i, j);
  }
}
```

### **5.5.2 `break` Statement**

Interrompe un ciclo immediatamente.

```js
for (let i = 0; i < 10; i++) {
  if (i === 5) break; // Esce dal ciclo quando i è 5
  console.log(i);
}
```

### **5.5.3 `continue` Statement**

Salta all'iterazione successiva.

```js
for (let i = 0; i < 5; i++) {
  if (i === 2) continue; // Salta quando i è 2
  console.log(i);
}
```

### **5.5.4 `return` Statement**

Termina una funzione e restituisce un valore.

```js
function sum(a, b) {
  return a + b;
}
```

### **5.5.5 `yield` Statement**

Utilizzato nelle **funzioni generator** per restituire valori progressivi.

```js
function* generator() {
  yield 1;
  yield 2;
}
```

### **5.5.6 `throw` Statement**

Genera un'eccezione.

```js
throw new Error("Errore!");
```

### **5.5.7 `try/catch/finally`**

Gestisce errori con un blocco di codice sicuro.

```js
try {
  let x = y; // Errore: y non è definito
} catch (error) {
  console.log("Errore catturato:", error.message);
} finally {
  console.log("Questo codice viene sempre eseguito");
}
```

---

## **5.6 Miscellaneous Statements**

### **5.6.1 `with` Statement**

Evita di ripetere il nome di un oggetto (ma è sconsigliato per motivi di sicurezza e prestazioni).

```js
let obj = { x: 10, y: 20 };
with (obj) {
  console.log(x, y); // Evita di scrivere obj.x e obj.y
}
```

### **5.6.2 `debugger` Statement**

Interrompe il codice in modalità debug.

```js
debugger;
```

### **5.6.3 `"use strict"` Statement**

Attiva la modalità **strict mode**, che impedisce errori comuni. `"use strict"` è stato introdotto con ES5.

- Appare solo all'inizio di uno script o all'inizio del body di una funzione
- Qualunque codice all'interno di classi o in ES6 module è automaticamente *strict code*
- Lo scopo principale è quello di maggiorare il check di errori nel codice, incrementando la sicurezza
- Non permette l'utilizzo del costrutto `with` 
- Non sono permessi interi espressi in ottale
- È limitato l'accesso per controllare le chiamate allo stack

```js
"use strict";
x = 10; // Errore: x non è definito
```

---

## **5.7 Declarations**

Definiscono variabili, funzioni e classi.

### **5.7.1 `const`, `let`, and `var`**

- `let` e `const` hanno **scope a blocco** e sono preferibili a `var`.
	- Prima di ES6 si potevano dichiarare  variabili solo usando il costrutto `var`
- `const` definisce costanti.

```js
let x = 10;
const y = 20;
```

### **5.7.2 `function` Declaration**

Definisce funzioni.

```js
function greet() {
  console.log("Hello!");
}
```

### **5.7.3 `class` Declaration**

Definisce una classe.

```js
class Person {
  constructor(name) { // costruttore non sempre necessasrio
    this.name = name;
  }
}

// altro esempio di classe con funzioni
class Circle { 
	constructor(radius) { this.r = radius; } 
	area() { return Math.PI * this.r * this.r; }
	circumference() { return 2 * Math.PI * this.r; } 
}
```

### **5.7.4 `import` and `export`**

Utilizzato nei moduli ES6.

```js
export function greet() {
  console.log("Hello!");
}
import { greet } from "./module.js";
```