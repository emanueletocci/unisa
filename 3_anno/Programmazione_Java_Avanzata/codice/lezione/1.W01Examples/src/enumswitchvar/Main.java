/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package enumswitchvar;

/**
 *
 * @author lucagreco
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Colore c = Colore.ROSSO;
        
     //   Colore c1 = new Colore(245,220,210);  // non valido
       
        
        System.out.println(c.getRGB());
        
        
        Semaforo s = new Semaforo(c);
        
        s.indicazioniSwitchStatement();
        
        
        int p[] = new int[3];
        
        var p1 = new int[3];
        
        var p2 = "Mario";
        
        
        
    }
    
}
