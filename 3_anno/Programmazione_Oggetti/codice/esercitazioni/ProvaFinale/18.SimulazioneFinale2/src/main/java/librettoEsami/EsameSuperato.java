package librettoEsami;

import java.time.LocalDate;

public class EsameSuperato implements Comparable<EsameSuperato>{
    private String matricolaStudente, nomeInsegnamento;
    private LocalDate dataSuperamento;
    private Integer voto;

    public EsameSuperato(String matricolaStudente, LocalDate dataSuperamento, String nomeInsegnamento, Integer voto){
        this.matricolaStudente = matricolaStudente;
        this.dataSuperamento = dataSuperamento;
        this.nomeInsegnamento = nomeInsegnamento;
        this.voto = voto;
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
    public int getVoto(){
        return voto;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 31 * hash + getMatricolaStudente().hashCode();
        hash = 31 * hash + getNomeInsegnamento().hashCode();
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == null)
            return false;
        if(!(obj instanceof EsameSuperato))
            return false;
        EsameSuperato e = (EsameSuperato) obj;
        return this.getMatricolaStudente().equals(e.getMatricolaStudente()) && this.getNomeInsegnamento().equals(e.getNomeInsegnamento());
    }

    @Override
    public String toString() {
        return matricolaStudente + ";" + dataSuperamento + ";" + nomeInsegnamento + ";" + voto + "\n";
    }

    @Override
    public int compareTo(EsameSuperato es) {
        if(this.getMatricolaStudente() == es.getMatricolaStudente())
            return this.getNomeInsegnamento().compareTo(es.getNomeInsegnamento());
        return this.getMatricolaStudente().compareTo(es.getMatricolaStudente());
    }

}