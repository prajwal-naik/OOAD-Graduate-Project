import time

class Shape:
    def area(self):
        return 0.0

class Circle(Shape):
    def area(self):
        return 3.14 * 10 * 10

N = 20_000_000
start = time.time()
total = 0.0

for _ in range(N):
    s = Circle()
    total += s.area()

print(time.time() - start)