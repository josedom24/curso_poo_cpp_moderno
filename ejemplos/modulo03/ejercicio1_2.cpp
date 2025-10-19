#include <cstdio>   // fopen, fclose

int main() {
    FILE* file = fopen("datos.txt", "r"); // Apertura manual del archivo
    if (file) {
        // ... uso del archivo ...
        fclose(file); // Cierre manual obligatorio
    }

    return 0;
}
