/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.elencotelefonico;

import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.LinkedHashMap;
import java.util.Collection;
import java.util.Set;
import java.util.Iterator;


/**
 *
 * @author leonardorundo
 */
public class ElencoMap {
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        /* Esempio con HashMap o TreeMap */
        Map<Persona,String> elencoMap;
        elencoMap = new  HashMap<>();
        // elencoMap = new  TreeMap<>();
        
        elencoMap.put(new Persona("Luigi", "Rossi", "tyuio", 34), "08965432");
        elencoMap.put(new Persona("Luigia", "Verdi", "h5reg", 20), "081456732");
        elencoMap.put(new Persona("Pasquale", "Bianco", "lkmnh", 27), "063456778");
        elencoMap.put(new Persona("Martino", "Giallo", "rtghjn", 12), "08253456");
        elencoMap.put(new Persona("Luigia", "Verdi", "polkjnb", 28), "0985634765");
        elencoMap.put(new Persona("Vittoria", "Rosa", "nbvcd", 20), "082865436");
        elencoMap.put(new Persona("Antonio", "Bianco", "mnbvc", 27), "082865436");
        
        String tel = elencoMap.get(new Persona("","","tyuio", 19));
        System.out.println("Telefono: " + tel);
        
        //Sovrscrittura di un numero di telefono già presente
        String precTel = elencoMap.put(new Persona("Antonio", "Bianco", "mnbvc", 27), "089556677");
        System.out.println("Telefono prec: " + precTel);
        
        // Utilizzo del metodo keySet
        Set<Persona> setP = elencoMap.keySet();
        
        for(Persona p : setP){
            System.out.println(p);
        }
        
        // Utilizzo del metodo values
        Collection<String> collVal = elencoMap.values();
        for(String st: collVal)
            System.out.println(st);
        
        // Utilizzo del metodo entrySet
        Set<Map.Entry<Persona,String>> elenco_entrySet = elencoMap.entrySet();
        Iterator<Map.Entry<Persona,String>> it = elenco_entrySet.iterator();
        System.out.println(elenco_entrySet);
        while(it.hasNext()){
            Map.Entry<Persona,String> elem = it.next();
            System.out.println(elem.getKey() + " -> " + elem.getValue());
        }
                
        
        /* Esempio Linked Hash Map */
        Map<Integer,String> elenco_lhmap = new LinkedHashMap<>();        
        elenco_lhmap.put(101,"Pippo");    
        elenco_lhmap.put(102,"Pluto");    
        elenco_lhmap.put(103,"Topolino");
        elenco_lhmap.put(104,"Paperino");
        
        System.out.println("Prima dell'invocazione dei metodi: " + elenco_lhmap);     
        
        elenco_lhmap.put(102,"Orazio");
        elenco_lhmap.put(105,"Minnie");
        elenco_lhmap.remove(103);
        
        System.out.println("Dopo l'invocazione dei metodi: " + elenco_lhmap);      
    }
    
}
