/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.exceptions;

/**
 *
 * @author lucagreco ECCEZIONE NON CONTROLLATA
 */
public class VotoNonConsentitoException extends RuntimeException {

    /**
     * Creates a new instance of <code>VotoNonConsentitoException</code> without
     * detail message.
     */
    public VotoNonConsentitoException() {
    }

    /**
     * Constructs an instance of <code>VotoNonConsentitoException</code> with
     * the specified detail message.
     *
     * @param msg the detail message.
     */
    public VotoNonConsentitoException(String msg) {
        super(msg);
    }
}
