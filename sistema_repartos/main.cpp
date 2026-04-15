#include <iostream>
#include <stdexcept>
#include "GestorLogistica.hpp"

using namespace std;

int main() {
    try {
        GestorLogistica sistema;

        cout << "\n========================================\n";
        cout << "SISTEMA DE LOGISTICA\n";
        cout << "========================================\n";

        // Cargar datos desde ficheros
        sistema.cargarEnvios("paquetes.txt");
        sistema.cargarVehiculos("vehiculos.txt");

        // Mostrar estadisticas (variables static)
        sistema.mostrarEstadisticas();

        // Demostracion de sobrecarga de mostrarEnvios()
        cout << "\n========================================\n";
        cout << "DEMOSTRACION DE SOBRECARGA\n";
        cout << "========================================\n";

        sistema.mostrarEnvios();                    // Version 1: sin parametros
        sistema.mostrarEnvios("28001");             // Version 2: por CP
        sistema.mostrarEnvios(true);                // Version 3: solo no cargados (antes del reparto)

        // Mostrar vehiculos
        cout << "\n========================================\n";
        cout << "VEHICULOS DISPONIBLES\n";
        cout << "========================================\n";
        sistema.mostrarVehiculos();                  // Version 1: sin parametros
        sistema.mostrarVehiculos(true);              // Version 2: con detalle de carga

        cout << "\n========================================\n";
        cout << "ORDENANDO ENVIOS POR PRIORIDAD\n";
        cout << "(URGENTES + prioridad > NORMALES)\n";
        cout << "========================================\n";
        sistema.ordenarEnvios();
        sistema.mostrarEnvios();

        cout << "\n========================================\n";
        cout << "INICIANDO PROCESO DE REPARTO\n";
        cout << "========================================\n";
        sistema.repartir();

        cout << "\n========================================\n";
        cout << "ESTADO FINAL DE VEHICULOS\n";
        cout << "========================================\n";
        sistema.mostrarVehiculos(true);              // Mostrar vehiculos con su carga

        cout << "\n========================================\n";
        cout << "ENVIOS PENDIENTES (NO CARGADOS)\n";
        cout << "========================================\n";
        sistema.mostrarNoCargados();


        // Recogida manual de paquetes
        cout << "\n========================================\n";
        cout << "RECOGIDA MANUAL DE PAQUETES\n";
        cout << "========================================\n";
        cout << "Paquetes disponibles para recoger:\n";
        sistema.mostrarEnvios(true);                 // Mostrar solo no cargados
        sistema.recogidaManual();

        // Resumen final
        cout << "\n========================================\n";
        cout << "RESUMEN FINAL\n";
        cout << "========================================\n";
        sistema.mostrarNoCargados();
        sistema.mostrarEstadisticas();

        cout << "\n========================================\n";
        cout << "SISTEMA FINALIZADO CORRECTAMENTE\n";
        cout << "========================================\n";

    }
    catch (const exception& e) {
        cerr << "\nERROR FATAL: " << e.what() << endl;
        return 1;
    }

    return 0;
}