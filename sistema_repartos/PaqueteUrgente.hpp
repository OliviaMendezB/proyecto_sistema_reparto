#ifndef PAQUETEURGENTE_HPP
#define PAQUETEURGENTE_HPP

#include "Envio.hpp"

class PaqueteUrgente : public Envio {
    int prioridad;

public:
    PaqueteUrgente(std::string id, std::string cp, int prioridad);
    ~PaqueteUrgente();

    void mostrar() const override;
    int prioridadCarga() const override;
    std::string tipo() const override;

    int getPrioridad() const;
};

#endif