/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package oop2016.contest1.gruppoXX.test;

//ATTENZIONE: SOSTITUIRE NEL SEGUENTE IMPORT XX CON IL CODICE DEL PROPRIO GRUPPO
import gruppoXX.Person;
import gruppoXX.SelectStudentFilter;
import gruppoXX.Student;
import gruppoXX.Teacher;
import gruppoXX.TeacherType;

/**
 *
 * @author Gennaro
 */
public class TestSelectStudentFilter {

    public static void main(String[] args){
        
        SelectStudentFilter filter = new SelectStudentFilter();
        Person p; 
                
        //Test oggetto Person
        p = new Person("Matteo", "Baldi", 1998, 4, 1);
        System.out.println(p);
        if(!filter.checkPerson(p))
            System.out.print(" non ");
        System.out.println(" e' uno Student");

        
        //Test oggetto Student
        p = new Student("Luca", "Rossi", "0612708762", 1995, 7, 11);
        System.out.println(p);
        if(!filter.checkPerson(p))
            System.out.print(" non ");
        System.out.println(" e' uno Student");

            
        //Test oggetto Teacher
        p = new Teacher("Gennaro", "Percannella", TeacherType.ASSOCIATE_PROFESSOR, 1973, 5, 18);
        System.out.println(p);
        if(!filter.checkPerson(p))
            System.out.print(" non ");
        System.out.println(" e' uno Student");
    }
            
}
