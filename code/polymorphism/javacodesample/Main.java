package polymorphism.javacodesample;

import java.util.ArrayList;
import java.util.List;

abstract class Shape {
    abstract double area();
}

class Circle extends Shape {
    double area() { return Math.PI * 5 * 5; }
}

public class Main {
    public static void main(String[] args) {
        int N = 1_000_000; // fewer objects, adjust as needed
        List<Shape> shapes = new ArrayList<>(N);

        Runtime runtime = Runtime.getRuntime();
        runtime.gc(); // initial GC
        long memoryBefore = runtime.totalMemory() - runtime.freeMemory();
        long start = System.nanoTime();

        for(int i = 0; i < N; i++) {
            Shape s = new Circle();
            s.area();
            shapes.add(s); // keep alive
        }

        long end = System.nanoTime();
        runtime.gc(); // collect before measuring
        long memoryAfter = runtime.totalMemory() - runtime.freeMemory();

        System.out.println("Execution time: " + (end - start)/1e9 + " s");
        System.out.println("Memory used: " + (memoryAfter - memoryBefore) + " bytes");
    }
}
