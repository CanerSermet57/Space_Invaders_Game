#include "player.h"

player::player(Texture* texture)
{
	Texture t = *texture;
	playerbody.setSize(Vector2f((t.getSize().x / 2), (t.getSize().y / 2)));
	playerbody.setTexture(texture);
	playerbody.setOrigin(t.getSize().x / 4, t.getSize().y / 4);
	playerbody.setPosition(700, 800);
	speed = 40.0f;
}




void player::Update(float deltaTime)
{	
	Vector2f movement(0.0f, 0.0f);
	if (Keyboard::isKeyPressed(Keyboard::D))
	{		
		movement.x += speed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		movement.x -= speed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		movement.y -= speed * deltaTime;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		movement.y += speed * deltaTime;
	}
	playerbody.move(movement);
}

void player::Draw(RenderWindow& window)
{
	window.draw(playerbody);
}
