## **7.11 Summary**

Questo capitolo copre **creazione, manipolazione e iterazione degli array**. È fondamentale conoscere i metodi più usati come `.map()`, `.filter()`, `.reduce()`, `.splice()`, `.sort()`.

📌 **Suggerimento per l'esame**: pratica con i metodi più importanti (`map()`, `filter()`, `reduce()`, `sort()`, `splice()`). 🚀

---

## **7.1 Creating Arrays**

Esistono diversi modi per creare un array in JavaScript.

### **7.1.1 Array Literals**

Il modo più semplice per creare un array è usare la notazione **letterale**:

```js
let numbers = [1, 2, 3, 4, 5];
```

### **7.1.2 The Spread Operator (`...`)**

Il **spread operator** può essere usato per clonare o unire array:

```js
let arr1 = [1, 2, 3];
let arr2 = [...arr1, 4, 5]; // [1, 2, 3, 4, 5]
```

### **7.1.3 The `Array()` Constructor**

Si può creare un array anche con `new Array()`, ma è **sconsigliato** perché può causare ambiguità.

```js
let arr = new Array(3); // Crea un array vuoto con lunghezza 3
```

### **7.1.4 `Array.of()`**

Crea un array con gli elementi specificati:

```js
let arr = Array.of(3); // [3]
```

### **7.1.5 `Array.from()`**

Crea un array da un oggetto **iterabile**:

```js
let str = "hello";
let letters = Array.from(str); // ['h', 'e', 'l', 'l', 'o']
```

---

## **7.2 Reading and Writing Array Elements**

Gli elementi di un array sono accessibili tramite **indice numerico** (zero-based):

```js
let fruits = ["apple", "banana"];
console.log(fruits[0]); // "apple"
fruits[1] = "orange"; // Modifica un elemento
```

---

## **7.3 Sparse Arrays**

Un **array sparso** ha elementi mancanti:

```js
let sparseArray = [1, , , 4]; // Contiene due "buchi"
console.log(sparseArray.length); // 4
```

⚠️ **Attenzione**: I cicli `forEach` saltano gli elementi mancanti!

---

## **7.4 Array Length**

La proprietà `.length` indica la lunghezza dell’array. È modificabile:

```js
let arr = [1, 2, 3, 4];
arr.length = 2; // Tronca l'array a [1, 2]
```

---

## **7.5 Adding and Deleting Array Elements**

Si possono **aggiungere** o **rimuovere** elementi con:

```js
let arr = [1, 2, 3];
arr.push(4);   // Aggiunge alla fine → [1, 2, 3, 4]
arr.pop();     // Rimuove l'ultimo → [1, 2, 3]
arr.unshift(0); // Aggiunge all'inizio → [0, 1, 2, 3]
arr.shift();    // Rimuove il primo → [1, 2, 3]
```

⚠️ **`push()` e `pop()` sono più efficienti di `unshift()` e `shift()` perché non devono spostare gli elementi.**

---

## **7.6 Iterating Arrays**

Si può scorrere un array in vari modi:

### **Ciclo `for` classico**

```js
for (let i = 0; i < arr.length; i++) {
  console.log(arr[i]);
}
```

### **Ciclo `for/of` (ES6)**

```js
for (let value of arr) {
  console.log(value);
}
```

### **Metodo `.forEach()`**

```js
arr.forEach(value => console.log(value));
```

---

## **7.7 Multidimensional Arrays**

Un array può contenere altri array:

```js
let matrix = [[1, 2], [3, 4]];
console.log(matrix[0][1]); // 2
```

---

## **7.8 Array Methods**

### **7.8.1 Array Iterator Methods**

- **`map()`**: restituisce un nuovo array con valori trasformati
    
    ```js
    let doubled = [1, 2, 3].map(x => x * 2); // [2, 4, 6]
    ```
    
- **`filter()`**: filtra gli elementi in base a una condizione
    
    ```js
    let evens = [1, 2, 3, 4].filter(x => x % 2 === 0); // [2, 4]
    ```
    
- **`reduce()`**: riduce l'array a un singolo valore
    
    ```js
    let sum = [1, 2, 3].reduce((acc, val) => acc + val, 0); // 6
    ```
    

### **7.8.2 Flattening Arrays with `flat()` and `flatMap()`**

```js
let nested = [1, [2, [3]]];
console.log(nested.flat(2)); // [1, 2, 3]
```

### **7.8.3 Adding Arrays with `concat()`**

```js
let arr1 = [1, 2];
let arr2 = [3, 4];
console.log(arr1.concat(arr2)); // [1, 2, 3, 4]
```

### **7.8.4 Stacks and Queues with `push()`, `pop()`, `shift()`, `unshift()`**

- **Stack (LIFO)**: usa `push()` e `pop()`.
- **Queue (FIFO)**: usa `push()` e `shift()`.

### **7.8.5 Subarrays with `slice()`, `splice()`, `fill()`, and `copyWithin()`**

- **`slice(start, end)`**: estrae una parte dell’array
    
    ```js
    let arr = [1, 2, 3, 4];
    console.log(arr.slice(1, 3)); // [2, 3]
    ```
    
- **`splice(index, count, ...items)`**: modifica un array
    
    ```js
    let arr = [1, 2, 3];
    arr.splice(1, 1, "X"); // [1, "X", 3]
    ```
    
- **`fill(value, start, end)`**: riempie l’array con un valore
    
    ```js
    let arr = new Array(5).fill(0); // [0, 0, 0, 0, 0]
    ```
    

### **7.8.6 Array Searching and Sorting Methods**

- **`indexOf()` / `lastIndexOf()`**: trovano un valore
    
    ```js
    [1, 2, 3].indexOf(2); // 1
    ```
    
- **`find()`**: trova un elemento
    
    ```js
    [1, 2, 3].find(x => x > 1); // 2
    ```
    
- **`sort()`**: ordina gli elementi
    
    ```js
    let arr = [3, 1, 2];
    arr.sort((a, b) => a - b); // [1, 2, 3]
    ```
    

---

## **7.9 Array-Like Objects**

Strutture simili agli array (come `arguments`) non hanno metodi array.

---

## **7.10 Strings as Arrays**

Le stringhe sono simili agli array ma **immutabili**:

```js
let str = "hello";
console.log(str[0]); // "h"
```