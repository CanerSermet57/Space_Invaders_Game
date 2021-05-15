#include <SFML/Graphics.hpp>
#include <string> 
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "bullet.h"

using namespace sf;
using namespace std;

float x = 0;
float y = 0;
float radius = 60;
bool control = false;
CircleShape *active = nullptr;
vector<CircleShape*> sekiller;

void keyboardControl(Event& e)
{
	if (e.type == Event::KeyPressed)
	{
		if (e.key.code == Keyboard::Left)
		{
			x-=10;
		}
		if (e.key.code == Keyboard::Right)
		{
			x+=10;
		}
	}
	
}
void mouseControl(Event& e)
{
	if (e.type == Event::MouseButtonPressed)
	{
		if (e.mouseButton.button == Mouse::Left)
		{
			active = new CircleShape(0, 32);
			radius = 0;
			x = e.mouseButton.x;
			y = e.mouseButton.y;
			control = true;
		}
		if (e.mouseButton.button == Mouse::Right)
		{
			
		}		
	}
	if (e.type == Event::MouseButtonReleased)
	{
		if (e.mouseButton.button == Mouse::Left)
		{
			sekiller.push_back(active);
			control = false;
		}
		if (e.mouseButton.button == Mouse::Right)
		{
		}
	}
	if (e.type == Event::MouseMoved)
	{
		if (control)
		{
			radius = (e.mouseMove.x - x) / 2;
		}
	}
}



int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 16;
	RenderWindow window(VideoMode(1400, 900), "Railgun", Style::Close, settings);
	window.setFramerateLimit(60);

	Texture playertexture,bullettexture,enemytexture;
	playertexture.loadFromFile("ship.png");
	player user1(&playertexture);
	bullettexture.loadFromFile("bullet.png");
	bullet bullets(&bullettexture);
	enemytexture.loadFromFile("enemy.png");
	enemy enemys(&enemytexture);
	Clock clock;
	float deltaTime = 0.0f;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			keyboardControl(event);
			mouseControl(event);	
		}
		deltaTime = clock.restart().asSeconds();
		user1.Update(deltaTime * 10);
		//enemys.Update(deltaTime * 10);
		bullets.Update(deltaTime * 10, user1.playerbody.getPosition());
		window.clear();
		user1.Draw(window);
		enemys.Draw(window);
		bullets.Draw(window);
		window.display();






		/*
		for (CircleShape *x : sekiller)
		{
			window.draw(*x);
		}
		if (active)
		{
			active->setRadius(radius);
			active->setPosition(Vector2f(x, y));
			active->setFillColor(Color::Blue);
			active->setOutlineColor(Color::Red);
			active->setOutlineThickness(5);
			window.draw(*active);
		}
		*/
	}
	return 0;
}