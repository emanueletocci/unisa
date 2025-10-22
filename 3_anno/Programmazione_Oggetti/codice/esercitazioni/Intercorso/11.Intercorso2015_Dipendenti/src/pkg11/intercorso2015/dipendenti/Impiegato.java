/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg11.intercorso2015.dipendenti;

/**
 *
 * @author emanueletocci
 */
public class Impiegato extends AbstractDipendente{
    private String sede;
    
    public Impiegato(int matricola){
        super(matricola);
    }
    
    public Impiegato(String nome, int matricola, String sede){
        super(nome, matricola);
        this.sede = sede;
    }
    
    @Override
    public String toString(){
        return super.toString() + "\nSede: " + sede;
    }

    public String getSede() {
        return sede;
    }

    public void setSede(String sede) {
        this.sede = sede;
    }
            
}
