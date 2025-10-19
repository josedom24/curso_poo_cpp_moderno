#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> sp = std::make_shared<int>(200);
    std::weak_ptr<int> wp = sp; // Observador

    if (auto spt = wp.lock()) { // Convierte temporalmente a shared_ptr
        std::cout << *spt << "\n";
    } else {
        std::cout << "El recurso ya fue liberado.\n";
    }

    return 0;
}
