/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.persone;

import java.util.Comparator;

/**
 *
 * @author lucagreco
 */
public class EtaComparator implements Comparator<Persona> {

    @Override
    public int compare(Persona o1, Persona o2) {

        if (o1.getEta() != o2.getEta()) //  return o1.getEta() - o2.getEta();
        {
            return Integer.compare(o1.getEta(), o2.getEta());
        }

        return o1.compareTo(o2);

    }

}
