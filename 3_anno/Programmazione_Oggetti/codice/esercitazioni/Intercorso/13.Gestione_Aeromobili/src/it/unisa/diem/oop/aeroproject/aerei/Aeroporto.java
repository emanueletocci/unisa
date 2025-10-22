/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop.aeroproject.aerei;
import java.util.Map;
import it.unisa.diem.oop.aeroproject.checks.CodeChecker;
import java.util.HashMap;
 
/**
 *
 * @author emanueletocci
 */
public class Aeroporto{
    private Map <String, Aeromobile> hangar;
    private CodeChecker checker;
    
    public Aeroporto(CodeChecker checker){
        hangar = new HashMap();
        this.checker = checker;
    }
    public boolean inserisci(Aeromobile a){
        if ((checker == null) || (checker.check(a.getCodice()))){
            hangar.putIfAbsent(a.getCodice(), a);
            return true;
        }
        return false;
    }
    

  
    public Aeromobile cerca(String codice){
        try{
            if(hangar.containsKey(codice)){
                Aeromobile a = hangar.get(codice);
                Aeromobile cloned = (Aeromobile) a.clone();
                return cloned;
            }
        } catch(CloneNotSupportedException e){
            e.printStackTrace();
        }
        return null;
    }
    
    public Aeromobile rimuovi(String codice){
        return hangar.remove(codice);
    }
    
    public int elementi(){
        return hangar.size();
    }
    
    @Override
    public String toString(){
        StringBuffer sb = new StringBuffer ();
        for(Aeromobile s : hangar.values()){
            sb.append(s);
        }
        return sb.toString();    }
}
