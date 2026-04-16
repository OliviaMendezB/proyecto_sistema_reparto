#include "GestorLogistica.hpp"
#include "PaqueteNormal.hpp"
#include "PaqueteUrgente.hpp"
#include "Furgoneta.hpp"
#include "Moto.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <stdexcept>

using namespace std;

GestorLogistica::GestorLogistica() {}

GestorLogistica::~GestorLogistica() {
    // Liberar memoria de todos los envios
    for (size_t i = 0; i < envios.size(); i++) {
        delete envios[i];
        envios[i] = nullptr;
    }

    // Liberar memoria de todos los vehiculos
    for (size_t i = 0; i < vehiculos.size(); i++) {
        delete vehiculos[i];
        vehiculos[i] = nullptr;
    }
}

void GestorLogistica::cargarEnvios(const std::string& archivo) {
    ifstream file(archivo);

    try {
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el archivo: " + archivo);
        }

        string tipo, id, cp;
        while (file >> tipo >> id >> cp) {
            try {
                if (tipo == "N") {
                    double peso;
                    file >> peso;
                    if (peso <= 0) throw invalid_argument("Peso invalido");
                    envios.push_back(new PaqueteNormal(id, cp, peso));
                }
                else if (tipo == "U") {
                    int prioridad;
                    file >> prioridad;
                    if (prioridad < 1 || prioridad > 5) {
                        throw out_of_range("Prioridad debe ser 1-5");
                    }
                    envios.push_back(new PaqueteUrgente(id, cp, prioridad));
                }
                else {
                    throw runtime_error("Tipo de paquete desconocido: " + tipo);
                }
            }
            catch (const exception& e) {
                cerr << "Error en paquete " << id << ": " << e.what() << endl;
            }
        }
        file.close();

        if (envios.empty()) {
            throw runtime_error("No se cargaron envios del archivo");
        }
    }
    catch (const exception& e) {
        cerr << "Error fatal: " << e.what() << endl;
    }
}

void GestorLogistica::cargarVehiculos(const std::string& archivo) {
    ifstream file(archivo);

    try {
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el archivo: " + archivo);
        }

        string tipo, id, cp;
        while (file >> tipo >> id >> cp) {
            if (tipo == "F") {
                vehiculos.push_back(new Furgoneta(id, cp));
            }
            else if (tipo == "M") {
                vehiculos.push_back(new Moto(id, cp));
            }
            else {
                cerr << "Tipo de vehiculo desconocido: " << tipo << endl;
            }
        }
        file.close();

        if (vehiculos.empty()) {
            throw runtime_error("No se cargaron vehiculos del archivo");
        }
    }
    catch (const exception& e) {
        cerr << "Error fatal: " << e.what() << endl;
    }
}

bool compararPrioridad(Envio* a, Envio* b) {
    return a->prioridadCarga() > b->prioridadCarga();
}

void GestorLogistica::ordenarEnvios() {
    sort(envios.begin(), envios.end(), compararPrioridad);
}

void GestorLogistica::repartir() {
    if (vehiculos.empty()) {
        throw runtime_error("No hay vehiculos disponibles");
    }
    if (envios.empty()) {
        throw runtime_error("No hay envios para repartir");
    }

    for (size_t i = 0; i < envios.size(); i++) {
        for (size_t j = 0; j < vehiculos.size(); j++) {
            if (vehiculos[j]->getCP() == envios[i]->getCP()) {
                if (vehiculos[j]->cargar(envios[i])) {
                    break;
                }
            }
        }
    }
}

// Sobrecarga de mostrarEnvios
void GestorLogistica::mostrarEnvios() const {
    cout << "\n===== TODOS LOS ENVIOS =====\n";
    for (size_t i = 0; i < envios.size(); i++) {
        envios[i]->mostrar();
        cout << endl;
    }
}

void GestorLogistica::mostrarEnvios(bool soloNoCargados) const {
    if (soloNoCargados) {
        cout << "\n===== ENVIOS NO CARGADOS =====\n";
        for (size_t i = 0; i < envios.size(); i++) {
            if (!envios[i]->estaCargado()) {
                envios[i]->mostrar();
                cout << " - Cargado: No" << endl;
            }
        }
    }
    else {
        mostrarEnvios();
    }
}

void GestorLogistica::mostrarEnvios(const std::string& cp) const {
    cout << "\n===== ENVIOS CON CP: " << cp << " =====\n";
    for (size_t i = 0; i < envios.size(); i++) {
        if (envios[i]->getCP() == cp) {
            envios[i]->mostrar();
            cout << endl;
        }
    }
}

void GestorLogistica::mostrarVehiculos() const {
    cout << "\n===== TODOS LOS VEHICULOS =====\n";
    for (size_t i = 0; i < vehiculos.size(); i++) {
        vehiculos[i]->mostrar();
    }
}

void GestorLogistica::mostrarVehiculos(bool mostrarCarga) const {
    cout << "\n===== VEHICULOS =====\n";
    for (size_t i = 0; i < vehiculos.size(); i++) {
        vehiculos[i]->mostrar(mostrarCarga);
    }
}

void GestorLogistica::mostrarNoCargados() const {
    cout << "\n===== ENVIOS NO CARGADOS =====\n";
    int contador = 0;
    for (size_t i = 0; i < envios.size(); i++) {
        if (!envios[i]->estaCargado()) {
            envios[i]->mostrar();
            cout << endl;
            contador++;
        }
    }

    if (contador == 0) {
        cout << "No hay envios pendientes\n";
    }
    else {
        cout << "\nTotal pendientes: " << contador << "\n";
    }
}

void GestorLogistica::recogidaManual() {
    string id;
    cout << "\n=== RECOGIDA MANUAL ===\n";
    cout << "ID del paquete a recoger (-1 para salir): ";
    cin >> id;

    while (id != "-1") {
        bool encontrado = false;
        for (size_t i = 0; i < envios.size(); i++) {
            if (envios[i]->getId() == id && !envios[i]->estaCargado()) {
                envios[i]->setCargado(true);
                cout << "Paquete " << id << " recogido manualmente\n";
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "Paquete no encontrado o ya estaba cargado\n";
        }

        cout << "Siguiente ID (-1 para salir): ";
        cin >> id;
    }
}

void GestorLogistica::mostrarEstadisticas() const {
    cout << "\n===== ESTADISTICAS =====\n";
    cout << "Total envios creados (static): " << Envio::getTotalEnvios() << endl;
    cout << "Total vehiculos creados (static): " << Vehiculo::getTotalVehiculos() << endl;
    cout << "Envios en sistema: " << envios.size() << endl;
    cout << "Vehiculos en sistema: " << vehiculos.size() << endl;
}

// Getters
const std::vector<Envio*>& GestorLogistica::getEnvios() const {
    return envios;
}

const std::vector<Vehiculo*>& GestorLogistica::getVehiculos() const {
    return vehiculos;
}