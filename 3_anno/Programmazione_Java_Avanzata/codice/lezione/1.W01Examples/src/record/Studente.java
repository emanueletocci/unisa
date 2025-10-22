/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Record.java to edit this template
 */
package record;

/**
 *
 * @author lucagreco
 */
public record Studente(String nome, String cognome, String matricola) {
    
    private static int count = 0;
    
    /*
    public Studente(String nome, String cognome, String matricola) { // costruttore canonico
    
        if(!matricola.matches("[0-9]{9}")) throw new IllegalArgumentException("Matricola non valida");
        
        this.nome = nome;
        this.cognome = cognome;
        this.matricola = matricola;
    
    }
    */
    
    public Studente {
    
         if(!matricola.matches("[0-9]{9}")) throw new IllegalArgumentException("Matricola non valida");
        
    
    }
    
    public Studente(String nome, String cognome, CorsoDiStudi cds){
    
        this(nome,cognome, cds.getPrefisso() + String.format("%04d", ++count));
    
    
    }
    

}
