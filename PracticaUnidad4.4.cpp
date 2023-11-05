//MAVI - Unidad 4 - Ejercicio 4
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Texture cuad_yellow_tex;
Sprite cuad_yellow_sprite;

int main() {
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Atrapado");

	cuad_yellow_tex.loadFromFile("Unidad4_Assets/cuad_yellow.png");
	cuad_yellow_sprite.setTexture(cuad_yellow_tex);
	cuad_yellow_sprite.setScale(0.2f, 0.2f);
	cuad_yellow_sprite.setPosition(0, (600-cuad_yellow_sprite.getGlobalBounds().height)/2.0f);

	sf::Vector2f position = cuad_yellow_sprite.getPosition(); //Posiciones x,y del sprite
	sf::FloatRect size = cuad_yellow_sprite.getGlobalBounds(); //Tamaño del sprite respecto a sus límites 
	float limiteIzquierdo = 0;  //Limites de pantalla
	float limiteDerecho = 800 - size.width;
	float limiteSuperior = 0;
	float limiteInferior = 600 - size.height;
	float speedMove = 8.0f; //Velocidad de movimiento
	
	while (App.isOpen())
	{
		sf::Event event;
		while (App.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				App.close();
				break;
			}
			
			//Movimiento de los sprites si están dentro de los límites
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				position = cuad_yellow_sprite.getPosition();
				if (position.x > limiteDerecho) {   
					cuad_yellow_sprite.move(0, 0); 
				}
				else {
					cuad_yellow_sprite.move(speedMove, 0);
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				position = cuad_yellow_sprite.getPosition();
				if (position.x < limiteIzquierdo) {
					cuad_yellow_sprite.move(0, 0);
				}
				else {
					cuad_yellow_sprite.move(-speedMove, 0);
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				position = cuad_yellow_sprite.getPosition();
				if (position.y < limiteSuperior) {
					cuad_yellow_sprite.move(0, 0);
				}
				else {
					cuad_yellow_sprite.move(0, -speedMove);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				position = cuad_yellow_sprite.getPosition();
				if (position.y > limiteInferior) {
					cuad_yellow_sprite.move(0, 0);
				}
				else {
					cuad_yellow_sprite.move(0, speedMove);
				}
			}
		}
	
		App.clear();

		App.draw(cuad_yellow_sprite);

		App.display();
	}

	return 0;
}
