package videoteca.Main.references;

import videoteca.Film;
import videoteca.Genere;
import videoteca.Videoteca;

import java.util.List;

public class MainReferences {
    public static void main(String[] args) {
        Videoteca videoteca = new Videoteca();

        videoteca.aggiungiFilm(new Film("Interstellar", Genere.FANTASCIENZA, 9));
        videoteca.aggiungiFilm(new Film("Howl moving castle", Genere.ANIMAZIONE, 5));
        videoteca.aggiungiFilm(new Film("Blade Runner", Genere.FANTASCIENZA, 9));
        videoteca.aggiungiFilm(new Film("Mission Impossible", Genere.AZIONE, 8));
        videoteca.aggiungiFilm(new Film("The Heitful 8", Genere.AZIONE, 8));
        videoteca.aggiungiFilm(new Film("The Shawshank Redemption", Genere.DRAMMATICO, 7));
        videoteca.aggiungiFilm(new Film("The Godfather", Genere.DRAMMATICO, 10));
        videoteca.aggiungiFilm(new Film("The Dark Knight", Genere.AZIONE, 10));
        videoteca.aggiungiFilm(new Film("The Matrix", Genere.FANTASCIENZA, 9));
        videoteca.aggiungiFilm(new Film("The Lord of the Rings", Genere.FANTASY, 10));
        videoteca.aggiungiFilm(new Film("The Lion King", Genere.ANIMAZIONE, 5));
        videoteca.aggiungiFilm(new Film("The Silence of the Lambs", Genere.THRILLER, 9));
        videoteca.aggiungiFilm(new Film("The Departed", Genere.CRIMINALE, 8));
        videoteca.aggiungiFilm(new Film("The Social Network", Genere.DRAMMATICO, 9));
        videoteca.aggiungiFilm(new Film("The Wolf of Wall Street", Genere.DRAMMATICO, 8));
        videoteca.aggiungiFilm(new Film("The Revenant", Genere.AVVENTURA, 8));
        videoteca.aggiungiFilm(new Film("The Grand Budapest Hotel", Genere.COMMEDIA, 9));

        System.out.println(videoteca);

        List<?> titoli = videoteca.estraiCampo(Film::getTitolo);
        System.out.println(titoli);

        Videoteca videoteca2 = videoteca.filtra(Filtri::isBelFilm);
        System.out.println(videoteca2);

        Filtri filtri = new Filtri();
        Videoteca videoteca3 = videoteca.filtra(filtri::isFantascienza);
    }
}
