#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include "Text.h"
#include "Buttons.h"
#include "Highscores.h"
using namespace std;
using namespace sf;


class Game
{
	
private:
	//Variables
	//window
	RenderWindow* window;
	VideoMode videomode;
	bool Fullscreen;
	Event ev;
	//Mouse Positions
	Vector2i mousePosWindow;
	Vector2f mousePosView;
	//Classes
	TextClass text;
	Buttons buttons;
	Highscores highscores;
	//Game Logic
	unsigned coins; //Positief alleen
	int health;
	float MoveSpeed;
	float enemyspawntimer;
	float enemyspawntimermax;
	int maxenemies;
	bool mouseHeld;
	bool endgame;
	bool Boolquit;
	//Game Objects
	vector<Sprite> enemies;
	Sprite enemy;
	Texture enemyTexture;
	Sprite background;
	Texture backgroundTexture;
	//Private Functions
	void initvariables();
	void initwindow();
	void initbackground();
	void initenemies();
	


public:
	//Constructors / Destructors
	Game();
	virtual ~Game();
	//Accessors
	const bool GameRunning() const;
	const bool getendgame() const;
	//Functions
	void toggleFullscreen();
	void spawnEnemy();
	void pollEvents();
	void updateMousePos();
	void updateEnemies();
	void update();

	void renderbackground(RenderTarget& target);
	void renderEnemies(RenderTarget& target);
	void render();
};
