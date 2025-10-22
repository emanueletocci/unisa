public class Agriturismo {
    private String comuneAzienda, titolare, nomeAzienda, indirizzo, recapito;
    private int postiLetto, postiAuto, postiTenda, postiRoulotte;
    private boolean pernottamento, camping;

    public Agriturismo(String comuneAzienda, String titolare, String nomeAzienda, String indirizzo, int postiLetto, int postiAuto, int postiTenda, int postiRoulotte, String recapito) {
        this.comuneAzienda = comuneAzienda;
        this.indirizzo = indirizzo;
        this.nomeAzienda = nomeAzienda;
        this.postiAuto = postiAuto;
        this.postiLetto = postiLetto;
        this.postiRoulotte = postiRoulotte;
        this.postiTenda = postiTenda;
        this.recapito = recapito;
        this.titolare = titolare;
        this.pernottamento = postiLetto > 0;
        this.camping = postiRoulotte > 0 || postiTenda > 0;
    }

    public boolean isCamping() {
        return camping;
    }

    public void setCamping(boolean camping) {
        this.camping = camping;
    }

    public String getComuneAzienda() {
        return comuneAzienda;
    }

    public void setComuneAzienda(String comuneAzienda) {
        this.comuneAzienda = comuneAzienda;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public void setIndirizzo(String indirizzo) {
        this.indirizzo = indirizzo;
    }

    public String getNomeAzienda() {
        return nomeAzienda;
    }

    public void setNomeAzienda(String nomeAzienda) {
        this.nomeAzienda = nomeAzienda;
    }

    public boolean isPernottamento() {
        return pernottamento;
    }

    public void setPernottamento(boolean pernottamento) {
        this.pernottamento = pernottamento;
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
        pernottamento = postiLetto > 0;
    }

    public int getPostiRoulotte() {
        return postiRoulotte;
    }

    public void setPostiRoulotte(int postiRoulotte) {
        this.postiRoulotte = postiRoulotte;
        camping = postiRoulotte > 0 || postiTenda > 0;
    }

    public int getPostiTenda() {
        return postiTenda;
    }

    public void setPostiTenda(int postiTenda) {
        this.postiTenda = postiTenda;
        camping = postiRoulotte > 0 || postiTenda > 0;
    }

    public String getRecapito() {
        return recapito;
    }

    public void setRecapito(String recapito) {
        this.recapito = recapito;
    }

    public String getTitolare() {
        return titolare;
    }

    public void setTitolare(String titolare) {
        this.titolare = titolare;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        return "***\n" + nomeAzienda + " di \n" + titolare + " \n" + indirizzo + "\n" + comuneAzienda + (pernottamento ? "Disponibili" : "Non disponibili") + " camere pernottamento\n" + "\u001B[4m" + recapito + "\u001B[0m\n";

    }
}
