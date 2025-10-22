/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//ATTENZIONE: SOSTITUIRE NEL SEGUENTE PACKAGE XX CON IL CODICE DEL PROPRIO GRUPPO
package gruppoXX;
import java.util.List;

/**
 *
 * @author Gennaro
 */
public interface Filterable {
    public List<Person> filter(PersonFilter f);
}
