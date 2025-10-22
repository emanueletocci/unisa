/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gruppoXX;
/**
 *
 * @author emanueletocci
 */
public class SelectStudentFilter implements PersonFilter{
    public boolean checkPerson (Person p){
        return (p instanceof Student);
    }
}
