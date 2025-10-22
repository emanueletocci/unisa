package gestioneDipendenti;

import java.io.IOException;
import java.time.LocalDateTime;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        GestoreTimbrature gestore = new GestoreTimbrature();

        Dipendente d1 = new Dipendente("Emanuele", "Tocci", "TCCMNL03H09D086D");
        Dipendente d2 = new Dipendente("Chiara", "Arnone", "CHRNNL03H09D086F");
        Dipendente d3 = new Dipendente("Omar", "Silano", "SLNMR05H09D186G");

        gestore.registraIngresso(new TimbraturaDipendente(d1, LocalDateTime.of(2025, 1, 23, 15, 30)));
        gestore.registraIngresso(new TimbraturaDipendente(d1, LocalDateTime.of(2025, 1, 23, 17, 45)));
        gestore.registraIngresso(new TimbraturaDipendente(d1, LocalDateTime.of(2025, 2, 21, 17, 45)));

        gestore.registraIngresso(new TimbraturaDipendente(d2, LocalDateTime.of(2025, 1, 23, 8, 30)));
        gestore.registraIngresso(new TimbraturaDipendente(d2, LocalDateTime.of(2025, 1, 23, 16, 15)));

        gestore.registraIngresso(new TimbraturaDipendente(d3, LocalDateTime.of(2023, 1, 23, 8, 30)));
        gestore.registraIngresso(new TimbraturaDipendente(d3, LocalDateTime.of(2023, 1, 23, 8, 30)));   //duplicato
        gestore.registraIngresso(new TimbraturaDipendente(d3, LocalDateTime.of(2024, 12, 23, 8, 30)));
        gestore.registraIngresso(new TimbraturaDipendente(d3, LocalDateTime.of(2025, 1, 21, 8, 30)));

        System.out.println("Stampo gli ingressi del dipendente: TCCMNL03H09D086D - d1\n");
        gestore.stampaTimbrature(gestore.cercaDipendente("TCCMNL03H09D086D"));

        System.out.println("Stampo gli ingressi del dipendente: CHRNNL03H09D086F - d2\n");
        gestore.stampaTimbrature(gestore.cercaDipendente("CHRNNL03H09D086F"));

        System.out.println("Stampo gli ingressi del dipendente: SLNMR05H09D186G - d3\n");
        gestore.stampaTimbrature(gestore.cercaDipendente("SLNMR05H09D186G"));

        System.out.println("-".repeat(50));
        System.out.println("Stampo tutti gli ingressi\n");

        //gestore.stampaTimbrature(gestore.getAllTimbrature());
        gestore.stampaTuttiTimbri();

        gestore.stampaSuFile("TCCMNL03H09D086D", gestore.cercaDipendente("TCCMNL03H09D086D"));
        gestore.stampaSuFile("CHRNNL03H09D086F", gestore.cercaDipendente("CHRNNL03H09D086F"));
        gestore.stampaSuFile("SLNMR05H09D186G", gestore.cercaDipendente("SLNMR05H09D186G"));

        System.out.println("Leggo da file\n");
        Set<TimbraturaDipendente> timbriEmanuele = gestore.leggiDaFile("TCCMNL03H09D086D");

        System.out.println("Stampo timbri Emanuele letti da file\n");
        gestore.stampaTimbrature(timbriEmanuele);


    }
}