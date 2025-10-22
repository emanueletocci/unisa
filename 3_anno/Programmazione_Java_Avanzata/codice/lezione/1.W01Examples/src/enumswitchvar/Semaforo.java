/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package enumswitchvar;

import static enumswitchvar.Colore.GIALLO;
import static enumswitchvar.Colore.NERO;
import static enumswitchvar.Colore.ROSSO;
import static enumswitchvar.Colore.VERDE;

/**
 *
 * @author lucagreco
 */
public class Semaforo {

    Colore c;

    public Semaforo(Colore c) {

        this.c = c;

    }

    public void indicazioni() {

        switch (c) {

            case NERO:
                System.out.println("Semaforo spento.");
                break;

            case ROSSO:
                System.out.println("Attenzione. Non attraversare l'incrocio.");
                break;

            case GIALLO:
                System.out.println("Liberare in fretta l'incrocio.");
                break;

            case VERDE:
                System.out.println("E' possibile attraversare.");
                break;

        }

    }

    public void indicazioniNew() {

        switch (c) {

            case NERO -> {
                System.out.println("Semaforo spento.");
            }

            case ROSSO ->
                System.out.println("Attenzione. Non attraversare l'incrocio.");

            case GIALLO ->
                System.out.println("Liberare in fretta l'incrocio.");

            case VERDE ->
                System.out.println("E' possibile attraversare.");

        }

    }

    public void indicazioniSwitchStatement() {

        var s = switch (c) {

            case NERO ->
                "Semaforo spento.";

            case ROSSO ->
                "Attenzione. Non attraversare l'incrocio.";

            case GIALLO -> {

                int i = 0;

                i++;

                yield i;
            }

            case VERDE ->
                "E' possibile attraversare.";

        };

        System.out.println(s);

    }

}
