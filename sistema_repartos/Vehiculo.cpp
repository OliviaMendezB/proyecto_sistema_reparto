#include "Vehiculo.hpp"
#include <iostream>

int Vehiculo::totalVehiculos = 0;  // Inicializar estática

Vehiculo::Vehiculo(std::string id, std::string cp, int cap)
    : id(id), cp(cp), capacidad(cap), idNumerico(++totalVehiculos) {
}

Vehiculo::~Vehiculo() {}

void Vehiculo::mostrar(bool mostrarCarga) const {
    std::cout << "Vehiculo " << id << " CP:" << cp
        << " (" << carga.size() << "/" << capacidad << ")";
    if (mostrarCarga && !carga.empty()) {
        std::cout << "\n  Carga: ";
        for (size_t i = 0; i < carga.size(); ++i) {
            std::cout << carga[i]->getId();
            if (i < carga.size() - 1) std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

std::string Vehiculo::getCP() const { return cp; }
std::string Vehiculo::getId() const { return id; }
int Vehiculo::getCargaActual() const { return carga.size(); }
int Vehiculo::getCapacidad() const { return capacidad; }
bool Vehiculo::tieneEspacio() const { return carga.size() < capacidad; }
int Vehiculo::getTotalVehiculos() { return totalVehiculos; }
int Vehiculo::getIdNumerico() const { return idNumerico; }