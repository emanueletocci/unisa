/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop;

/**
 *
 * @author emanueletocci
 */
public class Autovettura extends Veicolo{
    private int numeroPosti;

    public Autovettura(String numTelaio, String modello, String alimentazione, String targa, int numeroPosti) {
        super(numTelaio, modello, alimentazione, targa);
        this.numeroPosti = numeroPosti;
    }

    public int getNumeroPosti() {
        return numeroPosti;
    }
    
    @Override
    public boolean controllaTarga(){
        return super.getTarga().matches("^[A-Za-z]{2}[0-9]{3}[A-Za-z]{2}");
    }
    
    @Override
    public String toString(){
        return super.toString() + ", Posti: " + numeroPosti;
    }
}
