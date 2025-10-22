/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.inputoutputtest;

import java.io.*;
import java.util.*;

/**
 *
 * @author leonardorundo
 */
public class TestIO {

    public static void main(String[] args) throws IOException {

        Set<Persona> s = new HashSet();
        s.add(new Persona("Luigi", 1.86, 27));
        s.add(new Persona("Marco", 1.75, 34));
        s.add(new Persona("Rosa", 1.78, 21));
        s.add(new Persona("Marta", 1.65, 38));

        System.out.println(s);

        scriviUsandoObjectOutputStream("prova.bin", s);
        Set<Persona> s2 = leggiUsandoObjectInputStream("prova.bin");
        if (s2 == null) {
            System.out.println("Lettura fallita"); 
        }else {
            System.out.println("Lettura riuscita\n" + s2);
        }

        scriviUsandoDataOutputStream("prova2.bin", s);
        Set<Persona> s3 = leggiUsandoDataInputStream("prova2.bin");
        if (s3 == null) {
            System.out.println("Lettura fallita"); 
        }else {
            System.out.println("Lettura riuscita\n" + s3);
        }

        scriviUsandoPrintWriter("prova.txt", s);
        Set<Persona> s4 = leggiUsandoScanner("prova.txt");
        if (s4 == null) {
            System.out.println("Lettura fallita"); 
        }else {
            System.out.println("Lettura riuscita\n" + s4);
        }

    }

    private static Set<Persona> leggiUsandoDataInputStream(String nomeFile) {
        Set<Persona> s = new HashSet();

        try (DataInputStream i = new DataInputStream(new BufferedInputStream(new FileInputStream(nomeFile)))) {
            int size = i.readInt();
            String nome;
            double altezza;
            int eta;
            for (int k = 1; k <= size; k++) {
                nome = i.readUTF();
                altezza = i.readDouble();
                eta = i.readInt();
                s.add(new Persona(nome, altezza, eta));
            }
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
            return null;
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        return s;
    }

    private static Set<Persona> leggiUsandoScanner(String nomeFile) {
        Set<Persona> s = new HashSet();

        try (Scanner i = new Scanner(new BufferedReader(new FileReader(nomeFile)))) {
            i.useLocale(Locale.US);
            i.useDelimiter(";\n*");
            String nome;
            double altezza;
            int eta;
            while (i.hasNext()) {
                nome = i.next();
                altezza = i.nextDouble();
                eta = i.nextInt();
                s.add(new Persona(nome, altezza, eta));
            }
        } catch (FileNotFoundException e) {
            System.out.println(e);
            return null;
        } catch (RuntimeException e) {//Raggiunta la fine del file   
        }
        return s;
    }

    private static Set<Persona> leggiUsandoObjectInputStream(String nomeFile) {
        Set<Persona> s = null;

        try (ObjectInputStream i = new ObjectInputStream(new BufferedInputStream(new FileInputStream(nomeFile)))) {
            s = (Set<Persona>) i.readObject();
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return null;
        }
        return s;
    }

    private static void scriviUsandoDataOutputStream(String nomeFile, Set<Persona> s) {
        try (DataOutputStream o = new DataOutputStream(new BufferedOutputStream(new FileOutputStream(nomeFile)))) {
            o.writeInt(s.size());
            for (Persona p : s) {
                o.writeUTF(p.getNome());
                o.writeDouble(p.getAltezza());
                o.writeInt(p.getEta());
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    private static void scriviUsandoPrintWriter(String nomeFile,
            Set<Persona> s) {
        try (PrintWriter o = new PrintWriter(
                new BufferedWriter(
                        new FileWriter(nomeFile)))) {
            for (Persona p : s) {
                o.print(p.getNome() + ";" + p.getAltezza() + ";" + p.getEta() + ";\n");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private static void scriviUsandoObjectOutputStream(String nomeFile, Set<Persona> s) {

        try (ObjectOutputStream o = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(nomeFile)))) {
            o.writeObject(s);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

}
