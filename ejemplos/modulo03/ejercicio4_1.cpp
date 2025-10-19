#include <memory>
#include <iostream>

int main() {
    // Creación segura con make_unique
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    std::cout << *ptr << "\n";

    // Transferencia de propiedad
    std::unique_ptr<int> ptr2 = std::move(ptr);

    if (!ptr) {
        std::cout << "ptr ya no posee el recurso.\n";
    }

    return 0; // ptr2 libera automáticamente la memoria
}
