#include "HUD.h"


HUD::HUD()
{
	
	// Associate a texture with the sprite
	// !!Watch this space!!
	HUD_Texture.loadFromFile("Graphics/HUD.png");
	HUDimage.setTexture(HUD_Texture);

	// Set the position
	HUDimage.setPosition(1100, 800);

	// Make Book for HUD
	bookHUD_Texture.loadFromFile("Graphics/Book.png");
	clueBookHUD.setTexture(bookHUD_Texture);
	clueBookHUD.setPosition(1350, 875);

	// Make Butcher for HUD
	butcherHUD_Texture.loadFromFile("Graphics/Butcher.png");
	suspectButcherHUD.setTexture(butcherHUD_Texture);
	suspectButcherHUD.setPosition(1550, 830);
	suspectButcherHUD.scale(0.4,0.4);

	// Make Friend for HUD
	friendHUD_Texture.loadFromFile("Graphics/Friend.png");
	suspectFriendHUD.setTexture(friendHUD_Texture);
	suspectFriendHUD.setPosition(1750, 830);
	suspectFriendHUD.scale(0.4,0.4);
}


FloatRect HUD::getPosition()
{
	return HUDimage.getGlobalBounds();
}

Sprite HUD::getHUDSprite()
{
	return HUDimage;
}

Sprite HUD::addBook()
{
	return clueBookHUD;
}

Sprite HUD::addButcher()
{
	return suspectButcherHUD;
}

Sprite HUD::addFriend()
{
	return suspectFriendHUD;
}
