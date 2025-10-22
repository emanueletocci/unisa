package it.unisa.diem.oop.negozio;
import it.unisa.diem.oop.negozio.Prodotto;
import java.time.LocalDate;

/**
 *
 * @author emanueletocci
 */

public class ProdottoAlimentare extends Prodotto{
    private LocalDate dataScadenza;
    
    public ProdottoAlimentare(String codice, String descrizione, double prezzo, LocalDate dataScadenza){
        super(codice, descrizione, prezzo);
        this.dataScadenza = dataScadenza;
    }
    
    public LocalDate getDataScadenza(){
        return dataScadenza;
    }
    
    @Override 
    public double applicaSconto(){
        LocalDate now = LocalDate.now();
        double prezzo = super.getPrezzo();
        if(dataScadenza.isBefore(now.minusDays(10L)))
            return prezzo - (20.0F/100.0F * prezzo);
        return prezzo;
    }
    
    @Override
    public String toString(){
        return "\n" + super.toString() + "\nScadenza = " + dataScadenza;
    }
}
