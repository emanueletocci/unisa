/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gruppoXX;
import gruppoXX.TeacherType;

/**
 *
 * @author emanueletocci
 */
public class Teacher extends Person{
    private TeacherType type;
    
    public Teacher(String name, String surname, TeacherType type, int year, int month, int dayOfMonth){
        super(name,surname,year,month,dayOfMonth);
        this.type = type;
    }
    
    public TeacherType getType(){
        return type;
    }
    
    @Override
    public String toString(){
        return super.toString() + "Type = " + type + "\n";
    }
}
