/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package sealed.interfac;

/**
 *
 * @author lucagreco
 */
public sealed interface Espressione  {
    
    int valuta();
    
}

non-sealed interface Descrivibile extends Espressione {

    void descrivi();


}

