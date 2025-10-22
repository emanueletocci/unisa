/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg14.ingv;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 *
 * @author emanueletocci
 */
public class EQReport implements Iterable<EQEvent>, Cloneable {
    private String name;
    private List<EQEvent> report;
    
    public EQReport(String name){
        this.name = name;
        report = new LinkedList<>();
    }
    
    public void addEvent(EQEvent e){
        report.add(e);
    }
    
    public void sort(){
        report.sort(null);
    }
    
    public void sort(Comparator<EQEvent> c){
        report.sort(c);
    }
    
    public static EQReport readFromTextFile(String filename){
        EQReport report = new EQReport("Reading from file: " + filename);
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))){
            String line;
            while ((line = reader.readLine()) != null){
                EQEvent e = new EQEvent();
                String[] tokens = line.split("\\|");
                e.setEventID(tokens[0]);
                e.setTime(LocalDateTime.parse(tokens[1]));
                e.setLatitude(Double.parseDouble(tokens[2]));
                e.setLongitude(Double.parseDouble(tokens[3]));
                e.setDepthkm(Double.parseDouble(tokens[4]));
                e.setAuthor(tokens[5]);
                e.setCatalog(tokens[6]);
                e.setContributor(tokens[7]);
                e.setContributorID(tokens[8]);
                e.setMagType(tokens[9]);
                e.setMagnitude(Double.parseDouble(tokens[10]));
                e.setMagAuthor(tokens[11]);
                e.setEventLocationName(tokens[12]);
                
                report.addEvent(e);
            }
        } catch (FileNotFoundException ex){
            ex.printStackTrace();
        } catch (IOException ex){
            ex.printStackTrace();
        }    
        return report;
    }
        
    public static void printToTextFile(EQReport eqr, String filename){
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for(EQEvent e : eqr) {
                writer.write(   e.getEventID() + '|' +
                        e.getTime()+ '|'+
                        e.getLatitude() + '|'+
                        e.getLongitude()+ '|' +
                        e.getDepthkm()+ '|' +
                        e.getAuthor() + '|'+
                        e.getCatalog()+ '|'+
                        e.getContributor() +'|'+
                        e.getContributorID()+ '|'+
                        e.getMagType()+ '|'+
                        e.getMagnitude()+ '|'+
                        e.getMagAuthor() + '|' +
                        e.getEventLocationName()+ '\n');
            }
        } catch (FileNotFoundException ex){
            ex.printStackTrace();
        } catch (IOException ex){
            ex.printStackTrace();
        }   
    }
    
    @Override
    public Iterator<EQEvent> iterator(){
        return report.iterator();
    }
    
    @Override
    public String toString() {
        return "EQReport{" + "name=" + name + " \n" + report + '}' + "\n\n";
    }

    @Override
    protected Object clone() {
        Object cloned = null;
        try{
            cloned = super.clone();
        } catch (CloneNotSupportedException ex){
            ex.printStackTrace();
        }
        return cloned;
    }
}
