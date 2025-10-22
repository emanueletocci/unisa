package it.unisa.diem.oop.elenco;
import java.time.LocalDate;
import java.util.Objects;

public class Persona {
    private final String nome;
    private final LocalDate dataNascita;
    private final String codiceFiscale;

    public Persona(String nome, LocalDate dataNascita, String codiceFiscale) {
        this.nome = nome;
        this.dataNascita = dataNascita;
        this.codiceFiscale = codiceFiscale;
    }

    public String getNome() {return nome;}

    public LocalDate getDataNascita() {return dataNascita;}

    public String getCodiceFiscale() {return codiceFiscale;}

    @Override
    public int hashCode() {
        return codiceFiscale.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if(! (this instanceof Persona)) return false;
        Persona pt = (Persona) obj;
        return this.getCodiceFiscale() == pt.getCodiceFiscale();
    }

    @Override
    public String toString() {
        return "\n***\nNome=" + nome + "\nData di nascita=" + dataNascita + "\nCodice fiscale=" + codiceFiscale;
    }

}
