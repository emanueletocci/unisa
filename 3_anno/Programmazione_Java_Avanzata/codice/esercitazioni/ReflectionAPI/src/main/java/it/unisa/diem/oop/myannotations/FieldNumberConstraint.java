package it.unisa.diem.oop.myannotations;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Target(ElementType.TYPE)
@Retention ( RetentionPolicy.RUNTIME )
public @interface FieldNumberConstraint {
    int value();
}
