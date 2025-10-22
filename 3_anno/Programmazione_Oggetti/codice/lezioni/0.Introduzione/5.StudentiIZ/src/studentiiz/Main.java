/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package studentiiz;

import it.unisa.diem.oop.persone.Persona;
import it.unisa.diem.oop.persone.PersonaUnisa;
import it.unisa.diem.oop.persone.Studente;

/**
 *
 * @author lucagreco
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        Persona p1 = new Persona("Ernesto", "Grigi", "ERNGR0002");

        // PersonaUnisa p = new PersonaUnisa("Mario", "Rossi","MRG0001", "06127001");
        PersonaUnisa s = new Studente("Pietro", "Rossi", "PRS0001", "061270004", 29.5F);

        //   if (s instanceof Studente) {
        if (s.getClass() == Studente.class) {

            Studente s2 = (Studente) s;

            System.out.println(s2.getVotoMedio());

        }

        System.out.println(s);

    }

}
