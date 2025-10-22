/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Exception.java to edit this template
 */
package pkg11.intercorso2015.exceptions;
import pkg11.intercorso2015.dipendenti.Dipendente;

/**
 *
 * @author emanueletocci
 */
public class DipendenteDuplicatoException extends Exception {
    Dipendente d;
    public DipendenteDuplicatoException(Dipendente d){
        this.d = d;
    }
}
