/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package studentiiz;

import it.unisa.diem.oop.persone.Persona;
import it.unisa.diem.oop.persone.Studente;
import it.unisa.diem.oop.exceptions.AccessibileException;
import it.unisa.diem.oop.spazi.Aula;
import it.unisa.diem.oop.exceptions.AulaPienaException;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author lucagreco
 */
public class MainAula {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws AulaPienaException  {
        Persona p = new Persona("Mario", "Rossi", "MRS0001");
        Persona s = new Studente("Stefano", "Grigi", "SRG0002", "06127001", 29.5F);
        Aula a = new Aula("M", 1);
        
        a.entra(p);

        try {
            Persona p3 = a.esce();
            System.out.println(p3);
            a.entra(p);
        } catch (AccessibileException ex) {
            Logger.getLogger(MainAula.class.getName()).log(Level.SEVERE, null, ex);
        }
        finally {
            System.out.println("finally");
        }
        try {
            a.entra(s);
        } catch (AulaPienaException ex) {
            System.err.println(ex.getMessage());
            //Logger.getLogger(MainAula.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println(a);
    }
    
}
