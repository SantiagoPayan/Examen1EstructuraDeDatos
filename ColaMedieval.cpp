
#include "headers/ColaMedieval.hpp"
#include <stdexcept>
#include <iostream>

ColaMedieval::ColaMedieval() : totalNobles(0), totalPlebeyos(0) {}

ColaMedieval::ColaMedieval(const ColaMedieval& otra) {
    this->nobles = otra.nobles;
    this->plebeyos = otra.plebeyos;
    this->totalNobles = otra.totalNobles;
    this->totalPlebeyos = otra.totalPlebeyos;
}

ColaMedieval& ColaMedieval::operator=(const ColaMedieval& otra) {
    if (this != &otra) {
        this->nobles = otra.nobles;
        this->plebeyos = otra.plebeyos;
        this->totalNobles = otra.totalNobles;
        this->totalPlebeyos = otra.totalPlebeyos;
    }
    return *this;
}

ColaMedieval::~ColaMedieval() {
    vaciar();
}

void ColaMedieval::anadirPersona(std::string nombre, bool esNoble) {
    if (esNoble) {
        nobles.push(nombre);
        totalNobles++;
    } else {
        plebeyos.push(nombre);
        totalPlebeyos++;
    }
}

std::string ColaMedieval::consultarPrimerElemento() const {
    if (estaVacia()) throw std::underflow_error("La cola esta vacia.");
    if (!nobles.isEmpty()) return nobles.getFront(); 
    return plebeyos.getFront();
}

// si hay plebeyos, el último es un plebeyo. Si no, es un noble.
std::string ColaMedieval::consultarUltimoElemento() const {
    if (estaVacia()) throw std::underflow_error("La cola esta vacia.");
    if (!plebeyos.isEmpty()) return plebeyos.getFound(); 
    return nobles.getFound();
}

void ColaMedieval::eliminarPrimerElemento() {
    if (estaVacia()) throw std::underflow_error("La cola ya esta vacia.");
    
    if (!nobles.isEmpty()) {
        nobles.pop();
        totalNobles--;
    } else {
        plebeyos.pop();
        totalPlebeyos--;
    }
}

int ColaMedieval::consultarNumeroNobles() const { return totalNobles; }
int ColaMedieval::consultarNumeroPlebeyos() const { return totalPlebeyos; }

// Suma total de ciudadanos
int ColaMedieval::consultarNumeroCiudadanos() const { 
    return totalNobles + totalPlebeyos; 
}

bool ColaMedieval::estaVacia() const {
    return nobles.isEmpty() && plebeyos.isEmpty();
}

// Vaciar ambas colas y reiniciar los contadores
void ColaMedieval::vaciar() {
    nobles.clear();
    plebeyos.clear();
    totalNobles = 0;
    totalPlebeyos = 0;
}

// Imprimir a los nobles primero y luego plebeyos
void ColaMedieval::imprimir() const {
    if (estaVacia()) {
        std::cout << "[Fila vacia]\n";
        return;
    }
    if (!nobles.isEmpty()) nobles.print();
    if (!plebeyos.isEmpty()) plebeyos.print();
}
