import java.util.Random;

public class AutomobiliPedoni extends Thread {
	static final int N_AUTO = 25;
	static final int DIM = 20;

	int id,x,y,dx,dy;
	Incrocio incr;
	char c;

	// Le automobili e pedoni hanno id, usano il monitor e hanno posizione, spostamento e simbolo da stampare
	public AutomobiliPedoni(int id, Incrocio incr, int x, int y, int dx, int dy, char c) {
		this.id = id;
		this.x=x;
		this.y=y;
		this.dx=dx;
		this.dy=dy;
		this.incr=incr;
		this.c=c;
	}

	public void run() {
		Random r = new Random();
		int speed = r.nextInt(4)+2;
		try {
			Thread.sleep(r.nextInt(10)*1000);

			while(x+dx<DIM && y+dy<DIM && x+dx>0 && y+dy>0) {
				// La macchina si ferma al semaforo
				if ((dx == -1 && x==DIM/2+2) || (dx == 1 && x==DIM/2-3))
					incr.arrivaPedone(); // Il Pedone arriva all'incrocio
				else if  ((dy == -1 && y==DIM/2+2) || (dy == 1 && y==DIM/2-3))
					incr.arrivaAuto(); // L'auto arriva all'incrocio
				else if ((dx == -1 && x==DIM/2-3) || (dx == 1 && x==DIM/2+2)) {
					incr.attraversatoPedone(); // il pedone ha attraversato
				}
				else if ((dy == -1 && y==DIM/2-3) || (dy == 1 && y==DIM/2+2)) {
					incr.attraversatoAuto(); // l'auto ha attraversato
				}
				// La macchina/pedone si muove da x,y con dx,dy
				if (incr.strada(x,y) != ' ' && incr.strada(x,y) != c) {
					System.out.println("Incidente!!!");
					System.exit(1);
				}
				incr.muovi(c,x,y,dx,dy);
				x+=dx; y+=dy;

				// La macchina/pedone ha una sua velocita'
				Thread.sleep(200 + speed*50);
			}
		} catch (InterruptedException e) {}

		// La macchina/pedone esce dall'incrocio		
		incr.libera(x,y);

	}

	public static void main(String args[]) throws InterruptedException {
		int i;
		AutomobiliPedoni[] t = new AutomobiliPedoni[N_AUTO*4];
		Stampa s;

		// Crea il monitor Incrocio
		Incrocio incr = new Incrocio(DIM);

		// Crea il thread che stampa l'incrocio
		s = new Stampa(incr);
		s.start();

		// Crea le macchine/pedoni
		for (i=0;i<N_AUTO;i++) {
			t[i*4]   = new AutomobiliPedoni(i*2,incr,DIM/2,0,0,1,'>');
			t[i*4+1] = new AutomobiliPedoni(i*2+1,incr,DIM/2-1,DIM-1,0,-1,'<');
			t[i*4+2] = new AutomobiliPedoni(i*4+2,incr,0,DIM/2-1,1,0,'O');
			t[i*4+3] = new AutomobiliPedoni(i*4+3,incr,DIM-1,DIM/2,-1,0,'O');
		}
		for (i=0;i<N_AUTO*4;i++) {
			sleep(500);
			t[i].start();
		}

		// Attende che tutte le macchine/pedoni siano usciti
		for (i=0;i<N_AUTO*4;i++) {
			t[i].join();
		}

		// Interrompe il thread che stampa
		s.interrupt();
	}

	// Classe estremamente poco elegante che stampa l'incrocio in modo brutale
	static class Stampa extends Thread {
		static final String ANSI_RESET = "\u001B[0m";
		static final String ANSI_RED = "\u001B[31m";
		static final String ANSI_GREEN = "\u001B[32m";

		Incrocio incr;
		int sem;

		public Stampa(Incrocio incr) {
			this.incr = incr;
			sem = 0;
		}
		public void run() {
			int i,j,w,count=0;
			try {
				while(true) {
					
					Thread.sleep(50);
					count++;
					if (count%50 == 0) {
						// incr.cambiaSemaforo();
						sem = (sem + 1) % 4;
					}
					// Tecnologia avanzata per l'animazione:
					System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					// Loop per ogni cella della strada
					for (i=1;i<DIM-1;i++) {
						for (j=1;j<DIM-1;j++) {
							if (i==DIM/2-2 || i==DIM/2+1) {
								if (j<DIM/2-2|| j>DIM/2+1)
									System.out.print("---");
								else if (j==DIM/2-2)
									System.out.print("+  ");
								else if (j==DIM/2+1)
									System.out.print("  +");
								else
									System.out.print(" " + incr.strada(i,j)+ " ");
							} else
								System.out.print(" " + incr.strada(i,j)+ " ");
						}
						System.out.println();
						System.out.println();
						
						
					}
				}
			} catch (InterruptedException e) {}
		}
	}

}