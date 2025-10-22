/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gruppoXX;
import java.time.LocalDate;

/**
 *
 * @author emanueletocci
 */
public class SelectYoungPersonFilter implements PersonFilter{
    private LocalDate maxDate;
    
    public SelectYoungPersonFilter(int year, int month, int dayOfMonth){
        this.maxDate = LocalDate.of(year, month, dayOfMonth);
    }
    
    @Override
    public boolean checkPerson(Person p){
        return p.getBirthDate().isAfter(maxDate);
    }
}
