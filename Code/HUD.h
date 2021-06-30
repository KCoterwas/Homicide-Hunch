#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class HUD
{
private:

	// Of course we will need a sprite
	Sprite HUDimage;

	// And a texture
	// !!Watch this space!!
	Texture HUD_Texture;

	Sprite clueBookHUD;

	Texture bookHUD_Texture;

	Sprite suspectButcherHUD;

	Texture butcherHUD_Texture;

	Sprite suspectFriendHUD;

	Texture friendHUD_Texture;

	Vector2f m_Position;

public:

	HUD();

	void setPosition(int x, int y);

	// Where is the player
	FloatRect getPosition();

	// Send a copy of the sprite to main
	Sprite getHUDSprite();
	
	Sprite addBook();
	
	Sprite addButcher();

	Sprite addFriend();

};
