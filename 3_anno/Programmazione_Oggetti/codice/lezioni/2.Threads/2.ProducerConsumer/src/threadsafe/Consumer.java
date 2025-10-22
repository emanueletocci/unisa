package threadsafe;

import java.util.Random;

/**
 *
 * @author lucagreco
 */
public class Consumer implements Runnable {
    
    private Buffer<String> buffer;
    private int delay;
    
    public Consumer(Buffer<String> buffer, int delay) {
        this.buffer = buffer;
        this.delay = delay;
    }

    @Override
    public void run() {
        String element;
        while(!Thread.currentThread().isInterrupted()) {
            try {
                Thread.sleep(delay*1000);
                element = buffer.remove();
            } catch (InterruptedException ex) {
                return;}
            System.out.println(Thread.currentThread().getName() + " ha letto dal buffer " + element );
        }

    }
}
