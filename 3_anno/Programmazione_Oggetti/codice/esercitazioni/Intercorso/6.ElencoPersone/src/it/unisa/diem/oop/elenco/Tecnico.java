/* IMPORT DA COMPLETARE*/
package it.unisa.diem.oop.elenco;
import java.time.LocalDate;

public class Tecnico extends Persona {
    private final String dipartimento;
    
    public Tecnico(String nome, LocalDate dataNascita, String codiceFiscale, String dipartimento) {
        super(nome, dataNascita, codiceFiscale);
        this.dipartimento = dipartimento;
    }
    
    @Override
    public String toString(){
        return super.toString() + "\nDipartimento: " + dipartimento;
    }
    
    public String getDipartimento(){
        return dipartimento;
    }
}
