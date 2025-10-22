package it.unisa.diem.oop;

public class Tanker extends Truck {
    private final int totalCapacity;
    private final int compartments;
    private boolean foodGrade;
    
    public Tanker(Truck tractor, int totalCapacity, int compartments, boolean foodGrade) {
        super(tractor.getChassisID(), tractor.getRegistrationDate());
 
        if (totalCapacity<5000 || totalCapacity>25000) 
            throw new IllegalArgumentException("Invalid total capacity value or bad compartments number");
        this.totalCapacity = totalCapacity;
        if (compartments > 4) 
            throw new IllegalArgumentException("Invalid total capacity value or bad compartments number");
        this.compartments = compartments;
        this.foodGrade = foodGrade;
    }

    public int getTotalCapacity() {
       return this.totalCapacity;
    }

    public int getCompartments() {
        return this.compartments;
    }

    public boolean isFoodGrade() {
        return foodGrade == true;
    }
    
    @Override
    public String toString() {
       return super.toString() + "->Tanker{Capacity:" + this.totalCapacity + " , Compartments:" + this.compartments + " , food:" + this.foodGrade + "}";
    }
}