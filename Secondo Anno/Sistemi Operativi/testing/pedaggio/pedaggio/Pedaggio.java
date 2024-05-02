public class Pedaggio {

    private int X, Y;   // dimensioni della strada
    private int NTOLLS; // numero di caselli
    private boolean cars[][];
    private boolean pedaggio[];
    private int totali[];
    
    public Pedaggio(int x, int y, int ntolls) {
        this.X = x;
        this.Y = y;
        this.NTOLLS = ntolls;
        this.cars = new boolean[x][y]; 
        this.pedaggio = new boolean[ntolls];
        this.totali = new int[ntolls];
    }

    // si muove da x,y a nx,ny. Se nx,ny è occupato attende altrimenti
    // occupa nx,ny e libera x,y.
    public synchronized void move(int x, int y, int nx, int ny) throws InterruptedException {
      while(cars[nx][ny]) {
        wait();
      }
      cars[nx][ny] = true;
      libera(x, y);
    }

    // libera la posizione x,y sulla strada (invocata quando l'auto esce definitivamente)
    public synchronized void libera(int x, int y) {
      cars[x][y] = false;
      notifyAll();
    }

    // paga a idCasello un valore parziale che si accumula ai pagamenti precedenti
    // corrisponde a inserire una moneta o banconota nella macchinetta.
    // Viene invocato tante volte, fino a raggiungimento della cifra corretta
    public synchronized void paga(int idCasello, int parziale) {
      this.totali[idCasello] += parziale;
    }

    // idCasello attende che il pagamento del totale sia avvenuto. Accumula i vari
    // pagamenti parziali e esce solamente quando il totale è stato raggiunto.
    // Viene invocato una volta sola e esce solo quando il totale è stato raggiunto
    // Quando il pagamento è effettuato da' il via libera all'auto.
    public synchronized void incassa(int idCasello, int totale) throws InterruptedException {
      while(this.totali[idCasello] < totale) {
        wait();
      }
      this.totali[idCasello] = 0;
      pedaggio[idCasello] = true;
      notifyAll();
    } 

    // Attende l'OK dell'avenuto pagamento prima di superare il casello.
    // Quando ha il via libera procede.
    public synchronized void attendiOK(int idCasello) throws InterruptedException {
      while(!pedaggio[idCasello]) {
        wait();
      }
      pedaggio[idCasello] = false;
    }
}
