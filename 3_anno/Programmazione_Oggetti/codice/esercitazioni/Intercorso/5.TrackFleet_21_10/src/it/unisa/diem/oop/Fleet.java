package it.unisa.diem.oop;
import java.util.*;

public class Fleet {
    private final String name;
    private final Set<Truck> fleet;
    
    public Fleet(String name) {
        this.name = name;
        this.fleet = new LinkedHashSet<>();
    }
   
    public void add(Truck obj) {
        this.fleet.add(obj);
    }

    public Fleet filterFoodGrade() {
        Fleet foodFleet = new Fleet("foodFleet");
        Iterator<Truck> iterator = this.fleet.iterator();
        while(iterator.hasNext()){
            Truck truck = iterator.next();
            if(truck instanceof Tanker && ((Tanker) truck).isFoodGrade()) {
                foodFleet.add(truck);
            }
        }
        return foodFleet;
    }

    @Override
    public String toString() {
        return this.name + " contains: \n" + fleet;
    }
}
