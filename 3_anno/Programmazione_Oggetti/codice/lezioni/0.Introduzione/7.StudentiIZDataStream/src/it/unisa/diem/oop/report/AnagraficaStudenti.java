/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.report;

import it.unisa.diem.oop.persone.Studente;
import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author lucagreco
 */
public class AnagraficaStudenti {
    
    private String descrizione;
    private Map<String,Studente> anagrafica;
    
    
    public AnagraficaStudenti(String descrizione) {
    
        this.descrizione = descrizione;
        
        anagrafica = new HashMap<>();
 
    }
    
    
    public void aggiungi(Studente s) {
    
        anagrafica.putIfAbsent(s.getMatricola(), s);
    
    }
    
    public Studente cerca(String matricola) {
    
        return anagrafica.get(matricola);
    
    
    }
    
    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer("Anagrafica: " + descrizione + "\n");
    
        for(Studente s : anagrafica.values() ) {
            sb.append(s + "\n");
        }
        
        return sb.toString();
    }
    
    public void salvaDOS(String nomefile) throws IOException {
        FileOutputStream fos = new FileOutputStream(nomefile);
        DataOutputStream dos = new DataOutputStream(fos);
        dos.writeUTF(descrizione);
        
        for(Studente s : anagrafica.values()) {
            dos.writeUTF(s.getNome());
            dos.writeUTF(s.getCognome());
            dos.writeUTF(s.getCodiceFiscale());
            dos.writeUTF(s.getMatricola());
            dos.writeFloat(s.getVotoMedio());
        }
        
        dos.close();
    }
    
    
    public static AnagraficaStudenti leggiDOS(String nomefile) throws IOException {
        FileInputStream fis = new FileInputStream(nomefile);
        BufferedInputStream bis = new BufferedInputStream(fis);
        DataInputStream dis = new DataInputStream(bis);
        AnagraficaStudenti a = null;
        
        try {          
         String descrizione = dis.readUTF();      
         a = new AnagraficaStudenti(descrizione);
        
            while(true) {           
                String nome = dis.readUTF();
                String cognome = dis.readUTF();
                String codFiscale = dis.readUTF();
                String matricola = dis.readUTF();
                float votoMedio = dis.readFloat();
                
                Studente s = new Studente(nome,cognome,codFiscale,matricola,votoMedio);                
                a.aggiungi(s);
            }
        }
        catch(EOFException ex) {
            System.out.println("Lettura completata.");
        }
        finally{
            dis.close();
        }
    return a;
    
    }  
}
