#ifndef FURGONETA_HPP
#define FURGONETA_HPP

#include "Vehiculo.hpp"

class Furgoneta : public Vehiculo {
public:
    Furgoneta(std::string id, std::string cp);
    ~Furgoneta();

    bool cargar(Envio* e) override;
    void mostrar() const override;
};

#endif