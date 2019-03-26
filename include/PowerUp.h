#ifndef POWERUP_H
#define POWERUP_H
#include <SFML/Graphics.hpp>"

class PowerUp
{
    public:
        PowerUp(int tipo, sf::Vector2f posicion, sf::Color color, int tiempoG, int tiempoV);
        virtual ~PowerUp();
        int getTipo();
        sf::Vector2f getPosicion();
        sf::Color getColor();
        sf::RectangleShape getForma();
        int getTiempoGeneracion();
        int getTiempoVida();
        sf::Clock getClock();
        void restart();

    protected:

    private:
        int tipo;
        sf::Vector2f posicion;
        sf::Color color;
        int tiempoGeneracion;
        int tiempoVida;
        sf::RectangleShape forma;
        sf::Clock clock;
};

#endif // POWERUP_H
