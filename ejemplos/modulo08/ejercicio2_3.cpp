#include <iostream>

template <typename T, int N>
class Arreglo {
private:
    T datos[N];
public:
    T& operator[](int i) { return datos[i]; }
    const T& operator[](int i) const { return datos[i]; }
    constexpr int size() const { return N; }
};

int main() {
    Arreglo<int, 5> arr;
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = i * 10;

    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << ' ';
}
