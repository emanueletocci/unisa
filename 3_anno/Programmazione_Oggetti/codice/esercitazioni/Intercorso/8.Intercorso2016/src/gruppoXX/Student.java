/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gruppoXX;

/**
 *
 * @author emanueletocci
 */
public class Student extends Person{
    private final String matricola;
    
    public Student(String name, String surname, String matricola, int year, int month, int dayOfMonth){
        super(name,surname,year,month,dayOfMonth);
        this.matricola = matricola;
    }
    
    public String getMatricola(){
        return matricola;
    }
    
    @Override
    public String toString(){
        return super.toString() + "Matricola = " + matricola;
    }
    
}
