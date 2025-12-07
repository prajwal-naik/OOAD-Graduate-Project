from abc import ABC, abstractmethod
import math
import time
import tracemalloc

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

class Circle(Shape):
    def area(self):
        return math.pi * 5 * 5

def main():
    s = Circle()
    tracemalloc.start()
    start = time.time_ns()
    for i in range(1_000_000):
        s.area()
    end = time.time_ns()
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()
    print((end - start) / 1e9)
    print("Current memory:", current, "bytes")
    print("Peak memory:", peak, "bytes")

if __name__ == "__main__":
    main()