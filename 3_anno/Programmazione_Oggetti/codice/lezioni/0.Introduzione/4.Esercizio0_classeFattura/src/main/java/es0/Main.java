package es0;

/* per usare classi in package differenti occorre importare il package che contiene la
 *  classe o specificare il nome completo della classe: it.unisa.diem.oop.gestionemagazzino.Fattura
 *
 */

import it.unisa.diem.oop.gestionemagazzino.Fattura;
import it.unisa.diem.oop.gestionemagazzino.Prodotto;

public class Main {
    public static void main(String[] args) {
        Prodotto p0 = new Prodotto(0, "matita", 1F);
        Prodotto p1 = new Prodotto(1, "penna", 2F);
        Prodotto p2 = new Prodotto(2, "gomma", 1.5F);
        Prodotto p3 = new Prodotto(3, "compasso", 5F);
        Prodotto p4 = new Prodotto(4, "righello", 1.3F);

        Fattura f0 = new Fattura(1, "Giovanni", p0);
        f0.setProdottoFattura(p3);
        f0.setProdottoFattura(p4);
        f0.setProdottoFattura(p4);
        f0.setProdottoFattura(p1);
        f0.setProdottoFattura(p4);  //non inserito in quanto vettore già pieno

        Fattura f1 = new Fattura(2, "Michele", p1);
        f1.setProdottoFattura(p2);
        f1.setProdottoFattura(p4);

        Fattura f2 = new Fattura(3, "Antonio", p2);
        f2.setProdottoFattura(p1);
        f2.setProdottoFattura(p4);
        f2.setProdottoFattura(p3);

        Fattura f3 = new Fattura(4, "Giorgia", p3);
        f3.setProdottoFattura(p2);

        Fattura f4 = new Fattura(5, "Giovanni", p4);

        f0.stampaFattura();
        f1.stampaFattura();
        f2.stampaFattura();
        f3.stampaFattura();
        f4.stampaFattura();
   }
}