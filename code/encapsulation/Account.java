package encapsulation;

import java.util.ArrayList;
import java.util.List;

public class Account {
    private double balance;
    public Account(double b) { this.balance = b; }
    public double getBalance() { return balance; }
    public void setBalance(double b) { balance = b; }

    public static void main(String[] args) {
        int N = 10_000_000;
        List<Account> accounts = new ArrayList<>(N); // store objects

        Runtime runtime = Runtime.getRuntime();
        runtime.gc(); // initial GC
        long memoryBefore = runtime.totalMemory() - runtime.freeMemory();
        long start = System.nanoTime();

        for(int i = 0; i < N; i++) {
            Account acc = new Account(1000);
            acc.setBalance(1500);
            acc.getBalance();
            accounts.add(acc); // keep alive
        }

        long end = System.nanoTime();
        runtime.gc(); // collect garbage before measuring memory
        long memoryAfter = runtime.totalMemory() - runtime.freeMemory();

        System.out.println("Execution time: " + (end - start)/1e9 + " s");
        System.out.println("Memory used: " + (memoryAfter - memoryBefore) + " bytes");
    }
}
