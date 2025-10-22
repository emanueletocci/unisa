package it.unisa.diem.oop.annotations.processor;

import it.unisa.diem.oop.annotations.AtMostThree;
import it.unisa.diem.oop.annotations.FieldNumberConstraint;

import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.Element;
import javax.lang.model.element.ElementKind;
import javax.lang.model.element.TypeElement;
import java.util.Objects;
import java.util.Set;

@SupportedAnnotationTypes({"it.unisa.diem.oop.annotations.AtMostThree", "it.unisa.diem.oop.annotations.FieldNumberConstraint"})
@SupportedSourceVersion(SourceVersion.RELEASE_8)

public class Processor extends AbstractProcessor {
    private Messager messager;

    @Override
    public synchronized void init(ProcessingEnvironment processingEnv) {
        super.init(processingEnv);
        messager = processingEnv.getMessager();
    }

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        Set<? extends Element> annotatedElements = roundEnv.getElementsAnnotatedWithAny();
        for (Element element : annotatedElements) {
            if(element.getAnnotation(AtMostThree.class) != null){
                if(element.getClass().getDeclaredMethods().length > 3)
                    messager.printError("Class cannot have more than 3 methods");
            } else if(element.getAnnotation(FieldNumberConstraint.class) != null){
                if(element.getClass().getDeclaredFields().length != element.getAnnotation(FieldNumberConstraint.class).value());
                    messager.printError("Class must have " + element.getAnnotation(FieldNumberConstraint.class).value() + " fields");
            }

        }
        return true;
    }
}