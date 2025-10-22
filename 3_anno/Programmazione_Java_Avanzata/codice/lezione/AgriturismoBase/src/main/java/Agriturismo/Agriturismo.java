package Agriturismo;

public class Agriturismo {
    private final String comune;
    private final String titolare;
    private final String denominazione;
    private int postiLetto;
    private int postiAuto;
    private int postiTenda;
    private int postiRoulotte;
    private String recapiti;
    private boolean pernottamento;
    private boolean camping;

    public Agriturismo(String comune, String titolare, String denominazione, int postiLetto, int postiAuto, int postiTenda, int postiRoulotte, String recapiti) {
        this.comune = comune;
        this.titolare = titolare;
        this.denominazione = denominazione;
        this.postiLetto = postiLetto;
        this.postiAuto = postiAuto;
        this.postiTenda = postiTenda;
        this.postiRoulotte = postiRoulotte;
        this.recapiti = recapiti;
        this.pernottamento = false;
        this.camping = false;
    }

    public boolean isCamping() {
        return camping;
    }

    public void setCamping(boolean camping) {
        this.camping = camping;
    }

    public boolean isPernottamento() {
        return pernottamento;
    }

    public void setPernottamento(boolean pernottamento) {
        this.pernottamento = pernottamento;
    }

    public String getRecapiti() {
        return recapiti;
    }

    public void setRecapiti(String recapiti) {
        this.recapiti = recapiti;
    }

    public int getPostiRoulotte() {
        return postiRoulotte;
    }

    public void setPostiRoulotte(int postiRoulotte) {
        this.postiRoulotte = postiRoulotte;
    }

    public int getPostiTenda() {
        return postiTenda;
    }

    public void setPostiTenda(int postiTenda) {
        this.postiTenda = postiTenda;
    }

    public int getPostiAuto() {
        return postiAuto;
    }

    public void setPostiAuto(int postiAuto) {
        this.postiAuto = postiAuto;
    }

    public int getPostiLetto() {
        return postiLetto;
    }

    public void setPostiLetto(int postiLetto) {
        this.postiLetto = postiLetto;
    }

    public String getDenominazione() {
        return denominazione;
    }

    public String getTitolare() {
        return titolare;
    }

    public String getComune() {
        return comune;
    }
}
