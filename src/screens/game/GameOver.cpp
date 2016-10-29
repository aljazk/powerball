#include "GameOver.hpp"

GameOver::GameOver(){
	//create interface
	createInter();
}

void GameOver::createInter(){
	/*
	int startPos = 100;
	int sizeY = 60;
	int gap = 2;
	Text text;
	text.set(sf::Vector2f(251,startPos+1), "Game Over", sf::Color(100,0,0), 30);
	text.setStyle(sf::Text::Bold);
	inter.add(text);
	text.set(sf::Vector2f(252,startPos), "Game Over", sf::Color(220,0,0), 30);
	text.setStyle(sf::Text::Bold);
	inter.add(text);
	MenuButton mbutton;
	mbutton.set(sf::Vector2f(252,startPos+(sizeY+gap)*1), "Restart", 1);
	inter.add(mbutton);
	mbutton.set(sf::Vector2f(252,startPos+(sizeY+gap)*2), "Back to menu", 2);
	inter.add(mbutton);
	*/
	int startPos = 100;
	int sizeY = 100;
	int gap = 2;
	Text text;
	text.setPosition(sf::Vector2f(251,startPos+1));
	text.setName("Game Over");
	text.setTextColor(sf::Color(100,0,0));
	text.centerText();
	gui.emplace<Text>(text);
	text.setPosition(sf::Vector2f(252,startPos));
	text.setTextColor(sf::Color(220,0,0));
	text.centerText();
	gui.emplace<Text>(text);
	MenuButton mbutton;
	mbutton.setPosition(sf::Vector2f(252, startPos+(sizeY+gap)*2));
	mbutton.setName("Restart");
	mbutton.action = "restart";
	mbutton.centerText();
	gui.emplace<MenuButton>(mbutton);
	mbutton.setPosition(sf::Vector2f(252, startPos+(sizeY+gap)*3));
	mbutton.setName("To level select");
	mbutton.action = "lvlselect";
	mbutton.centerText();
	gui.emplace<MenuButton>(mbutton);
	mbutton.setPosition(sf::Vector2f(252, startPos+(sizeY+gap)*4));
	mbutton.setName("Back to menu");
	mbutton.action = "tomenu";
	mbutton.centerText();
	gui.emplace<MenuButton>(mbutton);
}

void GameOver::run(sf::RenderWindow &window){
	background.update(window);
	sf::Vector2u backSize = background.getSize();
    while (window.isOpen()){
		
        sf::Event event;
        while (window.pollEvent(event)){
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
				break;
		}
		
		
        window.clear(sf::Color::Black);
		
		//draw background
		sf::VertexArray backVert(sf::Quads);
		VertQuad backQuad;
		sf::Vector2u size = window.getSize();
		backQuad.set(sf::Vector2f(0,0), sf::Vector2f(backSize.x,backSize.y), sf::Vector2f(0,0), sf::Vector2f(size.x, size.y));
		backQuad.setCenter(sf::Vector2f(size.x, 0));
		backQuad.setColor(sf::Color(150,150,150));
		backQuad.add(backVert);
		window.draw(backVert, &background);
		
		action = gui.check(window);
		if (action != ""){
			break;
		}
		gui.draw(window);
        window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
			action = "restart";
			break;
		}
	}
	if(action == "restart"){
		
	}
}

std::string GameOver::getAction(){
	return action;
}