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
    private boolean p_attende = false;

    private boolean p_occupato = false;

    // La persona è la prossima ad essere servita e attende che si liberi 
    // lo sportello. Se la persona è sulla coda prioritaria (priority è
    // true) appena lo sportello si libera la persona può procedere. Se
    // la persona è sulla coda normale (priority è false) la persona
    // attende che non ci siano altre persone in coda prioritaria già
    // in attesa e che lo sportello si liberi. In altre parole, dà 
    // la precedenza a persone in attesa in coda prioritaria.
    synchronized void attendiSportello(boolean priority) 
            throws InterruptedException {
        if (priority) {
            // gestione coda prioritaria
            p_attende = true;

            while(p_occupato)
              wait();

            p_attende = false;
        } else {
            // gestione coda non prioritaria
          while(p_occupato || p_attende)
            wait();
        }
      p_occupato = true;
    }

    // La persona ha raggiunto lo sportello, ha fruito del servizio e ora 
    // lo libera
    public synchronized void liberaSportello() { 
      p_occupato = false;

      notifyAll();
    } 
}
