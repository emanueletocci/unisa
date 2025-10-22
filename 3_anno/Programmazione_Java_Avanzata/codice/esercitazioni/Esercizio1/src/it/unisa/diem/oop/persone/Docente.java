package it.unisa.diem.oop.persone;

public final class Docente extends MembroUnisa{
    private String insegnamento;

    public Docente(String nomeCompleto, String codiceFiscale, String matricola, String insegnamento) {
        super (nomeCompleto, codiceFiscale, matricola );
        this.insegnamento = insegnamento;
    }

    public String getInsegnamento() {
        return insegnamento;
    }

    @Override
    public String toString(){
        return super.toString() + ", Insegnamento: " + insegnamento;
    }
}
