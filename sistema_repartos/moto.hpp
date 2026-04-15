#ifndef MOTO_HPP
#define MOTO_HPP

#include "Vehiculo.hpp"

class Moto : public Vehiculo {
public:
    Moto(std::string id, std::string cp);
    ~Moto();

    bool cargar(Envio* e) override;
    void mostrar() const override;
};

#endif