package ristorante;

public class BackupAutomatico implements Runnable {
    private final Comande comande;
    private static final int DELAY = 2000;

    public BackupAutomatico(Comande comande){
        this.comande = comande;
    }

    @Override
    public void run(){
        while(!Thread.currentThread().isInterrupted()) {
            comande.salvaOrdinazioni();
            System.out.println("\nBACKUP EFFETTUATO");
            try {
                Thread.sleep(DELAY);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
