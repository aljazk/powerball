#include "MainMenu.hpp"

MainMenu::MainMenu(){
	//background
	back.loadFromFile("images/menu_background.png");
	
	// create font
	font.loadFromFile("arial.ttf");
	// create text
	text.setFont(font);
	// define eclipsed time
	eclipsed = 1;
	// create interface
	createGUI();
}

void MainMenu::createGUI(){
	int startPos = 340;
	int sizeY = 100;
	int gap = 2;
	MenuButton mbutton;
	mbutton.setPosition(sf::Vector2f(252,startPos+(sizeY+gap)*0));
	mbutton.setName("Single Player");
	mbutton.action = "sp";
	gui.emplace<MenuButton>(mbutton);
	mbutton.setPosition(sf::Vector2f(252,startPos+(sizeY+gap)*1));
	mbutton.setName("Map Editor");
	mbutton.action = "me";
	gui.emplace<MenuButton>(mbutton);
	mbutton.setPosition(sf::Vector2f(252,startPos+(sizeY+gap)*2));
	mbutton.setName("Exit");
	mbutton.action = "exit";
	gui.emplace<MenuButton>(mbutton);
}

void MainMenu::run(sf::RenderWindow &window){
	std::string action = "";
	// start loop
	
	sf::VertexArray backVert(sf::Quads);
	VertQuad backQuad;
	sf::Vector2u size = window.getSize();
	sf::Vector2u backSize = back.getSize();
	backQuad.set(sf::Vector2f(0,0), sf::Vector2f(backSize.x,backSize.y), sf::Vector2f(0,0), sf::Vector2f(size.x, size.y));
	backQuad.setCenter(sf::Vector2f(size.x, 0));
	backQuad.add(backVert);
	
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
		
		action = gui.check(window);
		if(action == "sp"){
			GameScreen::run(window);
		}
		if(action == "me"){
			MapEditor map_editor;
			map_editor.run(window);
		}
		if(action == "exit"){
            window.close();
		}
		
		// draw background
		window.draw(backVert, &back);
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
}