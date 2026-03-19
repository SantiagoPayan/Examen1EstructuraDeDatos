#ifndef COLAMEDIEVAL_HPP
#define COLAMEDIEVAL_HPP

#include "Queue.hpp"
#include <string>

class ColaMedieval {
private:
    Queue<std::string> nobles;
    Queue<std::string> plebeyos;
    int totalNobles;
    int totalPlebeyos;

public:
    ColaMedieval();
    ColaMedieval(const ColaMedieval& otra);
    ColaMedieval& operator=(const ColaMedieval& otra);
    ~ColaMedieval();

    void anadirPersona(std::string nombre, bool esNoble);
    std::string consultarPrimerElemento() const;
    std::string consultarUltimoElemento() const; 
    void eliminarPrimerElemento();
    int consultarNumeroNobles() const;
    int consultarNumeroPlebeyos() const;
    int consultarNumeroCiudadanos() const; 
    bool estaVacia() const;
    void vaciar();
    void imprimir() const; 
};

#endif
