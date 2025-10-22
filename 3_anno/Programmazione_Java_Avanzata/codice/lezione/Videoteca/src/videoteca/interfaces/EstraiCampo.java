package videoteca.interfaces;
import videoteca.Film;

@FunctionalInterface
public interface EstraiCampo<T> {
    T estrai(Film f);
}
