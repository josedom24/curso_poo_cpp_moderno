#include <iostream>

class Multiplicador {
private:
    int factor_;
public:
    explicit Multiplicador(int factor) : factor_(factor) {}

    int operator()(int x) const {
        return x * factor_;
    }

};

int main() {
    Multiplicador por2(2);
    Multiplicador por10(10);

    std::cout << por2(5) << '\n';   // 10
    std::cout << por10(3) << '\n';  // 30
}
