// #include <iostream>
// #include <chrono>
// #include <sys/resource.h>
// using namespace std;
// class Shape {
// public:
//     virtual double area() const { return 0.0; }
// };
// class Circle : public Shape {
// public:
//     double area() const override { return 3.14 * 5 * 5; }
// };
// int main() {
//     int N = 10'000'000;
//     auto start = chrono::high_resolution_clock::now();
//     for (int i = 0; i < N; i++) {
//         Shape* shape = new Circle();
//         shape -> area();
//         delete shape;
//     }
//     auto end = chrono::high_resolution_clock::now();
//     cout << chrono::duration<double>(end - start).count() << endl;
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

class Account {
private:
    double balance;
public:
    Account(double b) : balance(b) {}
    double getBalance() const { return balance; }
    void setBalance(double b) { balance = b; }
};

int main() {
    int N = 10'000'000;
    vector<Account*> accounts;  // Keep objects alive

    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        Account* newAccount = new Account(100);
        newAccount->setBalance(200);
        newAccount->getBalance();
        accounts.push_back(newAccount);  // Store
    }
    auto end = high_resolution_clock::now();

    cout << "Execution time: " << chrono::duration<double>(end - start).count() << " s\n";

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    cout << "Peak memory: " << usage.ru_maxrss << " bytes\n";

    // Clean up
    for (auto acc : accounts) delete acc;
    return 0;
}
