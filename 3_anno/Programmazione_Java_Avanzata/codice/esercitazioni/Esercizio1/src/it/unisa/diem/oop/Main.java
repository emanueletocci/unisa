package it.unisa.diem.oop;

import it.unisa.diem.oop.persone.*;
import java.io.IOException;

public class Main {
    private final String filePath = "membri_unisa.csv";
    public static void main(String[] args) {
        Anagrafica anagrafica = new Anagrafica();

        anagrafica.aggiungiMembro(new Studente("Emanuele Tocci", "TCCMNL03H09D086D", "0612707488", CorsoDiStudi.LT.toString(), 27.01));
        anagrafica.aggiungiMembro(new Docente("Francesco Rossi", "RSSFRS05H10D050E", "0612708400", "Basi di Dati"));
        anagrafica.aggiungiMembro(new Studente("Ida Giordano", "GRDIDL04H01D084H", "0612707321", CorsoDiStudi.LT.toString(), 29.01));
        anagrafica.aggiungiMembro(new Studente("Vittorio De Chiara", "DCHVTT01H01D084J", "0622707000", CorsoDiStudi.LM.toString(), 29.01));
        anagrafica.aggiungiMembro(new Studente("Giampaolo Grigi", "GMPGRG07D07D000I", "0622707001", CorsoDiStudi.LM.toString(), 29.01));
        anagrafica.aggiungiMembro(new Studente("Antonio Grimaldi", "GMRANT05F09D0GGI", "880507001", CorsoDiStudi.PhD.toString(), 29.01));
        anagrafica.aggiungiMembro(new Docente("Anna Rossi", "RSSANN01H10D059A", "0622709009", "Intelligenza Artificiale"));
        anagrafica.aggiungiMembro(new Studente("Marco Lupi", "LPIMRC05H02C352E", "0612707599", CorsoDiStudi.LT.toString(), 26.50));
        anagrafica.aggiungiMembro(new Studente("Lucia Bianchi", "BNCFLA03H51D489C", "0622707102", CorsoDiStudi.LM.toString(), 28.30));
        anagrafica.aggiungiMembro(new Studente("Elena Rossi", "RSSLNA02H45F205F", "0612707854", CorsoDiStudi.LT.toString(), 30.00));
        anagrafica.aggiungiMembro(new Studente("Giuseppe Verdi", "VRDGPP02H01D071B", "0622707201", CorsoDiStudi.LM.toString(), 27.50));
        anagrafica.aggiungiMembro(new Studente("Francesca De Luca", "DLUFRN04H58F839V", "880507004", CorsoDiStudi.PhD.toString(), 28.00));
        anagrafica.aggiungiMembro(new Docente("Mario Neri", "NRIMRI03H09D104L", "0612708900", "Sistemi Operativi"));
        anagrafica.aggiungiMembro(new Docente("Giorgio Verde", "VRDGGR07H11D203M", "0622708203", "Reti di Calcolatori"));
        anagrafica.aggiungiMembro(new Docente("Caterina Fiore", "FRCATR04H15F820P", "880507002", "Machine Learning"));

        try {
            anagrafica.writeCSV("Anagrafica.csv");
            //anagrafica.readCSV("Anagrafica.csv");
        } catch (IOException e){
            e.printStackTrace();
        }

        System.out.println("\n***ANAGRAFICA***\n");
        System.out.println(anagrafica.toString());

    }
}
