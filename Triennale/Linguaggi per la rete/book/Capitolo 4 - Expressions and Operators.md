## **4.14 Summary**

Questo capitolo ha coperto le **espressioni** e gli **operatori** in JavaScript, incluse operazioni aritmetiche, confronti, logica booleana, assegnazione e operatori avanzati (`?.`, `??`, `typeof`, `delete`).

📌 **Suggerimento per l'esame**: fai pratica con gli operatori più usati, come `===`, `&&`, `||`, `? :` e `??`. 🚀

Le **espressioni** sono frammenti di codice che producono un valore, mentre gli **operatori** combinano valori per creare nuove espressioni. Questo capitolo copre i diversi tipi di espressioni e gli operatori disponibili in JavaScript.

---

## **4.1 Primary Expressions**

Le **espressioni primarie** sono le più semplici e comprendono:

- **Literals (letterali)**: valori scritti direttamente nel codice (`42`, `"hello"`, `true`).
- **Variabili e costanti**: riferimenti a valori memorizzati (`x`, `myArray`).
- **Parentesi**: per forzare l’ordine di valutazione (`(2 + 3) * 4`).

Esempio:

```js
let x = 42;  // Un'espressione primaria
let string = "Hello" // Un'altra espressione primaria
```

---

## **4.2 Object and Array Initializers**

JavaScript consente di creare **oggetti** e **array** con inizializzatori:

- **Oggetti** con `{ key: value }`
- **Array** con `[val1, val2, val3]`

Esempio:

```js
let obj = { name: "Alice", age: 25 }; // {} per oggetti
let arr = [1, 2, 3, 4];  // [] per array
```

---

## **4.3 Function Definition Expressions**

Le funzioni possono essere definite come espressioni e assegnate a variabili:

```js
let square = function(x) { return x * x; };
```

Oppure con la sintassi **arrow function**:

```js
// arrow function usante anche in altri framework
// di javascript come React
let square = x => x * x; 
```

---

## **4.4 Property Access Expressions**

Gli oggetti e gli array supportano due metodi per accedere alle proprietà:

- **Notazione punto**: `obj.prop`
	- Utilizzata per **accedere ad un identificatore**
- **Notazione con parentesi quadre**: `obj["prop"]`
	- Utilizzata per **accedere ad un indice o ad una specifica proprietà**
### **4.4.1 Conditional Property Access**

Con ES2020 è stato introdotto l’operatore **opzionale `?.`** per evitare errori se una proprietà è `undefined` o `null`:

```js
let user = {};
console.log(user?.profile?.name); // undefined invece di errore
```

---

## **4.5 Invocation Expressions**

Le **espressioni di invocazione** servono per chiamare funzioni:

```js
let result = square(5); // Chiamata di funzione
```

### **4.5.1 Conditional Invocation**

Con ES2020 è stato introdotto `?.()` per eseguire una funzione solo se esiste:

```js
let func = null;
func?.(); // Non genera errore
```

---

## **4.6 Object Creation Expressions**

Gli oggetti possono essere creati con il costruttore `new`:

```js
let today = new Date();
```

Se il costruttore non richiede argomenti, si possono omettere le parentesi:

```js
let obj = new Object;
```

---

## **4.7 Operator Overview**

Gli **operatori** in JavaScript sono simboli che modificano o combinano valori.

### **4.7.1 Number of Operands**

- **Unari**: agiscono su un solo operando (`-x`, `typeof x`).
- **Binari**: operano su due (`x + y`, `x * y`).
- **Ternari**: usano tre (`condizione ? val1 : val2`).

### **4.7.2 Operand and Result Type**

Alcuni operatori convertono implicitamente i tipi (`"5" * 2 // 10`).

### **4.7.3 Operator Side Effects**

Alcuni operatori, come `=`, modificano lo stato del programma.

### **4.7.4 Operator Precedence**

Definisce l’ordine di esecuzione: `*` ha precedenza su `+`.

### **4.7.5 Operator Associativity**

- **Sinistra a destra**: `*`, `/`, `%`.
- **Destra a sinistra**: `=` (assegnazione).

### **4.7.6 Order of Evaluation**

Dipende da **precedenza** e **associatività**.

---

## **4.8 Arithmetic Expressions**

- **4.8.1 The `+` Operator**: concatenazione di stringhe e somma.
- **4.8.2 Unary Arithmetic Operators**: `+x`, `-x`.
- **4.8.3 Bitwise Operators**: `&`, `|`, `^`, `~`.

---

## **4.9 Relational Expressions**

- **4.9.1 Equality and Inequality Operators**
    - `==` (converte i tipi), `===` (controlla i tipi).
- **4.9.2 Comparison Operators**: `<`, `>`, `<=`, `>=`.
- **4.9.3 The `in` Operator**: verifica se una proprietà esiste in un oggetto.
- **4.9.4 The `instanceof` Operator**: verifica se un oggetto è di una certa classe.

---

## **4.10 Logical Expressions**

- **4.10.1 Logical AND (`&&`)**
- **4.10.2 Logical OR (`||`)**
- **4.10.3 Logical NOT (`!`)**

---

## **4.11 Assignment Expressions**

Permettono di assegnare valori:

```js
let x = 10;
x += 5; // x = x + 5
```

### **4.11.1 Assignment with Operation**

Esempi: `+=`, `-=`, `*=`, `/=`.

---

## **4.12 Evaluation Expressions**

### **4.12.1 `eval()`**

Esegue codice JavaScript dinamico, ma è **sconsigliato** per motivi di sicurezza.

### **4.12.2 Global `eval()`**

Esegue codice nel contesto globale.

### **4.12.3 Strict `eval()`**

Non può dichiarare variabili globali.

---

## **4.13 Miscellaneous Operators**

### **4.13.1 The Conditional Operator (`?:`)**

```js
let age = 20;
let status = (age >= 18) ? "Adult" : "Minor";
```

### **4.13.2 First-Defined (`??`)**

Restituisce il primo valore **definito**:

```js
let x = null ?? 5; // x = 5
```

### **4.13.3 The `typeof` Operator**

Restituisce il tipo di una variabile:

```js
typeof 42; // "number"
```

### **4.13.4 The `delete` Operator**

Rimuove proprietà da un oggetto:

```js
let obj = { name: "Alice" };
delete obj.name;
```

### **4.13.5 The `await` Operator**

Usato con funzioni asincrone (`async`).

### **4.13.6 The `void` Operator**

Restituisce `undefined`.

### **4.13.7 The Comma Operator (`,`)**

Valuta più espressioni in sequenza:

```js
let a = (1, 2, 3); // a = 3
```