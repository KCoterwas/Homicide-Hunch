#include "SecondLevel.h"

SecondLevel::SecondLevel()
{
	
	// Associate a texture with the sprite
	// !!Watch this space!!
	SL_Texture.loadFromFile("Graphics/Landscape.png");
	SLBackground.setTexture(SL_Texture);

	// Set the position
	SLBackground.setPosition(0, 0);
}


FloatRect SecondLevel::getPosition()
{
	return SLBackground.getGlobalBounds();
}

Sprite SecondLevel::getSprite()
{
	return SLBackground;
}
