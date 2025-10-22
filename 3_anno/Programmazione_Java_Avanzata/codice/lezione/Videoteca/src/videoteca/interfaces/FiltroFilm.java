package videoteca.interfaces;

import videoteca.Film;

// interfaccia funzionale: interfaccia che dichiara un unico metodo astratto - SAM: Single Abstract Method
@FunctionalInterface
public interface FiltroFilm {
    boolean filtra(Film film);
}
