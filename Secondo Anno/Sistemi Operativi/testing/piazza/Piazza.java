/*
 * Corso di Sistemi Operativi 2021
 * Terza esercitazione: monitor
 *
 * Author: Riccardo Focardi
 *
 * Compilare con: javac Piazza.java
 */

import java.util.Random;
import java.util.HashMap;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;

public class Piazza {
    final static int  N_THREAD=40;
    final static int SLEEPBASE=100;
    final static int N_ITER=20;
    final static Person[] person = new Person[N_THREAD];
    final static String contrade[] =  new String[] {"Bruco","Chiocciola","Aquila","Civetta"};
    private static int flag = 0;
    static Random rand = new Random(44);
    static private HashMap<String,Integer> n_persone = new HashMap<String,Integer>();
    static private HashMap<String,Integer> max_persone = new HashMap<String,Integer>();
    static private HashMap<String,List<String>> conflicts = new HashMap<String,List<String>>();
    static private HashMap<String,List<String>> permitted = new HashMap<String,List<String>>();
    static private List<String> checked = new ArrayList<String>();

    public static void main(String args[]) throws InterruptedException {
        int i,j,k;

        Monitor m = new Monitor();

        for (String kk : contrade) {
            permitted.put(kk,new ArrayList<String>());
        }
        conflicts.put("Bruco",Arrays.asList("Chiocciola", "Aquila", "Civetta"));
        conflicts.put("Chiocciola",Arrays.asList("Bruco", "Civetta"));
        conflicts.put("Aquila",Arrays.asList("Bruco"));
        conflicts.put("Civetta",Arrays.asList("Bruco", "Chiocciola"));

        for (String kk : contrade) {
            for (String p : contrade) {
                if (p != kk && !conflicts.get(kk).contains(p)) {
                    permitted.get(kk).add(p);
                } 
            }
        }
        // System.out.println(permitted);

        for(j=0;j<N_ITER;j++) {
            for (String kk : contrade) {
                max_persone.put(kk,0);
                n_persone.put(kk,0);
            }
            checked = new ArrayList<String>();

            for (i=0;i<N_THREAD;i++) {
                k=rand.nextInt(4);
                person[i] = new Person(j,m,k);
                max_persone.put(contrade[k],max_persone.get(contrade[k])+1);
                person[i].start();
            }
            // System.out.println(max_persone);

            for (String kk : contrade) {
                if (max_persone.get(kk)==0) {
                    System.out.println(String.format("[ERRORE] Nessuna persona %s!",kk));
                    System.exit(1);
                }
            }

            for (i=0;i<N_THREAD;i++) {
                person[i].join();
            }
        }
        System.out.println(String.format("Terminato, flag=%06x",flag));
    }

    static class Person extends Thread {
        String contrada;
        Monitor m;
        int j;

        Person(int j,Monitor m, int k) {
            this.contrada = contrade[k];
            this.m = m;
            this.j = j;
            flag = (flag + (k*(rand.nextInt(16777216))))%16777216;
        }

        public void run() {
            try {
                go();
            } catch (InterruptedException e) {
                System.out.println(String.format("Persona %s interrotta!",contrada));
            }
        }

