/*
 * Corso di Sistemi Operativi 2020
 * Prima verifica: pipe
 *
 * Author: Riccardo Focardi
 *
 * Per essere sicuri che le pipe siano create e aperte testare la soluzione con:
 * ./crypto -i /tmp/pipeIn -o /tmp/pipeOut & (sleep 1; ./soluzione)
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <signal.h>

#define MAX 10000 // numero loop
#define NKEY 10  // chiavi di cifratura da 0 a NKEY-1

// frasi di EINSTEIN
char * frasi[] = {
    "ALBERT EINSTEIN: L'uomo ha scoperto la bomba atomica, pero' nessun topo al mondo costruirebbe una trappola per topi.#",
    "ALBERT EINSTEIN: Il mondo e' un posto pericoloso, non a causa di quelli che compiono azioni malvagie ma per quelli che osservano senza fare nulla.#",
    "ALBERT EINSTEIN: Solo due cose sono infinite: l'universo e la stupidita' umana, riguardo l'universo ho ancora dei dubbi.#",
    "ALBERT EINSTEIN: Mai memorizzare quello che puoi comodamente trovare in un libro.#",
    "ALBERT EINSTEIN: Cerca di diventare non un uomo di successo ma piuttosto un uomo di valore.#",
    "ALBERT EINSTEIN: Se una scrivania in disordine e' segno di una mente disordinata, di cosa, allora, e' segno una scrivania vuota?#",
    "ALBERT EINSTEIN: Ognuno e' un genio. Ma se si giudica un pesce dalla sua abilita' di arrampicarsi sugli alberi lui passera' tutta la sua vita a credersi stupido.#",
    "ALBERT EINSTEIN: Il tempo e' relativo, il suo unico valore e' dato da cio' che noi facciamo mentre sta passando.#",
    "ALBERT EINSTEIN: Il valore di una persona risiede in cio' che e' capace di dare e non in cio' che e' capace di prendere.#",
    "ALBERT EINSTEIN: I computer sono incredibilmente veloci, accurati e stupidi. Gli uomini sono incredibilmente lenti, inaccurati e intelligenti. L'insieme dei due costituisce una forza incalcolabile.#",
    "ALBERT EINSTEIN: Il mondo e' un bel posto e per esso vale la pena di lottare.#",
    "ALBERT EINSTEIN: La creativita' e' contagiosa. Trasmettila.#",
    "ALBERT EINSTEIN: L'umanita' avra' la sorte che sapra' meritarsi.#",
    "ALBERT EINSTEIN: L'insegnamento deve essere tale da far percepire cio' che viene offerto come un dono prezioso, e non come un dovere imposto.#",
    "ALBERT EINSTEIN: Tutto cio' che ha valore nella societa' umana dipende dalle opportunita' di progredire che vengono accordate ad ogni individuo.#",
	NULL
};
char *pipein=NULL,*pipeout=NULL; // pipe names
int fd0=0, fd1=1; 	// stdin e stdout by default

void die() {
	close(fd0);
	close(fd1);
	unlink(pipein);
	unlink(pipeout);
	exit(1);
}

/* 
 * invia la stringa s su fd cifrandola con la chiave k
 */
void inviaCifrato(int fd, char * s, char k) {
	int i;
	char c;
	for (i=0;i<strlen(s);i++) {
		c = s[i]-k;
		write(fd,&c,1);
	}
}

int main(int argc, char **argv) {
	int verbose=0;		// verbosità
	int i,j;			// indici
	int nfrasi;			// numero delle frasi
	int index;			// indice frase casuale
	char key;			// chiave di cifratura
	int c;				// parser
	char d;				// carattere per la lettura
	int fd;				// fd temporaneo

	// se interrotto esce gracefully, cancellando le pipe
	signal(SIGINT,die);

	while ((c = getopt (argc, argv, "vhi:o:")) != -1) {
	    switch (c)
	      {
	      case 'i':
	      case 'o':
	      	if (c=='i')
	      		pipein=optarg;
	      	else
	      		pipeout=optarg;
	      	unlink(optarg);
	      	printf("[*] Creazione pipe '%c' %s\n",c,optarg);
	      	if(mkfifo(optarg,0600)<0) {
	      		perror("[ERRORE] creazione pipe");
	      		die();
	      	}
	      	printf("[*] Apertura pipe  '%c' %s\n",c,optarg);
	        if ((fd = open(optarg,O_RDWR)) < 0) {
	        	perror("[ERRORE] apertura pipe");
	        	die();
	        }
	        if (c=='i')
	      		fd0=fd;
	      	else
	      		fd1=fd;
	        break;
	      case 'v':
	      	verbose=1;
	      	break;
	      default:
          	fprintf (stderr, "Utilizzo: %s [options]\n",argv[0]);
          	fprintf (stderr, "options:\n");
          	fprintf (stderr, "   -i pipeName: nome pipe input\n");
          	fprintf (stderr, "   -o pipeName: nome pipe output\n");
          	fprintf (stderr, "   -v:          modalita' verbosa\n");
          	fprintf (stderr, "   -h:          questa schermata\n");
	        die();
	      }
	}

	srandom(time(NULL));   	// inizializza la randomness

	// calcola il numero dei frasi
	for(nfrasi=0;frasi[nfrasi];nfrasi++);
	if(verbose)
		printf("[VERBOSO] Numero frasi: %d\n",nfrasi);

	// loop principale
	for (i=0;i<MAX;i++){
		index = random()%nfrasi; // sceglie la frase
		key   = (char) (random()%(NKEY-1) + 1);	 // sceglie la chiave
		if(verbose) {
			printf("[VERBOSO] Frase estratta  %d: %s\n",index,frasi[index]);
			printf("[VERBOSO] Chiave estratta %d\n",key);
		}

		// la frase cifrata con key
		inviaCifrato(fd1,frasi[index],key);

		if(verbose) {
			if (fd1 == 1) printf("\n");
			printf("[VERBOSO] ho inviato '%s' cifrato con %d\n",frasi[index],key);
		}
		j=0;
		while(j<strlen(frasi[index]) && read(fd0,&d,1)) {
			// ignora ciò che non è da spazio a 'z', quindi anche '\n'
			if (d>=' ' && d<='z') { 
				if (d!=frasi[index][j]) {
					printf("[ERRORE] letto %c invece di %c\n", d, frasi[index][j]);
					if(fd0==0) {
						while((c = getchar()) != '\n' && c != EOF);
					}
					die();
				}
				if (verbose) {
					printf("[VERBOSO] letto e verificato %c (ASCII %d)\n",d,d);
				}
				j++; // letto e verificato un carattere
			} else {
				if (verbose) {
					printf("[VERBOSO] letto e ignorato %c (ASCII %d)\n",d,d);
				}
			}
		}
	}

	printf("[*] Congratulazioni! Hai superato il crypto quiz!\n");
	close(fd0);
	close(fd1);
	unlink(pipein);
	unlink(pipeout);
	exit(0);
}