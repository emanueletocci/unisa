/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package record;

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
        
        Studente s = new Studente("Mario", "Rossi", "061270001");
        Studente s1 = new Studente("Luigi", "Rossi", CorsoDiStudi.LM);
        Studente s2 = new Studente("Diego", "Rossi", CorsoDiStudi.LM);
        
        System.out.println(s);
        System.out.println(s1);
        System.out.println(s2);
        
        
    }
    
}
