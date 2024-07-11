

/*
 * COMMENTO GENERALE:
 *
 * Illustrare la soluzione proposta spiegando accuratamente:
 *
 * - Come si è arrivati a scegliere le strutture dati utilizzate 
 * per la sincronizzazione
 *
 * SCRIVERE QUI!
 *
 * - Come funziona, intuitivamente, la sincronizzazione
 *
 * SCRIVERE QUI!
 *
 * - Come sono state utilizzate le wait e le notify / notifyAll
 *
 * SCRIVERE QUI!
 *
 * Commentare, inoltre, accuratamente il codice delle funzioni.
 *
 * Una consegna è insufficiente se:
 * 
 * - non funziona (anche se commentata accuratamente)
 * - i commenti sono assenti / scarsi / non accurati
 * - realizza la sincronizzazione in modo non chiaro o inutilmente complesso
 */

public class CodeMonitor {
    // Dichiarare qui le variabili del monitor
    // Costruttore del monitor
    private int libero = 1;
    private int priorityQueue = 0;
    public CodeMonitor() {
        // Inizializzare qui le variabili del monitor
    }


    // La persona è la prossima ad essere servita e attende che si liberi 
    // lo sportello. Se la persona è sulla coda prioritaria (priority è
    // true) appena lo sportello si libera la persona può procedere. Se
    // la persona è sulla coda normale (priority è false) la persona
    // attende che non ci siano altre persone in coda prioritaria già
    // in attesa e che lo sportello si liberi. In altre parole, dà 
    // la precedenza a persone in attesa in coda prioritaria.
    synchronized void attendiSportello(boolean priority)
            throws InterruptedException {
        if(priority) {
            while(libero == 0){
                priorityQueue++;
                wait();
            } 
            
            libero = 0;
            priorityQueue--;
        } else {
            while(libero == 0 || priorityQueue > 0){
                wait();
            } 
            libero = 0;
        }
    }

    // La persona ha raggiunto lo sportello, ha fruito del servizio e ora 
    // lo libera
    public synchronized void liberaSportello() {
        libero = 1;
        notifyAll();
    }
}
