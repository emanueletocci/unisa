import java.util.List;
import java.util.Set;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        System.out.println(PrintColors.format("\n***LISTA COMPLETA AGRITURISMI***\n", PrintColors.BLUE));

        ElencoAgriturismi elenco = new ElencoAgriturismi().carica("Agriturismi-Benevento.csv");
        System.out.println(elenco);

        // Aggiornamento Pernottamento/Camping

        Stream.of(elenco).filter()

        // Filtro per comune
        System.out.println(PrintColors.format("\n***FILTRO COMUNE***\n", PrintColors.BLUE));
        List<?> listaComuni = elenco.esporta(a -> a.getComuneAzienda());
        for (Object comune : listaComuni) {
            System.out.println(comune);
        }

        // Ordinamento
        System.out.println(PrintColors.format("\n***ORDINAMENTO NOME AZIENDA***\n", PrintColors.BLUE));
        elenco.ordina((a,b) -> a.getNomeAzienda().compareTo(b.getNomeAzienda()));
        System.out.println(elenco);

        // Comune con piu posti campeggio
        System.out.println(PrintColors.format("\n***POSTI CAMPEGGIO***\n", PrintColors.BLUE));
        System.out.println(elenco.postiCampeggio());

    }
}