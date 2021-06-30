// Include important C++ libraries here
#ifdef _MSC_VER
#include "stdafx.h"
#endif
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Player.cpp"
#include "Clue.h"
#include "Clue.cpp"
#include "Suspect.h"
#include "Suspect.cpp"
#include "HighSchool.h"
#include "HighSchool.cpp"
#include "SecondLevel.h"
#include "SecondLevel.cpp"
#include "HUD.h"
#include "HUD.cpp"
#include <iostream>

// Make code easier to type with "using namespace"
using namespace sf;


int main()
	{
	// Creating a video mode object
	VideoMode vm(1920, 1080);

	// Creating and opening a window for the game
	RenderWindow window(vm, "Homicide Hunch", Style::Default);
	//window.setFramerateLimit(60);

	// Create booleans for different screens
	bool titleScreen = true;	
	bool Credits = false;
	bool Options = false;
	bool firstLevel = false;
	bool levelTwo = false;
	bool defeatScreen = false;
	bool winScreen = false;

	// Create an instance of the Player class
	Player player;

	// Create an instance of the Clue class
	Clue clue;

	// Create an instance of the Suspect class
	Suspect suspect;

	//Create an instance of the HighSchool class
	HighSchool highSchool;

	//Create an instance of the SecondLevel class
	SecondLevel secondLevel;

	//Create an instance of the HUD class
	HUD HUDdisplay;

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("Graphics/Title.png");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);
	
	// Prepare Title music
	sf::Music titleM;
	// Open it from an audio file
	if (!titleM.openFromFile("Music/tomorrow.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}

	// Prepare Credits music
	sf::Music creditsM;
	// Open it from an audio file
	if (!creditsM.openFromFile("Music/funnysong.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}

	// Prepare High School music
	sf::Music highSchoolM;
	// Open it from an audio file
	if (!highSchoolM.openFromFile("Music/betterdays.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}

	// Prepare Second Level music
	sf::Music locationM;
	// Open it from an audio file
	if (!locationM.openFromFile("Music/ofeliasdream.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}


	// Prepare Mumbling Sound
	sf::Sound mumbleMale;
	sf::SoundBuffer mumbleM;

	if(!mumbleM.loadFromFile("Sound/mumblingMale.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}
	mumbleMale.setBuffer(mumbleM);


	// Prepare Crying Sound
	sf::Sound cryFemale;
	sf::SoundBuffer cryF;

	if(!cryF.loadFromFile("Sound/WomanCrying.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}
	cryFemale.setBuffer(cryF);

	
	// Prepare Tick Sound
	sf::Sound tickInteraction;
	sf::SoundBuffer tInteraction;

	if(!tInteraction.loadFromFile("Sound/Tick.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}
	tickInteraction.setBuffer(tInteraction);

	
	// Prepare Defeat Sound
	sf::Sound lose;
	sf::SoundBuffer loseBuff;

	if(!loseBuff.loadFromFile("Sound/Defeat.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}
	lose.setBuffer(loseBuff);

	// Prepare Walking on Gravel Sound
	sf::Sound walkingGravel;
	sf::SoundBuffer walkingG;

	if(!walkingG.loadFromFile("Sound/WalkingGravel.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}
	walkingGravel.setBuffer(walkingG);

	// Prepare Walking on Grass Sound
	sf::Sound walkingGrass;
	sf::SoundBuffer walkingGrs;

	if(!walkingGrs.loadFromFile("Sound/WalkingGrass.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}
	walkingGrass.setBuffer(walkingGrs);

		
	// Make the Henry Sprite
	Texture textureHenry;
	textureHenry.loadFromFile("Graphics/Henry.png");
	Sprite spriteHenry;
	spriteHenry.setTexture(textureHenry);
	spriteHenry.setPosition(810,650);

	// Make the Body Sprite
	Texture textureBody;
	textureBody.loadFromFile("Graphics/DeadBody.png");
	Sprite spriteBody;
	spriteBody.setTexture(textureBody);
	spriteBody.setPosition(200,850);

	// Creating Text
	sf::Font font;
	if (!font.loadFromFile("Font/TypistBold.ttf"))
	{
	    // error...
	}

	// Make the Play Button
	Texture texturePlay;
	texturePlay.loadFromFile("Graphics/Button.png");
	Sprite spritePlay;
	spritePlay.setTexture(texturePlay);
	spritePlay.setPosition(1350,400);

	sf::Text play;

		// select the font
		play.setFont(font); // font is a sf::Font

		// set the string to display
		play.setString("Play");

		// set the character size
		play.setCharacterSize(48); // in pixels, not points!

		// set the color
		play.setColor(sf::Color::Black);

		// set the position
		play.setPosition(1390,420);

	// Make the Options Button
	Texture textureOptions;
	textureOptions.loadFromFile("Graphics/Button.png");
	Sprite spriteOptions;
	spriteOptions.setTexture(textureOptions);
	spriteOptions.setPosition(1350,500);

	sf::Text options;

		// select the font
		options.setFont(font); // font is a sf::Font

		// set the string to display
		options.setString("Options");

		// set the character size
		options.setCharacterSize(40); // in pixels, not points!

		// set the color
		options.setColor(sf::Color::Black);

		// set the position
		options.setPosition(1370,520);

	// Make the Credits Button
	Texture textureCredits;
	textureCredits.loadFromFile("Graphics/Button.png");
	Sprite spriteCredits;
	spriteCredits.setTexture(textureCredits);
	spriteCredits.setPosition(1350,600);

	sf::Text credits;

	// select the font
	credits.setFont(font); // font is a sf::Font

		// set the string to display
		credits.setString("Credits");

		// set the character size
		credits.setCharacterSize(40); // in pixels, not points!

		// set the color
		credits.setColor(sf::Color::Black);

		// set the position
		credits.setPosition(1370,620);

	// Make the Exit Button
	Texture textureExit;
	textureExit.loadFromFile("Graphics/Button.png");
	Sprite spriteExit;
	spriteExit.setTexture(textureExit);
	spriteExit.setPosition(1350,700);

	sf::Text exit;

	// select the font
	exit.setFont(font); // font is a sf::Font

		// set the string to display
		exit.setString("Exit");

		// set the character size
		exit.setCharacterSize(48); // in pixels, not points!

		// set the color
		exit.setColor(sf::Color::Black);

		// set the position
		exit.setPosition(1390,720);

	// Creating the Options Screen
		// Make the Fullscreen Button
		Texture texturefullScreen;
		texturefullScreen.loadFromFile("Graphics/Button.png");
		Sprite spritefullScreen;
		spritefullScreen.setTexture(texturefullScreen);
		spritefullScreen.setPosition(500,200);

		
		// Making Fullscreen option
		sf::Text fullScreen;

		// select the font
		fullScreen.setFont(font); // font is a sf::Font

			// set the string to display
			fullScreen.setString("Fullscreen");

			// set the character size
			fullScreen.setCharacterSize(48); // in pixels, not points!

			// set the color
			fullScreen.setColor(sf::Color::Black);

			// set the position
			fullScreen.setPosition(200,220);

		/// Making "off" text on button
		sf::Text off;

		// select the font
		off.setFont(font); // font is a sf::Font

			// set the string to display
			off.setString("Off");

			// set the character size
			off.setCharacterSize(48); // in pixels, not points!

			// set the color
			off.setColor(sf::Color::Black);

			// set the position
			off.setPosition(550,220);


		// Making "on" text on button
		sf::Text on;

		// select the font
		on.setFont(font); // font is a sf::Font

			// set the string to display
			on.setString("On");

			// set the character size
			on.setCharacterSize(48); // in pixels, not points!

			// set the color
			on.setColor(sf::Color::Black);

			// set the position
			on.setPosition(850,220);


	// Creating the Credits Screen
		// Create a texture to hold a graphic on the GPU
		Texture textureBackgroundC;

		// Load a graphic into the texture
		textureBackgroundC.loadFromFile("Graphics/Landscape.png");


		// Create a sprite
		Sprite spriteBackgroundC;

		// Attach the texture to the sprite
		spriteBackgroundC.setTexture(textureBackgroundC);

		// Set the spriteBackground to cover the screen
		spriteBackgroundC.setPosition(0, 0);

		// Make the Back Button
		Texture textureBack;
		textureBack.loadFromFile("Graphics/Button.png");
		Sprite spriteBack;
		spriteBack.setTexture(textureBack);
		spriteBack.setPosition(1350,900);

		// Make my face
		Texture textureFace;
		textureFace.loadFromFile("Graphics/Kim.png");
		Sprite spriteFace;
		spriteFace.setTexture(textureFace);
		spriteFace.setPosition(1350,300);


		// Make Credits Title
		sf::Text creditsTitle;
		
			// select the font
			creditsTitle.setFont(font); // font is a sf::Font

			// set the string to display
			creditsTitle.setString("Credits");

			// set the character size
			creditsTitle.setCharacterSize(56); // in pixels, not points!

			// set the color
			creditsTitle.setColor(sf::Color::Black);

			// set the position
			creditsTitle.setPosition(810,140);

		// Make Name
		sf::Text name;

			// select the font
			name.setFont(font); // font is a sf::Font

			// set the string to display
			name.setString("Designed and Programmed by \nKim Coterwas");

			// set the character size
			name.setCharacterSize(40); // in pixels, not points!

			// set the color
			name.setColor(sf::Color::Black);

			// set the position
			name.setPosition(650,340);

		// Make Class Credit
		sf::Text classCredit;

			// select the font
			classCredit.setFont(font); // font is a sf::Font

			// set the string to display
			classCredit.setString("Made for Marist College's \nCMPT 414_111 Game Design and Programming I");

			// set the character size
			classCredit.setCharacterSize(40); // in pixels, not points!

			// set the color
			classCredit.setColor(sf::Color::Black);

			// set the position
			classCredit.setPosition(650,440);

		// Make Resources Credit
		sf::Text resources;

			// select the font
			resources.setFont(font); // font is a sf::Font

			// set the string to display
			resources.setString("Resources Used:");

			// set the character size
			resources.setCharacterSize(40); // in pixels, not points!

			// set the color
			resources.setColor(sf::Color::Black);

			// set the position
			resources.setPosition(650,540);	

		// Make Resources Credit
		sf::Text resourcesUsed;

			// select the font
			resourcesUsed.setFont(font); // font is a sf::Font

			// set the string to display
			resourcesUsed.setString("Brick wall image from http://www.publicdomainpictures.net/hledej.php?hleda=brick+wall\nCredits Screen image from https://commons.wikimedia.org/wiki/File:Hobart_Bluff_(15835732535).jpg \nSprite Creation with piskelapp.com \nMusic from bensound.com \nGravel, Tick, Trombone, and Crying Sound from SoundBible.com \nMumbling and Grass Sound from https://www.freesound.org/people/pfranzen/sounds/264770/");

			// set the character size
			resourcesUsed.setCharacterSize(20); // in pixels, not points!

			// set the color
			resourcesUsed.setColor(sf::Color::Black);

			// set the position
			resourcesUsed.setPosition(650,580);	

		// Make Back Text
		sf::Text back;

			// select the font
			back.setFont(font); // font is a sf::Font

			// set the string to display
			back.setString("Back");

			// set the character size
			back.setCharacterSize(48); // in pixels, not points!

			// set the color
			back.setColor(sf::Color::Black);

			// set the position
			back.setPosition(1390,920);

		// Make Date Text
		sf::Text dateUpdate;

			// select the font
			dateUpdate.setFont(font); // font is a sf::Font

			// set the string to display
			dateUpdate.setString("Last Updated: 12/6/2016");

			// set the character size
			dateUpdate.setCharacterSize(30); // in pixels, not points!

			// set the color
			dateUpdate.setColor(sf::Color::Black);

			// set the position
			dateUpdate.setPosition(650,740);


	// Making Clues Collected Text
		sf::Text collectedClues;

		// select the font
		collectedClues.setFont(font); // font is a sf::Font

		// set the string to display
		collectedClues.setString("Clues\nCollected:");

		// set the character size
		collectedClues.setCharacterSize(30); // in pixels, not points!

		// set the color
		collectedClues.setColor(sf::Color::Black);

		// set the position
		collectedClues.setPosition(1125,850);

	// Making Next Area Text
		sf::Text toNextLvl;

		// select the font
		toNextLvl.setFont(font); // font is a sf::Font

		// set the string to display
		toNextLvl.setString("To the next area -->");

		// set the character size
		toNextLvl.setCharacterSize(30); // in pixels, not points!

		// set the color
		toNextLvl.setColor(sf::Color::Black);

		// set the position
		toNextLvl.setPosition(1500,500);


	// Making Back to School Text
		sf::Text toHighSchool;

		// select the font
		toHighSchool.setFont(font); // font is a sf::Font

		// set the string to display
		toHighSchool.setString("<-- Back to the School");

		// set the character size
		toHighSchool.setCharacterSize(30); // in pixels, not points!

		// set the color
		toHighSchool.setColor(sf::Color::Black);

		// set the position
		toHighSchool.setPosition(200,500);

	// Making End Game Text
		sf::Text toOffice;

		// select the font
		toOffice.setFont(font); // font is a sf::Font

		// set the string to display
		toOffice.setString("vv Arrest the Murderer vv \nvv    at the Office     vv");

		// set the character size
		toOffice.setCharacterSize(30); // in pixels, not points!

		// set the color
		toOffice.setColor(sf::Color::White);

		// set the position
		toOffice.setPosition(600,900);



	// Making Defeat Text
		sf::Text defeat;

		// select the font
		defeat.setFont(font); // font is a sf::Font

		// set the string to display
		defeat.setString("Defeat! You did not collect all of the clues!");

		// set the character size
		defeat.setCharacterSize(40); // in pixels, not points!

		// set the color
		defeat.setColor(sf::Color::Red);

		// set the position
		defeat.setPosition(100,500);

	// Making Win Text
		sf::Text win;

		// select the font
		win.setFont(font); // font is a sf::Font

		// set the string to display
		win.setString("You win! You collected all of the clues \nand were able to catch the killer!");

		// set the character size
		win.setCharacterSize(40); // in pixels, not points!

		// set the color
		win.setColor(sf::Color::Green);

		// set the position
		win.setPosition(100,500);

		
		titleM.play();
		creditsM.play();
		highSchoolM.play();
		locationM.play();

		bool isWalking = false;
		bool isFullscreen = false;
		bool viewedBook = false;
		bool talkButcher = false;
		bool talkFriend = false;


	// Game Loop
	while (window.isOpen())
	{

		if(titleScreen)
		{
			creditsM.stop();
			highSchoolM.stop();
			locationM.stop();
			titleM.setLoop(true);

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
	
					

			int mouseX = Mouse::getPosition(window).x;
			int mouseY = Mouse::getPosition(window).y;

			// Clicking Buttons
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(spritePlay.getGlobalBounds().contains(mouseX, mouseY))
				{
					titleScreen = false;
					firstLevel = true;
					titleM.stop();
					highSchoolM.play();
					player.update();
					viewedBook = false;
					talkButcher = false;
					talkFriend = false;
					
				}

				if(spriteOptions.getGlobalBounds().contains(mouseX, mouseY))
				{
					titleScreen = false;
					Options = true;
				}
				if(spriteCredits.getGlobalBounds().contains(mouseX, mouseY))
				{
					titleScreen = false;
					Credits = true;
					titleM.stop();
					creditsM.play();
				}

				if(spriteExit.getGlobalBounds().contains(mouseX, mouseY))
				{
					window.close();
				}
			}
			//Draw the scene
		
			// Clear everything from the last frame
			window.clear();

			// Draw our game scene here
			window.draw(spriteBackground);

			// Draw Henry
			window.draw(spriteHenry);

			// Draw the Buttons
		
			window.draw(spritePlay);
			window.draw(spriteOptions);
			window.draw(spriteCredits);
			window.draw(spriteExit);

			window.draw(play);
			window.draw(options);
			window.draw(credits);
			window.draw(exit);
		
		
			// Show everything we just drew
			window.display();
		}
		if(Options)
		{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			int mouseX = Mouse::getPosition(window).x;
			int mouseY = Mouse::getPosition(window).y;

			// Clicking Back
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(spriteBack.getGlobalBounds().contains(mouseX, mouseY))
				{
					Options = false;
					titleScreen = true;
				}

			}

			// Clicking Fullscreen
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(spritefullScreen.getGlobalBounds().contains(mouseX, mouseY))
				{
					if(!isFullscreen)
					{
						isFullscreen = true;
						spritefullScreen.setPosition(800,200);
						window.create(VideoMode(1920,1080), "Homicide Hunch", (isFullscreen ? Style::Fullscreen : Style::Close|Style::Resize));
					} 
					else 
					{
						isFullscreen = false;
						spritefullScreen.setPosition(500,200);
						window.create(VideoMode(1920,1080), "Homicide Hunch", (isFullscreen ? Style::Default : Style::Close|Style::Resize));
					}
				}
			}
		
			// Clear everything from the last frame
			window.clear();

			// Draw the Buttons
			window.draw(spriteBackgroundC);
			window.draw(spritefullScreen);
			window.draw(fullScreen);
			window.draw(off);
			window.draw(on);
			window.draw(spriteBack);
			window.draw(back);
			
			// Show everything we just drew
			window.display();
		}

		if(Credits)
		{
			
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			int mouseX = Mouse::getPosition(window).x;
			int mouseY = Mouse::getPosition(window).y;

			// Clicking Back
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(spriteBack.getGlobalBounds().contains(mouseX, mouseY))
				{
					Credits = false;
					titleScreen = true;
					creditsM.stop();
					titleM.play();
				}

			}
		
			//Draw the scene
		
			// Clear everything from the last frame
			window.clear();

			// Draw Credits here
			window.draw(spriteBackgroundC);
			window.draw(creditsTitle);
			window.draw(name);
			window.draw(spriteFace);
			window.draw(classCredit);
			window.draw(resources);
			window.draw(resourcesUsed);
			window.draw(dateUpdate);

			// Draw the Buttons
			window.draw(spriteBack);
			window.draw(back);
			
			// Show everything we just drew
			window.display();
		}
		else if(firstLevel)
		{
			
			isWalking = false;
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			
			if (Keyboard::isKeyPressed(Keyboard::BackSpace))
			{
				firstLevel = false;
				titleScreen = true;
				highSchoolM.stop();
				titleM.play();
			}
			int mouseX = Mouse::getPosition(window).x;
			int mouseY = Mouse::getPosition(window).y;

			bool isWalking = false;

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				isWalking = true;
				player.moveUp();
			}
			else
			{
				player.stopUp();
				
			}

			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				isWalking = true;
				player.moveDown();
			}
			else
			{
				player.stopDown();
				
			}


			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				isWalking = true;
				player.moveRight();
			}
			else
			{
				player.stopRight();
				
			}

			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				isWalking = true;
				player.moveLeft();
			}
			else
			{
				player.stopLeft();
				
			}

			if(isWalking && !(walkingGravel.getStatus() == Sound::Status::Playing))
			{
				walkingGravel.play();
			}
			if(!isWalking && walkingGravel.getStatus() == Sound::Status::Playing)
			{
				walkingGravel.stop();
			}
			if(!isWalking && walkingGrass.getStatus() == Sound::Status::Playing)
			{
				walkingGrass.stop();
			}
			if(cryFemale.getStatus() == Sound::Status::Playing)
			{
				cryFemale.stop();
			}



			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(suspect.getPositionB().contains(mouseX, mouseY))
				{
					if(!(mumbleMale.getStatus() == Sound::Status::Playing))
					{
						talkButcher = true;
						mumbleMale.play();
					}
				}
			}

			if(mumbleMale.getStatus() == Sound::Status::Playing)
			{
				suspect.update();
				//std::cout << suspect.bTalk << std::endl;
			}

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(clue.getPosition().contains(mouseX, mouseY))
				{
					if(!(tickInteraction.getStatus() == Sound::Status::Playing))
					{
						tickInteraction.play();
						viewedBook = true;
					}
				}
			}

			if(player.getPosition().contains(1500,500))
			{
				firstLevel = false;
				levelTwo = true;
				highSchoolM.stop();
				locationM.play();
				
			}

			player.update();
			
			// Clear everything from the last frame
			window.clear();

			window.draw(highSchool.getSprite());
			
			window.draw(spriteBody);
			window.draw(clue.getSprite());
			window.draw(suspect.getSpriteB());
			window.draw(player.getSprite());
			window.draw(toNextLvl);
			window.draw(HUDdisplay.getHUDSprite());
			window.draw(collectedClues);

			// Making HUD Conditions
			if (viewedBook)
			{
				window.draw(HUDdisplay.addBook());
			}
			if (talkButcher)
			{
				window.draw(HUDdisplay.addButcher());
			}
			if (talkFriend)
			{
				window.draw(HUDdisplay.addFriend());
			}

			window.display();
		}
		if (levelTwo)
		{
			isWalking = false;
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::BackSpace))
			{
				levelTwo = false;
				titleScreen = true;
				locationM.stop();
				titleM.play();
			}
			int mouseX = Mouse::getPosition(window).x;
			int mouseY = Mouse::getPosition(window).y;


			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				isWalking = true;
				player.moveUp();
			}
			else
			{
				player.stopUp();
				
			}

			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				isWalking = true;
				player.moveDown();
			}
			else
			{
				player.stopDown();
				
			}


			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				isWalking = true;
				player.moveRight();
			}
			else
			{
				player.stopRight();
				
			}

			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				isWalking = true;
				player.moveLeft();
			}
			else
			{
				player.stopLeft();
				
			}

			if(!isWalking && walkingGravel.getStatus() == Sound::Status::Playing)
			{
				walkingGravel.stop();
			}

			if(isWalking && !(walkingGrass.getStatus() == Sound::Status::Playing))
			{
				walkingGrass.play();
			}
			if(!isWalking && walkingGrass.getStatus() == Sound::Status::Playing)
			{
				walkingGrass.stop();
			}

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(suspect.getPositionF().contains(mouseX, mouseY))
				{
					if(!(cryFemale.getStatus() == Sound::Status::Playing))
					{
						talkFriend = true;
						cryFemale.play();
					}
				}
			}

			if(player.getPosition().contains(200,500))
			{
				firstLevel = true;
				levelTwo = false;
				highSchoolM.play();
				locationM.stop();
				
			}

			if(player.getPosition().contains(900,900))
			{
				if(viewedBook && talkButcher && talkFriend)
				{
					winScreen = true;
					levelTwo = false;
					locationM.stop();
					creditsM.play();

				}
				else
				{
					defeatScreen = true;
					levelTwo = false;
					locationM.stop();
					lose.play();
				}
				
			}

			player.update();
			window.clear();

			window.draw(secondLevel.getSprite());
			window.draw(suspect.getSpriteF());
			window.draw(toHighSchool);
			window.draw(toOffice);
			window.draw(player.getSprite());
			window.draw(HUDdisplay.getHUDSprite());
			window.draw(collectedClues);

			// Making HUD Conditions
			if (viewedBook)
			{
				window.draw(HUDdisplay.addBook());
			}
			if (talkButcher)
			{
				window.draw(HUDdisplay.addButcher());
			}
			if (talkFriend)
			{
				window.draw(HUDdisplay.addFriend());
			}

			window.display();
		}
		if(defeatScreen)
		{
			isWalking = false;
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::BackSpace))
			{
				defeatScreen = false;
				titleScreen = true;
				titleM.play();
			}
			if(!isWalking && walkingGrass.getStatus() == Sound::Status::Playing)
			{
				walkingGrass.stop();
			}
			if(cryFemale.getStatus() == Sound::Status::Playing)
			{
				cryFemale.stop();
			}
			
			window.clear();
			window.draw(defeat);
			window.display();
		}
		if(winScreen)
		{
			isWalking = false;
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::BackSpace))
			{
				winScreen = false;
				titleScreen = true;
				creditsM.stop();
				titleM.play();
			}
			if(!isWalking && walkingGrass.getStatus() == Sound::Status::Playing)
			{
				walkingGrass.stop();
			}
			if(cryFemale.getStatus() == Sound::Status::Playing)
			{
				cryFemale.stop();
			}
			window.clear();
			window.draw(win);
			window.display();
		}
		

	}

	return 0;
}
