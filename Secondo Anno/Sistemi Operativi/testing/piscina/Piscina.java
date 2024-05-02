/*
 * Monitor Piscina
 * verifica del corso di Lab di Sistemi Operativi a.a. 2015/16
 * 
 * Si deve completare il monitor Piscina implementando i seguenti metodi:
 * 
 * - chiediMutex(int x,int y): chiede il mutex per accedere alla posizione
 *   x,y. Viene invocato dai nuotatori prima di spostarsi in x,y 
 * 
 * - rilasciaMutex(int x,int y): rilascia il mutex in posizione x,y. Viene 
 *   invocato dai nuotatori quando lasciano la posizione x,y
 * 
 * - attendiPartenza(int corsia): viene invocato dai nuotatori quando sono
 *   a bordo vasca pronti per partire. Il primo nuotatore deve attendere il
 *   via dello starter mentre i successivi devono attendere il ritorno del 
 *   nuotatore precedente. Questo metodo è utile allo starter per sapere 
 *   quando i nuotatori sono schierati
 * 
 * - arrivato(int corsia): viene invocato dai nuotatori quando hanno finito
 *   le 2 vasche e sono arrivati
 * 
 * - attendiSchieramento(): viene invocato dallo starter per attendere che 
 *   tutti i (primi) nuotatori siano schierati
 * 
 * - daiVia(): viene invocato dallo starter a schieramento completo, dopo il 
 *   conto alla rovescia, per dare il via
 * 
 * Ecco lo schema del nuotatore:
 * 
 *   // raggiunge il bordo vasca (invocando chiediMutex e rilasciaMutex)
 * 
 *   piscina.attendiPartenza(corsia); // attende lo starter
 * 
 *   // si tuffa e fa le 2 vasche (invocando chiediMutex e rilasciaMutex)
 * 
 *   piscina.arrivato(corsia); // notifica che è arrivato
 * 
 *   // si posizione a sinistra (invocando chiediMutex e rilasciaMutex)
 *   // festeggia se ha vinto \O/ 
 * 
 * Ecco lo schema dello starter:
 * 
 *   // attende che i nuotatori si siano schierati
 *   piscina.attendiSchieramento();
 * 	
 *   // conto alla rovescia e via!
 *   piscina.daiVia();
 * 
 */

public class Piscina {
	int x,y,corsie;
  private boolean piscina[][];
  private boolean corsia[];
  int partenze;
	// eventuali altri variabili ...

	Piscina(int x, int y, int corsie) {
		this.x = x; // Dimensione X schermo
		this.y = y; // Dimensione Y schermo
		this.corsie = corsie; // numero di corsie
    this.piscina = new boolean[x][y];
    this.corsia = new boolean[corsie];
		// inizializzazione altre variabili ...

	}

	public synchronized void chiediMutex(int x,int y) throws InterruptedException {
	  while(piscina[x][y])
      wait();
    piscina[x][y] = true;
  }

	public synchronized void rilasciaMutex(int x,int y) {
    piscina[x][y] = false;
    notifyAll();
  }

	public synchronized void attendiPartenza(int corsia) throws InterruptedException {
    partenze++;    
    while(!this.corsia[corsia])
      wait();
    this.corsia[corsia] = false;
	}

	public synchronized void arrivato(int corsia) {
    this.corsia[corsia] = true;
    notifyAll();
	}

	public synchronized void attendiSchieramento() throws InterruptedException {
    while(partenze < corsie)
      wait();
    System.out.println("Tutti i nuotatori sono pronti!" + partenze + " " + corsie);
    partenze = 0;
	}

	public synchronized void daiVia() {
    for(int i = 0; i < corsie; i++)
      this.corsia[i] = true;
    notifyAll();
	}
}
