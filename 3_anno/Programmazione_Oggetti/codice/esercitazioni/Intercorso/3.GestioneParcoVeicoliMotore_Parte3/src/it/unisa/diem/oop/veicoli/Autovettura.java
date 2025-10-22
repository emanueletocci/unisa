package it.unisa.diem.oop.veicoli;

public class Autovettura extends Veicolo {

    private final int numeroPosti;

    public Autovettura(String numTelaio, String modello, String alimentazione, String targa, int numeroPosti) {
        super(numTelaio, modello, alimentazione, targa);
        this.numeroPosti = numeroPosti;
    }

    public int getNumeroPosti() {
        return numeroPosti;
    }

    @Override
    public boolean controllaTarga() {
        String targa = getTarga();
        if (targa.length() != 7) {
            return false;
        }
        for (int index = 0; index < 2; index++) {
            if (!Character.isLetter(targa.charAt(index))) {
                return false;
            }
        }
        for (int index = 2; index < 5; index++) {
            if (!Character.isDigit(targa.charAt(index))) {
                return false;
            }
        }
        for (int index = 5; index < targa.length(); index++) {
            if (!Character.isLetter(targa.charAt(index))) {
                return false;
            }
        }
        return true;
        
        // Utilizzo di espressioni regolari
        // return getTarga().matches("^[A-Za-z]{2}\\d{3}[A-Za-z]{2}$");
        
    }

    @Override
    public String toString() {
        StringBuffer stringBuffer = new StringBuffer();
        stringBuffer.append(super.toString());
        stringBuffer.append(", ");
        stringBuffer.append("Numero posti = ");
        stringBuffer.append(getNumeroPosti());
        stringBuffer.append("\n");
        return stringBuffer.toString();
    }

}
