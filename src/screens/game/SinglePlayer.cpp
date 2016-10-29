#include "SinglePlayer.hpp"

SinglePlayer::SinglePlayer(){
	back.loadFromFile("images/menu_background.png");
	backSize = back.getSize();
	// create font
	font.loadFromFile("arial.ttf");
	// create text
	text.setFont(font);
	// define eclipsed time
	eclipsed = 0;
	
	action = "";
	//create interface
	createGUI();
	
	ObjectSetter os;
	os.add(Circle(0,0,25));
	map.set(CollisionObject(os));
}

void SinglePlayer::createGUI(){
	PauseButton pause;
	gui.emplace<PauseButton>(pause);
}

void SinglePlayer::setLevel(const Level &l){
	level = l;
	ObjectSetter os = level.getWallObject();
	map.add(CollisionObject(os));
	ai.emplace<Robot>();
	for(unsigned int i=0; i<10; i++){
		for(unsigned int j=0; j<10; j++){
		}
	}
	ai.emplace<Turret>(500,500);
	ai.add();
}

void SinglePlayer::run(sf::RenderWindow &window){
	
	
	Camera cam(1280, 720);
	
	
	clock.restart();
	
	// start loop
    while (window.isOpen()){
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
				break;
			}
		}
		
		// clear window
        window.clear(sf::Color::Black);
		
		//game step
		float px, py;
		float vx, vy;
		ball.move(eclipsed);
		ai.collide(map);
		ai.move(eclipsed);
		
		ball.getPosition(px, py);
		ball.getVelocity(vx, vy);
		cam.pos(px, py);
		ai.setBallPosition(px, py);
		map.setBall(px, py, vx, vy);
		map.collide();
		map.getPosition(px, py);
		map.getVelocity(vx, vy);
		ball.set(px, py, vx, vy);
		
		// draw background
		sf::VertexArray backVert(sf::Quads);
		VertQuad backQuad;
		sf::Vector2u size = window.getSize();
		backQuad.set(sf::Vector2f(0,0), sf::Vector2f(backSize.x,backSize.y), sf::Vector2f(0,0), sf::Vector2f(size.x, size.y));
		backQuad.setCenter(sf::Vector2f(size.x, 0));
		backQuad.add(backVert);
		
		window.setView(window.getDefaultView());
		window.draw(backVert, &back);
		
		window.setView(cam.get());
		
		level.draw(window);
		
		ai.draw(window);
		
		ball.draw(window);
		
		action = gui.check(window);
		
		window.setView(window.getDefaultView());
		gui.draw(window, eclipsed);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
			action = "pause";
		}
		
		if(action == "pause"){
			Pause pause;
			pause.run(window);
			action = pause.getAction();
			clock.restart();
		}
		
		if (action != ""){
			break;
		}
		
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
		window.setView(cam.get());
        window.display();
        //wait();
	}
	if (action == "over"){
		GameOver over;
		over.run(window);
		action = over.getAction();
		//run(window);
	}
	if (action == "restart"){ //restart
		action = "";
		run(window);
	}
	if (action == "tomenu"){//back to menu somehow ._.
		
	}
}