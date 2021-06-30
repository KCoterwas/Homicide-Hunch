#include "HighSchool.h"

HighSchool::HighSchool()
{
	
	// Associate a texture with the sprite
	// !!Watch this space!!
	HS_Texture.loadFromFile("Graphics/brick-wall.png");
	HSBackground.setTexture(HS_Texture);

	// Set the position
	HSBackground.setPosition(0, 0);
}


FloatRect HighSchool::getPosition()
{
	return HSBackground.getGlobalBounds();
}

Sprite HighSchool::getSprite()
{
	return HSBackground;
}
