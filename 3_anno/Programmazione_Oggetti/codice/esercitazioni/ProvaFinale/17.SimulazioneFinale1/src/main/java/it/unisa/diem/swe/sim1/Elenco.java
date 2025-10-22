package it.unisa.diem.swe.sim1;

import java.io.*;
import java.util.TreeMap;
import java.util.Map;

public class Elenco {
    Map<String,Persona> listaPersone;

    public Elenco() {
        listaPersone = new TreeMap<> (); //ordinamento basato sulle chiavi
    }

    public void aggiungi(Persona p) {
        listaPersone.put(p.getCodiceFiscale(), p);
    }

    public Persona cerca(String codFiscale) {
        return listaPersone.get(codFiscale);
    }

    public void stampaSuFile(String nomeFile) {
        StringBuffer sb = new StringBuffer();
        for(Persona p : listaPersone.values()){
            sb.append(p.getNome());
            sb.append(",");
            sb.append(p.getCodiceFiscale());
            sb.append(",");
            sb.append(p.getDataNascita());
            sb.append(",");
        }
        try(BufferedWriter writer = new BufferedWriter (new FileWriter (nomeFile))){
            writer.write(sb.toString());
        } catch (IOException ex){
            ex.printStackTrace();
        }

    }
    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        for(Map.Entry<String,Persona> entry : listaPersone.entrySet()) {
            sb.append("Key : ").append(entry.getKey()).append("\n");
            sb.append(entry.getValue());
        }
        return sb.toString();
    }
}
