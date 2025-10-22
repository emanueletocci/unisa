/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gruppoXX;
import java.time.LocalDate;

/**
 *
 * @author emanueletocci
 */

public class Person implements Comparable<Person>{
    private LocalDate birthDate;
    private final String name;
    private final String surname;
    
    public Person(String name, String surname, int year, int month, int dayOfMonth){
        this.name = name;
        this.surname = surname;
        this.birthDate = LocalDate.of(year,month,dayOfMonth);
        
    }
    public String getName(){
        return name;
    }
    public String getSurname(){
        return surname;
    }
    public LocalDate getBirthDate(){
        return birthDate;
    }
    
    @Override
    public String toString(){
        return "\n***\nName = " + name + "\nSurname = " + surname + "\nBirth date = " +birthDate + "\n";
    }

    @Override
    public int compareTo(Person o) {
        return this.getBirthDate().compareTo(o.getBirthDate());
    }

}

