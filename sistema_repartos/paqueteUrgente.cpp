#include "PaqueteUrgente.hpp"
#include <iostream>
#include <stdexcept>

PaqueteUrgente::PaqueteUrgente(std::string id, std::string cp, int p)
    : Envio(id, cp), prioridad(p) {
    if (prioridad < 1 || prioridad > 5) {
        throw std::out_of_range("La prioridad debe estar entre 1 y 5");
    }
}

PaqueteUrgente::~PaqueteUrgente() {}

void PaqueteUrgente::mostrar() const {
    std::cout << "[URGENTE] " << id << " CP:" << cp
        << " Prioridad:" << prioridad << " (IDnum:" << idNumerico << ")";
}

int PaqueteUrgente::prioridadCarga() const { return 2 + prioridad; }
std::string PaqueteUrgente::tipo() const { return "URGENTE"; }
int PaqueteUrgente::getPrioridad() const { return prioridad; }