/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop;

/**
 *
 * @author emanueletocci
 */
public class Camion extends Veicolo {
    private int numeroAssi;

    public Camion(String numTelaio, String modello, String alimentazione, String targa, int numeroAssi) {
        super(numTelaio, modello, alimentazione, targa);
        this.numeroAssi = numeroAssi;
    }

    public int getNumeroAssi() {
        return numeroAssi;
    }
    
    @Override
    public boolean controllaTarga(){
        return super.getTarga().matches("^[A-Za-z]{2}[0-9]{6}");
    }
    
    @Override
    public String toString(){
        return super.toString() + ", Assi: " + numeroAssi;
    }
}
