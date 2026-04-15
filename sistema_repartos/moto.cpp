#include "Moto.hpp"
#include <iostream>

Moto::Moto(std::string id, std::string cp)
    : Vehiculo(id, cp, 2) {
}

Moto::~Moto() {}

bool Moto::cargar(Envio* e) {
    if (e == nullptr) return false;
    if (e->getCP() != cp) return false;
    if (!tieneEspacio()) return false;
    if (e->estaCargado()) return false;

    carga.push_back(e);
    e->setCargado(true);
    return true;
}

void Moto::mostrar() const {
    std::cout << "Moto " << id << " CP:" << cp
        << " (" << carga.size() << "/" << capacidad << ") [IDveh:" << idNumerico << "]";
    if (!carga.empty()) {
        std::cout << "\n  Paquetes:";
        for (auto e : carga) {
            std::cout << " " << e->getId();
        }
    }
    std::cout << std::endl;
}
