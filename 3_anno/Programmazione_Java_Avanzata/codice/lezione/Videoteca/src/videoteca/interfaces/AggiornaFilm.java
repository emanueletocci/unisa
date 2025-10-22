package videoteca.interfaces;

import videoteca.Film;

@FunctionalInterface
public interface AggiornaFilm {
    void aggiorna(Film film);
}
