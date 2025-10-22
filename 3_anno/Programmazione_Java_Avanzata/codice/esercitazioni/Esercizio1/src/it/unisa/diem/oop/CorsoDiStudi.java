package it.unisa.diem.oop;

public enum CorsoDiStudi {
    LT("06127"),
    LM("06227"),
    PhD("8805");

    private final String prefisso;
    CorsoDiStudi(String prefisso){
        this.prefisso = prefisso;
    }

    public String getPrefisso(){
        return prefisso;
    }
}
