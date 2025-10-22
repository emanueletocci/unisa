package librettoEsami;

import java.util.*;
import static java.lang.System.*;
import java.time.*;

public class EsameSuperato implements Comparable<EsameSuperato>{
    private String matricolaStudente, nomeInsegnamento;
    private int voto, id;
    private LocalDate dataSuperamento;

    public EsameSuperato(String matricolaStudente, LocalDate dataSuperamento, String nomeInsegnamento, int voto  ){
        if(voto < 18 || voto > 30){
            throw new IllegalArgumentException("ERROR! Sono ammessi solamente voti compresi tra 18 e 30");
        }
        this.matricolaStudente = matricolaStudente;
        this.dataSuperamento = dataSuperamento;
        this.nomeInsegnamento = nomeInsegnamento;
        this.voto = voto;
        this.id = this.hashCode();
    }

    @Override
    public String toString(){
        return  "Matricola = " + matricolaStudente + "\n" +
                "Data = " + dataSuperamento + "\n" +
                "Nome Esame = " + nomeInsegnamento + "\n" +
                "Voto = " + voto + "\n" +
                "*********************************\n";
    }

    public String getMatricolaStudente(){
        return matricolaStudente;
    }
    public String getNomeInsegnamento(){
        return nomeInsegnamento;
    }
    public LocalDate getDataSuperamento(){
        return dataSuperamento;
    }
    public Integer getVoto(){
        return voto;
    }
    public Integer getId(){
        return id;
    }

    @Override
    public int compareTo(EsameSuperato esame){
        return this.getId().compareTo(esame.getId());
    }

    @Override
    public int hashCode(){
        /*
         * Considerando che non é possibile sovrascrivere un esame giá presente nel libretto, ho deciso di implementare il campo id
         * sulla base della matricola e del nome dell'insegnamento: uno studente non puó avere in libretto 2 volte lo stesso esame;
         * Con "EsameSuperato" ho pertanto supposto un esame con voto > 18 e che sia stato accettato dallo studente.
         *
         * In caso di conflitto con gli id, rimane in libretto il primo esame registrato con lo stesso di.
         */

        int hash = 7;
        hash = 31 * hash + this.getMatricolaStudente().hashCode();
        hash = 31 * hash + this.getNomeInsegnamento().toUpperCase().trim().hashCode();
        return hash;
    }

    @Override
    public boolean equals(Object o){
        if(o == null)
            return false;
        if(!(o instanceof EsameSuperato esame))
            return false;
        return this.getId().equals(esame.getId());
    }
}
