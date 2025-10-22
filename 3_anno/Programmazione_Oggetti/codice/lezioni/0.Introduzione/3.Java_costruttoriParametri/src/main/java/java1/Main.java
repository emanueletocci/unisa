package java1;
public class Main {
    public static void main(String[] args) {
        System.out.println(Prodotto.contegigoProdotti + " inizializzata a 0 per default"); //gli attributi statici vengono inizializzati automaticamente con la classe e pertanto sono disponibili prima di istanziare l' oggetto

        Prodotto p = new Prodotto(6, "auto", 1000F);
        Prodotto p1 = new Prodotto();

        System.out.println(p.getCodiceProdotto());
        System.out.println(p.getDescrizioneProdotto());
        System.out.println(p.getCostoProdotto());
        p1.stampaInfoProdotto();
        System.out.println("Sono stati inseriti: " + Prodotto.contegigoProdotti + " prodotti"); //gli attributi statici vengono inizializzati automaticamente con la classe e pertanto sono disponibili prima di istanziare l' oggetto
    }
}