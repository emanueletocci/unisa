/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop.aeroproject.aerei;

/**
 *
 * @author emanueletocci
 */
public abstract class Aeromobile implements Cloneable {
    private final String codice;
    private int numeroSequenziale;
    private static int counter = 0;

    public Aeromobile(String codice) {
        this.codice = codice;
        counter ++;
        numeroSequenziale = counter;
    }

    public String getCodice() {
        return codice;
    }

    public int getNumeroSequenziale() {
        return numeroSequenziale;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone(); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/OverriddenMethodBody
    }
    
    

    @Override
    public String toString() {
        return "\nAeromobile n. " + numeroSequenziale + " - Codice = " + codice;
    }
    
}
