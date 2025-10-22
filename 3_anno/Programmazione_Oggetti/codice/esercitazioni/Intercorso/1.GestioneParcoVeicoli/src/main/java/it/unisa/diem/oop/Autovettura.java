package it.unisa.diem.oop;

public class Autovettura extends Veicolo{
    private int numeroPosti;

    public Autovettura(String numTelaio, String modello, String alimentazione, String targa, int numeroPosti) {
        super(numTelaio, modello, alimentazione, targa);
        this.numeroPosti = numeroPosti;
    }

    public int getNumeroPosti() {
        return numeroPosti;
    }

    @Override
    public boolean controllaTarga() {
        return getTarga().matches("[A-Z]{2}[0-9]{3}[A-Z]{2}");
    }

    @Override
    public String toString() {
        return super.toString() + ", numero posti: " + numeroPosti;
    }
}
