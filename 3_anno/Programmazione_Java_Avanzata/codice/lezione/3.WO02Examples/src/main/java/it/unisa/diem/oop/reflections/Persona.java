package it.unisa.diem.oop.reflections;

import java.util.Objects;

public class Persona {
    private String nome;
    private String cognome;
    private String codiceFiscale;

    public Persona(String cognome, String codiceFiscale, String nome) {
        this.cognome = cognome;
        this.codiceFiscale = codiceFiscale;
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    public String getNome() {
        return nome;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Persona persona)) return false;
        return Objects.equals ( codiceFiscale, persona.codiceFiscale );
    }

    @Override
    public int hashCode() {
        return Objects.hashCode ( codiceFiscale );
    }

    @Override
    public String toString() {
        return "Persona{" +
                "codiceFiscale='" + codiceFiscale + '\'' +
                ", nome='" + nome + '\'' +
                ", cognome='" + cognome + '\'' +
                '}';
    }
}
