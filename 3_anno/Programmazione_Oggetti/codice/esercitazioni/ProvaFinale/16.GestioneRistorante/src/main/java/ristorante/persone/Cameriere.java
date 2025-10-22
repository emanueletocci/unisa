package ristorante.persone;
import ristorante.Comande;
import ristorante.Menu;
import ristorante.Ordinazione;

import java.util.Random;

public class Cameriere implements Runnable {
    private String nome;
    Comande comande;

    public Cameriere(String nome, Comande comande){
        this.nome = nome;
        this.comande = comande;
    }

    @Override
    public void run(){
        Menu menu = new Menu();
        Random generator = new Random();
        while(!Thread.currentThread().isInterrupted()) {
            int tavolo = generator.nextInt(4) + 1;
            int quantita = generator.nextInt(3) + 1;
            String piatto = menu.getPiatto();
            Ordinazione ordine = new Ordinazione(piatto, tavolo, quantita);
            try {
                Thread.sleep(generator.nextInt(5000) + 5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            comande.aggiungiOrdinazione(ordine);
            System.out.println("\nOrdinazione presa da " + nome + ": " + ordine);
        }
    }
}
