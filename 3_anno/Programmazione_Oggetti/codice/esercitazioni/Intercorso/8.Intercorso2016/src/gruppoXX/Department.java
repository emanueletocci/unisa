/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gruppoXX;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

/**
 *
 * @author emanueletocci
 */
public class Department implements Sortable, Filterable{
    List<Person> people;
    
    public Department(){
        people = new LinkedList<>();
    }
    @Override
    public void sort(){
        people.sort(null);
    }
    @Override
    public String toString(){
        return "\n" + people;
    }
    public void add(Person person) {
        people.add(person);
    }
    
    @Override
    public List<Person> filter(PersonFilter f) {
        List<Person> filteredList = new LinkedList<>();
        for (Person person : people) {
            if (f.checkPerson(person)) {
                filteredList.add(person);
            }
        }
        return filteredList;
    }
}
