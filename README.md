# Suma de Elementos en Ensamblador y C++

Este proyecto demuestra cómo sumar elementos de un arreglo utilizando una función híbrida que combina C++ y ensamblador (ASM) para x86-64, comparando su rendimiento.

## 📋 Descripción

El programa:
1. Crea un vector grande de enteros (100,000,000 elementos)
2. Calcula la suma de todos los elementos usando una función en ensamblador
3. Mide y muestra el tiempo de ejecución

## 🛠️ Tecnologías
- **Lenguaje**: C++ con inline assembly (x86-64 AT&T syntax)
- **Compilador**: Requiere soporte para ASM inline (GCC, Clang)
- **Sistema**: x86-64 (64-bit)

## ⚡ Rendimiento
El código en ensamblador está optimizado para:
- Uso eficiente de registros (RAX, RCX, RDX)
- Instrucciones específicas para aritmética de 32 bits (`addl`)
- Optimización de bucle con `loop`

## 🚀 Compilación y Ejecución
```bash
g++ -o sum_program main.cpp -O2
./sum_program
