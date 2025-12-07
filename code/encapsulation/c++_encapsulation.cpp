// #include <iostream>
// #include <chrono>
// #include <sys/resource.h>
// using namespace std;
// using namespace std::chrono;
// class Account {
// private:
//     double balance;
// public:
//     Account(double b) : balance(b) {}
//     double getBalance() const { return balance; }
//     void setBalance(double b) { balance = b; }
// };
// int main() {
//     int N = 10'000'000;
//     auto start = high_resolution_clock::now();
//     for (int i = 0; i < N; i++) {
//         Account* newAccount = new Account(100);
//         newAccount -> setBalance(200);
//         double newBalance = newAccount -> getBalance();
//         delete newAccount;
//     }
//     auto end = high_resolution_clock::now();
//     cout << chrono::duration<double>(end - start).count() <<endl;

//     struct rusage usage;
//     getrusage(RUSAGE_SELF, &usage);
//     cout << "Peak memory: " << usage.ru_maxrss << " bytes\n";
//     return 0;
// }


#include <iostream>
#include <chrono>
#include <sys/resource.h>
#include <vector>
using namespace std;
using namespace std::chrono;

class Shape {
public:
    virtual double area() const { return 0.0; }
    virtual ~Shape() {}  // Always add virtual destructor
};

class Circle : public Shape {
public:
    double area() const override { return 3.14 * 5 * 5; }
};

int main() {
    int N = 10'000'000;
    vector<Shape*> shapes;  // Keep objects alive

    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        Shape* shape = new Circle();
        shape->area();
        shapes.push_back(shape);  // Store
    }
    auto end = high_resolution_clock::now();

    cout << "Execution time: " << chrono::duration<double>(end - start).count() << " s\n";

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    cout << "Peak memory: " << usage.ru_maxrss << " bytes\n";

    // Clean up
    for (auto s : shapes) delete s;
    return 0;
}
