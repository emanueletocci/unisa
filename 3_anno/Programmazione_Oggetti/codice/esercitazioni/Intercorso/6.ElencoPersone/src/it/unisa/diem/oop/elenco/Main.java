package it.unisa.diem.oop.elenco;
import java.io.*;
import java.time.LocalDate;
import java.util.*;

public class Main {

    public static void main(String[] args) {

        Elenco e = new Elenco();

        for (int i = 0; i < 5; i++) 
            e.aggiungi(creaPersonaCasuale());
       
        System.out.println(e);
    }

    private static Persona creaPersonaCasuale() {

        Random r = new Random();
        String[] nomi = {"Nicola", "Pasquale", "Marta", "Luisa", "Teresa", "Luca", "Daniela", "Gennaro", "Domenico", "Margherita", "Luigi"};
        String[] dipartimenti = {"DIEM", "DI", "DISPAC"};

        if (r.nextInt() % 2 == 0) 
            return new Tecnico(nomi[r.nextInt(nomi.length)], LocalDate.of(1900 + r.nextInt(121), 1 + r.nextInt(12), 1 + r.nextInt(27)), UUID.randomUUID().toString().replace("-", "").substring(0, 13), dipartimenti[r.nextInt(dipartimenti.length)]);
        return new Persona(nomi[r.nextInt(nomi.length)], LocalDate.of(1900 + r.nextInt(121), 1 + r.nextInt(12), 1 + r.nextInt(27)), UUID.randomUUID().toString().replace("-", "").substring(0, 13));

    }

}
