package gestioneDipendenti;

public class Dipendente implements Comparable<Dipendente> {
    private String nome, cognome, codiceFiscale;

    public Dipendente(String nome, String cognome, String codiceFiscale){
        this.nome = nome;
        this.cognome = cognome;
        this.codiceFiscale = codiceFiscale.trim().toUpperCase();
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    @Override
    public String toString(){
        return "Nome: " + nome + "\nCognome: " + cognome + "\nCF: " + codiceFiscale + "\n";
    }

    @Override
    public int hashCode(){
        return codiceFiscale.hashCode();
    }

    @Override
    public boolean equals(Object obj){
        if (obj == null)
            return false;
        if(!(obj instanceof Dipendente d))
            return false;
        return d.getCodiceFiscale().equals(this.getCodiceFiscale());
    }

    @Override
    public int compareTo(Dipendente d){
        return this.getCodiceFiscale().compareTo(d.getCodiceFiscale());
    }
}
