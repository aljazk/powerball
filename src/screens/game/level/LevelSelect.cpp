#include "LevelSelect.hpp"

LevelSelect::LevelSelect(){
	back.loadFromFile("images/menu_background.png");
	backSize = back.getSize();
	// create font
	font.loadFromFile("arial.ttf");
	// create text
	text.setFont(font);
	// define eclipsed time
	eclipsed = 1;
	// create interface
	createInter();
}

void LevelSelect::createInter(){
	int startPos = 100;
	int sizeY = 100;
	int gap = 2;
	MenuButton mbutton;
	mbutton.setPosition(sf::Vector2f(252,startPos+(sizeY+gap)*1));
	mbutton.setName("Level 1");
	mbutton.action = "1";
	mbutton.centerText();
	gui.emplace<MenuButton>(mbutton);
	mbutton.setPosition(sf::Vector2f(252,startPos+(sizeY+gap)*2));
	mbutton.setName("Back to menu");
	mbutton.action = "tomenu";
	mbutton.centerText();
	gui.emplace<MenuButton>(mbutton);
}

std::string LevelSelect::run(sf::RenderWindow &window){
	std::string action = ""; 
	// start loop
    while (window.isOpen()){
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)){
			//inter.enterText(event);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
		}
		
		// clear window
        window.clear(sf::Color::Black);
		// draw background
		sf::VertexArray backVert(sf::Quads);
		VertQuad backQuad;
		sf::Vector2u size = window.getSize();
		backQuad.set(sf::Vector2f(0,0), sf::Vector2f(backSize.x,backSize.y), sf::Vector2f(0,0), sf::Vector2f(size.x, size.y));
		backQuad.setCenter(sf::Vector2f(size.x, 0));
		backQuad.add(backVert);
		window.draw(backVert, &back);
		
		
		action = gui.check(window);
		if (action != ""){
			return action;
		}
		gui.draw(window);
		
		// end the current frame
		eclipsed = clock.restart().asSeconds();
		// display fps
		std::ostringstream s;
		s << 1.f/eclipsed << std::endl;
		text.setString(s.str());
		text.setCharacterSize(10);
		text.setFillColor(sf::Color::White);
		text.setPosition(10,10);
		window.draw(text);


		// draw stuff on window
        window.display();
        //wait();
    }
	return action;
}