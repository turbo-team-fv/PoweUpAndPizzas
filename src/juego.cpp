#include <iostream>
#include <SFML/Graphics.hpp>
#include "juego.h"
#define kVel 5

using namespace sf;


juego::juego(int ancho, int alto, std::string titulo){
    //ctor

    // Declaro el array de poweUps
    PowerUp *prueba = new PowerUp(1, sf::Vector2f(100,100),sf::Color::Blue, 4, 10);
    powerUps.push_back(*prueba);
    PowerUp *prueba2 = new PowerUp(0, sf::Vector2f(600,100),sf::Color::Red, 6, 5);
    powerUps.push_back(*prueba2);

    std::cout<< "probando el array de powerUPs"<<std::endl;
    std::cout<< powerUps[1].getTipo() <<std::endl;
    std::cout<< powerUps[0].getPosicion().x <<std::endl;
    std::cout<< powerUps[0].getPosicion().y <<std::endl;
    std::cout<< powerUps.size() <<std::endl;

     sf::Clock colckPowerUps;

     // std::cout<< powerUps[0].getClock().getElapsedTime().asSeconds() <<std::endl;

    //Numero de pizzas para la puntuacion
    numPizzas = 0;
    // Posicion en el vector de pizzas => muestra la pizza que se muestra
    posPizza = 0;

    //Declaro las pizzas
    pizzas.push_back(sf::Vector2f(250,250));
    pizzas.push_back(sf::Vector2f(500,500));

    fps = 60;

    ventana = new RenderWindow(VideoMode(ancho, alto), titulo);

    ventana->setFramerateLimit(fps);

    textura1 = new Texture;

    // Cargamos la textura
    textura1->loadFromFile("resources/sprites.png");
    // Asigamos el sprite a partir de una textura

    jugador = new Sprite(*textura1);
    jugador->setOrigin(75/2,75/2);
    jugador->setTextureRect(IntRect(0*75, 0*75, 75, 75));

    // Pongo la pizza inicial en el mapa
    cuadrado = sf::RectangleShape(sf::Vector2f(15.f, 15.f));
    cuadrado.setPosition(pizzas[posPizza].x, pizzas[posPizza].y);
    cuadrado.setFillColor(sf::Color::Yellow);

    // Posicion del jugador
    jugador->setPosition(400,300);

    evento1 = new Event;

    dibujar();

    gameLoop();

}

void juego::dibujar() {
    // float duracion = colckPowerUps.getElapsedTime().asSeconds();
    ventana->clear();
    ventana->draw(cuadrado);
    // std::cout<< "probando el array de powerUPs"<<std::endl;
    // std::cout<< powerUps[0].getTipo() <<std::endl;

    for( int i = 0; i < powerUps.size(); i++) {
        float duracion = powerUps[i].getClock().getElapsedTime().asSeconds();
        // Al tiempo de vida se le suma el de generacion para que tenga una duracion real y no la que falta para llegar a esos segundos
        if(duracion > powerUps[i].getTiempoGeneracion() && duracion < powerUps[i].getTiempoVida() + powerUps[i].getTiempoGeneracion()){
            ventana->draw(powerUps[i].getForma());
        }
        if(duracion > powerUps[i].getTiempoVida() + powerUps[i].getTiempoGeneracion() ) {
            std::cout<< powerUps[i].getClock().getElapsedTime().asSeconds() <<std::endl;
            powerUps[i].restart();
        }

    }
    ventana->draw(*jugador);

    ventana->display();
}

void juego::gameLoop() {

    while(ventana->isOpen()){
        procesarEventos();
        procesarColisiones();
        dibujar();
    }
}

void juego::procesarEventos() {

    while(ventana->pollEvent(*evento1)) {
        switch(evento1->type){
            case Event::Closed:
                ventana->close();
                exit(1);
            break;

            case Event::KeyPressed:

                if(Keyboard::isKeyPressed(Keyboard::Up)){
                    //jugador->setPosition(jugador->getPosition().x, jugador->getPosition().y - 2);
                    jugador->setTextureRect(sf::IntRect(0*75, 3*75, 75, 75));
                    jugador->move(0,-kVel);
                }else if(Keyboard::isKeyPressed(Keyboard::Down)){
                        //jugador->setPosition(jugador->getPosition().x, jugador->getPosition().y + 2);
                        jugador->setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));
                        jugador->move(0,kVel);
                    }else if(Keyboard::isKeyPressed(Keyboard::Left)){
                            //jugador->setPosition(jugador->getPosition().x - 2, jugador->getPosition().y);
                            jugador->setTextureRect(sf::IntRect(3.5*75, 2*75, 75, 75));
                            jugador->move(-kVel,0);
                        }else if(Keyboard::isKeyPressed(Keyboard::Right)){
                            //jugador->setPosition(jugador->getPosition().x + 2, jugador->getPosition().y);
                            jugador->setTextureRect(sf::IntRect(0*75, 2*75, 75, 75));
                            jugador->move(kVel,0);
                            }else if(Keyboard::isKeyPressed(Keyboard::A)) {
                                ventana->close();
                                exit(1);
                            }
            break;

            case Event::MouseButtonPressed:
                if(Mouse::isButtonPressed(Mouse::Left)) {
                    jugador->setPosition((Vector2f)posMouse);
                }
            break;
        }
    }
}

void juego::procesarMosue() {
    // lo hacemos relativo a la pantalla de juego sino pilla la pantalla del PC
    posMouse = Mouse::getPosition(*ventana);
    posMouse = (Vector2i)ventana->mapPixelToCoords(posMouse);

}

void juego::procesarColisiones() {
    //Colision para recoger una pizza
    if(jugador->getGlobalBounds().intersects(cuadrado.getGlobalBounds())){
        numPizzas++;
        std::cout<<"Puntuacion pizzas = "<< numPizzas <<std::endl;
        if(posPizza == pizzas.size()-1){
            posPizza = 0;
        }else{
            posPizza++;
        }
        cuadrado.setPosition(pizzas[posPizza].x, pizzas[posPizza].y);
    }
    // colisiones con los powerUps
    for(int i = 0; i < powerUps.size(); i++){
        if(jugador->getGlobalBounds().intersects(powerUps[i].getForma().getGlobalBounds())){
            powerUps[i].restart();
            std::cout<<"HEmos cogido un poweUp de tipo " <<powerUps[i].getTipo() <<std::endl;
            // Como hago para que no se borre al pasar por encima?
        }
    }
    // Colision con los bordes de la pantalla ???


}

void juego::setPowerUps(std::vector<PowerUp> objetos){
    powerUps = objetos;
}
juego::~juego()
{
    //dtor
}
