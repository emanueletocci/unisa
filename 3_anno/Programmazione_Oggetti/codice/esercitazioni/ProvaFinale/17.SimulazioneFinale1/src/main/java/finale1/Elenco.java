package finale1;

/* IMPORT DA COMPLETARE*/
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.Map;

public class Elenco {
    Map<String, Persona> elencoPersone;

    public Elenco(){
        elencoPersone = new LinkedHashMap<>();
    }
    public void aggiungi(Persona p) {
        elencoPersone.putIfAbsent(p.getCodiceFiscale(), p);
    }
    
    public Persona cerca(String codFiscale) {
        return elencoPersone.get(codFiscale.toUpperCase());
    }
    
    public void stampaSuFile(String nomeFile) throws IOException {
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(nomeFile))){
            StringBuffer sb = new StringBuffer();
            for (Persona p : elencoPersone.values()){
                sb.append(p);
            }
            writer.write(sb.toString());
        }
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        Iterator<Persona> it = elencoPersone.values().iterator();
        while(it.hasNext()){
            sb.append(it.next().toString());
        }
        return sb.toString();
    }
    
}