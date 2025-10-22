package it.unisa.diem.oop.data;

import it.unisa.diem.oop.myannotations.AtMostThree;
import it.unisa.diem.oop.myannotations.FieldNumberConstraint;

@AtMostThree
@FieldNumberConstraint(2)
public class LongClass {
    public int foo;
    public String foo2;
    public void m1(){}
    public void m2(){}
    public void m3(){}
    public void m4(){}
}
