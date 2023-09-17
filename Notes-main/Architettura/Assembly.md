```cpp
// Codice equivalente in C
// long strlen_c_rec( unsigned char* s)
// {
//   if( *s == 0)
//     return 0;
//   return 1+strlen_c_rec(s+1);
// }

  .global strlen_rec
strlen_rec:
  ldrb w2, [x0]
  cmp w2, #0
  b.eq returnzero

  // effettuare la chiamata ricorsiva
  str x30, [so, #-16]! // push x30 (lr)
  add x0, x0, #1
  bl strlen_rec
  // ora in x0 abbiamo il risultato della chiamata ricorsiva 
  // a cui dobbiamo aggiungere +1
  add x0, x0, #1
  ldr x30, [sp], #16 // pop x30 (lr)
  ret

returnzero:
  mov x0, #0
  ret
```

#### Ricorda di controllare sempre lo stack, potrebbero verificarsi buffer stack overflow se non si controlla in maniera adeguata, sopratutto in caso di input da parte dell'utente!