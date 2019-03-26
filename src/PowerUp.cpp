#include "PowerUp.h"


PowerUp::PowerUp(int tipo, sf::Vector2f posicion, sf::Color color, int tiempo, int tiempoV){
    //ctor
    // inicializo los atributos del powerUp
    /**
    *   1 => Vida
    *   2 => Turbo
    *   3 => Invisivilidad
    *   4 => Tiempo
    **/
    this->tipo = tipo;
    this->posicion = posicion;
    this->color = color;
    this->tiempoGeneracion = tiempo;
    this->tiempoVida = tiempoV;
    // Creo el cuadrado por defecto en el constructor
    this->forma = sf::RectangleShape(sf::Vector2f(15.f, 15.f));
    this->forma.setPosition(posicion.x, posicion.y);
    this->forma.setFillColor(color);
//    this->clock = sf::Clock;
    sf::Clock clock;
}

int PowerUp::getTipo(){
    return tipo;
}

sf::Vector2f PowerUp::getPosicion() {
    return posicion;
}

sf::RectangleShape PowerUp::getForma() {
    return forma;
}

int PowerUp::getTiempoGeneracion() {
    return tiempoGeneracion;
}

int PowerUp::getTiempoVida() {
    return tiempoVida;
}

sf::Clock PowerUp::getClock() {
    return clock;
}
void PowerUp::restart() {
    clock.restart();
}

PowerUp::~PowerUp()
{
    //dtor
}
