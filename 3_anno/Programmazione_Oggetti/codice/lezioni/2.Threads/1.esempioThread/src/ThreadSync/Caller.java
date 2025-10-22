package ThreadSync;

public class Caller implements Runnable{
    private String msg;
    private CallMe target;
    public Caller(CallMe t, String s){
        target = t;
        msg = s;
        new Thread(this).start ();
    }

    @Override
    public void run(){
        synchronized (target){
            target.call(msg);
        }
    }
}