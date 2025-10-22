package videoteca;

import videoteca.PrintColors;
import videoteca.interfaces.AggiornaFilm;
import videoteca.interfaces.EstraiCampo;
import videoteca.interfaces.FiltroFilm;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

public class Videoteca {
    private String nome;
    private List<Film> videoteca;

    public Videoteca(String nome) {
        this.nome = nome;
        videoteca = new ArrayList<>();
    }
    public Videoteca() {
        videoteca = new ArrayList<>();
    }

    public void aggiungiFilm (Film film) {
        videoteca.add(film);
    }

    public void rimuoviFilm(Film film){
        videoteca.remove(film);
    }

    // Il mettodo prende come parametro un'interfaccia funzionale
    // il cui metodo astratto filtra() viene implementato tramite lambda

    public Videoteca filtra(FiltroFilm filtro, String nome){
        Videoteca vc = new Videoteca(nome);
        for(Film film : videoteca){
            if(filtro.filtra(film))   // metodo virtuale invocato su un reference di un'interfaccia
                vc.aggiungiFilm(film);
        }
        return vc;
    }

    // Effettuo overload del metodo per consentire la creazione di videoteche senza nome
    public Videoteca filtra(FiltroFilm filtro){
        Videoteca vc = new Videoteca();
        for(Film film : videoteca){
            if(filtro.filtra(film))   // metodo virtuale invocato su un reference di un'interfaccia
                vc.aggiungiFilm(film);
        }
        return vc;
    }

    public String getNome() {
        return nome;
    }

    public void aggiorna(AggiornaFilm film) {
        for(Film f : videoteca){
            film.aggiorna(f);
        }
    }

    public <T> List<T> estraiCampo(EstraiCampo<T> campo) {
        List<T> campi = new ArrayList<>();

        for(Film f : videoteca){
            campi.add(campo.estrai(f));
        }

        return campi;
    }
    /* STREAM API */

    public Stream<Film> stream(){
        return videoteca.stream();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append(PrintColors.format((nome == null) ? "Videoteca senza nome" : nome , PrintColors.GREEN)).append("\n");
        for(Film f: videoteca){
            sb.append(f.toString());
        }
        return sb.toString();
    }
}
