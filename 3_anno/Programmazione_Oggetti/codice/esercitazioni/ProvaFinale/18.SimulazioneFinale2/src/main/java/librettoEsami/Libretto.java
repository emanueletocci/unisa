package librettoEsami;

import java.io.*;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

public class Libretto {
    Set<librettoEsami.EsameSuperato> listaSuperati;

    public Libretto() {
        listaSuperati = new TreeSet<>();
    }

    public void aggiungi (librettoEsami.EsameSuperato e) {
        listaSuperati.add(e);
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        for (EsameSuperato esame : listaSuperati){
            sb.append(esame.toString());
        }
        return sb.toString();
    }

    public void salvaCSV(String nomefile) {
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(nomefile))){
            writer.write(this.toString());
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}