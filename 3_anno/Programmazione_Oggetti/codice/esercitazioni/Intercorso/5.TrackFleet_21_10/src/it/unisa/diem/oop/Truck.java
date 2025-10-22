package it.unisa.diem.oop;
import java.time.LocalDate;

public class Truck {
    private final String chassisID;
    private final LocalDate registrationDate;

    public Truck(String chassisID, LocalDate registrationDate) {
        this.chassisID=chassisID;
        this.registrationDate=registrationDate;
    }

    public String getChassisID() {
        return chassisID;
    }

    public LocalDate getRegistrationDate() {
        return registrationDate;
    }

    @Override
    public int hashCode() {      
         return this.chassisID.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Truck))
            return false;
        Truck truck = (Truck) obj;
        return this.getChassisID() == truck.getChassisID();
    }

    @Override
    public String toString() {
        return "\n Truck{Chassis:" + this.chassisID + " , Date:" + this.registrationDate + "}"; 
    }
}
