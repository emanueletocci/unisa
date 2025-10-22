/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package oop2016.contest1.gruppoXX.test;

//ATTENZIONE: SOSTITUIRE NEL SEGUENTE IMPORT XX CON IL CODICE DEL PROPRIO GRUPPO

import gruppoXX.Student;


/**
 *
 * @author Gennaro
 */
public class TestStudent {
        
    public static void main(String[] args){
        Student p = new Student("Luca", "Rossi", "0612708762", 1995, 7, 11);
        System.out.println(p);
        Student p2 = new Student("Marco", "Verdi", "0612708762", 1994, 2, 15);
        System.out.println(p2);
        if(p.compareTo(p2)>0)
            System.out.println("La persona più anziana e': \n" + p);
        else if(p.compareTo(p2)<0)
            System.out.println("La persona più anziana e': \n" + p2);
        else
            System.out.println("La persone sono coetanee");

    }
    
}
