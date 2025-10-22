package ThreadSync;

public class Synch {
    public static void main (String args[]){
        CallMe target = new CallMe();
        new Caller(target, "Hello");
        new Caller(target, "Syncronized");
        new Caller(target, "World");
    }
}