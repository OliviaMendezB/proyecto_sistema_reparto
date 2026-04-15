#ifndef ENVIO_HPP
#define ENVIO_HPP

#include <string>

class Envio {
protected:
    std::string id;
    std::string cp;
    bool cargado;
    static int totalEnviosCreados;  // Variable estática
    const int idNumerico;            // Variable constante

public:
    Envio(std::string id, std::string cp);
    virtual ~Envio();

    virtual void mostrar() const = 0;
    virtual int prioridadCarga() const = 0;
    virtual std::string tipo() const = 0;

    std::string getId() const;
    std::string getCP() const;
    bool estaCargado() const;
    void setCargado(bool c);

    static int getTotalEnvios();      // Método estático
    int getIdNumerico() const;        // Método const
};

#endif