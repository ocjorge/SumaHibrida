#include <iostream>
#include <vector>
#include <chrono>

// Declaración de la función en ensamblador (la implementación estará más adelante)
extern "C" long long sum_asm(const int* arr, size_t n);

int main() {
    // Crear el mismo vector grande de enteros
    std::vector<int> data(100000000, 1);
    size_t size = data.size();
    const int* data_ptr = data.data();

    // Medir el tiempo de ejecución de la función en ensamblador
    auto start_time_asm = std::chrono::high_resolution_clock::now();
    long long sum_hybrid = sum_asm(data_ptr, size);
    auto end_time_asm = std::chrono::high_resolution_clock::now();
    auto duration_hybrid = std::chrono::duration_cast<std::chrono::milliseconds>(end_time_asm - start_time_asm);

    std::cout << "Suma (híbrida): " << sum_hybrid << std::endl;
    std::cout << "Tiempo de ejecución (híbrida): " << duration_hybrid.count() << " ms" << std::endl;

    return 0;
}

// Implementación de la función en ensamblador (en un archivo separado o inline con directivas del compilador)
// Ejemplo para arquitectura x86-64 (AT&T syntax)
asm(".global sum_asm\n"
    "sum_asm:\n"
    "    movq %rdi, %rax    # rax = dirección del array (primer argumento)\n"
    "    movq %rsi, %rcx    # rcx = número de elementos (segundo argumento)\n"
    "    movq $0, %rdx      # rdx = acumulador (inicializado a 0)\n"
    "    testq %rcx, %rcx    # ¿Hay elementos para sumar?\n"
    "    jz .Lend\n"
    ".Lloop:\n"
    "    addl (%rax), %edx   # edx += valor actual del array (se usa addl para enteros de 32 bits)\n"
    "    addq $4, %rax      # avanzar al siguiente elemento (4 bytes por int)\n"
    "    loop .Lloop        # decrementar rcx y saltar a .Lloop si no es cero\n"
    ".Lend:\n"
    "    movq %rdx, %rax    # mover el resultado (en rdx) a rax (valor de retorno)\n"
    "    ret\n");
