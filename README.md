Sistema de Gestión de Repartos

## Objetivo

El objetivo de este proyecto es aplicar conceptos de programación orientada a objetos en C++, como herencia, polimorfismo y gestión de memoria, mediante la simulación de un sistema logístico de reparto.

## 1. INTRODUCCIÓN

El sistema de gestión de paquetes simula un proceso de reparto utilizando una flota de vehículos. Permite:
- Cargar paquetes desde un archivo de texto
- Cargar vehículos desde un archivo de texto
- Ordenar paquetes por prioridad (urgentes primero)
- Asignar automáticamente paquetes a vehículos según código postal
- Identificar paquetes que no han podido ser cargados
- Recoger paquetes manualmente
- Mostrar estadísticas del sistema

## 2. Estructura General del Sistema

El proyecto está organizado en los siguientes módulos:
- Envio
- PaqueteNormal
- PaqueteUrgente
- Vehiculo
- Furgoneta
- Moto
- GestorLogistica

Cada módulo cuenta con:
- .hpp → definición de la clase
- .cpp → implementación de los métodos

Otros archivos importantes: maoin.cpp, paquetes.txt y vehiculos.txt

## 3. Ficheros de Entrada
paquetes.txt:
U P001 28001 5
N P004 28002 2.5
--> formato: Tipo (U = Urgente, N = Normal) , ID del paquete, código postal y prioridad

vehiculos.txt:
F F001 28001
M M001 28002
--> formato: Tipo (F = Furgoneta, M = Moto), ID del vehículo y código postal

## 4. Herencia
El sistema implementa herencia de la siguiente forma:

Envio
├── PaqueteNormal
└── PaqueteUrgente

Vehiculo
├── Furgoneta
└── Moto

## 5. ASPECTOS TÉCNICOS
El proyecto implementa los siguientes conceptos de programación orientada a objetos:

- Herencia - Jerarquía de clases
- Polimorfismo - Métodos virtuales y sobrescritura
- Variables estáticas - Contadores y estadísticas globales
- Manejo de excepciones - `try`, `catch`, `throw`
- Sobrecarga de métodos - Múltiples versiones de `mostrarEnvios()`
- Punteros y referencias - Paso de objetos por referencia
- Destructores - Liberación correcta de memoria

## 6. Flujo del Programa (main)

### FASE 1: Preparación
- Uso de try-catch
- Creación de GestorLogistica

### FASE 2: Carga de datos
- Lectura de paquetes.txt
- Lectura de vehiculos.txt

### FASE 3: Estadísticas
- Uso de variables static

### FASE 4: Sobrecarga
- mostrarEnvios()
- mostrarEnvios("28001")
- mostrarEnvios(true)

### FASE 5: Vehículos
- Mostrar sin detalle
- Mostrar con detalle

### FASE 6: Ordenación
- Ordenar por prioridad

### FASE 7: Reparto
- Asignación automática por código postal
- Paquetes cargados y pendientes

### FASE 8: Resultados
- Vehículos con carga
- Paquetes no cargados

### FASE 9: Recogida manual
- Entrada de IDs por usuario

### FASE 10: Resumen final
- Estadísticas finales

### FASE 11: Finalización
- Mensaje de éxito
- return 0
- Liberación de memoria (destructores)

