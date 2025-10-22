package it.unisa.diem.oop;

public class Camion extends Veicolo {
    private int numeroAssi;

    public Camion(String numTelaio, String modello, String alimentazione, String targa, int numeroAssi) {
        super(numTelaio, modello, alimentazione, targa);
        this.numeroAssi = numeroAssi;
    }

    public int getNumAssi() {
        return numeroAssi;
    }

    @Override
    public boolean controllaTarga() {
        return getTarga().matches("[A-Z]{2}[0-9]{3}");
    }

    @Override
    public String toString() {
        return super.toString() + ", numero assi: " + numeroAssi;
    }
}
