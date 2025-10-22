/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.box;
import it.unisa.diem.oop.exceptions.AutorimessaPienaException;
import it.unisa.diem.oop.exceptions.AutorimessaVuotaException;
import it.unisa.diem.oop.exceptions.BoxException;
import it.unisa.diem.oop.exceptions.TargaNonValidaException;
import it.unisa.diem.oop.veicoli.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author leonardorundo
 */
public class TestRimessa {

    public static void main(String[] args) {
        Autorimessa autorimessa = new Autorimessa(5, "Parcheggio E1");

        try {
            autorimessa.entra(new Camion("sdf244", "Fiat CX45", "Gasolio", "TT656671", 4));
        } catch (BoxException ex) {
            Logger.getLogger(TestRimessa.class.getName()).log(Level.SEVERE, null, ex);
        }

        try {
            autorimessa.entra(new Camion("spl265", "Volvo PTG", "Gasolio", "YH96671", 6));
        } catch (BoxException ex) {
            Logger.getLogger(TestRimessa.class.getName()).log(Level.SEVERE, null, ex);
        }

        try {
            autorimessa.entra(new Autovettura("mk23t", "Fiat Punto", "Metano", "EA566FM", 5));
        } catch (BoxException ex) {
            Logger.getLogger(TestRimessa.class.getName()).log(Level.SEVERE, null, ex);
        }

        try {
            autorimessa.entra(new Autovettura("cgt612", "Fiat Idea", "Gasolio", "AQ9Y7UUU", 5));
        } catch (BoxException ex) {
            Logger.getLogger(TestRimessa.class.getName()).log(Level.SEVERE, null, ex);
        }

        try {
            autorimessa.entra(new Moto("das7896", "Honda Hornet", "Benzina", "AT51233", false));
        } catch (BoxException ex) {
            Logger.getLogger(TestRimessa.class.getName()).log(Level.SEVERE, null, ex);
        }
        try {
            autorimessa.entra(new Moto("gdt7896", "Suzuki Bandit", "Benzina", "AT5123N", false));
        } catch (BoxException ex) {
            Logger.getLogger(TestRimessa.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println(autorimessa);
    }
}
