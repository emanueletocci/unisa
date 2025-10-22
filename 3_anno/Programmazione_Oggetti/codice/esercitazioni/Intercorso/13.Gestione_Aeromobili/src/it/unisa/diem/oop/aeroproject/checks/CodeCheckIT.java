/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop.aeroproject.checks;

import it.unisa.diem.oop.aeroproject.checks.CodeChecker;

/**
 *
 * @author emanueletocci
 */

public class CodeCheckIT implements CodeChecker {
    @Override
    public boolean check(String codice) {
        return codice.matches("IT[A-Z]{2}\\d{3}");
    }
}