/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop.aeroproject.aerei;

/**
 *
 * @author emanueletocci
 */
public class AereoAMotore extends Aeromobile{
    private final int numRotori;
    
    public AereoAMotore(String codice, int numRotori) {
        super(codice);
        this.numRotori = numRotori;
    }

    public int getNumRotori() {
        return numRotori;
    }
    
    @Override
    public String toString(){
        return super.toString() + " - Tipo = Aereo a motore - Numero rotori = " + numRotori;
    }
    
}
