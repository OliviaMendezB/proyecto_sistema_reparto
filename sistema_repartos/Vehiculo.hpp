#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include <vector>
#include <string>
#include "Envio.hpp"

class Vehiculo {
protected:
    std::string id;
    std::string cp;
    int capacidad;
    std::vector<Envio*> carga;
    static int totalVehiculos;  // Variable estática
    const int idNumerico;        // Variable constante

public:
    Vehiculo(std::string id, std::string cp, int cap);
    virtual ~Vehiculo();

    virtual bool cargar(Envio* e) = 0;
    virtual void mostrar() const = 0;
    virtual void mostrar(bool mostrarCarga) const;

    std::string getCP() const;
    std::string getId() const;
    int getCargaActual() const;
    int getCapacidad() const;
    bool tieneEspacio() const;

    static int getTotalVehiculos();   // Método estático
    int getIdNumerico() const;        // Método const
};

#endif