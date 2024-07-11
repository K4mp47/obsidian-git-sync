import java.lang.Math;

class Porta {
  private int numComponenti; // numero di componenti
  private int numColori = 3; // numero di colori
  private boolean aperta = false;
  private int lastEntered;
  private int currentColor = -1;
  private boolean lock = false;

  public Porta(int numComponenti) {
    this.numComponenti = numComponenti;
    this.lastEntered = 0;
  }
  
  public synchronized void entra(int col, int num) throws InterruptedException {
    if(num == 0){
      while(lock){
        wait();
      }
      currentColor = col;
      lock = true;
    } else {
      while(currentColor != col || lastEntered+1 != num){
        wait();
      }
      lastEntered = num;
      if(lastEntered == numComponenti-1){
        lock = false;
        lastEntered = 0;
      }
      notifyAll();
    }
  }

  public synchronized void attendi() throws InterruptedException {
    while (!aperta)
      wait(); // attende che la porta venga aperta
  }
  
  public synchronized void apri() {
    aperta = true;
    notifyAll(); // sveglia tutti i thread in attesa 
  }
}

class Test extends Thread {
  private static final String colori[]={"Rosso","Bianco","Verde","Blu"}; // colori
  private static final int numColori = colori.length; // quanti colori/squadre ci sono
  private static final int numComponenti =10; // numero componenti
  private final int col, num; // colore e numero del giocatore
  private final Porta porta; // monitor utlizzato dal giocatore
   
  // costruttore: salva colore numero e monitor
  Test(int col,int num, Porta porta) {
    this.col = col;
    this.num = num;
    this.porta = porta;
  }
   
  // lancia il codice vero e proprio e cattura l'eccezione di interruzione
  public void run() {
    try {
      code();
    } catch (InterruptedException e) {
      System.out.println("Componente "+colori[col]+" numero "+num+" interrotto!!");
    }
  }
   
  // codice dei thread
  void code() throws InterruptedException {
    // evita che i thread siano gia' in fila
    sleep((int)(1000*Math.random()));
     
    // il giocatore e' pronto
    System.out.println("Componente "+colori[col]+" numero "+num+" pronto!");
     
    // attende che la porta venga aperta dal main
    porta.attendi();
     
    // cerca di entrare
    porta.entra(col,num);
     
    // attenzione che questo output non e' sincronizzato con entra.... quindi non e' detto
    // che venga stampato nell'ordine corretto. Aggiungere un blocco synchonized(porta){ } 
    // se necessario
    System.out.println("Componente "+colori[col]+" numero "+num+" e' entrato!");
     
  }
   
  public static void main(String argv []) throws InterruptedException {
    int i,j;
     
    Porta p = new Porta(numComponenti); // crea il monitor
     
    // crea i thread dei vari colori/numeri
    for (i=0; i<numColori; i++)
      for (j=0; j<numComponenti; j++) {
        (new Test(i,j,p)).start();
      }
   
    // attende 3 secondi prima di aprire la porta (tutti i thread devono attendere)
    sleep(3000);
    p.apri();
    System.out.println("La porta e' aperta!!");
  }
   
}
