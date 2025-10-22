package videoteca.Main;

import videoteca.Film;
import videoteca.Genere;
import videoteca.PrintColors;
import videoteca.Videoteca;

import java.util.List;

public class MainLambdas {
    public static void main(String[] args) {
        Videoteca videoteca = new Videoteca("Videoteca Completa");

        // Carico alcuni film per prova
        videoteca.aggiungiFilm(new Film("Interstellar", Genere.FANTASCIENZA, 9));
        videoteca.aggiungiFilm(new Film("Howl moving castle", Genere.ANIMAZIONE, 10));
        videoteca.aggiungiFilm(new Film("Blade Runner", Genere.FANTASCIENZA, 9));
        videoteca.aggiungiFilm(new Film("Mission Impossible", Genere.AZIONE, 8));
        videoteca.aggiungiFilm(new Film("The Heitful 8", Genere.AZIONE, 8));
        videoteca.aggiungiFilm(new Film("The Shawshank Redemption", Genere.DRAMMATICO, 7));
        videoteca.aggiungiFilm(new Film("The Godfather", Genere.DRAMMATICO, 10));
        videoteca.aggiungiFilm(new Film("The Dark Knight", Genere.AZIONE, 10));
        videoteca.aggiungiFilm(new Film("The Matrix", Genere.FANTASCIENZA, 9));
        videoteca.aggiungiFilm(new Film("The Lord of the Rings", Genere.FANTASY, 10));
        videoteca.aggiungiFilm(new Film("The Lion King", Genere.ANIMAZIONE, 0));
        videoteca.aggiungiFilm(new Film("The Silence of the Lambs", Genere.THRILLER, 9));
        videoteca.aggiungiFilm(new Film("The Departed", Genere.CRIMINALE, 8));
        videoteca.aggiungiFilm(new Film("The Social Network", Genere.DRAMMATICO, 9));
        videoteca.aggiungiFilm(new Film("The Wolf of Wall Street", Genere.DRAMMATICO, 8));
        videoteca.aggiungiFilm(new Film("The Revenant", Genere.AVVENTURA, 8));
        videoteca.aggiungiFilm(new Film("The Grand Budapest Hotel", Genere.COMMEDIA, 9));
        videoteca.aggiungiFilm(new Film("Pinocchio", Genere.ANIMAZIONE, 0));

        System.out.println(videoteca);

        // Filtraggio
        Videoteca videotecaFantascienza = videoteca.filtra(f -> f.getGenere().equals(Genere.FANTASCIENZA), "Fantascienza");
        System.out.println(videotecaFantascienza);

        Videoteca videotecaAnimazione = videoteca.filtra(f -> f.getGenere().equals(Genere.ANIMAZIONE), "Animazione");
        System.out.println(videotecaAnimazione);
        
        // Aggiornamento Batch -  le operazioni effettuate sulle collezioni filtrate si riflettono sulla collezione originale!
        System.out.println(PrintColors.format("Aggiornamento Batch", PrintColors.RED));

        Videoteca videoteca2 = videoteca.filtra(f -> f.getGenere().equals(Genere.ANIMAZIONE) && f.getValutazione() < 3);
        System.out.println(videoteca2);
        videoteca2.aggiorna(f -> f.setValutazione(10)); // aggiorno tutti i voti dei film presenti nella videoteca2
        System.out.println(videoteca2);

        // Estrazione di attributi
        System.out.println(PrintColors.format("Estrazione Attributi", PrintColors.RED));

        List<?> titoli = videoteca.estraiCampo(f -> f.getTitolo());

        System.out.println("Nomi: " + titoli);

        // Ristampo la videoteca originale
        System.out.println(videoteca);
    }
}
