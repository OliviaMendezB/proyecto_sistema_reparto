#include "PaqueteNormal.hpp"
#include <iostream>
#include <stdexcept>

PaqueteNormal::PaqueteNormal(std::string id, std::string cp, double p)
    : Envio(id, cp), peso(p) {
    if (peso <= 0) {
        throw std::invalid_argument("El peso debe ser positivo");
    }
}

PaqueteNormal::~PaqueteNormal() {}

void PaqueteNormal::mostrar() const {
    std::cout << "[NORMAL] " << id << " CP:" << cp
        << " Peso:" << peso << " (IDnum:" << idNumerico << ")";
}

int PaqueteNormal::prioridadCarga() const { return 1; }
std::string PaqueteNormal::tipo() const { return "NORMAL"; }
double PaqueteNormal::getPeso() const { return peso; }