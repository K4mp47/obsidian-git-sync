
public class Staffetta {

	Piscina piscina;
	static final int X=100;
	static final int BASE_SLEEP=50;
	static final int SLEEP_STAMPA=100;
	static final int X_PISCINA_START=30;
	static final int X_PISCINA_END=X-3;
	static final int Y_PISCINA=3;
	static final int L_CORSIE=4; 	// larghezza corsie
	static final int CORSIE=8; 		// olimpionica!
	static final int NUOTATORI=4;
	static final int Y=Y_PISCINA+CORSIE*L_CORSIE+2;

	// Per il testing
	Boolean schierato[] = new Boolean[CORSIE]; 
	Boolean via = false;

	int arrivato[] = new int[CORSIE];  // nuotatori arrivati per corsia
	int ordineArrivo = 0;   // ordine di arrivo
	Boolean running = true; // per terminare il thread di stampa

	char[][] screen = new char[X][Y]; // lo schermo

	Staffetta(Piscina piscina) {
		this.piscina = piscina; // il monitor
		java.util.Arrays.fill(schierato,false); // per il testing
	}

	// prende l'ordine di arrivo, sincorizzato, no parimerito!
	synchronized int getOrdineArrivo(int corsia) {
		ordineArrivo +=1;
		return ordineArrivo;
	}

	// si muove chiedendo il mutex
	void move(char c, char cold, int x,int y,int newX, int newY) throws InterruptedException{
		piscina.chiediMutex(newX,newY); // acquisisci mutex sulla cella nuova
		if (screen[newX][newY] == 'O') {
			System.out.println("[Errore Mutex] Nuotatore si sposta su altro nuotatore!");
			System.exit(1);
		}
		screen[newX][newY] = c;
		screen[x][y] = cold;
		piscina.rilasciaMutex(x,y); // rilascia il mutex sulla cella vecchia
	}

	// stampa lo schermo (grafica sofisticata)
	synchronized void printScreen() {
		int x,y;
		System.out.print("\033[H\033[2J");
		for (y=0;y<Y;y++) {
			for (x=0;x<X;x++) {
				System.out.print(screen[x][y]);
			}
			System.out.println();
		}
	}	

	// inizializza lo schermo a vuoto
	void  initScreen() {
		int x,y;
		for (y=0;y<Y;y++) {
			for (x=0;x<X;x++) {
				screen[x][y]=' ';
			}
		}

	}
	
	// scrive i contorni della piscina
	synchronized void stampaPiscina() {
		int x,y,c;
		for (y=Y_PISCINA;y<=L_CORSIE*CORSIE+Y_PISCINA;y++) {
			if (((y-Y_PISCINA) % L_CORSIE) == 0) {
				for (x=X_PISCINA_START;x<X_PISCINA_END;x++) {
					if (x==X_PISCINA_START || x==X_PISCINA_END-1) {
						screen[x][y] = '+';
					} else {
						screen[x][y] = '-';
					}
				}
			} else {
				screen[X_PISCINA_START][y] = '|';
				screen[X_PISCINA_END-1][y] = '|';
			}
		}
	}

	public static void main(String[] args) throws InterruptedException{
		int i,corsia;

		Piscina piscina = new Piscina(X,Y,CORSIE); // monitor
		Staffetta staffetta = new Staffetta(piscina); // staffetta
		Stampa stampa = new Stampa(staffetta); // thread di stampa
		Nuotatore[] nuotatore = new Nuotatore[CORSIE*staffetta.NUOTATORI]; // nuotatori
		Starter starter = new Starter(staffetta,piscina); // thread starter

		// inizializza lo schermo
		staffetta.initScreen();
		// fa partire il thread di stampa
		stampa.start();

		// fa partire i thread nuotatori
		for (i=0;i<CORSIE*staffetta.NUOTATORI;i++) {
			corsia = i%CORSIE;
			nuotatore[i] = new Nuotatore(staffetta,piscina,corsia,i/CORSIE*2,corsia*L_CORSIE+Y_PISCINA+(L_CORSIE/2));
			nuotatore[i].start();
		}

		starter.start(); // fa partire il thread starter

		// attende la conclusione dei nuotatori e dello starter
		for (i=0;i<CORSIE*staffetta.NUOTATORI;i++) {
			nuotatore[i].join();
		}
		starter.join();

		staffetta.running = false; // termina il thread di stampa
		stampa.join();

		System.out.println("Terminato correttamente! Gran bella gara!");
	}
}

class Nuotatore extends Thread {
	Staffetta staffetta;
	Piscina piscina; // il monitor
	int corsia; // propria corsia
	int x,y; // propria posizione

	Nuotatore(Staffetta staffetta,Piscina piscina,int corsia,int x, int y) {
		this.staffetta = staffetta;
		this.piscina = piscina;
		this.corsia = corsia;
		this.x = x;
		this.y = y;
	}

