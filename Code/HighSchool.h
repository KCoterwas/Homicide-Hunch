#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class HighSchool
{
private:

	// Of course we will need a sprite
	Sprite HSBackground;

	// And a texture
	// !!Watch this space!!
	Texture HS_Texture;

	Vector2f m_Position;

public:

	HighSchool();

	void setPosition(int x, int y);

	// Where is the player
	FloatRect getPosition();

	// Send a copy of the sprite to main
	Sprite getSprite();

};
