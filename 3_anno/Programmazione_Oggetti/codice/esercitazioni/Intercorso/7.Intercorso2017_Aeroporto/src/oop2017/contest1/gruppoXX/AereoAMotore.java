/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package oop2017.contest1.gruppoXX;

/**
 *
 * @author emanueletocci
 */
public class AereoAMotore extends Aeromobile{
    private int numRotori;
    
    public AereoAMotore(String codice, int numRotori){
        super(codice);
        this.numRotori = numRotori;
    }
    
    public int getNumRotori(){
        return numRotori;
    }
    @Override
    public String toString(){
        return super.toString() + " -Tipo = Aereo a motore - Numero rotori = " + numRotori ;
    }
}
