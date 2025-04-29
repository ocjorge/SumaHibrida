# 🔍 Suma Híbrida en C++ y Ensamblador (x86-64)
![C++](https://img.shields.io/badge/C++-17-blue?logo=cplusplus)
![ASM](https://img.shields.io/badge/Assembly-x86--64-red)
![License](https://img.shields.io/badge/License-MIT-green)

Este proyecto demuestra cómo sumar elementos de un arreglo utilizando una función híbrida que combina C++ y ensamblador (ASM) para x86-64, comparando su rendimiento.

## 📜 Código Híbrido C++/ASM
**Combina** lo mejor de ambos mundos para un rendimiento optimizado en operaciones críticas.

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

## 🚀 Características
- **⚡ Alto rendimiento**: Suma de 100 millones de enteros en milisegundos.
- **🔗 Integración directa**: Ensamblador inline (AT&T) en C++.
- **⏱️ Benchmarking**: Mide tiempos de ejecución con `<chrono>`.

## 🚀 Compilación y Ejecución
```bash
g++ -o sum_program main.cpp -O2
./sum_program
