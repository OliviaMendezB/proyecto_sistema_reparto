#include "Furgoneta.hpp"
#include <iostream>

Furgoneta::Furgoneta(std::string id, std::string cp)
    : Vehiculo(id, cp, 5) {
}

Furgoneta::~Furgoneta() {}

bool Furgoneta::cargar(Envio* e) {
    if (e == nullptr) return false;
    if (e->getCP() != cp) return false;
    if (!tieneEspacio()) return false;
    if (e->estaCargado()) return false;

    carga.push_back(e);
    e->setCargado(true);
    return true;
}

void Furgoneta::mostrar() const {
    std::cout << "Furgoneta " << id << " CP:" << cp
        << " (" << carga.size() << "/" << capacidad << ") [IDveh:" << idNumerico << "]";
    if (!carga.empty()) {
        std::cout << "\n  Paquetes:";
        for (size_t i = 0; i < carga.size(); i++) {
            std::cout << " " << carga[i]->getId();
        }
    }
    std::cout << std::endl;
}
