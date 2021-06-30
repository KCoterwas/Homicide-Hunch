#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Suspect
{
private:

	// Of course we will need a sprite
	Sprite suspectButcher;
	Sprite suspectFriend;

	// And a texture
	// !!Watch this space!!
	Texture butcher_Texture;
	Texture friend_Texture;

	Vector2f m_Position;

	Text butcherSpeech;

	enum butcherTalk{Closed, Open};
	
	sf::Vector2i select;

	const static int butcherWidth = 169;
	const static int butcherHeight = 387;

public:

	Suspect();

	void setPosition(int x, int y);

	// Where is the butcher
	FloatRect getPositionB();

	// Send a copy of the butcher to main
	Sprite getSpriteB();

	// Where is the friend
	FloatRect getPositionF();

	// Send a copy of the friend to main
	Sprite getSpriteF();

	void update();

};

