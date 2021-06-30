#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Clue
{
private:

	// Of course we will need a sprite
	Sprite clueBook;

	// And a texture
	// !!Watch this space!!
	Texture book_Texture;

	Text bookContents;

	Vector2f m_Position;

public:

	Clue();

	void setPosition(int x, int y);

	// Where is the player
	FloatRect getPosition();

	// Send a copy of the sprite to main
	Sprite getSprite();

};
