package finale1;

import java.time.LocalDate;

public class Persona {
    /*Dichiarazione Attributi*/
    String name;
    LocalDate dataNascita;
    String codiceFiscale;

    public Persona(String name, LocalDate dataNascita, String codiceFiscale) {
        this.name = name;
        this.dataNascita = dataNascita;
        this.codiceFiscale = codiceFiscale.toUpperCase();
    }
    
    /*Metodi Getter*/
    public String getName(){
        return name;
    }
    public LocalDate getData(){
        return dataNascita;
    }
    public String getCodiceFiscale(){
        return codiceFiscale;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        return hash = 31 * hash + codiceFiscale.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == null)
            return false;
        if (!(obj instanceof Persona))
            return false;
        Persona p = (Persona) obj;
        return p.getCodiceFiscale().equals(this.getCodiceFiscale());
    }

    @Override
    public String toString() {
        return name + "," + codiceFiscale + "," + dataNascita + "\n";
    }
    
}