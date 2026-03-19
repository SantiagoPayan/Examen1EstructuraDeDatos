#include "headers/ColaMedieval.hpp"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

void imprimirEstado(const ColaMedieval& cola) {
    cout << "--------------------------------------------------\n";
    cout << "Ciudadanos totales en espera: " << cola.consultarNumeroCiudadanos() << "\n";
    cout << "Nobles: " << cola.consultarNumeroNobles() 
         << " | Plebeyos: " << cola.consultarNumeroPlebeyos() << "\n";
    cout << "Fila actual:\n";
    cola.imprimir();
    cout << "--------------------------------------------------\n";
}

int main() {
    srand(time(nullptr));
    ColaMedieval filaCamelot;
    
    // Cola normal
    Queue<string> historialAtendidos; 

    cout << "==================================================\n";
    cout << "   SIMULACION DEL REY ARTURO (COLA MEDIEVAL)\n";
    cout << "==================================================\n\n";

    // Ciudadanos iniciales 
    filaCamelot.anadirPersona("[Noble] Sir Lancelot", true);
    filaCamelot.anadirPersona("[Plebeyo] Juan el Herrero", false);
    filaCamelot.anadirPersona("[Noble] Lady Ginebra", true);

    int tiempoTotalSimulacion = 5; // Simular 5 turnos para que no tarde mucho

    for (int minuto = 1; minuto <= tiempoTotalSimulacion; ++minuto) {
        cout << "\n[Turno " << minuto << "]\n";

        if (!filaCamelot.estaVacia()) {
            string atendido = filaCamelot.consultarPrimerElemento();
            cout << "El Rey Arturo esta atendiendo a: " << atendido << "\n";
            
            //  historial
            historialAtendidos.push(atendido); 
            
            filaCamelot.eliminarPrimerElemento();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        } else {
            cout << "El Rey Arturo esta bebiendo hidromiel. No hay fila.\n";
        }

        // Llegada de nuevos ciudadanos
        int probabilidadLlegada = rand() % 100;
        if (probabilidadLlegada < 30) { 
            cout << ">>> Ha llegado un nuevo Noble a la corte!\n";
            filaCamelot.anadirPersona("[Noble] Lord " + to_string(rand() % 100), true);
        } else if (probabilidadLlegada < 70) { 
            cout << ">>> Ha llegado un nuevo Plebeyo buscando ayuda!\n";
            filaCamelot.anadirPersona("[Plebeyo] Aldeano " + to_string(rand() % 100), false);
        }

        imprimirEstado(filaCamelot);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // LISTADO FINAL
    cout << "\n==================================================\n";
    cout << "El Rey Arturo ha cerrado la corte.\n";
    cout << "LISTADO DE CIUDADANOS ATENDIDOS HOY (EN ORDEN):\n";
    if (historialAtendidos.isEmpty()) {
        cout << "Nadie fue atendido hoy.\n";
    } else {
        historialAtendidos.print();
    }
    cout << "==================================================\n";

    return 0;
}
