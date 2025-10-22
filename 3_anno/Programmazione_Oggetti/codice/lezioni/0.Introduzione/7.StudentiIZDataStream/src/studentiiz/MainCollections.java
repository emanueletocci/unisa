/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package studentiiz;

import it.unisa.diem.oop.persone.EtaComparator;
import it.unisa.diem.oop.persone.Persona;
import it.unisa.diem.oop.persone.Studente;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

/**
 *
 * @author lucagreco
 */
public class MainCollections {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Persona p = new Persona("Mario20", "Rossi", "MRS0001");
        
        Persona p1 = p.clona();
        
        Persona s = new Studente("Stefano", "Grigi", "MRS0001", "06127001", 29.5F);
        
        boolean test1 = p.equals(p1);
       
       
        System.out.println(test1);
       
        List<Persona> persone;
  
       persone = new LinkedList<Persona>();
       
       persone.add(p);
       
      // persone.add(s);
       
       persone.add(p1);
       
       
       System.out.println(persone.contains(s));  // esempio contains
       
       
       System.out.println(persone.get(1));
       
      // System.out.println(persone);
      
      // costrutto for-each
      for(Persona pm : persone) {
      
          System.out.println(pm);
      
      }
      
      // tramite Iteratore
      Iterator<Persona> ip = persone.iterator();
      
      while(ip.hasNext()) {
      
          Persona pi = ip.next();
          
          System.out.println(pi);
      
      
      }
      
      System.out.println("SET");
        
    Set<Persona> persone2; 
    
    persone2 = new HashSet<Persona>();
    
    persone2.add(p);
    persone2.add(s);
    persone2.add(p1);
    
    System.out.println(persone2);
    
     System.out.println("TREE");
     
     Set<String> parole ;
     
     parole = new TreeSet<>();
     
     
     parole.add("Ciao");
     parole.add("Benvenuti");
     parole.add("Attenzione");
     
     System.out.println(parole);
     
     
     
     
     Set<Persona> persone3 ;
     
     persone3 = new TreeSet<>(new EtaComparator()); // ordine fissato da comparatore
     
    //  persone3 = new TreeSet<>(); // ordine naturale
     
     s.setEta(30);
     p.setEta(20);
     p1.setEta(20);
     
     
     
     persone3.add(s);
     persone3.add(p);
     persone3.add(p1);
     
     System.out.println(persone3);
    
        
    }
    
    
    
}
