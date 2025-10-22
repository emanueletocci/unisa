/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sealed.interfac;

/**
 *
 * @author lucagreco
 */
public class EspressioneSomma implements Descrivibile {
    
    private int a,b;
    
    public EspressioneSomma(int a, int b) {
    
        this.a = a;
        this.b = b;
    
    
    }

    @Override
    public void descrivi() {
        
        
        System.out.println(" il Risultato di  " + a +  "+ " + b + "=" + valuta());
    
    }

    @Override
    public int valuta() {
        
        return a+b;
        
        
        }
    
}
