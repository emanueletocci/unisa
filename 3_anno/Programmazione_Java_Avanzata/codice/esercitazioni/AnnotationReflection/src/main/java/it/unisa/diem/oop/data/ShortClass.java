package it.unisa.diem.oop.data;

import it.unisa.diem.oop.myannotations.AtMostThree;
import it.unisa.diem.oop.myannotations.FieldNumberConstraint;

@FieldNumberConstraint ( 2 )
@AtMostThree
public class ShortClass {
    private float foo;
    public float getFoo(){
        return foo;
    }
}
