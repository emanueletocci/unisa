/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg14.ingv;

import java.util.Comparator;

/**
 *
 * @author emanueletocci
 */
public class MagnitudeComparator implements Comparator<EQEvent> {
    @Override
    public int compare(EQEvent e1, EQEvent e2){
        return Double.compare(e1.getMagnitude(), e2.getMagnitude());
    }
}
