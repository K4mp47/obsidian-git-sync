/*
 * COMMENTO GENERALE:
 *
 * Illustrare la soluzione proposta spiegando accuratamente:
 * - Come si è arrivati a scegliere le strutture dati utilizzate per la sincronizzazione
 * - Come funziona, intuitivamente, la sincronizzazione
 * - Come sono state utilizzate le wait e le notify / notifyAll
 *
 * Commentare, inoltre, accuratamente il codice delle funzioni.
 *
 * Una consegna è insufficiente se:
 * - non funziona (anche se commentata accuratamente)
 * - i commenti sono assenti / scarsi / non accurati
 * - realizza la sincronizzazione in modo non chiaro o inutilmente complesso
 */

public class CodaPoste {

    private int X, Y;       // dimensioni dell'ufficio
    private int N_SPORTELLI;  // numero di sportelli
    
    private boolean[][] persona;
    private boolean[] occupato;

    public CodaPoste(int x, int y, int n_sportelli) {
        this.X = x;
        this.Y = y;
        persona = new boolean[X][Y];
        this.N_SPORTELLI = n_sportelli;
        occupato = new boolean[N_SPORTELLI];
    }

    // si muove da x,y a nx,ny. Se nx,ny è occupato attende altrimenti
    // occupa nx,ny e libera x,y.
    public synchronized void move(int x, int y, int nx, int ny) throws InterruptedException {
      while(persona[nx][ny])
        wait();

      persona[nx][ny] = true;
      libera(x,y);
    }

    // libera la posizione x,y (invocata quando l'utente esce dall'ufficio)
    public synchronized void libera(int x, int y) {
      persona[x][y] = false;

      notifyAll();
    }

    // restituisce l'indice dello sportello libero, -1 se non c'è nessuno  
    private int spLibero() {
      for(int i = 0; i < N_SPORTELLI; i++){
        if(!occupato[i])
          return i;
      }
      return -1;
    }

    // La persona è la prossima ad essere servita e attende che si liberi uno sportello.
    // Nel caso ci sia almeno uno sportello libero, occupa il primo disponibile e ne
    // ritorna l'indice.
    public synchronized int attendiSportello() throws InterruptedException {
      int a = -1;
      while((a=spLibero()) == -1){
        wait();
      }
    
      occupato[a] = true;
      return a; // da modificare opportunamente
    }

    // La persona ha raggiunto lo sportello, ha fruito del servizio e ora lo libera
    public synchronized void liberaSportello(int id) {
      occupato[id] = false;

      notifyAll();
    } 
}
