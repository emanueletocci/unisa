/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.persone;

import java.util.Objects;

/**
 *
 * @author lucagreco
 */
public class Persona implements Clonabile<Persona>, Comparable<Persona> {

    private String nome;
    private String cognome;
    private String codiceFiscale;
    private int eta;

    public Persona(String nome, String cognome, String codiceFiscale) {
        this.nome = nome;
        this.cognome = cognome;
        this.codiceFiscale = codiceFiscale;
    }

    public final String getNome() {
        return this.nome;
    }

    public String getCognome() {
        return this.cognome;
    }

    public String getCodiceFiscale() {
        return this.codiceFiscale;
    }

    public void setEta(int eta) {
        this.eta = eta;
    }

    public int getEta() {
        return eta;
    }

    @Override
    public boolean equals(Object obj) {

        if (obj == null) {
            return false;
        }
        if (this == obj) {
            return true; // RIFLESSIVA
        }
        if (this.getClass() != obj.getClass()) {
            return false; // PROPRIETA' SIMMETRICA
        }
        // if(!(obj instanceof Persona)) return false; // NON SIMMETRICA
        Persona p = (Persona) obj;
        return p.codiceFiscale.equals(this.codiceFiscale);

    }

    @Override
    public int hashCode() {
        return this.codiceFiscale.hashCode();
    }

    /*
    @Override
    public int hashCode() { // caso generale con più attributi
        int hash = 7;
        hash = 79 * hash + this.nome.hashCode();
        hash = 79 * hash + this.cognome.hashCode();
        hash = 79 * hash + this.codiceFiscale.hashCode();
        return hash;
    }
    
     */
    @Override
    public String toString() {
        return this.nome + " " + this.cognome + " " + this.codiceFiscale;
    }

    @Override
    public Persona clona() {
        return new Persona(this.nome, this.cognome, this.codiceFiscale);
    }

    @Override
    public int compareTo(Persona o) {
        /*  if(! this.cognome.equals(o.cognome))
            return this.cognome.compareTo(o.cognome); */
        return this.codiceFiscale.compareTo(o.codiceFiscale);
    }

}
