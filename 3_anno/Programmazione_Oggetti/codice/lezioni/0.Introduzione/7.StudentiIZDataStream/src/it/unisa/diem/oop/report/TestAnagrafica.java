package it.unisa.diem.oop.report;
import it.unisa.diem.oop.persone.Studente;
import java.io.IOException;

/**
 *
 * @author lucagreco
 */

public class TestAnagrafica {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {        
        AnagraficaStudenti a = new AnagraficaStudenti("OOP");
        
        a.aggiungi(new Studente("Mario", "Rossi", "MRS0001", "06127001", 28.5F));
        a.aggiungi(new Studente("Stefano", "Rossi", "STS0001", "06127002", 28.5F));
        a.aggiungi(new Studente("Mario", "Bianchi", "MBS0001", "06127003", 28.5F));
        
        System.out.println(a);
        a.salvaDOS("anagrafica.bin");
        
        AnagraficaStudenti a2 = AnagraficaStudenti.leggiDOS("anagrafica.bin");
        System.out.println(a2);
    }
}
