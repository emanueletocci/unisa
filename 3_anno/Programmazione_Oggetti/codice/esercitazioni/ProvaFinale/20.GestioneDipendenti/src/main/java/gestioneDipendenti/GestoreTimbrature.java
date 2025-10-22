package gestioneDipendenti;
import java.io.*;
import java.time.LocalDateTime;
import java.util.*;

public class GestoreTimbrature {
    private Map<String, Set<TimbraturaDipendente>> gestoreTimbrature;

    public GestoreTimbrature(){
        // La treeMap mi consente di ordinare automaticamente rispetto alle chiavi, ovvero per codice fiscale
        gestoreTimbrature = new TreeMap<>();
    }

    public void registraIngresso(TimbraturaDipendente timbro){
        if(gestoreTimbrature.containsKey(timbro.getDipendente().getCodiceFiscale())){
            /* Se la chiave é giá presente devo solamente aggiungere la timbratura al set interno*/
            gestoreTimbrature.get(timbro.getDipendente().getCodiceFiscale()).add(timbro);
        } else{
            /* Se la chiave non é presente bisogna creare anche il set delle timbrature */
            Set<TimbraturaDipendente> t= new TreeSet<>();
            t.add(timbro);
            gestoreTimbrature.put(timbro.getDipendente().getCodiceFiscale(), t);
        }
    }

    public Set<TimbraturaDipendente> cercaDipendente(String cf){
        if(gestoreTimbrature.containsKey(cf.trim().toUpperCase())){
            return gestoreTimbrature.get(cf);
        } else {
            System.out.println("Dipendente non trovato\n");
            return new TreeSet<>();
        }
    }

    public void stampaTimbrature(Set<TimbraturaDipendente> timbri){
        StringBuffer sb = new StringBuffer();
        for(TimbraturaDipendente t : timbri){
            sb.append(t.toString());
        }
        System.out.println(sb.toString());
    }

    public Set<TimbraturaDipendente> getAllTimbrature(){
        Set<TimbraturaDipendente> tempSet = new TreeSet<>();
        for(Map.Entry<String, Set<TimbraturaDipendente>> entry : gestoreTimbrature.entrySet()){
            String key = entry.getKey();
            Set<TimbraturaDipendente> value = entry.getValue();
            tempSet.addAll(value);
        }
        return tempSet;
    }

    public void stampaTuttiTimbri(){
        StringBuffer sb = new StringBuffer();
        String previusKey = "";
        for(Map.Entry<String, Set<TimbraturaDipendente>> entry : gestoreTimbrature.entrySet()){
            String key = entry.getKey();
            Set<TimbraturaDipendente> value = entry.getValue();
            if(!key.equalsIgnoreCase(previusKey))
                sb.append("\n**Dipendente: " +  key + "**\n");
            for(TimbraturaDipendente t : value) {
                sb.append(t);
            }
            previusKey = key;
        }
        System.out.println(sb.toString());
    }

    public void stampaSuFile(String cf, Set<TimbraturaDipendente> timbriDipendente) throws IOException {
        try(DataOutputStream writer = new DataOutputStream(new BufferedOutputStream(new FileOutputStream(cf.trim().toUpperCase() + ".bin")))){
            for (TimbraturaDipendente t : timbriDipendente){
                writer.writeUTF(t.getDipendente().getCodiceFiscale());
                writer.writeUTF(t.getDipendente().getNome());
                writer.writeUTF(t.getDipendente().getCognome());
                LocalDateTime dataOra = t.getDataOra();
                writer.writeInt(dataOra.getYear());
                writer.writeInt(dataOra.getMonthValue());
                writer.writeInt(dataOra.getDayOfMonth());
                writer.writeInt(dataOra.getHour());
                writer.writeInt(dataOra.getMinute());
                writer.writeChar('\n');
            }
        }
    }

    public Set<TimbraturaDipendente> leggiDaFile(String cf) throws IOException {
        Set<TimbraturaDipendente> tempSet = new TreeSet<>();
        try (DataInputStream reader = new DataInputStream(new BufferedInputStream(new FileInputStream(cf.trim().toUpperCase() + ".bin")))) {
            while (reader.available() > 0) {
                String codiceFiscale = reader.readUTF();
                String nome = reader.readUTF();
                String cognome = reader.readUTF();
                int year = reader.readInt();
                int month = reader.readInt();
                int day = reader.readInt();
                int hour = reader.readInt();
                int minute = reader.readInt();
                reader.readChar(); // Leggiamo e scartiamo il '\n'

                LocalDateTime dataOra = LocalDateTime.of(year, month, day, hour, minute);

                Dipendente tempDip = new Dipendente(nome, cognome, codiceFiscale);
                tempSet.add(new TimbraturaDipendente(tempDip, dataOra));
                System.out.println("CF: " + codiceFiscale + " - Data/Ora: " + dataOra);
            }
        }
        return tempSet;
    }
}
