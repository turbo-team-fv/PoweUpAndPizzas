#include <iostream>
#include <SFML/Graphics.hpp>"
#include "juego.h"7
#include "PowerUp.h"
#include <vector>

using namespace sf;

int main(){
    juego * partida1;
    std::vector<PowerUp> objetos;
    // objetos.push_back( PowerUp(1, Vector2f(100,100),Color(250,250,250), 50) );

    partida1 = new juego(800, 600, "Hola");
    // partida1->setPowerUps(objetos);

    return 0;
    }

