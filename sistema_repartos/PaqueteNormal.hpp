#ifndef PAQUETENORMAL_HPP
#define PAQUETENORMAL_HPP

#include "Envio.hpp"

class PaqueteNormal : public Envio {
    double peso;

public:
    PaqueteNormal(std::string id, std::string cp, double peso);
    ~PaqueteNormal();

    void mostrar() const override;
    int prioridadCarga() const override;
    std::string tipo() const override;

    double getPeso() const;
};

#endif