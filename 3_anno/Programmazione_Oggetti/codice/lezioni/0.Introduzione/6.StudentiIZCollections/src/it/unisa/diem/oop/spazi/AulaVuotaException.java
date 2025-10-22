/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.spazi;

/**
 *
 * @author lucagreco
 */
public class AulaVuotaException extends AccessibileException {

    /**
     * Creates a new instance of <code>AulaVuotaException</code> without detail
     * message.
     */
    public AulaVuotaException() {
    }

    /**
     * Constructs an instance of <code>AulaVuotaException</code> with the
     * specified detail message.
     *
     * @param msg the detail message.
     */
    public AulaVuotaException(String msg) {
        super(msg);
    }
}
