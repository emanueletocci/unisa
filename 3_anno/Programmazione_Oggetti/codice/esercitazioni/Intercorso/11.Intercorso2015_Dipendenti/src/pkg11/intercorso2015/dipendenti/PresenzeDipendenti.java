/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg11.intercorso2015.dipendenti;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import pkg11.intercorso2015.exceptions.DipendenteAssenteException;
import pkg11.intercorso2015.exceptions.DipendenteDuplicatoException;

/**
 *
 * @author emanueletocci
 */
public class PresenzeDipendenti {
    private Map<Dipendente, Integer> m;
    
    public PresenzeDipendenti(){
        m = new HashMap<>();
    }
    
    public void aggiornaPresenzeDipendente(Dipendente d, int presenze) throws DipendenteAssenteException{
        if(!m.containsKey(d)) 
            throw new DipendenteAssenteException(d);
        m.replace(d,presenze);
    }
   
    public void aggiungiNuovoDipendente(Dipendente d) throws DipendenteDuplicatoException{
        if(m.containsKey(d)) 
            throw new DipendenteDuplicatoException(d);
        m.put(d, 0);
    }
    
    public void rimuoviDipendente(Dipendente d)throws DipendenteAssenteException {
        if(!m.containsKey(d)) 
            throw new DipendenteAssenteException(d);
        m.remove(d);
    }
    
    @Override
    public String toString(){
        return m.toString();
    }
    
    public Set<Tecnico> getTecnici(){
        Set<Map.Entry<Dipendente,Integer>> s = m.entrySet();
        Set<Tecnico> retVal = new HashSet<>();
        
        for(Map.Entry<Dipendente,Integer> e : s){
            if (e.getKey() instanceof Tecnico)
                retVal.add((Tecnico)e.getKey());
        }
        return retVal;
    }
}
