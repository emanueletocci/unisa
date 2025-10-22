package ristorante;
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Comande implements Serializable{
    private final String filename;
    private Boolean leggiBackup;
    private Queue<Ordinazione> listaOrdinazioni;

    public Comande (String filename, Boolean leggiBackup){
        this.filename = filename;
        this.leggiBackup = leggiBackup;

        if(leggiBackup){    // se true la lista deve essere importata da file
            listaOrdinazioni = (Queue<Ordinazione>) leggiDaFile();
        } else{
            listaOrdinazioni = new LinkedList<>();
        }
    }

    public synchronized void aggiungiOrdinazione(Ordinazione ordinazione){
        listaOrdinazioni.add(ordinazione);
        notifyAll();
    }

    public synchronized Ordinazione consegnaOrdinazione(){
        while(listaOrdinazioni.isEmpty()){
            try{
                wait();     // blocco il thread corrente se la coda é vuota dato che non posso rimuovere nulla
            } catch (InterruptedException e){
                e.printStackTrace();
            } catch (Exception ex){
                ex.printStackTrace();
            }
        }
        notifyAll();
        return listaOrdinazioni.remove();
    }

    public synchronized void salvaOrdinazioni(){
        // SERIALIZZAZIONE
        while(listaOrdinazioni.isEmpty()){
            try{
                wait();
            } catch (Exception e){
                e.printStackTrace();
            }
        }
        try(ObjectOutputStream writer = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(filename)))){
            writer.writeObject(listaOrdinazioni);
        } catch (IOException e){
            e.printStackTrace();
        }
    }

    private Object leggiDaFile(){
        try(ObjectInputStream reader = new ObjectInputStream(new BufferedInputStream(new FileInputStream(filename)))){
           return reader.readObject();
        } catch (IOException e){
            e.printStackTrace();
        } catch (Exception e){
            e.printStackTrace();
        }
        return null;
    }

}
