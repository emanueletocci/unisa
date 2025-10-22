/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.box;

import it.unisa.diem.oop.veicoli.Veicolo;

/**
 *
 * @author leonardorundo
 */
public abstract class Box {
    
    public int maxPosti;
    private String nome;

    public Box(int maxPosti, String nome) {
        this.maxPosti = maxPosti;
        this.nome = nome;
    }

    public int getMaxPosti() {
        return maxPosti;
    }

    public void setMaxPosti(int maxPosti) {
        this.maxPosti = maxPosti;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public abstract void entra(Veicolo veicolo);

    public abstract Veicolo esce();

    @Override
    public String toString() {
        StringBuffer stringBuffer = new StringBuffer();
        stringBuffer.append("Nome Box = ");
        stringBuffer.append(getNome());
        stringBuffer.append(", Capienza = ");
        stringBuffer.append(getMaxPosti());
        return stringBuffer.toString();
    }
    
}
