/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Enum.java to edit this template
 */
package enumswitchvar;

/**
 *
 * @author lucagreco
 */
public enum Colore {
   
   
    ROSSO(255,0,0), NERO(0,0,0), GIALLO(255,0,255), VERDE(0,255,0);
    
    
    private final int r,g,b;
    
    Colore(int r, int g, int b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    public int getR() {
        return r;
    }

    public int getG() {
        return g;
    }

    public int getB() {
        return b;
    }
    
    public String getRGB() {
    
        return "(" + this.r + "," + this.g + "," + this.b + ")";
    
    }
   
    
}
