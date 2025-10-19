#include <iostream>
#include <utility>
#include <string>

int main() {
    std::pair<int, std::string> p = std::make_pair(2, "dos");
    std::cout << p.first << ", " << p.second << '\n';
}
