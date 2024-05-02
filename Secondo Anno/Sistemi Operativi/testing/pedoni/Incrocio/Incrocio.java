/*
 * Ci sono automobili e pedoni che si approcciano a un incrocio 
 * Le auto si comportano secondo il seguente schema:
 * 
 ********
 *  finche' sulla strada:
 *
 *		Se accede all'incrocio:
 *			incr.arrivaAuto(); // indica che sta per attraversare
 *		Se esce dall'incrocio:
 *			incr.attraversatoAuto(); // indica che ha attraversato
 *				
 *		incr.muovi(c,x,y,dx,dy); // la macchina si muove se ha strada
 *		x+=dx; y+=dy;
 *		
 *	incr.libera(x,y); // esce dalla strada
 *********
 * I pedoni:
 ********
 *  finche' sulla strada:
 *
 *		Se accede all'incrocio:
 *			incr.arrivaPedone(); // indica che sta per attraversare
 *		Se esce dall'incrocio:
 *			incr.attraversatoPedone(); // indica che ha attraversato
 *				
 *		incr.muovi(c,x,y,dx,dy); // il pedone si muove se ha strada
 *		x+=dx; y+=dy;
 *		
 *	incr.libera(x,y); // esce dalla strada
 *********
 * Progettare un monitor Incrocio che implementi i seguenti metodi:
 *
 * void muovi(char c, int x, int y, int dx, int dy)
 *   se la posizione x+dx,y+dy e' occupata attende. Altrimenti scrive c in tale posizione e libera
 *   la posizione attuale x,y scrivendo uno spazio
 *
 * void libera(int x, int y)
 *   libera la posizione x,y scrivendo uno spazio
 * 
 * char strada(int x, int y)
 *   ritorna il carattere (auto o spazio) in posizione x,y (serve per stampare le auto)
 *
 * void arrivaAuto() 
 *   Se ci sono pedoni in attesa o in attraversamento attende
 *
 * void attraversatoAuto() 
 *   Indica che ha finito di attraversare l'incrocio
 *
 * void arrivaPedone() 
 *   Se ci sono auto in attraversamento attende, ma ha la precedenza
 *
 * void attraversatoPedone() 
 *   Indica che ha finito di attraversare l'incrocio
 *
 */
public class Incrocio {
	int DIM;
	char[][] strada;

  int autoInAttesa = 0;
  int pedoniInAttesa = 0;

	public Incrocio(int DIM) {
		int i,j;
		this.DIM = DIM;
		this.strada = new char[DIM][DIM];
		for (i=0;i<DIM;i++)
			for (j=0;j<DIM;j++)
				strada[i][j] = ' ';
	}

	public synchronized void muovi(char c, int x, int y, int dx, int dy) throws InterruptedException{
    while(strada[x+dx][y+dy] != ' ')
      wait();
		strada[x+dx][y+dy]= c;
		libera(x,y);
	}

	public synchronized void libera(int x, int y) {
		strada[x][y] = ' ';
    notifyAll();
	}
	
	public char strada(int x, int y) {
		return strada[x][y];
	}

	public synchronized void arrivaAuto() throws InterruptedException {
	  while(pedoniInAttesa > 0)
      wait();
    autoInAttesa++;
  }

	public synchronized void attraversatoAuto() {
    autoInAttesa--;
    notifyAll();
  }

	public synchronized void arrivaPedone() throws InterruptedException {
    while(autoInAttesa > 0)
      wait();
    pedoniInAttesa++;	
  }

	public synchronized void attraversatoPedone() {
    pedoniInAttesa--;
    notifyAll();
  }
}
