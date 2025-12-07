public class Optimization {
    static abstract class Shape {
        abstract double area();
    }

    static class Circle extends Shape {
        double area() { return 3.14 * 10 * 10; }
    }

    public static void main(String[] args) {
        int N = 20_000_000;
        long start = System.nanoTime();
        double total = 0;

        for (int i = 0; i < N; i++) {
            Shape s = new Circle();
            total += s.area();
        }

        long end = System.nanoTime();
        System.out.println((end - start) / 1e9);
    }
}
