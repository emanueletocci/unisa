/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop.negozio;
import java.time.LocalDate;

/**
 *
 * @author emanueletocci
 */
public class ProdottoNonAlimentare extends Prodotto{
    private String materiale;
    public ProdottoNonAlimentare(String codice, String descrizione, double prezzo, String materiale) {
        super(codice, descrizione, prezzo);
        this.materiale = materiale;
    }
    
    public boolean isRiciclabile(){
        if (materiale.equals("carta") || materiale.equals("vetro") || materiale.equals("cotone"))
            return true;
        return false;
    }
    
    @Override
    public String toString(){
        return "\n" + super.toString() + "\nMateriale = " + materiale;
    }
    
    @Override 
    public double applicaSconto(){
        double prezzo = super.getPrezzo();
        if(this.isRiciclabile())
            return prezzo - (10.0F/100.0F * prezzo);
        return prezzo;
    }
}
