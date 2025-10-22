package es0;

import it.unisa.diem.oop.gestionemagazzino.Fattura;
import it.unisa.diem.oop.gestionemagazzino.Prodotto;

public class MainFattura {
    public static void main(String[] args) {
        Fattura f = new Fattura(35, "Fattura di Giovanni");

        //Relazione tra classi - Aggregazione
        Prodotto p = new Prodotto(5, "Compasso", 10F);
        f.setProdottoFattura(p);
        f.setProdottoFattura(new Prodotto(1, "Matita", 1F));
        f.setProdottoFattura(new Prodotto(2, "Penna", 1.3F));
        f.setProdottoFattura(new Prodotto(3, "Gomma", 1.5F));
        f.setProdottoFattura(new Prodotto(4, "Righello", 1.2F));
        f.stampaFattura();
    }
}
