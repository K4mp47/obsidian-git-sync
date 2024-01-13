Risolve problemi di spazio di memoria limitato, creando l'illusione che esista più memoria di quella disponibile. I sistemi a memoria virtuale hanno due tipi di indirizzi, fisici e virtuali, in base agli indirizzi di memoria a cui ci si sta riferendo. La MMU(Memory Management Unit) è la componente hw dedicata alla traduzione da indirizzo virtuale a fisico.

###### Concetti di base

Spazio di indirizzamento reale R ==> Intervallo di indirizzi fisici disponibili  
Spazio di indirizzamento virtuale V ==> Intervallo di indirizzi virtuali ai quali il processo può fare riferimento(sono solo i processi ad usare gli indirizzi virtuali)  
Spesso gli indirizzi virtuali sono più grandi di quelli fisici presenti nella macchina, quindi SO deve memorizzare parti di V per ogni processo al di fuori della memoria principale  
Il SO usa un sistema di memoria a due livelli, permettendo scambi di porzioni di V tra memoria principale e secondaria

[[Paginazione]]
[[Segmentazione]]
