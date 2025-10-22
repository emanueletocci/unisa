package threadsafe;

/**
 *
 * @author lucagreco
 */

public class TestThreadSafe {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws InterruptedException {

        Buffer<String> buffer = new Buffer<String>(3);
        Producer producer = new Producer(buffer,2);
        Consumer consumer1 = new Consumer(buffer,3);
        Consumer consumer2 = new Consumer(buffer,4);
        
        Thread t1 = new Thread(producer);
        Thread t2 = new Thread(consumer1);
        Thread t3 = new Thread(consumer2);
        
        t1.start();
        t2.start();
        t3.start();
        
        Thread.sleep(25000);
        
        t1.interrupt();
        t2.interrupt();
        t3.interrupt();
    }
}
