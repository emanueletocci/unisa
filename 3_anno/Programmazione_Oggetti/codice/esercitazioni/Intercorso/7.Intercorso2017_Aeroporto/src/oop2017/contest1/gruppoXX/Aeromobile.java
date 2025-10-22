/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package oop2017.contest1.gruppoXX;

/**
 *
 * @author emanueletocci
 */
public abstract class Aeromobile {
    private String codice;
    private int numeroSequenziale;
    private static int allocati=0;
    
    public Aeromobile(String codice){
        this.codice = codice;
        allocati++;
        numeroSequenziale = allocati;
    }
    
    public String getCodice(){
        return codice;
    }
    
    @Override
    public String toString(){
        return "\nAeromobile n." + numeroSequenziale + " - Codice = " + codice;
    }
    
    public int getNumeroSequenziale(){
        return numeroSequenziale;
    }
}
