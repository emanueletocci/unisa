package videoteca.Main.references;
import videoteca.Film;
import videoteca.Genere;

public class Filtri {
    public static boolean isBelFilm(Film f){
        return f.getValutazione() > 8;
    }

    public boolean isFantascienza(Film f){
        return f.getGenere().equals(Genere.FANTASCIENZA);
    }
}
