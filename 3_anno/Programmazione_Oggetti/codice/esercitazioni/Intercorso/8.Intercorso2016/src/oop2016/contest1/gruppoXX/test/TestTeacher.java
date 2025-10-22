/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package oop2016.contest1.gruppoXX.test;


//ATTENZIONE: SOSTITUIRE NEL SEGUENTE IMPORT XX CON IL CODICE DEL PROPRIO GRUPPO
import gruppoXX.Teacher;
import gruppoXX.TeacherType;

/**
 *
 * @author Gennaro
 */
public class TestTeacher {

    public static void main(String[] args) {
        Teacher p = new Teacher("Gennaro", "Percannella", TeacherType.ASSOCIATE_PROFESSOR, 1973, 5, 18);
        System.out.println(p);
        Teacher p2 = new Teacher("Mario", "Vento", TeacherType.FULL_PROFESSOR, 1960, 1, 5);
        System.out.println(p2);
        if(p.compareTo(p2)>0)
            System.out.println("La persona più anziana e': \n" + p);
        else if(p.compareTo(p2)<0)
            System.out.println("La persona più anziana e': \n" + p2);
        else
            System.out.println("La persone sono coetanee");

    }

}
