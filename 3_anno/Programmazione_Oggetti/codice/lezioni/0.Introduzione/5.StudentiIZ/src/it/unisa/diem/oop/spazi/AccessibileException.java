/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.spazi;

/**
 *
 * @author lucagreco ECCEZIONE CONTROLLATA
 */
public class AccessibileException extends Exception {

    /**
     * Creates a new instance of <code>AccessibileException</code> without
     * detail message.
     */
    public AccessibileException() {
    }

    /**
     * Constructs an instance of <code>AccessibileException</code> with the
     * specified detail message.
     *
     * @param msg the detail message.
     */
    public AccessibileException(String msg) {
        super(msg);
    }
}
