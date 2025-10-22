package ProduttoreConsumatore;

public class WareHouse implements GeneralWareHouse{
  private int numberOfProducts;
  private int idNumber;
  private boolean empty = true;
  public synchronized void put(int idNumber) {
    if (!empty) {
      try {
        wait(); //blocca il producer dopo aver realizzato un put, finché non viene invocata la notify
      }
      catch (InterruptedException exc) {
        exc.printStackTrace();
      }
    }
    this.idNumber = idNumber;
    numberOfProducts++;
    printSituation("Produced " + idNumber);
    empty = false;
    notify(); //sveglia il consumer
  }
  public synchronized int get() {
    if (empty)
      try {
        wait();
      }
      catch (InterruptedException exc) {
        exc.printStackTrace();
      }
    numberOfProducts--;
    printSituation("Consumed " + idNumber);
    empty = true;    
    notify();
    return idNumber;
  }
  private synchronized void printSituation(String msg) {
    System.out.println(msg +"\n" + numberOfProducts + " Product in Warehouse");
  }
}