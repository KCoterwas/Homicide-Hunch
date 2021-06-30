#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:

	// Of course we will need a sprite
	Sprite m_Sprite;

	// And a texture
	// !!Watch this space!!
	Texture m_Texture;

	Vector2f m_Position;

	// Which direction is the player currently moving in
	bool m_UpPressed;
	bool m_DownPressed;	
	bool m_LeftPressed;
	bool m_RightPressed;

	enum PlayerDir{Left, Right, Down, Up};
	sf::Vector2i select;

	const static int HenryWidth = 245;
	const static int HenryHeight = 326;

public:

	Player();

	void setPosition(int x, int y);

	// Where is the player
	FloatRect getPosition();

	// Send a copy of the sprite to main
	Sprite getSprite();

	// The next four functions move the player
	void moveLeft();

	void moveRight();

	void moveUp();

	void moveDown();

	// Stop the player moving in a specific direction
	void stopRight();

	void stopLeft();

	void stopUp();

	void stopDown();

	void update();



};

