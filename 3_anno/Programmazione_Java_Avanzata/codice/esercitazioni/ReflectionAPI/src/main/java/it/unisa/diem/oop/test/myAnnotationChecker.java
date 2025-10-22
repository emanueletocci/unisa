package it.unisa.diem.oop.test;
import it.unisa.diem.oop.data.LongClass;
import it.unisa.diem.oop.data.ShortClass;
import it.unisa.diem.oop.exceptions.AnnotationException;
import it.unisa.diem.oop.myannotations.AtMostThree;
import it.unisa.diem.oop.myannotations.FieldNumberConstraint;

import java.lang.annotation.Annotation;
import java.util.Scanner;

public class myAnnotationChecker {
    public static void main(String[] args) throws ClassNotFoundException {
        while(true) {
            System.out.println ( "Inserire il nome della classe da controllare" );
            var input=new Scanner(System.in).nextLine();
            if(input.isEmpty ()) return;
            Class<?> clazz = Class.forName ( "it.unisa.diem.oop.data." + input );
            Annotation annotation=clazz.getAnnotation ( AtMostThree.class );

            if(annotation!=null){
                if (clazz.getDeclaredMethods ().length>3){
                    throw new AnnotationException ( "" );
                }
            }
            FieldNumberConstraint annot=clazz.getAnnotation ( FieldNumberConstraint.class );
            if(annot!=null){
                if (clazz.getDeclaredFields ().length != annot.value ()){

                    throw new AnnotationException ( "" );
                }
            }
        }
    }
}
