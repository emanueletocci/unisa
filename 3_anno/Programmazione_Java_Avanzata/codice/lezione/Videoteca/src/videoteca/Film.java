package videoteca;

public class Film {
    private String titolo;
    private Genere genere;
    private int valutazione;

    public Film(String titolo, Genere genere, int valutazione) {
        this.genere = genere;
        this.titolo = titolo;
        this.valutazione = valutazione;
    }

    public String getTitolo() {
        return titolo;
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public Genere getGenere() {
        return genere;
    }

    public void setGenere(Genere genere) {
        this.genere = genere;
    }

    public int getValutazione() {
        return valutazione;
    }

    public void setValutazione(int valutazione) {
        this.valutazione = valutazione;
    }

    @Override
    public String toString() {
        return "titolo = " + titolo  +
                ", genere = " + PrintColors.format(genere.toString(), PrintColors.YELLOW) +
                ", valutazione = " + valutazione + "\n";
    }
}
