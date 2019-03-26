#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>"
#include <vector>
#include <PowerUp.h>

using namespace sf;

class juego {
    public:
        juego(int ancho, int alto, std::string titulo);
        virtual ~juego();
        void dibujar();
        void gameLoop();
        void procesarEventos();
        void procesarMosue();
        void procesarColisiones();
        void setPowerUps(std::vector<PowerUp> objetos);

    protected:

    private:

        RenderWindow * ventana;
        int fps;
        Texture * textura1;
        Texture * textura2;
        Sprite * jugador;
        RectangleShape cuadrado;
        Event * evento1;
        Vector2i posMouse;
        int posPizza;
        std::vector < sf::Vector2f > pizzas;
        int numPizzas;
        std::vector<PowerUp> powerUps;
        sf::Clock colckPowerUps;

    };

#endif // JUEGO_H
