/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package oop2017.contest1.gruppoXX;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Objects;

/**
 *
 * @author emanueletocci
 */
public class Aeroporto {
    private List<Aeromobile> l;
    private CodeChecker checker;
    
    public Aeroporto(CodeChecker checker){
        this.checker = checker;
        l = new ArrayList<>();
    }
    
    public Aeromobile cerca(String codice){
        Iterator<Aeromobile> i = l.iterator();
        while(i.hasNext()){
            Aeromobile tempAereo = i.next();
            if (tempAereo.getCodice().equals(codice)){
                return tempAereo;
            }
        }
        return null;
    }
    
    public Aeromobile rimuovi(String codice){
        Iterator<Aeromobile> i = l.iterator();
        while(i.hasNext()){
            Aeromobile tempAereo = i.next();
            if (tempAereo.getCodice().equals(codice)){
                l.remove(tempAereo);
                return tempAereo;
            }
        }
        return null;
    }
    
    public boolean inserisci(Aeromobile a){
        if ((checker == null) || (checker.check(a.getCodice()))){
            this.l.add(a);
            return true;
        }
        return false;
    }
    
    public int elementi(){
        return l.size();
    }
    
    @Override
    public String toString(){
        return "\n" + l.toString();
    }
    
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Aeroporto other = (Aeroporto) obj;
        return Objects.equals(this.l, other.l);
    }
}
