package librettoEsami;
import com.sun.source.tree.Tree;

import java.io.*;
import java.nio.Buffer;
import java.time.LocalDate;
import java.util.Map;
import java.util.*;

public class LibrettoEsami {

    /*
     * Ho scelto come struttura dati un TreeSet per gestire eventuali esami duplicati. Per come é stato pensato l'attributo id,
     * due esami sono uguali solamente se hanno in comune la matricola e il nome dell'insegnamento. Il campo ID viene infatti generato
     * attraverso il metodo hashCode definito in EsameSuperato. Se due esami hanno lo stesso id significa che hanno gli stessi campi
     * matricolaStudente e NomeInsegnamento.

     * Il TreeSet mi garantisce l'ordinamento basato sull'id e la gestione automatica dei duplicati (considero valido il primo voto
     * presente nel catalogo, a paritá di id).
     */

    private Set<EsameSuperato> listaEsami;
    private Map<String, Set<EsameSuperato>> librettoInsegnamento = new HashMap<>();
    private Map<String, Set<EsameSuperato>> librettoMatricola = new HashMap<>();

    public LibrettoEsami(){
        listaEsami = new TreeSet<>();
    }

    public boolean aggiungiEsame(EsameSuperato e ){
        return listaEsami.add(e); //ritorna false se l'elemento che si cerca di inserire é giá presente
    }

    public boolean rimuoviEsame(EsameSuperato e){
        return listaEsami.remove(e); //ritorna false se il Set non contiene l'elemento che si vuole rimuovere
    }

    @Override
    public String toString(){
        StringBuffer sb = new StringBuffer();
        for(EsameSuperato e : listaEsami){
            sb.append(e.toString());
        }
        return sb.toString();
    }

    public void stampaLista(){
        System.out.printf("*Sono presenti %d esami*\n", listaEsami.size());
        StringBuffer sb = new StringBuffer();
        for(EsameSuperato e : listaEsami){
            sb.append(e.toString());
        }
        System.out.println(sb.toString());
    }

    public Map<String, Set<EsameSuperato>> raggruppaPerMatricola(){
        for(EsameSuperato e : listaEsami){
            if(librettoMatricola.containsKey(e.getMatricolaStudente()))
                librettoMatricola.get(e.getMatricolaStudente()).add(e); // prelevo la lista e aggiungo il nuovo valore
            else {
                Set<EsameSuperato> t = new TreeSet<>();
                t.add(e);
                /*
                 * Se la matricola non é presente, creo un nuovo TreeSet e lo aggiungo come valore, insieme alla matricola (chiave)
                 */
                librettoMatricola.put(e.getMatricolaStudente().trim().toUpperCase(), t);
            }
        }
        return librettoMatricola;
    }

    public void stampaPerInsegnamento(){
        int count = 0;
        StringBuffer sb = new StringBuffer();
        String previusKey = "";
        for(Map.Entry<String, Set<EsameSuperato>> entry : librettoInsegnamento.entrySet()){
            String key = entry.getKey().toUpperCase();
            if(key != previusKey.toUpperCase())
                sb.append("\n** INSEGNAMENTO: ").append(key).append(" **\n");
            for(EsameSuperato esame : entry.getValue()) {
                sb.append(esame.toString());
                count ++;
            }
        }
        System.out.printf("*Sono presenti %d esami*\n", count);
        System.out.println(sb.toString());
    }

    public void stampaPerMatricola(){
        int count = 0;
        StringBuffer sb = new StringBuffer();
        String previusKey = "";
        for(Map.Entry<String, Set<EsameSuperato>> entry : librettoMatricola.entrySet()){
            String key = entry.getKey().toUpperCase();
            if(key != previusKey.toUpperCase())
                sb.append("\n\n** MATRICOLA: ").append(key).append(" **\n");
            for(EsameSuperato esame : entry.getValue()) {
                sb.append(esame.toString());
                count ++;
            }
        }
        System.out.printf("*Sono presenti %d esami*\n", count);
        System.out.println(sb.toString());
    }

    public void ricercaMatricola(String matricola){
        matricola = matricola.trim().toUpperCase();
        StringBuffer sb = new StringBuffer();
        if(librettoMatricola.containsKey(matricola)){
            for(EsameSuperato esame : librettoMatricola.get(matricola)){
                sb.append(esame.toString());
            }
            System.out.println(sb.toString());
        } else {
            System.out.println("Matricola non trovata!\n");
        }
    }
    public void ricercaInsegnamento(String nome){
        nome = nome.trim().toUpperCase();
        StringBuffer sb = new StringBuffer();
        if(librettoInsegnamento.containsKey(nome)){
            for(EsameSuperato esame : librettoInsegnamento.get(nome)){
                sb.append(esame.toString());
            }
            System.out.println(sb.toString());
        } else {
            System.out.println("Insegnamento non trovato!\n");
        }
    }

    /* Questo metodo consente di raggruppare gli esami per insegnamento*/
    public Map<String, Set<EsameSuperato>> raggruppaPerInsegnamento(){
        for(EsameSuperato e : listaEsami){
            if(librettoInsegnamento.containsKey(e.getNomeInsegnamento()))
                librettoInsegnamento.get(e.getNomeInsegnamento()).add(e);
            else{
                Set<EsameSuperato> t = new TreeSet<>();
                t.add(e);
                librettoInsegnamento.put(e.getNomeInsegnamento().trim().toUpperCase(), t);
            }
        }
        return librettoInsegnamento;
    }

    public void leggiFile(String filename) throws IOException {
        try(Scanner reader = new Scanner(new BufferedReader(new FileReader(filename)))){
            reader.useDelimiter(",|\\n");
            while(reader.hasNext()){
                String matricola = reader.next();
                LocalDate data = LocalDate.parse(reader.next());
                String nomeEsame = reader.next();
                Integer voto = Integer.parseInt(reader.next());
                EsameSuperato esame = new EsameSuperato(matricola, data, nomeEsame, voto);
                this.aggiungiEsame(esame);
            }
        }
    }

    /*
     * Funzione che crea un nuovo libretto basato sul contenuto di un file testuale e lo restituisce. A differenza del metodo precendente, questo crea un nuovo libretto.
     */
    public LibrettoEsami leggiFileAlternativo(String filename) throws IOException{
        LibrettoEsami l = new LibrettoEsami();
        try(BufferedReader reader = new BufferedReader(new FileReader(filename))){
            String line;
            while((line = reader.readLine()) != null){
                String[] tokens = line.split(",");
                String matricola = tokens[0];
                LocalDate data = LocalDate.parse(tokens[1]);
                String nomeEsame = tokens[2];
                Integer voto = Integer.parseInt(tokens[3]);
                EsameSuperato esame = new EsameSuperato(matricola, data , nomeEsame, voto);
                l.aggiungiEsame(esame);
            }
        }
        return l;
    }


}
