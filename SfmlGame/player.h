#pragma once
#include <SFML/Graphics.hpp>
#include <string> 
#include <iostream> 
using namespace sf;
using namespace std;
class player
{
public:
	player(Texture* texture);
	void Draw(RenderWindow& window);
	void Update(float deltaTime);

	RectangleShape playerbody;

	
private:
	float speed;
	bool control;

};

