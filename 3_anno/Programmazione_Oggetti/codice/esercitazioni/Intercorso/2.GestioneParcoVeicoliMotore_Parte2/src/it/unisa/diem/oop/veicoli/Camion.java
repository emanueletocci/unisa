package it.unisa.diem.oop.veicoli;

public class Camion extends Veicolo {

    private final int numeroAssi;

    public Camion(String numTelaio, String modello, String alimentazione, String targa, int numeroAssi) {
        super(numTelaio, modello, alimentazione, targa);
        this.numeroAssi = numeroAssi;
    }

    public int getNumeroAssi() {
        return numeroAssi;
    }

    @Override
    public boolean controllaTarga() {
        boolean result = true;
        String targa = getTarga();
        if (targa.length() != 8) {
            result = false;
        }
        for (int index = 0; index < 2 && result; index++) {
            if (!Character.isLetter(targa.charAt(index))) {
                result = false;
            }
        }
        for (int index = 2; index < targa.length() && result; index++) {
            if (!Character.isDigit(targa.charAt(index))) {
                result = false;
            }
        }
        return result;
    }

    @Override
    public String toString() {
        StringBuffer stringBuffer = new StringBuffer();
        stringBuffer.append(super.toString());
        stringBuffer.append(", ");
        stringBuffer.append("Numero assi = ");
        stringBuffer.append(getNumeroAssi());
        stringBuffer.append("\n");
        return stringBuffer.toString();
    }

}
