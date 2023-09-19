# Introduzione
> - Due compiti intermedi per non dover per forza fare il modulo 1
> - Modulo 2: solo se modulo 1 é stato passato
> - 

# 19 settembre 2023: introduzione a sistemi operativi

## Cos'é un sistema operativo:
>- macchina astratta
>- gestore di risorse
>	- bisogna ottimizzare la gestione delle risorse per migliorare le performance della macchina

```
utenti(applicazioni)
------------
SO (macchina astratta, astrazione della macchina reale per l'utente)
(si occupa anche di gestire le risorse HW)
------------
HW(componenti fisici, HDD, SSD, RAM, I/O, ecc.)
```
## Struttura del sistema operativo:
>- Monolitica
>- a livelli
>- MicroKernel

#### Definizione di SO: software che controlla l'HW
> SO funziona da interfaccia tra utente/applicazioni ed HW, inoltre si occupa di gestire le risorse della macchina

![[Pasted image 20230919145405.png]]

```
Software:
[
	User mode:
	[
		User Interface,
		Other programs(web browser ecc.)
	]
	Kernel mode:
	[
		Operating System
	]
]
HW:[]
```

>SO: principalmente usa i sistemi in modalitá nucleo (Kernel), le applicazioni invece sono invece principalmente in modalitá kernel

![[Pasted image 20230919145526.png]]
> Con il termine *programmi di sistema* ci riferiamo a quei programmi usati per eseguire le operazioni (Compilatori, editor, ecc.)

> I'OS é una macchina estesa che:
> - Nasconde i dettagli delle operazioni eseguite (**MASCHERAMENTO**)
> - Presenta all'utente il sistema con un interfaccia semplice da usare (**TRASPARENZA**)
> - Gestisce le risorse, perché:
> 	- Ogni programma richiede tempo e spazio per le risorse

