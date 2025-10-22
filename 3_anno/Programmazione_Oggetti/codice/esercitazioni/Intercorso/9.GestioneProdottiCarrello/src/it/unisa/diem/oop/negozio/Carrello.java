/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package it.unisa.diem.oop.negozio;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 *
 * @author emanueletocci
 */
public class Carrello {

    List<Prodotto> carrello;

    public Carrello() {
        carrello = new ArrayList<>();
    }

    public void addProdotto(Prodotto p) {
        this.carrello.add(p);
    }

    public double getTotale() {
        Iterator<Prodotto> it = carrello.iterator();
        double sum = 0D;
        while(it.hasNext()){
            Prodotto p = it.next();
            sum += p.getPrezzo();
        }
        return sum;
    }

    public double getTotaleScontato() {
        Iterator<Prodotto> it = carrello.iterator();
        double sum = 0.0F;
        while(it.hasNext()){
            Prodotto p = it.next();
            sum += p.applicaSconto();
        }
        return sum;
    }

    public void removeProdotto(Prodotto p) {
        this.carrello.remove(p);
    }

    public Prodotto getProdotto(int idx) {
        return this.carrello.get(idx);
    }

    @Override
    public String toString() {
        return carrello + " \n\nPrezzo totale = " + getTotale() + " €\nPrezzo scontato = " + getTotaleScontato() + " €";
    }
}
