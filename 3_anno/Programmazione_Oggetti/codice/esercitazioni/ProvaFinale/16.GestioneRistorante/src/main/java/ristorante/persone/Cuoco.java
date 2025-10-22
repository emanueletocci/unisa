package ristorante.persone;

import ristorante.Ordinazione;
import ristorante.Comande;
import java.util.Random;

public class Cuoco implements Runnable{
    private String nome;
    private final Comande comande;

    public Cuoco(Comande comande){
        this.comande = comande;
    }

    @Override
    public void run(){
        Random generator = new Random();
        while (!Thread.currentThread().isInterrupted()) {
            Ordinazione ordine = comande.consegnaOrdinazione();
            try {
                Thread.sleep(generator.nextInt(5000) + 5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("\nPiatto Pronto: " + ordine);
        }
    }
}