	public void run() {
		int myArrivato; // si salva il numero all'interno della squadra
		int myOrdine=0; // ordine di arrivo
		int i;
		try {
			java.util.Random rn = new java.util.Random();
			
			int longSleep = staffetta.BASE_SLEEP*5+rn.nextInt(staffetta.BASE_SLEEP);

			// posizionamento iniziale
			piscina.chiediMutex(x,y);
			staffetta.screen[x][y]='O';

			// raggiunge il bordo vasca
			while (x < staffetta.X_PISCINA_START-1) {
				sleep(longSleep);
				staffetta.move('O',' ',x,y,x+1,y); // si muove in mutua esclusione
				x+=1;
			}

			staffetta.schierato[corsia] = true; // per il testing

			piscina.attendiPartenza(corsia); // attende lo starter

			// test
			if (!staffetta.via) {
				synchronized(staffetta) {
					staffetta.printScreen();
					System.out.println("[ERRORE sincronizzazione] Un nuotatore sta partendo prima dello start!");
				}
				System.exit(1);
			}

			int shortSleep = staffetta.BASE_SLEEP+rn.nextInt(staffetta.BASE_SLEEP/5);

			// si tuffa!
			sleep(shortSleep);
			staffetta.move('O',' ',x,y,x+1,y);
			sleep(shortSleep);
			staffetta.move('O','|',x+1,y,x+2,y);
			sleep(shortSleep);
			staffetta.move('*',' ',x+2,y,x+3,y);
			sleep(shortSleep);

			x+=3;

			// prima vasca
			while (x < staffetta.X_PISCINA_END-2) {
				sleep(shortSleep);				
				staffetta.move('O',' ',x,y,x+1,y);
				if (staffetta.X_PISCINA_START != x-2)
					staffetta.screen[x-2][y]=' ';
				staffetta.screen[x-1][y]='>';
				x+=1;
			}			

			// cambio direzione
			staffetta.screen[x][y] = '*';
			sleep(longSleep);
			
			// seconda vasca
			shortSleep = staffetta.BASE_SLEEP+rn.nextInt(staffetta.BASE_SLEEP/5);
			while (x > staffetta.X_PISCINA_START+1) {
				sleep(shortSleep);				
				staffetta.move('O',' ',x,y,x-1,y);
				if (staffetta.X_PISCINA_END-1 != x+2)
					staffetta.screen[x+2][y]=' ';
				if (staffetta.X_PISCINA_END-1 != x+1)
					staffetta.screen[x+1][y]='<';
				x-=1;
			}
			staffetta.screen[x+2][y]=' ';

			// si sposta in basso per uscire
			staffetta.move('O',' ',x,y,x,y+1);
			y+=1;

			piscina.arrivato(corsia); // notifica che è arrivato

			staffetta.arrivato[corsia] += 1;
			myArrivato = staffetta.arrivato[corsia];

			// se è l'ultimo della squadra salva l'ordine e lo stampa
			if (staffetta.arrivato[corsia] == staffetta.NUOTATORI) {
				myOrdine = staffetta.getOrdineArrivo(corsia);
				staffetta.screen[staffetta.X_PISCINA_END+1][staffetta.L_CORSIE*corsia+staffetta.Y_PISCINA+(staffetta.L_CORSIE/2)] = Character.forDigit(myOrdine, 10);
			}

			// esce dalla vasca
			sleep(longSleep*10);
			staffetta.move('O',' ',x,y,x-2,y); 
			x-=2;

			// si posizione a sinistra
			while (x > myArrivato*3-1) {
				sleep(longSleep);
				staffetta.move('O',' ',x,y,x-1,y);
				x-=1;
			}			

			// i primi festeggiano \O/ 
			if (myOrdine == 1 && myArrivato == staffetta.NUOTATORI) {
				for (i=0;i<staffetta.NUOTATORI;i++) {
					staffetta.screen[i*3+1][y] = '\\';
					staffetta.screen[i*3+3][y] = '/';
				}
			}

		} catch (InterruptedException e) {}
	}
}

// thread di stampa
class Stampa extends Thread {
	Staffetta staffetta;

	Stampa(Staffetta staffetta) {
		this.staffetta = staffetta;
	}

	public void run() {
		staffetta.stampaPiscina();
		while(staffetta.running) {
			try {
				sleep(staffetta.SLEEP_STAMPA);
			} catch (InterruptedException e) {}
			staffetta.printScreen();

		}
	}
}

class Starter extends Thread {
	Staffetta staffetta;
	Piscina piscina;

	Starter(Staffetta staffetta, Piscina piscina) {
		this.staffetta = staffetta;
		this.piscina = piscina; // monitor
	}

	public void run() {
		int i;

		try {
			// attende che i nuotatori si siano schierati
			piscina.attendiSchieramento();
	
			// test
			for (i=0;i<staffetta.CORSIE;i++) {
				if (!staffetta.schierato[i]) {
					synchronized(staffetta) {
						staffetta.printScreen();
						System.out.println("[ERRORE sincronizzazione] Lo starter sta dando il via prima che lo schieramento sia completo");
						System.exit(1);
					}
				}
			}

			// conto alla rovescia e via!
			sleep(staffetta.BASE_SLEEP*30);
			staffetta.screen[staffetta.X_PISCINA_START][1] = '3';
			sleep(staffetta.BASE_SLEEP*30);
			staffetta.screen[staffetta.X_PISCINA_START][1] = '2';
			sleep(staffetta.BASE_SLEEP*30);
			staffetta.screen[staffetta.X_PISCINA_START][1] = '1';
			sleep(staffetta.BASE_SLEEP*30);
			staffetta.screen[staffetta.X_PISCINA_START][1] = 'G';
			staffetta.screen[staffetta.X_PISCINA_START+1][1] = 'O';
			staffetta.screen[staffetta.X_PISCINA_START+2][1] = '!';

			staffetta.via = true; // per il testing

			// dà il via ai nuotatori
			piscina.daiVia();
		} catch (InterruptedException e) {}
	}
}
