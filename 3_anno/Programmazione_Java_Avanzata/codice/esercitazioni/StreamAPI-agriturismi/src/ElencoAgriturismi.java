import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;
import java.util.stream.Stream;

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

    public <R> List<R> esporta(Function<Agriturismo, R> estrattore) {
        return agriturismi.stream()
                .map(estrattore)
                .distinct()
                .collect(Collectors.toList());
    }

    public void ordina(Comparator<Agriturismo> comparator) {
        agriturismi.sort(comparator);
    }

    public void aggiorna(Consumer<Agriturismo> aggiorna) {
        for (Agriturismo agriturismo : agriturismi) {
            aggiorna.accept(agriturismo);
        }
    }

    public int postiCampeggio(){
        return agriturismi.stream().mapToInt(a -> a.getPostiRoulotte() + a.getPostiTenda()).sum();
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
        try{
            Files.lines(Path.of(filename))
                    .skip(1)
                    .map(l -> {
                        String tokens[] = l.split(";");
                        return new Agriturismo(tokens[0],
                                tokens[1].isEmpty() ? null : tokens[1],
                                tokens[2].isEmpty() ? null : tokens[2],
                                tokens[3].isEmpty() ? null : tokens[3],
                                tokens[4].isEmpty() ? 0 : Integer.parseInt(tokens[4]),
                                tokens[5].isEmpty() ? 0 : Integer.parseInt(tokens[5]),
                                tokens[6].isEmpty() ? 0 : Integer.parseInt(tokens[6]),
                                tokens[7].isEmpty() ? 0 : Integer.parseInt(tokens[7]),
                                tokens[8].isEmpty() ? null : tokens[8]);
                    }).toList().forEach(risultato::aggiungi);
        } catch(IOException e){
            e.printStackTrace();
        }
        return risultato;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Agriturismo agriturismo : agriturismi) {
            sb.append(agriturismo.toString());
        }
        return sb.toString();
    }



}
