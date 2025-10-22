/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package threadsafe;

import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author lucagreco
 */
public class Buffer<E> {

    private int size;
    private Queue<E> buffer;

    public Buffer(int size) {
        this.size = size;
        this.buffer = new LinkedList<E>();
    }

    public synchronized boolean isEmpty() {
        return buffer.isEmpty();
    }

    public synchronized boolean isFull() {
        return buffer.size() == size;
    }
    
    public synchronized void add(E e) throws InterruptedException {
        while(isFull()) 
            wait();
        buffer.add(e);
        notifyAll();
    }
    
    public synchronized E remove() throws InterruptedException {
        while(isEmpty())
            wait();
        E e1 = buffer.remove();
        notifyAll();
        return e1;
    }
}
