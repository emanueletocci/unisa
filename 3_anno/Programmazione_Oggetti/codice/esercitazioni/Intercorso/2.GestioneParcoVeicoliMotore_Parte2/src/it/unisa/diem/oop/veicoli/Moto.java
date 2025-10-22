package it.unisa.diem.oop.veicoli;

public class Moto extends Veicolo {

    private final boolean guidaLibera;

    public Moto(String numTelaio, String modello, String alimentazione, String targa, boolean guidaLibera) {
        super(numTelaio, modello, alimentazione, targa);
        this.guidaLibera = guidaLibera;
    }

    public boolean getGuidaLibera() {
        return guidaLibera;
    }

    @Override
    public boolean controllaTarga() {
        String targa = getTarga();
        if (targa.length() != 8) {
            return false;
        }
        for (int index = 0; index < 2; index++) {
            if (!Character.isLetter(targa.charAt(index))) {
                return false;
            }
        }
        for (int index = 2; index < targa.length(); index++) {
            if (!Character.isDigit(targa.charAt(index))) {
                return false;
            }
        }
        return true;
        
        // Utilizzo di espressioni regolari
        // return getTarga().matches("^[A-Za-z]{2}\\d{6}$");
        
    }

    @Override
    public String toString() {
        StringBuffer stringBuffer = new StringBuffer();
        stringBuffer.append(super.toString());
        stringBuffer.append(", ");
        stringBuffer.append("Guida libera = ");
        stringBuffer.append(getGuidaLibera());
        stringBuffer.append("\n");
        return stringBuffer.toString();
    }

}
