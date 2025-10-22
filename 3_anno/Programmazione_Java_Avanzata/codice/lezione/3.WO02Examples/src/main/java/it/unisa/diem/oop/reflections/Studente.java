package it.unisa.diem.oop.reflections;

import java.util.Objects;

public class Studente extends Persona{
    private String matricola;

    public Studente(String cognome, String codiceFiscale, String nome, String matricola) {
        super ( cognome, codiceFiscale, nome );
        this.matricola = matricola;
    }

    public String getMatricola() {
        return matricola;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Studente studente)) return false;
        if (!super.equals ( o )) return false;
        return Objects.equals ( matricola, studente.matricola );
    }

    @Override
    public int hashCode() {
        return Objects.hash ( super.hashCode (), matricola );
    }

    @Override
    public String toString() {
        return super.toString() + "Studente{" +
                "matricola='" + matricola + '\'' +
                '}';
    }

    @DaImplementare
    public String generaMatricola("Mario"){
        return null;
    }
}
