/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.exceptions;

/**
 *
 * @author lucagreco
 */
public class AulaPienaException  extends AccessibileException {

    /**
     * Creates a new instance of <code>AulaPienaException</code> without detail
     * message.
     */
    public AulaPienaException() {
    }

    /**
     * Constructs an instance of <code>AulaPienaException</code> with the
     * specified detail message.
     *
     * @param msg the detail message.
     */
    public AulaPienaException(String msg) {
        super(msg);
    }
}
