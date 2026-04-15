#ifndef GESTORLOGISTICA_HPP
#define GESTORLOGISTICA_HPP

#include <vector>
#include <string>
#include "Envio.hpp"
#include "Vehiculo.hpp"

class GestorLogistica {
private:
    std::vector<Envio*> envios;
    std::vector<Vehiculo*> vehiculos;

public:
    GestorLogistica();
    ~GestorLogistica();

    void cargarEnvios(const std::string& archivo);
    void cargarVehiculos(const std::string& archivo);
    void ordenarEnvios();
    void repartir();

    // Sobrecarga de métodos
    void mostrarEnvios() const;
    void mostrarEnvios(bool soloNoCargados) const;
    void mostrarEnvios(const std::string& cp) const;

    void mostrarVehiculos() const;
    void mostrarVehiculos(bool mostrarCarga) const;  // Sobrecarga

    void mostrarNoCargados() const;
    void recogidaManual();
    void mostrarEstadisticas() const;

    // Métodos con referencias
    void mostrarEnvio(const Envio& e) const;
    void procesarVehiculo(const Vehiculo& v) const;

    // Getters
    const std::vector<Envio*>& getEnvios() const;
    const std::vector<Vehiculo*>& getVehiculos() const;
};

#endif