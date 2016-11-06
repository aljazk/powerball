#include "LightingScreen.hpp"

LightingScreen::LightingScreen(){	
	//background
	back.loadFromFile("images/back.jpg");
	
	// create font
	font.loadFromFile("arial.ttf");
	// create text
	text.setFont(font);
	// define eclipsed time
	eclipsed = 1;
	// create interface
	createGUI();
}

void LightingScreen::createGUI(){
	
}

int random(){
	return rand()%100;
}

void LightingScreen::run(sf::RenderWindow &window){
	std::string action = "";
	
	sf::VertexArray backVert(sf::Quads);
	VertQuad backQuad;
	sf::Vector2u size = window.getSize();
	sf::Vector2u backSize = back.getSize();
	backQuad.set(sf::Vector2f(0,0), sf::Vector2f(backSize.x,backSize.y), sf::Vector2f(0,0), sf::Vector2f(size.x, size.y));
	backQuad.setCenter(sf::Vector2f(size.x, 0));
	backQuad.add(backVert);
	
	srand (time(NULL));
	for(unsigned int i=0; i<10; i++){
		sf::Color rand_color = sf::Color(random()*15.5+100, random()*15.5+100, random()*15.5+100, 255);
		Light light(random()*12.8, random() *7.2, random()*10 + 1000, rand_color);
		if (i == 0){
			lighting.addLight(light);
		} else {
			lighting.addStaticLight(light);
		}
	}
	
    while (window.isOpen()){
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)){
			if (event.type == sf::Event::MouseMoved){
				lighting.setPosition((float)event.mouseMove.x, 720-(float)event.mouseMove.y);
			}
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
		}
		
		// clear window
        window.clear(sf::Color::Black);
		
		action = gui.check(window);
		
		// draw background
		window.draw(backVert, &back);
		gui.draw(window);
		
		lighting.draw(window);
		
		// end the current frame
		eclipsed = clock.restart().asSeconds();
		// display fps
		std::ostringstream s;
		s << "\n" <<1.f/eclipsed << std::endl;
		text.setString(s.str());
		text.setCharacterSize(10);
		text.setFillColor(sf::Color::White);
		text.setPosition(10,10);
		window.draw(text);

		// draw stuff on window
        window.display();
    }
}
