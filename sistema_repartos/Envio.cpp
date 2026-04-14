#include "Envio.hpp"
#include <iostream>

int Envio::totalEnviosCreados = 0;  // Inicializar estática

Envio::Envio(std::string id, std::string cp)
    : id(id), cp(cp), cargado(false), idNumerico(++totalEnviosCreados) {
}

Envio::~Envio() {}

std::string Envio::getId() const { return id; }
std::string Envio::getCP() const { return cp; }
bool Envio::estaCargado() const { return cargado; }
void Envio::setCargado(bool c) { cargado = c; }
int Envio::getTotalEnvios() { return totalEnviosCreados; }
int Envio::getIdNumerico() const { return idNumerico; }