/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package oop2016.contest1.gruppoXX.test;

//ATTENZIONE: SOSTITUIRE NEL SEGUENTE IMPORT XX CON IL CODICE DEL PROPRIO GRUPPO

import gruppoXX.Person;


/**
 *
 * @author Gennaro
 */
public class TestPerson {
        public static void main(String[] args) {
        Person p = new Person("Matteo", "Baldi", 1998, 4, 1);
        System.out.println(p);
        Person p2 = new Person("Luca", "Rossi", 1994, 2, 15);
        System.out.println(p2);
        if(p.compareTo(p2)>0)
            System.out.println("La persona più anziana e': \n" + p);
        else if(p.compareTo(p2)<0)
            System.out.println("La persona più anziana e': \n" + p2);
        else
            System.out.println("La persone sono coetanee");

    }

}
