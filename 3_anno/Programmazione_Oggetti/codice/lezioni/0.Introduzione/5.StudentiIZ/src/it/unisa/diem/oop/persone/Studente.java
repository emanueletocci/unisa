/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.persone;

/** ECCEZIONE NON CONTROLLATA
 *
 * @author lucagreco
 */
public class Studente extends PersonaUnisa {
    
    
    private float votoMedio;
    
    
    public Studente (String nome, String cognome, String codiceFiscale, String matricola, float votoMedio) {
    
        super(nome,cognome,codiceFiscale,matricola);
        
        if(votoMedio < 18) throw new VotoNonConsentitoException("voto medio non consentito.");
        
        this.votoMedio = votoMedio;
  
    
    }
    
    public float getVotoMedio() {
    
    
        return this.votoMedio;
    
    }
    
    @Override
    public String toString() {
    
        return super.toString() + " " + this.votoMedio;
    
    
    }

    @Override
    public String getRuolo() {
        
        return "Studente";
        
         }
    
}
