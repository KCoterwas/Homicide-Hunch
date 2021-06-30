//#include "stdafx.h"
#include "Clue.h"

Clue::Clue()
{
	
	// Associate a texture with the sprite
	// !!Watch this space!!
	book_Texture.loadFromFile("Graphics/Book.png");
	clueBook.setTexture(book_Texture);

	// Set the position
	clueBook.setPosition(900, 300);
}


FloatRect Clue::getPosition()
{
	return clueBook.getGlobalBounds();
}

Sprite Clue::getSprite()
{
	return clueBook;
}

