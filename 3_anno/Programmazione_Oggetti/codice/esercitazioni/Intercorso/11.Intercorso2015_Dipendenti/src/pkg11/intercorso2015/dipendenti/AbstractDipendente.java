/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg11.intercorso2015.dipendenti;

/**
 *
 * @author emanueletocci
 */
public abstract class AbstractDipendente implements Dipendente{
    private String nome;
    private int matricola;
    
    public AbstractDipendente(int matricola){
        this.matricola = matricola;
    }
    
    public AbstractDipendente(String nome,int matricola){
        this.matricola = matricola;
        this.nome = nome;
    }
    
    @Override
    public String getNome() {
        return nome;
    }
    
    @Override
    public int getMatricola() {
        return matricola;
    }
    
    @Override
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    @Override
    public void setMatricola(int matricola) {
        this.matricola = matricola;
    }
    
    @Override
    public int hashCode(){
        Integer mat = matricola;
        return mat.hashCode();
    }
    @Override
    public String toString(){
        return "\n***\nNome: " + nome + "\nMatricola: " + matricola;
    }
    
    @Override
    public boolean equals (Object obj){
        if(obj == null) return false;
        if (this == obj) return true;
        if (this.getClass() != obj.getClass()) return false;
        Dipendente d = (Dipendente) obj;
        return d.getMatricola() == d.getMatricola();
    }
}
