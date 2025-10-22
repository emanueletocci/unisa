package it.unisa.diem.oop.persone;

public abstract class Persona{
    private String nomeCompleto;
    private String codiceFiscale;

    public Persona(String nomeCompleto, String codiceFiscale) {
        this.codiceFiscale = codiceFiscale;
        this.nomeCompleto = nomeCompleto;
    }

    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    public String getNomeCompleto() {
        return nomeCompleto;
    }

    @Override
    public boolean equals(Object o){
        if(o == null)
            return false;
        if(!(o instanceof Persona p))
            return false;
        return this.codiceFiscale.equals(p.getCodiceFiscale());
    }

    @Override
    public int hashCode(){
        int hash = 7;
        hash = 31 * hash + this.nomeCompleto.hashCode();
        hash = 31 * hash + this.codiceFiscale.hashCode();
        return hash;
    }

    @Override
    public String toString(){
        return "Nome: " + nomeCompleto + ", Codice Fiscale: " + codiceFiscale;
    }
}
