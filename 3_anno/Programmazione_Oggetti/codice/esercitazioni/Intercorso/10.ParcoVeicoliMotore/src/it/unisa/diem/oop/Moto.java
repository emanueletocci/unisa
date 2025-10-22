/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop;

/**
 *
 * @author emanueletocci
 */
public class Moto extends Veicolo{
    private boolean guidaLibera;

    public Moto(String numTelaio, String modello, String alimentazione, String targa, boolean guidaLibera) {
        super(numTelaio, modello, alimentazione, targa);
        this.guidaLibera = guidaLibera;
    }

    public boolean isGuidaLibera() {
        return guidaLibera;
    }
    
    @Override
    public boolean controllaTarga(){
        return super.getTarga().matches("^[A-Za-z]{2}[0-9]{5}");
    }

    @Override
    public String toString() {
        return super.toString() + ", Guida libera: " + guidaLibera; 
    }
    
    
}
