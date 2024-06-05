class Filosofo extends Thread {
    static final int NTHREAD=5;             // numero di filosofi
    final int index; // indice locale del filosofo
    Tavola m;        // il monitor condiviso  

    // il filosofo memorizza il proprio indice e il monitor condiviso
    Filosofo(int index, Tavola m) {
        this.index = index;
        this.m = m;
    }
    
    // il thread esegue il codiceFilosofo a meno di interruzioni
    public void run()  {
        try { 
            codiceFilosofo(index);
        } catch (InterruptedException e) {
            System.out.println("Il filosofo "+index+" e' stato interrotto");
        }
    }
    // il filosofo pensa e mangia come al solito
    void codiceFilosofo(int index) throws InterruptedException {
        while(true) {
            // PENSA 
            System.out.println("Filosofo " + index +" pensa");
            //Thread.sleep(1000);
            m.raccogli_entrambe(index);
            //m.raccogli_sx(index); // raccoglie la bacchetta sinistra
            //m.raccogli_dx(index); // raccoglie la bacchetta destra
            
            //MANGIA
            System.out.println("Filosofo " + index +" mangia");
            //Thread.sleep(2000);
            m.deposita_entrambe(index);
            //m.deposita_sx(index); // deposita la bacchetta sinistra
            //m.deposita_dx(index); // deposita la bacchetta destra
        }
    }
    public static void main(String args[]) throws InterruptedException {
        int index;
        Tavola m = new Tavola(NTHREAD); // crea il monitor condiviso 

        // crea NTHREAD filosofi e li esegue
        for(index=0;index<NTHREAD;index++) {
            // Crea il filosofo con indice 'index' e lo esegue
            new Filosofo(index, m).start();
        }
        // esce lasciando i filosofi al loro destino
    }
}

class Tavola {
    private boolean bacchette[]; // le bacchette
    private final int NFIL;      // il numero di filosofi
    // crea le NFIL bacchette e le inizializza a true (presenti)
    // NOTA: non serve sincronizzarlo e' prima della creazione dei filosofi
    Tavola(int NFIL) { 
        int i;
        this.NFIL=NFIL;                 // memorizza il numero dei filosofi
        bacchette = new boolean[NFIL];  // crea le bacchette
        for (i=0;i<NFIL;i++)    // inizializza le bacchette a true
            bacchette[i] = true;
    }
    // raccoglie la bacchetta sinistra
    synchronized void raccogli_sx(int index) throws InterruptedException {
      while(!bacchette[index]) {
        wait();
      }
    }
    // raccoglie la bacchetta destra
    synchronized void raccogli_dx(int index) throws InterruptedException {
        raccogli_sx((index+1)%NFIL); // la dx e' sx del filosofo successivo
    }   
    // deposita la bacchetta sinistra e notifica TUTTI i filosofi
    synchronized void deposita_sx(int index) {
        bacchette[index] = true;
        notifyAll(); 
    }
    // deposita la bacchetta destra e notifica TUTTI i filosofi
    synchronized void deposita_dx(int index) {
        deposita_sx((index+1)%NFIL); // la dx e' sx del filosofo successivo
        notifyAll();
    }   

    synchronized void raccogli_entrambe(int index) throws InterruptedException {
        raccogli_sx(index);
        raccogli_dx(index);
    }

    synchronized void deposita_entrambe(int index) {
        deposita_sx(index);
        deposita_dx(index);
    }
}
