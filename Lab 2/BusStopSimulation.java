import java.util.concurrent.Semaphore;
import java.util.Random;

public class BusStopSimulation {
    static final int BUS_CAPACITY = 50;
    static final int MEAN_RIDER_ARRIVAL_MS = 1000; // 1 sec
    static final int MEAN_BUS_ARRIVAL_MS = 30000; // 30 sec
    static Semaphore mutex = new Semaphore(1);
    static Semaphore multiplex = new Semaphore(BUS_CAPACITY);
    static Semaphore busArrived = new Semaphore(0);
    static Semaphore allAboard = new Semaphore(0);
    static int waitingRiders = 0;
    static int boardingRiders = 0;

    public static void main(String[] args) {
        // Start bus thread
        new Thread(new Bus()).start();
        // Start rider generator thread
        new Thread(new RiderGenerator()).start();
    }

    static class RiderGenerator implements Runnable {
        Random rand = new Random();
        int riderId = 1;
        public void run() {
            while (true) {
                try {
                    Thread.sleep(getExpRandom(MEAN_RIDER_ARRIVAL_MS));
                } catch (InterruptedException e) { }
                new Thread(new Rider(riderId++)).start();
            }
        }
        private int getExpRandom(int mean) {
            return (int)(-Math.log(1 - rand.nextDouble()) * mean);
        }
    }

    static class Bus implements Runnable {
        Random rand = new Random();
        int busId = 1;
        public void run() {
            while (true) {
                try {
                    Thread.sleep(getExpRandom(MEAN_BUS_ARRIVAL_MS));
                } catch (InterruptedException e) { }
                System.out.println("Bus " + busId + " arrived.");
                mutex.acquireUninterruptibly();
                int ridersToBoard = Math.min(waitingRiders, BUS_CAPACITY);
                boardingRiders = ridersToBoard;
                if (ridersToBoard > 0) {
                    for (int i = 0; i < ridersToBoard; i++) {
                        busArrived.release();
                    }
                    mutex.release();
                    allAboard.acquireUninterruptibly();
                } else {
                    mutex.release();
                }
                System.out.println("Bus " + busId + " departed with " + ridersToBoard + " riders.");
                busId++;
            }
        }
        private int getExpRandom(int mean) {
            return (int)(-Math.log(1 - rand.nextDouble()) * mean);
        }
    }

    static class Rider implements Runnable {
        int id;
        public Rider(int id) { this.id = id; }
        public void run() {
            multiplex.acquireUninterruptibly(); // Limit riders in boarding area
            mutex.acquireUninterruptibly();
            waitingRiders++;
            System.out.println("Rider " + id + " arrived. Waiting riders: " + waitingRiders);
            mutex.release();
            busArrived.acquireUninterruptibly();
            boardBus();
        }
        private void boardBus() {
            mutex.acquireUninterruptibly();
            waitingRiders--;
            boardingRiders--;
            System.out.println("Rider " + id + " boarded. Riders left to board: " + boardingRiders);
            if (boardingRiders == 0) {
                allAboard.release();
            }
            mutex.release();
            multiplex.release(); // Allow next rider into boarding area
        }
    }
}
