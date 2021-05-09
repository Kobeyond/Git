#include <iostream>
#include <time.h>
// #include <cstring>
using namespace std;

class Singleton {
private:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton inst;
        return inst;
    }
};

int main() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++) {
        cout << "rand: " << rand() % 10 << endl;
    }
}

