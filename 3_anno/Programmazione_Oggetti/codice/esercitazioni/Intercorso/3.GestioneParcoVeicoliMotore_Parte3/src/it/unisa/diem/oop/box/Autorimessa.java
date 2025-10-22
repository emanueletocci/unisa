/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.box;

import it.unisa.diem.oop.veicoli.Veicolo;
import it.unisa.diem.oop.exceptions.*;
/**
 *
 * @author leonardorundo
 */
public class Autorimessa extends Box {
    private final Veicolo[] veicoli;
    private int testa;
    private int coda;
    private int riemp;

    public Autorimessa(int maxPosti, String nome) {
        super(maxPosti, nome);
        riemp = 0;
        testa = 0;
        coda = 0;
        veicoli = new Veicolo[maxPosti];
    }

    private boolean autorimessaPiena() {
        return riemp == veicoli.length;
    }

    private boolean autorimessaVuota() {
        return riemp == 0;
    }

    @Override
    public void entra(Veicolo veicolo) throws AutorimessaPienaException, TargaNonValidaException{
        if (autorimessaPiena()) {
            System.out.println("Autorimessa piena. Ingresso vietato.");
            throw new AutorimessaPienaException("Autorimessa Piena.");
        } else if (!veicolo.controllaTarga()) {
            System.out.println("Targa non valida. Ingresso vietato.");
            throw new TargaNonValidaException("Targa non valida.");
        } else {
            veicoli[coda] = veicolo;
            coda = (coda + 1) % veicoli.length;
            riemp++;
        }
    }

    @Override
    public Veicolo esce() throws AutorimessaVuotaException {
        if (autorimessaVuota()) {
            throw new AutorimessaVuotaException("Autorimessa vuota. Uscita vietata.");
        } else {
            Veicolo veicolo = veicoli[testa];
            testa = (testa + 1) % veicoli.length;
            riemp--;
            return veicolo;
        }
    }

    @Override
    public String toString() {
        StringBuffer stringBuffer = new StringBuffer();
        stringBuffer.append(super.toString());
        stringBuffer.append("\nVeicoli presenti : \n");
        for (int index = 0; index < riemp; index++) {
            stringBuffer.append(veicoli[(testa + index) % veicoli.length]);
        }
        return stringBuffer.toString();
    }
    
}
