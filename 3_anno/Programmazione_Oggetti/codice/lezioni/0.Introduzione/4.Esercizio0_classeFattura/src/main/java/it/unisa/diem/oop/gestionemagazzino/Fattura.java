package it.unisa.diem.oop.gestionemagazzino;
/*
Obiettivo: Implementare una classe Fattura per gestire la vendita di prodotti.

Dettagli della classe:

	    La classe Fattura deve avere:
	•	Una descrizione di tipo stringa.
	•	Un numero identificativo di tipo intero.
	•	Un array di oggetti Prodotto.

	    Funzionalità richieste:

	•	Aggiungere uno alla volta i prodotti all’array all’interno della fattura.
	•	Al termine dell’inserimento dei prodotti, deve essere stampata una
	    rappresentazione della fattura, comprensiva di descrizione, numero identificativo
	    e l’elenco dei prodotti inseriti.
 */
public class Fattura {
    private int idFattura;
    private String descrizioneFattura;
    private Prodotto prodVett[] = new Prodotto[5];
    private int count = 0;         //conteggio "Prodotti" inseriti

    //costruttore esplicito
    public Fattura(int idFattura, String descrizioneFattura, Prodotto prod) {
        this.idFattura = idFattura;
        this.descrizioneFattura = descrizioneFattura;
        setProdottoFattura(prod);
    }

    public Fattura(int idFattura, String descrizioneFattura) {
        this.idFattura = idFattura;
        this.descrizioneFattura = descrizioneFattura;
    }

    public void setProdottoFattura(Prodotto prod) {
        if (count == prodVett.length) {
            return;
        }
        prodVett[count++] = prod;
    }

    public void stampaFattura() {
        System.out.println("Fattura n." + idFattura);
        System.out.println("Descrizione fattura: " + descrizioneFattura);
        for (int i = 0; i < count; i++) {
            prodVett[i].stampaInfoProdotto();
        }
    }
}
