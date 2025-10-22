package it.unisa.diem.oop.persone;

public abstract sealed class MembroUnisa extends Persona permits Studente, Docente{
    private String matricola;

    public MembroUnisa(String nomeCompleto, String codiceFiscale, String matricola){
        super(nomeCompleto, codiceFiscale);
        this.matricola = matricola;
    }

    public String getMatricola() {
        return matricola;
    }

    public void setMatricola(String matricola) {
        this.matricola = matricola;
    }

    @Override
    public boolean equals(Object o){
        if(o == null)
            return false;
        if(!(o instanceof MembroUnisa membro))
            return false;

        return matricola.equals(membro.getMatricola());
    }

    @Override
    public int hashCode(){
        return matricola.hashCode();
    }

    @Override
    public String toString(){
        return super.toString() + ", Matricola: " + this.matricola;
    }
}
