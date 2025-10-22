package it.unisa.diem.oop;

import it.unisa.diem.oop.persone.*;
import java.io.*;
import java.util.*;

public class Anagrafica {
    /*
    * incapsula una collezione di MembroUnisa e fornisce metodi di aggiunta e rimozione degli elementi. Prevede un metodo readCSV che consente di leggere da file di testo studenti e
    * docenti (la scelta del tipo di oggetto da istanziare è effettuata con un'espressione switch). Prevede inoltre un metodo writeCSV per salvare l'anagrafica su file di testo.
    */

    private Set<MembroUnisa> listaMembriUnisa;

    public Anagrafica(){
        listaMembriUnisa = new HashSet<>();
    }

    public void aggiungiMembro(MembroUnisa p){
        listaMembriUnisa.add(p);
    }

    public void rimuoviMembro(MembroUnisa p){
        listaMembriUnisa.remove(p);
    }

    public void clearSet(){
        listaMembriUnisa.clear();
    }


    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (MembroUnisa membro : listaMembriUnisa) {
            sb.append(membro.getCodiceFiscale());
            sb.append(";");
            sb.append(membro.getNomeCompleto());
            sb.append(";");
            sb.append(membro.getMatricola());
            sb.append(";");

            switch (membro) {
                case Docente d -> {
                    sb.append("docente;");
                    sb.append(d.getInsegnamento());
                }
                case Studente s -> {
                    sb.append("studente;");
                    sb.append(s.getCorsoDiStudi());
                    sb.append(";");
                    sb.append(s.getVotoMedio());
                }
                default -> throw new IllegalArgumentException("Tipo di membro non supportato");
            }
            sb.append("\n");
        }
        return sb.toString();
    }


    /* Gestione IO */

    public Anagrafica readCSV(String filename) throws IOException {
        Anagrafica a = new Anagrafica();
        System.out.println("Lettura in corso");
        try (Scanner reader = new Scanner(new BufferedReader(new FileReader(filename)))) {
            reader.useDelimiter(";\n*");
            String cf = null;
            String nomeCompleto = null;
            String matricola = null;
            String tipoMembro = null;

            while (reader.hasNext()) {
                cf = reader.next();
                nomeCompleto = reader.next();
                matricola = reader.next();
                tipoMembro = reader.next();
    
                switch (tipoMembro) {
                    case "studente" -> {
                        String corsoDiStudi = reader.next();
                        if (reader.hasNextDouble()) {
                            Double voto = Double.parseDouble(reader.next());
                            a.aggiungiMembro(new Studente(nomeCompleto, cf, matricola, corsoDiStudi, voto));
                        } else {
                            // Gestisci l'errore, ad esempio, registrando un messaggio o saltando la riga
                            reader.next(); // Salta il valore non valido
                        }
                    }
                    case "docente" -> {
                        String insegnamento = reader.next();
                        a.aggiungiMembro(new Docente(nomeCompleto, cf, matricola, insegnamento));
                    }
                    default -> {
                        // Gestisci il caso di tipoMembro non valido, se necessario
                    }
                }
            }
        }
        System.out.println("Lettura completata");
        return a;
    }


    public Anagrafica writeCSV(String filename) throws IOException {
        Anagrafica a = new Anagrafica();
        System.out.println("\nScrittura in corso");
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (MembroUnisa membro : listaMembriUnisa) {
                StringBuffer sb = new StringBuffer(); // Crea un nuovo StringBuffer per ogni membro
    
                sb.append(membro.getCodiceFiscale());
                sb.append(";");
                sb.append(membro.getNomeCompleto());
                sb.append(";");
                sb.append(membro.getMatricola());
                sb.append(";");
    
                switch (membro) {
                    case Docente d -> {
                        sb.append("docente;");
                        sb.append(d.getInsegnamento());
                    }
                    case Studente s -> {
                        sb.append("studente;");
                        sb.append(s.getCorsoDiStudi());
                        sb.append(";");
                        sb.append(s.getVotoMedio());
                    }
                    default -> throw new IllegalArgumentException("Tipo di membro non supportato");
                }
                sb.append("\n");
                writer.write(sb.toString());
            }
        }
        return a;
    }

}
