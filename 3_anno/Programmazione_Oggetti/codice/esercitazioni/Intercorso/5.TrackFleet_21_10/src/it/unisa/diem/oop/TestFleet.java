/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package it.unisa.diem.oop;
import java.time.LocalDate;

/**
 *
 * @author lucagreco
 */
public class TestFleet {
    public static void main(String[] args) {
        Fleet f = new Fleet("myFleet");

        Truck tractor1 = new Truck("HH245TP", LocalDate.of(2020, 10, 10));
        Truck tractor2 = new Truck("HH247TH", LocalDate.of(2019, 10, 10));
        Truck tractor3 = new Truck("HH237TG", LocalDate.of(2019, 10, 10));

        Tanker tanker1 = new Tanker(tractor1, 5000, 3, true);
        Tanker tanker2 = new Tanker(tractor2, 7500, 1, false);

        f.add(tanker1);
        f.add(tanker2);
        f.add(tractor1);
        f.add(tractor2);
        f.add(tractor3);

        System.out.println(f);

        try {
            Tanker tanker3 = new Tanker(tractor2, 2000, 1, false);
        } catch (IllegalArgumentException ex) {
            System.out.println("\nException test: \n" + ex + "\n");
        }
        Fleet t = f.filterFoodGrade();
        System.out.println(t);
    }

}
