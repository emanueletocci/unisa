/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package generics;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author lucagreco
 */
public class GenericsExample {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        checkNumbers(2, new ArrayList<Integer>());

        checkNumbersS(2.5, new ArrayList<Object>());

        checkNumbersG(2.5, new ArrayList<Double>());

        List<Object> ll = new ArrayList<>();

        ll.add("ciao");

        checkNumbersS(2.5, ll);

        Range<Integer> ri = new Range<>(2, 4);

        System.out.println(ri.contains(6));

    }

    //PECS - Producer Extends Consumer Super//
    public static void checkNumbers(Number n, List<? extends Number> l) {

        //  l.add(n); // non consentito
        for (Number nc : l) {

            System.out.println(nc);

        }

    }

    public static void checkNumbersS(Double n, List<? super Double> l) {

        l.add(n);

        // l si riferisce all'istanza di una collezione che può consentire l'aggiunta di un Double
        for (Object nc : l) {

            System.out.println(nc);

        }

    }

    public static <U extends Number> void checkNumbersG(U n, List<U> l) {

        l.add(n);

        for (U nc : l) {

            System.out.println(nc);

        }

    }

}
