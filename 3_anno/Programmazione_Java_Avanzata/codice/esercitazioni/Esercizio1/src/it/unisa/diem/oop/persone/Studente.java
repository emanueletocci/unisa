package it.unisa.diem.oop.persone;

import com.sun.source.tree.SwitchTree;

public final class Studente extends MembroUnisa{
    private double votoMedio;
    private String corsoDiStudi;

    public Studente(String nomeCompleto, String codiceFiscale, String matricola, String corsoDiStudi, double votoMedio) {
        super (nomeCompleto, codiceFiscale, matricola);

        this.corsoDiStudi = corsoDiStudi;
        this.votoMedio = votoMedio;

        // Controllo matricole
        if (corsoDiStudi.equals("LT") && !matricola.startsWith("06127")) {
            throw new IllegalArgumentException("La matricola non è coerente con il corso di studi LT");
        } else if (corsoDiStudi.equals("LM") && !matricola.startsWith("06227")) {
            throw new IllegalArgumentException("La matricola non è coerente con il corso di studi LM");
        } else if (corsoDiStudi.equals("PhD") && !matricola.startsWith("8805")) {
            throw new IllegalArgumentException("La matricola non è coerente con il corso di studi PhD");
        }
    }

    public String getCorsoDiStudi() {
        return corsoDiStudi;
    }

    public void setCorsoDiStudi(String corsoDiStudi) {
        this.corsoDiStudi = corsoDiStudi;
    }

    public double getVotoMedio() {
        return votoMedio;
    }

    public void setVotoMedio(double votoMedio) {
        this.votoMedio = votoMedio;
    }

    @Override
    public String toString(){
        return super.toString() + ", Voto: " + votoMedio + ", Corso: " + corsoDiStudi;
    }
}
