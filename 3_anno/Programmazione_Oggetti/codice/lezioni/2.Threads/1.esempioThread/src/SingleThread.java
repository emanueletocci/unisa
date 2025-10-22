//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
import static java.lang.Thread.*;
import static java.lang.System.*;
public class SingleThread {
    public static void main(String[] args) {
        Thread t = currentThread(); // oggetto che esegue l'oggetto corrente ovvero il thread corrente
        t.setName("Thread Principale");
        t.setPriority(10);  //min=1, max=10
        out.println("Thread in esecuzione: " + t);
        try{
            for(int i=5; i>0; i--){
                out.println(i);
                sleep(1000);
            }
        } catch(InterruptedException ex){
            out.println("Thread Interrotto");
        }
    }
}