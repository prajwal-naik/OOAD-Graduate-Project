#include <iostream>
#include <chrono>
using namespace std;

class Shape {
public:
    virtual double area() const { return 0.0; }
};

class Circle : public Shape {
public:
    double area() const override { return 3.14 * 10 * 10; }
};

int main() {
    int N = 20'000'000;

    auto start = chrono::high_resolution_clock::now();
    double total = 0.0;

    for (int i = 0; i < N; i++) {
        Shape* s = new Circle();
        total += s->area();
        delete s;
    }

    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration<double>(end - start).count() << endl;
    return 0;
}