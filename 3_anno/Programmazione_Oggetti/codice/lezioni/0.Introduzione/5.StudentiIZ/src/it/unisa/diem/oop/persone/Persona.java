/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.persone;

/**
 *
 * @author lucagreco
 */
public class Persona {

    private String nome;
    private String cognome;
    private String codiceFiscale;

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

    @Override
    public String toString() {

        return this.nome + " " + this.cognome + " " + this.codiceFiscale;

    }

}
