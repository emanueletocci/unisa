package it.unisa.diem.oop;

public class Moto extends Veicolo{
    private boolean guidaLibera;

    public Moto(String numTelaio, String modello, String alimentazione, String targa, boolean guidaLibera){
        super(numTelaio, modello, alimentazione, targa);
        this.guidaLibera = guidaLibera;
    }

    public boolean getGuidaLibera(){
        return guidaLibera;
    }

    @Override
    public boolean controllaTarga(){
        return getTarga().matches("[A-Z]{2}[0-9]{5}");
    }
    @Override
    public String toString() {
        return super.toString() + ", guida libera: " + guidaLibera;
    }
}

