
## **Summary**

Questo capitolo ha trattato il **ruolo di JavaScript nei browser**, spiegando come interagire con il **DOM**, gestire gli **eventi**, usare le **Web APIs** e migliorare le **prestazioni e sicurezza**.

📌 **Suggerimenti per l’esame**:

- ✅ Sapere come usare **`querySelector()`, `textContent`, `addEventListener()`**.
- ✅ Comprendere le differenze tra **`defer` e `async`**.
- ✅ Conoscere le API principali come **`fetch()` e `localStorage`**.
- ✅ Capire i concetti di **CORS, event delegation e performance optimization**.

JavaScript è il linguaggio principale per **lo sviluppo web client-side**, eseguendosi direttamente nei browser. Questo capitolo esplora come JavaScript interagisce con il browser e manipola il contenuto delle pagine web attraverso il **DOM**, gli eventi e l'interazione con l'utente.

---

## **15.1 The Web Platform**

JavaScript, insieme a **HTML e CSS**, forma la base delle applicazioni web. Funziona in un ambiente sandbox sicuro, con restrizioni per proteggere gli utenti da minacce alla sicurezza.

Le componenti principali della piattaforma web:

- **DOM (Document Object Model)**: rappresentazione della pagina web in forma di oggetto.
- **BOM (Browser Object Model)**: API per interagire con il browser (finestra, navigazione, ecc.).
- **Eventi**: gestiscono l'interazione utente.
- **Web APIs**: funzioni avanzate fornite dai browser (es. `fetch()`, `localStorage`).

---

## **15.2 Scripting Web Pages**

JavaScript può essere incluso in una pagina web in diversi modi:

### **15.2.1 `<script>` Tag**

Il codice può essere scritto direttamente in un tag `<script>`:

```html
<script>
  console.log("Hello from JavaScript!");
</script>
```

### **15.2.2 External Scripts**

Un file esterno `.js` può essere collegato usando l'attributo `src`:

```html
<script src="script.js"></script>
```

### **15.2.3 `defer` e `async`**

- **`defer`**: carica lo script senza bloccare il parsing della pagina ed esegue il codice **dopo** il caricamento dell'HTML.
- **`async`**: esegue lo script **non appena è caricato**, senza aspettare l'HTML.

```html
<script src="script.js" defer></script>
<script src="script.js" async></script>
```

✅ **Usare `defer` è consigliato per evitare blocchi nel caricamento della pagina.**

---

## **15.3 The Window Object**

L'oggetto globale in un browser è `window`, che rappresenta la finestra del browser.  
Esempi:

```js
console.log(window.innerWidth); // Larghezza della finestra
window.alert("Messaggio di avviso!"); // Mostra un popup
```

Alcuni metodi utili di `window`:

- `alert()`, `confirm()`, `prompt()`: interazione con l'utente.
- `setTimeout()`, `setInterval()`: esecuzione temporizzata di codice.
- `open()`, `close()`: apertura e chiusura di finestre.

---

## **15.4 The Document Object Model (DOM)**

Il **DOM** è una rappresentazione gerarchica della pagina HTML. JavaScript può **leggere e modificare il DOM** per aggiornare i contenuti dinamicamente.

### **15.4.1 Selezionare Elementi del DOM**

- **`getElementById()`**:
    
    ```js
    let el = document.getElementById("myId");
    ```
    
- **`getElementsByClassName()`** e **`getElementsByTagName()`**:
    
    ```js
    let elements = document.getElementsByClassName("myClass");
    ```
    
- **`querySelector()` e `querySelectorAll()`**:
    
    ```js
    let el = document.querySelector(".myClass");
    let allEls = document.querySelectorAll("p");
    ```
    

### **15.4.2 Modificare il DOM**

- **Cambiare il contenuto di un elemento**:
    
    ```js
    document.getElementById("title").textContent = "Nuovo Testo";
    ```
    
- **Modificare l'HTML interno**:
    
    ```js
    document.getElementById("content").innerHTML = "<b>Testo in grassetto</b>";
    ```
    
- **Aggiungere o rimuovere elementi**:
    
    ```js
    let newEl = document.createElement("p");
    newEl.textContent = "Nuovo paragrafo";
    document.body.appendChild(newEl);
    ```
    

### **15.4.3 Modificare Stili CSS**

```js
document.getElementById("box").style.backgroundColor = "red";
```

---

## **15.5 Handling Events**

Gli eventi permettono di rispondere all'interazione dell'utente con la pagina web.

### **15.5.1 Event Listeners**

```js
document.getElementById("btn").addEventListener("click", () => {
  alert("Bottone cliccato!");
});
```

### **15.5.2 Tipi di Eventi**

- **Click:** `click`
- **Tastiera:** `keydown`, `keyup`
- **Mouse:** `mouseover`, `mouseout`
- **Modulo HTML:** `submit`, `change`, `focus`

### **15.5.3 Event Delegation**

Si usa per ottimizzare la gestione degli eventi su più elementi.

```js
document.getElementById("list").addEventListener("click", (event) => {
  if (event.target.tagName === "LI") {
    console.log("Hai cliccato su", event.target.textContent);
  }
});
```

---

## **15.6 Web APIs**

I browser offrono **API avanzate** per interagire con il sistema.

### **15.6.1 `fetch()` API** (Richieste HTTP)

`fetch()` permette di ottenere dati da un server:

```js
fetch("https://api.example.com/data")
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error("Errore:", error));
```

### **15.6.2 Local Storage e Session Storage**

Memorizzano dati nel browser.

```js
localStorage.setItem("username", "Alice");
console.log(localStorage.getItem("username")); // "Alice"
```

### **15.6.3 Geolocation API**

```js
navigator.geolocation.getCurrentPosition(position => {
  console.log(position.coords.latitude, position.coords.longitude);
});
```

---

## **15.7 Security and Performance**

### **15.7.1 Cross-Origin Restrictions (CORS)**

Per motivi di sicurezza, JavaScript non può accedere a dati da altri domini senza autorizzazione.

### **15.7.2 Avoiding Blocking Operations**

Evitare operazioni lente (`alert()`, `synchronous XMLHttpRequest`) per non bloccare la UI.

### **15.7.3 Debouncing e Throttling**

Tecniche per ottimizzare le performance negli eventi ad alta frequenza come `scroll` e `resize`.