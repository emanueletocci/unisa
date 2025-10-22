/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.inputoutputtest;

import java.io.Serializable;
import java.util.Objects;

/**
 *
 * @author leonardorundo
 */


public class Persona implements Serializable{
    private String nome;
    private double altezza;

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 83 * hash + Objects.hashCode(this.nome);
        hash = 83 * hash + (int) (Double.doubleToLongBits(this.altezza) ^ (Double.doubleToLongBits(this.altezza) >>> 32));
        hash = 83 * hash + this.eta;
        return hash;
    }

    @Override
    public String toString() {
        return "Persona{" + "nome=" + nome + ", altezza=" + altezza + ", eta=" + eta + '}';
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Persona other = (Persona) obj;
        if (Double.doubleToLongBits(this.altezza) != Double.doubleToLongBits(other.altezza)) {
            return false;
        }
        if (this.eta != other.eta) {
            return false;
        }
        if (!Objects.equals(this.nome, other.nome)) {
            return false;
        }
        return true;
    }
    private int eta;

    public Persona(String nome, double altezza, int eta) {
        this.nome = nome;
        this.altezza = altezza;
        this.eta = eta;
    }

    public String getNome() {
        return nome;
    }

    public double getAltezza() {
        return altezza;
    }

    public int getEta() {
        return eta;
    }
}
