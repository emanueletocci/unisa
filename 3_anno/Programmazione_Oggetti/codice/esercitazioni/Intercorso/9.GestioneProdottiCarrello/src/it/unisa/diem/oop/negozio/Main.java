/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package it.unisa.diem.oop.negozio;
import java.time.LocalDate;

/**
 *
 * @author emanueletocci
 */

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here\
        Carrello carr = new Carrello();
        double totale=0, scontato=0;
        
        carr.addProdotto(new ProdottoAlimentare("1", "latte", 2.4, LocalDate.of(2024, 10, 23)));
        carr.addProdotto(new ProdottoAlimentare("2", "formaggio", 4.5, LocalDate.of(2024, 11, 2)));
        carr.addProdotto(new ProdottoNonAlimentare("3", "fogli", 4.2, "carta"));
        carr.addProdotto(new ProdottoNonAlimentare("4", "bottiglia", 3.4, "vetro"));
        carr.addProdotto(new ProdottoAlimentare("5", "tonno", 6.1, LocalDate.of(2050, 10, 30)));
        carr.addProdotto(new ProdottoNonAlimentare("6", "scatola", 2.6, "polistirolo"));
        carr.addProdotto(new ProdottoNonAlimentare("7", "sedia", 20.9, "plastica"));
        carr.addProdotto(new ProdottoAlimentare("8", "mozzarella", 4.7, LocalDate.of(2021,10,28)));
        carr.addProdotto(new ProdottoNonAlimentare("9", "marsupio", 10.8, "cotone"));
        
        // Calcolo del prezzo totale
        totale = carr.getTotale();
        
        // Calcolo del prezzo scontato
        scontato = carr.getTotaleScontato();
        
        // Stampa dello scontrino (contenuto del Carrello)
        System.out.println("\n Scontrino (Contenuto del carrello)");
        System.out.println(carr.toString());
    }
    
}
