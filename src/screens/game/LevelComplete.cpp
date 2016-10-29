#include "LevelComplete.hpp"

LevelComplete::LevelComplete(){
	// create interface
	action = "";
	createGUI();
}

void LevelComplete::createGUI(){
	int startPos = 100;
	int sizeY = 100;
	int gap = 2;
	Text text;
	text.setPosition(sf::Vector2f(251,startPos+1));
	text.setName("Level Complete!");
	text.setTextColor(sf::Color(100,0,0));
	text.centerText();
	gui.emplace<Text>(text);
	text.setPosition(sf::Vector2f(252,startPos));
	text.setTextColor(sf::Color(220,0,0));
	text.centerText();
	gui.emplace<Text>(text);
	MenuButton mbutton;
	mbutton.setPosition(sf::Vector2f(252, startPos+(sizeY+gap)*1));
	mbutton.setName("Next Level");
	mbutton.action = "nextlvl";
	mbutton.centerText();
	gui.emplace<MenuButton>(mbutton);
	mbutton.setPosition(sf::Vector2f(252, startPos+(sizeY+gap)*2));
	mbutton.setName("Restart");
	mbutton.action = "restart";
	mbutton.centerText();
	gui.emplace<MenuButton>(mbutton);
	mbutton.setPosition(sf::Vector2f(252, startPos+(sizeY+gap)*3));
	mbutton.setName("Back to menu");
	mbutton.action = "tomenu";
	mbutton.centerText();
	gui.emplace<MenuButton>(mbutton);
}

void LevelComplete::run(sf::RenderWindow &window){
	background.update(window);
	sf::Vector2u backSize = background.getSize();
    while (window.isOpen()){
        // check all the window's events that were triggered since the last iteration of the loop
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
		gui.draw(window);
		if (action != ""){
			break;
		}
		
        window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
			break;
		}
	}
}

std::string LevelComplete::getAction(){
	return action;
}