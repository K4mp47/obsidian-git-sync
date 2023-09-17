Assumiamo di avere un programma che ha:
- Instruction miss ratio: 2%
- Data miss ratio: 4%
- Numero lw/sw = 36% IC
- CPI$_{ideale}$ = 2
- Miss penalty = 40 cicli di clock
- Cicli di stallo dovuti alle istruzioni:
	- IC * istruction miss ratio * miss penalty = IC * 0.02 * 40 = 0.8 IC
- Cicli di stallo dovuti ai dati:
	- IC$_{dati}$ \* data miss ratio \* miss penalty = (0.36\*IC) \* 0.04 \* 40 = 0.58 \* IC 
- Cicli di stallo totali:
	- Cicli stallo istruzioni + cicli stallo dati = 0.8\*IC + 0.58\*IC
- Cicli di stallo medi per istruzione:
	- 1.38 IC / IC =  1.38
- CPI$_{reale}$ = CPI$_{ideale}$ + cicli di stallo medi per istruzione
- CPI$_{reale}$ = 2 + 1.38 = 3.38
- Speedup = 3.38 / 2 = 1.69

Cerchiamo di risponde le seguenti domande:
- Se velocizzassi la CPU e lasciassi immutato il sottosistema di memoria cosa succederebbe?
	- Il tempo assoluto di penalty, miss ratio e IC rimangono invariati, mentre il CPI$_{ideale}$ e il miss penalty variano a seconda di come ho velocizzato la CPU
	- Se modifico l’organizzazione interna della CPU:
		• Diminuisco CPI$_{ideale}$
		• miss penalty resta invariato, quindi resterebbero invariati i cicli di stallo totali dovuti ai miss
	- Se aumento la frequenza (overclock):
		• CPIideale resta invariato
		• CPIreale aumenta perché il miss penalty (in numerodi cicli) aumenta perché i cicli sono più brevi

># ☢
>Notiamo quindi che il sistema di memoria ha un impatto forte sulle performance di un sistema
>Legge di Amdahl:
	Exe time after improvement = Exe time affected by improvement / Amount of improvement + Exe time unaffected by improvement