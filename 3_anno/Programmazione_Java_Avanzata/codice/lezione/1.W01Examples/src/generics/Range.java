/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package generics;

/**
 *
 * @author lucagreco
 */
public class Range<T extends Number & Comparable<T>> {
    
    private T low;
    private T high;

    public Range(T low, T high) {
        this.low = low;
        this.high = high;
        
       
        if(low.compareTo(high) >=0) throw new IllegalArgumentException("low deve essere inferiore a high");
        
    }

 
    
    public T getLow() {
        return low;
    }

    public T getHigh() {
        return high;
    }
    
    
    public boolean contains(T e) {
 
        return ( e.compareTo(low) >= 0) && (e.compareTo(high) <= 0 );
    
  
    
    }
    
    @Override
    public String toString() {
    
        return low + " ~ " + high;
    
    
    }
    
    
    
}
