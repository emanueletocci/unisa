import static java.lang.Thread.*;
import static java.lang.System.*;

public class ThreadCreation implements Runnable{
    public ThreadCreation(){
        Thread principale = currentThread();
        principale.setName("Thread Principale");
        Thread creato = new Thread(this, "Thread Figlio");
        out.println("Thread Attuale: " + principale);
        out.println("Thread Creato: " + creato);
        creato.start(); //imposta il Thread in stato "ready". Il Thread prima o poi eseguirá il metodo run
        try{
            sleep(3000);
        } catch (InterruptedException e){
            out.println("Thread Principale Interrotto!");
        }
        out.println("Uscita Thread Principale");
    }
    public void run(){
        try{
            for (int i = 5 ; i > 0 ; i--){
                out.println(i);
                sleep(1000);
            }
        } catch(InterruptedException e){
            out.println ("Thread Figlio Interrotto!");
        }
        out.println("Uscita Thread Figlio");
    }
    public static void main(String args[]){
        new ThreadCreation();
    }
}