        public void go() throws InterruptedException {
            // System.out.println(String.format("Saluti dal thread di tipo %s", this.contrada));
            // m.test1();


            synchronized(m) {
                m.entra(contrada);
                System.out.println(String.format("[%s] entra in piazza", this.contrada));

                n_persone.put(contrada,n_persone.get(contrada)+1);

                for (String k : conflicts.keySet()) {
                    if (n_persone.get(k)>0) {
                        for (String c : conflicts.get(k)) {
                            if (n_persone.get(c)>0) {
                                System.out.println(String.format("[ERRORE] %s assieme a %s",k,c));
                                System.out.println(String.format("Stato: %s",n_persone));
                                System.out.println(String.format("Iterazione: %d",j));

                                System.exit(1);
                            }
                        }
                    }
                }
            }

            sleep(SLEEPBASE);

            synchronized(m) {
                m.esce(contrada);
                if (!permitted.get(contrada).isEmpty() 
                    && !checked.contains(contrada) 
                    && n_persone.get(contrada) == max_persone.get(contrada)) 
                {
                    boolean ok=false;
                    for (String k : permitted.get(contrada)) {
                        if (n_persone.get(k)==max_persone.get(k)) {
                            ok=true;
                            checked.add(k);
                        }
                    }
                    if (!ok) {
                        ok=true;
                        for (String k : permitted.get(contrada)) {
                            if (!checked.contains(k)) {
                                ok=false;
                                break;
                            }
                        }
                    }
                    if (!ok) {
                        System.out.println(String.format("[ERRORE] uno di %s non è entrato insieme a %s!",permitted.get(contrada), contrada));
                        System.out.println(String.format("Stato: %s",n_persone));
                        System.out.println(String.format("Iterazione: %d",j));

                        System.exit(1);
                    }
                    checked.add(contrada);
                }
                n_persone.put(contrada,n_persone.get(contrada)-1);
            }

            System.out.println(String.format("[%s] esce dalla piazza", this.contrada));
        }
    }
}

/*
 * @author: Campagnolo Alberto Matricola 897569
 * @version: 0.1
 * @descrition: La funzione controlla all'interno del while se 
 *              possono entrare in piazza o meno le rispettive contrade
 *              se non possono le mette in attesa
 *              utilizza un contatore per controllare quante persone 
 *              di una contrada entrano.
 *
 * */

class Monitor {
    // La contrada Aquila 1 non vuole incontrare Bruco
    // La contrada Chiocciola 2 non vuole incontrare né Bruco né Civetta
    // La contrada Civetta 3 non vuole incontrare né Bruco né Chiocciola
    // La contrada Bruco 4 non vuole incontrare nessun altra contrada
    
    // crea una mappa con le contrade e il numero corrispettivo  
    private HashMap<String,Integer> contrade = new HashMap<String,Integer>();
    // crea un array di quattro booleani per tenere traccia delle contrade che sono in Piazza
    private int[] inPiazza = new int[4];
    
    Monitor() {
      contrade.put("Aquila",1); 
      contrade.put("Chiocciola",2);
      contrade.put("Civetta",3);
      contrade.put("Bruco",4);
      // inizializza inPiazza tutto a zero
    }

    synchronized void entra(String contrada) throws InterruptedException {
      // controlla se la contrada può entrare in Piazza
      // se non può, aspetta
      // la contrada è Aquila entra se Bruco non è in Piazza
      // la contrada è Chiocciola entra se Bruco e Civetta non sono in Piazza
      // la contrada è Civetta entra se Bruco e Chiocciola non sono in Piazza 
      // la contrada è Bruco entra sempre
      while(contrada == "Aquila" && inPiazza[contrade.get("Bruco")-1] != 0 ||
            contrada == "Chiocciola" && inPiazza[contrade.get("Bruco")-1] != 0 || inPiazza[contrade.get("Civetta")-1] != 0 ||
            contrada == "Civetta" && inPiazza[contrade.get("Bruco")-1] != 0 || inPiazza[contrade.get("Chiocciola")-1] != 0 ||
            contrada == "Bruco" && inPiazza[contrade.get("Aquila")-1] != 0 || inPiazza[contrade.get("Chiocciola")-1] != 0 || inPiazza[contrade.get("Civetta")-1] != 0
      )
      {
        wait();
      }
      // la contrada entra in Piazza
      inPiazza[contrade.get(contrada)-1]++;
    }

    synchronized void esce(String contrada) {
      // la contrada esce dalla Piazza
      // notifica a tutti i thread in attesa
      inPiazza[contrade.get(contrada)-1]--;
      // notifica a tutti i thread in attesa
      notifyAll();  
    }
}

