/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.spazi;

/**
 *
 * @author lucagreco
 */
public abstract class Spazio implements Accessibile {
    
    
    private String nome;
    private int maxPosti;
    
  
    public Spazio(String nome, int maxPosti) {
    
    
        this.nome = nome;
        this.maxPosti = maxPosti;
    
    }
    
    public String getNome() {
    
        return this.nome;
    
    
    }
    
    public int getMaxPosti() {
    
        return this.maxPosti;
    
    }
    
    public abstract String getTipo();
    
    @Override
    public String toString() {
    
        return this.getTipo() + ": " + this.nome + " capienza: " + this.maxPosti;
    
    }
    
}
