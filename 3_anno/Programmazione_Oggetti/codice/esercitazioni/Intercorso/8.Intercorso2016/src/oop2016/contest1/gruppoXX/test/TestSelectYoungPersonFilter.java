/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package oop2016.contest1.gruppoXX.test;

//ATTENZIONE: SOSTITUIRE NEL SEGUENTE IMPORT XX CON IL CODICE DEL PROPRIO GRUPPO

import gruppoXX.Person;
import gruppoXX.SelectYoungPersonFilter;
import gruppoXX.Student;


/**
 *
 * @author Gennaro
 */
public class TestSelectYoungPersonFilter {
    
        public static void main(String[] args){
        
        SelectYoungPersonFilter filter = new SelectYoungPersonFilter(1995,1,1);
        Person p; 
                
        // Test persona nata dopo l'1/1/1995
        p = new Person("Matteo", "Baldi", 1998, 4, 1);
        System.out.println(p);
        if(!filter.checkPerson(p))
            System.out.print(" non ");
        System.out.println(" e' una Young Person");

        
        // Test persona nata prima l'1/1/1995
        p = new Student("Luca", "Rossi", "0612708762", 1993, 7, 11);
        System.out.println(p);
        if(!filter.checkPerson(p))
            System.out.print(" non ");
        System.out.println(" e' una Young Person");

    }

}
