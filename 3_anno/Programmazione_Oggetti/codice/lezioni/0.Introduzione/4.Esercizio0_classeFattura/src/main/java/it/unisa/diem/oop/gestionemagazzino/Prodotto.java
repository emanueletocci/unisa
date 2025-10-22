package it.unisa.diem.oop.gestionemagazzino;

public class Prodotto {

    private final int codiceProdotto;
    private String descrizioneProdotto;
    private float costoProdotto;
    public static int contegigoProdotti;    //static = attributo di classe, variabili comune a tutti gli oggetti della classe

    public void stampaInfoProdotto() {
        System.out.println("Codice: " + codiceProdotto + ", Descrizione: " + descrizioneProdotto + ", Costo: " + costoProdotto + " €");
    }

    public Prodotto(){  //costruttore senza parametri (default)
        this.codiceProdotto = 0; //gli attributi final vanno inizializzati manualmente
    }

    public Prodotto(int codiceProdotto){    //alternativa al costruttore con 1 parametro
        this.codiceProdotto = codiceProdotto;
    }

    public Prodotto(float costoProdotto){
        this.codiceProdotto = 0;
        this.costoProdotto = costoProdotto;
    }
    public Prodotto(int codiceProdotto, String descrizioneProdotto, float costoProdotto) { //costruttore con parametri
        this.codiceProdotto = codiceProdotto;
        this.descrizioneProdotto = descrizioneProdotto;
        this.costoProdotto = costoProdotto;
    }

    //get functions
    public int getCodiceProdotto() {
        return this.codiceProdotto;
    }
    public String getDescrizioneProdotto() {
        return this.descrizioneProdotto;
    }
    public float getCostoProdotto() {
        return this.costoProdotto;
    }
}
