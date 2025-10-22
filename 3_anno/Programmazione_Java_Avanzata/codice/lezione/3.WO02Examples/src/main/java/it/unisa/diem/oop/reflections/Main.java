package it.unisa.diem.oop.reflections;

import javax.security.auth.login.Configuration;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.lang.reflect.Parameter;

public class Main {
    public static void main(String[] args) {
        Studente s = new Studente ( "Mario", "Rossi", "RSSMR01", "12345" );
        Class<?> c = s.getClass();
        Class<?> c1 = Studente.class;
        try {
            Class<?> c2 = Class.forName ( "it.unisa.diem.oop.reflections.Studente" );
        } catch (ClassNotFoundException e){
            e.printStackTrace ();
        }
        inspectClass(c);
    }

    static void inspectClass(Class<?> c){
        System.out.println("Classe: " +c.getCanonicalName ());

        System.out.println("***Costruttori***");

        Constructor<?>[] listaCostruttori = c.getConstructors();

        for(Constructor<?> constructor : listaCostruttori){
            constructor.getName();
            StringBuilder signature = new StringBuilder();
            constructor.getModifiers();     // i modificatori sono codificati con un numero intero
            signature.append(Modifier.toString(constructor.getModifiers())).append(' ');
            signature.append(constructor.getName()).append("( ");
            Parameter parameters[] = constructor.getParameters();

            for(Parameter pc : parameters){
                signature.append(pc.getName ()).append(' ');
                signature.append(pc.getName()).append(',');
            }

            signature.setCharAt(signature.length()-1, ')');
            System.out.println(signature);
        }
        System.out.println("***METODI***");
        Method methods[] = c.getMethods();

        for(Method m : methods){
            StringBuffer sb = new StringBuffer();

            sb.append(Modifier.toString(m.getModifiers())).append(' ');
            sb.append(m.getReturnType().getSimpleName()).append(' ');
            sb.append(m.getName()).append("( ");

            Parameter parameters[] = m.getParameters();

            for(Parameter param : parameters){
                sb.append(param.getType().getSimpleName()).append(' ');
                sb.append(param.getName()).append(',');
            }
            sb.setCharAt(sb.length() - 1, ')');
            System.out.println(sb);

            // ANNOTAZIONI

            DaImplementare di = null;
            if((di = m.getAnnotation(DaImplementare.class)) != null){
                System.out.println("---> Da Implementare");
            }
        }

    }

}