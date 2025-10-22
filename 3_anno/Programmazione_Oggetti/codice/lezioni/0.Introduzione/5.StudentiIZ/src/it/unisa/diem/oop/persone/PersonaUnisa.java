/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.persone;

/**
 *
 * @author lucagreco
 */
public abstract class PersonaUnisa extends Persona {
    
    private String matricola;
    
    
    public PersonaUnisa(String nome, String cognome, String codiceFiscale, String matricola) {
    
        super(nome,cognome,codiceFiscale);
        
        this.matricola = matricola;
    
    
    }
    
    public abstract String getRuolo() ;
    
    
    
    public String getMatricola() {
        
        
        return this.matricola;
    
    }
    
    @Override
    public String toString() {
    
        return this.getRuolo() +  " -> " + super.toString() + " " + this.matricola;
    
    }
    
    
}
