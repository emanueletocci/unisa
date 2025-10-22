package videoteca.Main;
import videoteca.Film;
import videoteca.Genere;
import videoteca.Videoteca;

import java.util.List;
import java.util.stream.Stream;

public class MainStreamAPI {
    public static void main(String[] args) {
        Videoteca videoteca = new Videoteca();

        videoteca.aggiungiFilm(new Film("Interstellar", Genere.FANTASCIENZA, 9));
        videoteca.aggiungiFilm(new Film("Howl moving castle", Genere.ANIMAZIONE, 5));
        videoteca.aggiungiFilm(new Film("Blade Runner", Genere.FANTASCIENZA, 10));
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

        Stream<Film> s1 = videoteca.stream().filter(film -> film.getGenere().equals(Genere.FANTASCIENZA));
        s1.forEach(f-> System.out.println(f));

        //s1.forEach(f -> System.out.println(f)); lo stream è già stato consumato

        // la modifica con gli stream é sconsigliata dalla documentazione
       videoteca.stream().filter(film -> film.getGenere().equals(Genere.FANTASCIENZA)).forEach(f -> f.setValutazione(5));

       System.out.println("\nVIDEOTECA INIZIALE");
       System.out.println(videoteca);   // la collezione originale è stata modificata

        int sum = videoteca.stream().mapToInt(film -> film.getValutazione()).sum();
        System.out.println("Somma delle valutazioni: " + sum);
        double average = videoteca.stream().mapToInt(Film::getValutazione).average().orElse(0.0);
        System.out.println("Media delle valutazioni: " + average);

        List<String> titoli = videoteca.stream().map(Film::getTitolo).toList();
        System.out.println("Titoli: " + titoli);

        List<?> parole = videoteca.stream().flatMap(f -> Stream.of(f.getTitolo().split(" "))).toList();
        System.out.println("Parole: " + parole);
    }
}
