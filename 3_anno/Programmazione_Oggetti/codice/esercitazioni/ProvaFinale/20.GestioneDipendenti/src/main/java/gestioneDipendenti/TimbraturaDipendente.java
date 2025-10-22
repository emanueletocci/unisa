package gestioneDipendenti;
import java.time.*;

public class TimbraturaDipendente implements Comparable<TimbraturaDipendente>{
    private final Dipendente dipendente;
    private final LocalDateTime dataOra;

    public TimbraturaDipendente(Dipendente dipendente, LocalDateTime dataOra) {
        this.dipendente = dipendente;
        this.dataOra = dataOra;
    }

    public Dipendente getDipendente() {
        return dipendente;
    }

    public LocalDateTime getDataOra() {
        return dataOra;
    }

    @Override
    public int compareTo(TimbraturaDipendente t){
        return t.getDataOra().compareTo(this.getDataOra());
    }

    @Override
    public String toString(){
        return dipendente.toString() + "Data: " + dataOra.toLocalDate() + "\nOrario: " + dataOra.toLocalTime() + "\n" + "*".repeat(20) + "\n";
    }

}
