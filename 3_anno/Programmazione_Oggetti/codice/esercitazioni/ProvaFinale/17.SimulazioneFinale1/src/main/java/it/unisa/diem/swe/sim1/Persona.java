package it.unisa.diem.swe.sim1;

import java.time.LocalDate;

public class Persona implements Comparable<Persona> {
    private String codiceFiscale;
    private String nome;
    private LocalDate dataNascita;

    public Persona(String nome, LocalDate dataNascita,  String codiceFiscale) {
        this.codiceFiscale = codiceFiscale;
        this.nome = nome;
        this.dataNascita = dataNascita;
    }

    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    public void setCodiceFiscale(String codiceFiscale) {
        this.codiceFiscale = codiceFiscale;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public LocalDate getDataNascita() {
        return dataNascita;
    }

    public void setDataNascita(LocalDate dataNascita) {
        this.dataNascita = dataNascita;
    }

    @Override
    public int hashCode() {
        int result = 17;
        return result = 31* result + codiceFiscale.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Persona))
            return false;
        Persona p = (Persona) obj;
        return p.codiceFiscale.equals(this.codiceFiscale);
    }

    @Override
    public String toString() {
        return "\nNome = " + nome + "\nCodiceFiscale = " + codiceFiscale +  "\nData di nascita = " + dataNascita +"\n\n";
    }

    @Override
    public int compareTo(Persona p) {
        return p.codiceFiscale.compareTo(this.codiceFiscale);
    }
}