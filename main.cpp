#include <iostream>
#include <SFML/Graphics.hpp>

#define kVel 5
/*
void procesarColisones(sf::Sprite sprite, sf::RectangleShape rectnagulo){
    // Colision del personaje con el powerUp

    if(sprite.getGlobalBounds().intersects(rectnagulo.getGlobalBounds())) {
        std::cout<<"Prueba para las colisiones"<<std::endl;
        // Pillo el powerUp

    }

}

int main()
{
    // Creo las posiciones de los powerUps
    sf::Vector2f powerUps[] = {sf::Vector2f(250,250), sf::Vector2f(500,500)};
    int numPoweUp = 0;
    //powerUps = {sf::Vector2f(250,250), sf::Vector2f(500,500)};
    std::cout<<powerUps[numPoweUp].x<<std::endl;

    // Creo un rectangulo que va a simular los powerUps
    sf::RectangleShape rectangulo(sf::Vector2f(15.f, 15.f));
    rectangulo.setPosition(powerUps[numPoweUp].x, powerUps[numPoweUp].y);
    rectangulo.setFillColor(sf::Color::Yellow);

    //Creamos una ventana
    sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex;
    sf::Texture fondo;

    if (!tex.loadFromFile("resources/sprites.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!fondo.loadFromFile("resources/city.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }

    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite sprite(tex);
    sf::Sprite backgroundSprite(fondo);

    //Le pongo el centroide donde corresponde
    sprite.setOrigin(75/2,75/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));


    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(320, 240);






    //Bucle del juego
    while (window.isOpen()) {
        procesarColisones(sprite, rectangulo);
        //Bucle de obtención de eventos
        sf::Event event;
        while (window.pollEvent(event))
        {

            switch(event.type){

                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window.close();
                    break;

                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:

                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(event.key.code) {

                        //Mapeo del cursor
                        case sf::Keyboard::Right:
                            sprite.setTextureRect(sf::IntRect(0*75, 2*75, 75, 75));
                            //Escala por defecto
                            sprite.setScale(1,1);
                            sprite.move(kVel,0);
                        break;

                        case sf::Keyboard::Left:
                            sprite.setTextureRect(sf::IntRect(0*75, 2*75, 75, 75));
                            //Reflejo vertical
                            sprite.setScale(-1,1);
                            sprite.move(-kVel,0);
                        break;

                        case sf::Keyboard::Up:
                            sprite.setTextureRect(sf::IntRect(0*75, 3*75, 75, 75));
                            sprite.move(0,-kVel);
                        break;

                        case sf::Keyboard::Down:
                            sprite.setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));
                            sprite.move(0,kVel);
                        break;


                        //Tecla ESC para salir
                        case sf::Keyboard::Escape:
                            window.close();
                        break;

                        //Cualquier tecla desconocida se imprime por pantalla su código
                        default:
                            std::cout << event.key.code << std::endl;
                        break;

                    }

            }

        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(rectangulo);
        window.draw(sprite);

        window.display();
    }

    return 0;
}

*/

