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

public abstract class Prodotto {
    private String codice;
    private String descrizione;
    private double prezzo;
    
    public Prodotto(String codice, String descrizione, double prezzo){
        this.codice = codice;
        this.descrizione = descrizione;
        this.prezzo = prezzo;
    }
    public String getCodice(){
        return this.codice;
    }
    public double getPrezzo(){
        return this.prezzo;
    }
    
    public abstract double applicaSconto();
    
    @Override 
    public boolean equals(Object obj){
        if(!(this instanceof Prodotto))
            return false;
        Prodotto p = (Prodotto) obj;
        return this.codice.equals(p.codice);
    }
    
    @Override
    public int hashCode(){
        return codice.hashCode();
    }
    
    @Override
    public String toString(){
        return "\nProdotto:\ncodice=" + codice + "\ndescrizione=" + descrizione + "\nprezzo=" + prezzo;
    }
}
