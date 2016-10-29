#include "GameScreen.hpp"

GameScreen::GameScreen(){
}

void GameScreen::run(sf::RenderWindow &window){
	LevelSelect select;
	run(window, select.run(window));
}

void GameScreen::run(sf::RenderWindow &window, std::string lvlid){
	if(lvlid == "tomenu"){
		return;
	}
	Level level;
	//load level
	level.load("levels/"+lvlid+"/map");
	//start game
	SinglePlayer game;
	game.setLevel(level);
	game.run(window);
	if (game.getAction() == "lvlselect"){
		run(window);
	} if (game.getAction() == "nextlvl"){
		run(window, lvlid);
	}
}