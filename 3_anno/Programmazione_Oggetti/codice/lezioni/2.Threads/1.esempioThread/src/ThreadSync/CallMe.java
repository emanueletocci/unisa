package ThreadSync;

import static java.lang.System.*;

public class CallMe {
    synchronized public void call (String msg){
        out.print("[" +msg);
        try{
            Thread.sleep(1000);
        } catch (Exception e){
            e.printStackTrace ();
        }
        out.print ("]");
    }
}


