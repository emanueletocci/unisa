/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Enum.java to edit this template
 */
package record;

/**
 *
 * @author lucagreco
 */
public enum CorsoDiStudi {
    
    LT("06127"),LM("06227"),PhD("88500");
    
    private final String prefisso;
    
    CorsoDiStudi(String prefisso) {
    
        this.prefisso = prefisso;
    
    }
    
    public String getPrefisso() {
    
    
        return prefisso;
    }
    
}
