/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.elencotelefonico;

import java.util.Objects;

/**
 *
 * @author leonardorundo
 */
public class Persona implements Comparable<Persona> {
    
    private String nome;
    private String cognome;
    private String codiceFiscale;
    private int eta;

    public int getEta() {
        return eta;
    }

    public void setEta(int eta) {
        this.eta = eta;
    }

    /**
     * Get the value of cognome
     *
     * @return the value of cognome
     */
    public String getCognome() {
        return cognome;
    }

    /**
     * Set the value of cognome
     *
     * @param cognome new value of cognome
     */
    public void setCognome(String cognome) {
        this.cognome = cognome;
    }


    /**
     * Get the value of codiceFiscale
     *
     * @return the value of codiceFiscale
     */
    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    /**
     * Set the value of codiceFiscale
     *
     * @param codiceFiscale new value of codiceFiscale
     */
    public void setCodiceFiscale(String codiceFiscale) {
        this.codiceFiscale = codiceFiscale;
    }


    /**
     * Get the value of nome
     *
     * @return the value of nome
     */
    public String getNome() {
        return nome;
    }

    /**
     * Set the value of nome
     *
     * @param nome new value of nome
     */
    public void setNome(String nome) {
        this.nome = nome;
    }

    public Persona(String nome, String cognome, String codiceFiscale, int eta) {
        this.nome = nome;
        this.cognome = cognome;
        this.codiceFiscale = codiceFiscale;
        this.eta = eta;
    }

    @Override
    public String toString() {
        return "Persona{" + "nome=" + nome + ", cognome=" + cognome + ", codiceFiscale=" + codiceFiscale + ", eta=" + eta + '}';
    }


    @Override
    public int hashCode() {
        int hash = 5;
        hash = 37 * hash + Objects.hashCode(this.codiceFiscale.toUpperCase());
        // Alternativa:
        // hash = 37 * hash + ( this.codiceFiscale == null ? 0 : this.codiceFiscale.toUpperCase().hashCode() );
        return hash;
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
        if (!Objects.equals(this.codiceFiscale.toUpperCase(), other.codiceFiscale.toUpperCase())) {
            return false;
        }
        return true;
        // Alternativa:
        //return this.codiceFiscale.equalsIgnoreCase(other.codiceFiscale);
    }

    @Override
    public int compareTo(Persona o) {
        return codiceFiscale.compareToIgnoreCase(o.codiceFiscale);
    }
    
}
