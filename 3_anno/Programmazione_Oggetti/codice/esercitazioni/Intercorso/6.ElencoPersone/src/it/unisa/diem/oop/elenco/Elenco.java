/* IMPORT DA COMPLETARE*/
package it.unisa.diem.oop.elenco;
import java.util.ArrayList;
import java.util.List;

public class Elenco {
    List<Persona> persone;
    
    public Elenco(){
        persone = new ArrayList<>();
    }

    public void aggiungi(Persona p) {
        this.persone.add(p);
    }

    @Override
    public String toString() {
        return persone.toString();
    }

}
