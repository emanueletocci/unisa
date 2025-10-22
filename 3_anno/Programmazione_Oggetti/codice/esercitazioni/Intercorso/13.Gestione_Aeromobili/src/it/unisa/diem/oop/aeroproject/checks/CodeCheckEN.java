/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop.aeroproject.checks;

/**
 *
 * @author emanueletocci
 */
public class CodeCheckEN implements CodeChecker {
    @Override
    public boolean check(String codice) {
        return codice.matches("EN\\d{2}[A-Z]{2}");
    }
}
