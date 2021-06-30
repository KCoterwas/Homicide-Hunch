#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class SecondLevel
{
private:

	// Of course we will need a sprite
	Sprite SLBackground;

	// And a texture
	// !!Watch this space!!
	Texture SL_Texture;

	Vector2f m_Position;

public:

	SecondLevel();

	void setPosition(int x, int y);

	// Where is the player
	FloatRect getPosition();

	// Send a copy of the sprite to main
	Sprite getSprite();

};
