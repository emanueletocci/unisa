import java.util.Set;

public class TestAgriturismiLambda {
    public static void main(String[] args) {
        ElencoAgriturismi elenco = new ElencoAgriturismi().carica("agriturismi.csv");
        System.out.println(elenco);

        // Filtro per comune
        System.out.println("\n***FILTRO PER COMUNE***\n");
        Set<?> listaComuni = elenco.esporta(a -> a.getComuneAzienda());
        System.out.println(listaComuni);

        // Filtro
        ElencoAgriturismi elencoCamping = elenco.filtra(a -> a.isCamping());
        System.out.println(elencoCamping);

        System.out.println(elenco.filtra(a -> a.getComuneAzienda().equals("Acerra")));

    }
}
