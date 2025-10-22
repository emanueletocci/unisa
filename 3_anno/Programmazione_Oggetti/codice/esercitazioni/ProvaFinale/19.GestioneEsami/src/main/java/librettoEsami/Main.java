package librettoEsami;
import java.io.IOException;
import java.util.Scanner;
import static java.lang.System.*;
import java.time.LocalDate;

public class Main {
    public static void main(String[] args) throws IOException {
        LibrettoEsami libretto = new LibrettoEsami();
        out.println("Questo programma Java simula la gestione di un'insieme di libretti universitari.");
        libretto = libretto.leggiFileAlternativo("esami.txt");  // Sovrascrivo il riferimento
        libretto.aggiungiEsame(new EsameSuperato("061277488", LocalDate.of(2020, 12, 11), "OOP", 30));
        libretto.aggiungiEsame(new EsameSuperato("061277488", LocalDate.of(2020, 12, 11), "Basi di Dati", 30));
        libretto.aggiungiEsame(new EsameSuperato("061277488", LocalDate.of(2020, 12, 11), "Analisi 1", 30));

        libretto.leggiFileAlternativo("altriEsami.txt");
        libretto.raggruppaPerMatricola();
        libretto.raggruppaPerInsegnamento();

        Integer scelta = 0;

        // Creiamo lo scanner prima del ciclo principale
        try (Scanner reader = new Scanner(System.in)) {
            do {
                out.println("\n****MENU****\n");
                out.println("1 - Visualizza Libretti \n2 - Ricerca Matricola \n3 - Ricerca Insegnamento\n ");
                out.println("Inserire il numero corrispondente alla scelta selezionata...\n");

                scelta = reader.nextInt();  // Legge la scelta dell'utente

                switch (scelta) {
                    case 1:
                        out.println("Scelta = 1 - Avvio Simulazione");
                        simulazione(libretto);  // Passa l'oggetto libretto alla simulazione
                        break;
                    case 2:
                        out.println("Scelta = 2 - Avvio Ricerca Matricola\n");
                        out.println("Inserire matricola da cercare: \n");
                        reader.nextLine();  // Consuma il newline residuo dopo nextInt
                        String matricola = reader.nextLine().trim().toUpperCase();  // Legge la matricola
                        out.println("Cerco la matricola: " + matricola + "\n");
                        libretto.ricercaMatricola(matricola);
                        break;
                    case 3:
                        out.println("Scelta = 3 - Ricerca Insegnamento");
                        out.println("Inserire insegnamento da cercare: \n");
                        reader.nextLine();  // Consuma il newline residuo dopo nextInt
                        String insegnamento = reader.nextLine().trim().toUpperCase();  // Legge l'insegnamento
                        out.println("Cerco l'insegnamento: " + insegnamento + "\n");
                        libretto.ricercaInsegnamento(insegnamento);
                        break;
                    default:
                        err.println("ERROR! Scelta non valida, riprovare");
                }

                out.println("\nSe vuoi ricominciare, inserisci '5'. Altrimenti, inserisci un altro numero per uscire.");
                Integer uscita = reader.nextInt();

                // Verifica se l'utente vuole continuare o uscire
                if (uscita != 5) {
                    out.println("Uscita dal programma...");
                    break;  // Uscita dal ciclo do-while
                }

            } while (true); // Continua fino a quando l'utente non decide di uscire
        } catch (Exception e) {
            err.println("Errore nella lettura dell'input: " + e.getMessage());
        }
    }


    private static void simulazione(LibrettoEsami libretto) throws IOException {
        out.println("\n**LISTA LIBRETTI UNIVERSITARI**\n");
        libretto.stampaLista();
        out.println("\n**LISTA LIBRETTI ORDINATO PER MATRICOLE**\n");
        libretto.stampaPerMatricola();
        out.println("\n**LISTA LIBRETTI ORDINATO PER INSEGNAMENTO**\n");
        libretto.stampaPerInsegnamento();
    }
}
