#include <iostream>
#include <string>

using namespace std;

// Estructura del equipo
struct Equipo {
    string nombre;
    string ciudad;
    int anioFundacion;
};

// Estructura del jugador
struct Jugador {
    string nombre;
    int edad;
    string videojuego;
    int ganadas;
    int perdidas;
    int puntos;
    Equipo eq; // equipo anidado
};

int main() {
    Jugador j[8];

    float sumaPuntos = 0;
    float promedio = 0;

    int masPuntos = 0;
    int masGanadas = 0;
    int arribaPromedio = 0;

    cout << "REGISTRO DE JUGADORES" << endl;

    // 1. Capturar los 8 jugadores
    for(int i = 0; i < 8; i++) {
        cout << "\nJugador " << i + 1 << endl;

        cout << "Nombre del jugador: ";
        getline(cin, j[i].nombre);

        cout << "Edad: ";
        cin >> j[i].edad;

        cin.ignore(); // limpia bufer

        cout << "Videojuego: ";
        getline(cin, j[i].videojuego);

        cout << "Partidas ganadas: ";
        cin >> j[i].ganadas;

        cout << "Partidas perdidas: ";
        cin >> j[i].perdidas;

        cout << "Puntos: ";
        cin >> j[i].puntos;

        cin.ignore();

        cout << "Nombre del equipo: ";
        getline(cin, j[i].eq.nombre);

        cout << "Ciudad del equipo: ";
        getline(cin, j[i].eq.ciudad);

        cout << "Ano de fundacion del equipo: ";
        cin >> j[i].eq.anioFundacion;

        cin.ignore();

        // Sumar puntos para el promedio
        sumaPuntos += j[i].puntos;
    }

    // 6. Promedio de puntos
    promedio = sumaPuntos / 8;

    // Calculos y busquedas
    for(int i = 0; i < 8; i++) {
        // 4. Mas puntos
        if(j[i].puntos > j[masPuntos].puntos) {
            masPuntos = i;
        }

        // 8. Mas partidas ganadas
        if(j[i].ganadas > j[masGanadas].ganadas) {
            masGanadas = i;
        }

        // 7. Cuantos superan el promedio
        if(j[i].puntos > promedio) {
            arribaPromedio++;
        }
    }

    // 2. Mostrar datos completos y 3. Partidas jugadas
    cout << "\n--- DATOS DE LOS PARTICIPANTES ---" << endl;
    for(int i = 0; i < 8; i++) {
        int totJugadas = j[i].ganadas + j[i].perdidas; // 3. Calculo de partidas jugadas

        cout << "\nJugador: " << j[i].nombre << " (" << j[i].edad << " anos)" << endl;
        cout << "Juego: " << j[i].videojuego << " | Puntos: " << j[i].puntos << endl;
        cout << "Partidas -> Ganadas: " << j[i].ganadas 
             << " | Perdidas: " << j[i].perdidas 
             << " | Total jugadas: " << totJugadas << endl;
        cout << "Equipo: " << j[i].eq.nombre 
             << " (" << j[i].eq.ciudad << ", Fundado en " << j[i].eq.anioFundacion << ")" << endl;
    }

    // 5. Mas victorias que derrotas
    cout << "\n--- JUGADORES CON MAS VICTORIAS QUE DERROTAS ---" << endl;
    for(int i = 0; i < 8; i++) {
        if(j[i].ganadas > j[i].perdidas) {
            cout << j[i].nombre << " - Ganadas: " << j[i].ganadas 
                 << " / Perdidas: " << j[i].perdidas << endl;
        }
    }

    // Resultados finales
    cout << "\n--- RESULTADOS ---" << endl;

    cout << "Jugador con mas puntos: " << j[masPuntos].nombre 
         << " (" << j[masPuntos].puntos << " pts)" << endl;

    // 6. Promedio de puntos
    cout << "Promedio de puntos: " << promedio << " pts" << endl;

    // 7. Quienes superan el promedio
    cout << "Jugadores que superan el promedio: " << arribaPromedio << endl;

    // 8. Jugador con mas partidas ganadas
    cout << "Jugador con mas victorias: " << j[masGanadas].nombre 
         << " (" << j[masGanadas].ganadas << " victorias)" << endl;

    // 9. Equipo del jugador con mayor puntuacion
    cout << "Equipo del jugador con mas puntos: " << j[masPuntos].eq.nombre 
         << " de " << j[masPuntos].eq.ciudad << endl;

    return 0;
}