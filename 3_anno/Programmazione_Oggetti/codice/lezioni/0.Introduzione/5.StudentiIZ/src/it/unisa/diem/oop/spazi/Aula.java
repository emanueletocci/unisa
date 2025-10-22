/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.spazi;

import it.unisa.diem.oop.persone.Persona;

/**
 *
 * @author lucagreco
 */
public class Aula extends Spazio {

    private Persona persone[];
    private int riemp;

    public Aula(String nome, int maxPosti) {
        super(nome, maxPosti);

        persone = new Persona[maxPosti];

        this.riemp = 0;

    }

    @Override
    public void entra(Persona p) throws AulaPienaException {

        if (aulaPiena()) {

            // System.out.println("Aula piena");
            throw new AulaPienaException("Aula piena.");

        }

        persone[riemp++] = p;

    }

    @Override
    public Persona esce() throws AulaVuotaException {

        if (aulaVuota()) {

            throw new AulaVuotaException("Aula vuota.");

        }

        Persona p = persone[--riemp];

        persone[riemp] = null;

        return p;

    }

    private boolean aulaPiena() {

        return riemp == persone.length;

    }

    private boolean aulaVuota() {

        return riemp == 0;

    }

    @Override
    public String getTipo() {

        return "Aula";

    }

    @Override

    public String toString() {

        StringBuffer sb = new StringBuffer(super.toString() + '\n');

        for (int i = 0; i < riemp; i++) {

            sb.append(persone[i] + "\n");

        }

        return sb.toString();

    }

}
