/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg11.intercorso2015.dipendenti;

import javax.swing.JOptionPane;
import pkg11.intercorso2015.exceptions.DipendenteDuplicatoException;

/**
 *
 * @author Gennaro
 */
public class GestioneDipendenti {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        PresenzeDipendenti p = new PresenzeDipendenti();
        Dipendente d=null;
        int op;
        
        try {
            p.aggiungiNuovoDipendente(d = new Tecnico("Pinco Pallo", 123, "Napoli"));
        } catch (DipendenteDuplicatoException ex) {
            System.out.println("Errore inserimento: elemento già presente " + d);
        }
        try {
            p.aggiungiNuovoDipendente(d = new Tecnico("Pinco Pallo", 123, "Napoli"));
        } catch (DipendenteDuplicatoException ex) {
            System.out.println("Errore inserimento: elemento già presente: " + d);
        }
        try {
            p.aggiungiNuovoDipendente(d = new Tecnico("Marco Rossi", 123, "Roma"));
        } catch (DipendenteDuplicatoException ex) {
            System.out.println("Errore inserimento: elemento già presente " + d);
        }
        try {
            p.aggiungiNuovoDipendente(d = new Tecnico("Marco Rossi", 523, "Roma"));
        } catch (DipendenteDuplicatoException ex) {
            System.out.println("Errore inserimento: elemento già presente " + d);
        }
        try {
            p.aggiungiNuovoDipendente(d = new Impiegato("Marco Rossi", 523, "3390011223"));
        } catch (DipendenteDuplicatoException ex) {
            System.out.println("Errore inserimento: elemento già presente " + d);
        }
        try {
            p.aggiungiNuovoDipendente(d = new Impiegato("Luigi Bianchi", 155, "3390011223"));
        } catch (DipendenteDuplicatoException ex) {
            System.out.println("Errore inserimento: elemento già presente " + d);
        }
        try {
            p.aggiungiNuovoDipendente(d = new Impiegato("Matteo Bruno", 569, "3558544123"));
        } catch (DipendenteDuplicatoException ex) {
            System.out.println("Errore inserimento: elemento già presente " + d);
        }

        
        System.out.println(p);
        
    }
    
    private static int menu(){
        String txt = "Selezionare l'operazione da effettuare\n"
                + "1. Aggiungere un nuovo dipendente\n"
                + "2. Rimuovere un dipendente\n"
                + "3. Aggiornare le presenze di un dipendente\n"
                + "4. Visualizzare le presenze di tutti i dipendenti\n"
                + "5. Visualizzare le presenze dei soli tecnici\n"
                + "6. Aggiornare lo stipendio dei dipendenti\n"
                + "0. Per terminare\n"
                + "\nSelezionare: ";
        int scelta;
        do{
            scelta = Integer.parseInt(JOptionPane.showInputDialog(txt));
        }while( (scelta<0) || (scelta>6) );
        return scelta;
    }/*
    private static Dipendente acquisisci dipendente(){
        int scelta = Integer.parseInt(JOptionPane.showInputDialog("Selezionare 1 per un Tecnico, qualsiasi altro numero per un Impiegato"));
        if (scelta == 1){
            Dipendente d = new Tecnico
        return d;
    }*/
}
