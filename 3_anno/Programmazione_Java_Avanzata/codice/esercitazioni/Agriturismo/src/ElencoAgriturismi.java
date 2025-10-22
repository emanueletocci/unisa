import java.io.*;
import java.util.*;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;

public class ElencoAgriturismi {
    private List<Agriturismo> agriturismi;

    public ElencoAgriturismi() {
        agriturismi = new ArrayList<Agriturismo>();
    }

    public void aggiungi(Agriturismo agriturismo) {
        agriturismi.add(agriturismo);
    }

    public ElencoAgriturismi filtra(Predicate<Agriturismo> filtro) {
        ElencoAgriturismi risultato = new ElencoAgriturismi();
        for (Agriturismo agriturismo : agriturismi) {
            if (filtro.test(agriturismo)) {
                risultato.aggiungi(agriturismo);
            }
        }
        return risultato;
    }

    public <R> Set<R> esporta(Function<Agriturismo,R> estrattore) {
        var result = new HashSet<R>();
        for (Agriturismo agriturismo : agriturismi) {
            result.add(estrattore.apply(agriturismo));
        }
        return result;
    }

    public void ordina(Comparator<Agriturismo> comparator) {
        agriturismi.sort(comparator);
    }

    public void aggiorna(Consumer<Agriturismo> aggiorna) {
        for (Agriturismo agriturismo : agriturismi) {
            aggiorna.accept(agriturismo);
        }
    }

    public int somma(Function<Agriturismo, Integer> estrattore) {
        int somma = 0;
        for (Agriturismo agriturismo : agriturismi) {
            somma += estrattore.apply(agriturismo);
        }
        return somma;
    }

    public ElencoAgriturismi carica(String filename) {
        ElencoAgriturismi risultato = new ElencoAgriturismi();
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            System.out.println("\n***LETTURA DA FILE***\n");
            String line;
            reader.readLine();
            while ((line = reader.readLine()) != null) {
                String[] fields = line.split(";");
                if (fields.length >= 9) { // Ensure there are enough fields
                    String comune = fields[0];
                    String titolare = fields[1];
                    String nome = fields[2];
                    String indirizzo = fields[3];
                    int postiLetto = fields[4].isEmpty() ? 0 : Integer.parseInt(fields[4]);
                    int postiMacchina = fields[5].isEmpty() ? 0 : Integer.parseInt(fields[5]);
                    int postiTenda = fields[6].isEmpty() ? 0 : Integer.parseInt(fields[6]);
                    int postiRoulotte = fields[7].isEmpty() ? 0 : Integer.parseInt(fields[7]);
                    String recapito = fields[8];
                    risultato.aggiungi(new Agriturismo(comune, titolare, nome, indirizzo, postiLetto, postiMacchina, postiTenda, postiRoulotte, recapito));
                } else {
                    System.err.println("Riga ignorata: " + line);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return risultato;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for(Agriturismo a : agriturismi) {
            sb.append(a.toString());
        }
        return sb.toString();
    }
}
