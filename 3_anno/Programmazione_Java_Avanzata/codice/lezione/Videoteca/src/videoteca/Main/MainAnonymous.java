package videoteca.Main;

import videoteca.Film;
import videoteca.Genere;
import videoteca.Videoteca;
import videoteca.interfaces.FiltroFilm;

public class MainAnonymous {
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

        Videoteca videotecaFantascienza = videoteca.filtra(new FiltroFilm() {
            @Override
            public boolean filtra(Film film) {
                return film.getGenere() == Genere.FANTASCIENZA;
            }
        });

        System.out.println(videotecaFantascienza);
        System.out.println("\n");

        // Prendo film di animazione con valutazione > 3
        Videoteca videoteca2 = videoteca.filtra(new FiltroFilm() {
            @Override
            public boolean filtra(Film film) {
                return film.getGenere() == Genere.ANIMAZIONE && film.getValutazione() > 3;
            }
        });
        System.out.println(videoteca2);
    }
}
