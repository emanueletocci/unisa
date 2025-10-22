package Agriturismo;
import java.util.*;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;

public class ElencoAgriturismi {
    private List<Agriturismo> elencoAgriturismi;

    public ElencoAgriturismi(){
        this.elencoAgriturismi = new LinkedList<>();
    }

    public void aggiungiAgriturismo(Agriturismo a){
        elencoAgriturismi.add( a);
    }

    // Estrazione attributi
    public <T> Set<T> esporta(Function<Agriturismo, T> function){
        Set risultato = new HashSet<>();
        for(Agriturismo a : elencoAgriturismi){
            risultato.add(function.apply(a));
        }
        return risultato;
    }

    // Filtraggio
    public Map<String, Agriturismo> filtra(Predicate<Agriturismo> predicate){
        Map<String , Agriturismo> risultato = new HashMap<>();
        for(Agriturismo a: elencoAgriturismi){
            if(predicate.test(a)){
                risultato.put(a.getComune(), a);
            }
        }
        return risultato;
    }

    public void ordina(Comparator<Agriturismo> comparator){
        elencoAgriturismi.sort(comparator);
    }

    // Aggiornamento elenco
    public void aggiorna(Consumer<Agriturismo> consumer){
        for(Agriturismo a : elencoAgriturismi){
            consumer.accept(a);
        }
    }

}
