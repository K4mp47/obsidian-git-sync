# La lezione di oggi è il primo approccio al uso di R attraverso RStudio
# Assicuratevi di avere la versione più aggiornata di R (R-4.3.1). Lo vedete nella finestra "Console" all'avvio di RStudio

# I seguente esercizio ci aiuta a ripassare la combinatoria e introdurre alcune definizioni formali (vedere insieme alla slide 19 di 1_Probabilita_Elementare.pdf)


# Una moneta bilanciata viene lanciata 100 volte.
# a) Si descriva lo spazio campionario dell'esperimento e se ne calcoli la
# cardinalità
Omega_moneta<-c("testa", "croce")
# T=1; C=0
# cardinalità
length(Omega_moneta)

#Omega = insieme di stringe di lunghezza 100 fatte di 0 e 1
N=2^100#cardinalità
#Possibile esperimento: lancio di 100 monete

# b) Si calcoli la cardinalita dell'evento B="si ottengono esattamente 50 teste nei primi 50 lanci e 50 croci negli ultimi 50". 
NB = 1

# c) Si calcoli la cardinalita dell'evento C="si ottengono esattamente 50 teste". 

NC = choose(100,50) #La funzione choose in R calcola il coefficiente binomiale
?choose #Per maggiori informazioni (vedete la finestra "Help")

# d) Si calcoli la cardinalita dell'evento D="si ottengono meno di 5 teste"
ND = choose(100,4)+choose(100,3)+choose(100,2)+choose(100,1)+choose(100,0)
