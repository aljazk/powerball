#include "SinglePlayer.hpp"

void ndelete(Ball *){
	return;
}

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
	std::shared_ptr<Ball> ptr_ball (&ball, ndelete);
	map.set(ptr_ball);
}

void SinglePlayer::createGUI(){
	PauseButton pause;
	gui.emplace<PauseButton>(pause);
}

void SinglePlayer::setLevel(const Level &l){
	level = l;
	ObjectSetter os = level.getWallObject();
	map.add(CollisionObject(os));
	ai.add(std::unique_ptr<Robot>(new Robot()));
	ai.add(std::unique_ptr<Turret>(new Turret(500,500)));
}

void SinglePlayer::collide(){
	while (true){
		map.collide();
		ai.collide(map);
		sf::sleep(sf::milliseconds(10));
	}
}

void SinglePlayer::run(sf::RenderWindow &window){
	
	
	Camera cam(1280, 720);
	
	
	clock.restart();
	sf::Clock bug_clock;
	bug_clock.restart();
	float move_time = 0;
	float collide_time = 0;
	float rest_time = 0;
	
	float lowest_fps = 3000;
	unsigned int low_spikes = 0;
	
	sf::Thread collide_thread(&collide, this);
	//collide_thread.launch();

	
	// start loop
    while (window.isOpen()){
		
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
				collide_thread.terminate();
                window.close();
				break;
			}
		}
		
		// clear window
        window.clear(sf::Color::Black);
		
		//game step
		bug_clock.restart();
		move_time = 0;
		
		ball.move(eclipsed);
		ai.move(eclipsed);
		
		move_time = bug_clock.restart().asSeconds();
		
		ai.check_delete();
		
		bug_clock.restart();
		collide_time = 0;
		
		map.collide();
		ai.collide(map);
		
		collide_time = bug_clock.restart().asSeconds();
		
		/*
		ball.getPosition(px, py);
		ball.getVelocity(vx, vy);
		cam.pos(px, py);
		ai.setBallPosition(px, py);
		map.setBall(px, py, vx, vy);
		map.collide();
		ai.collide(map);
		map.getPosition(px, py);
		map.getVelocity(vx, vy);
		ball.set(px, py, vx, vy);
		*/
		
		bug_clock.restart();
		rest_time = 0;
		
		cam.pos(ball.getPosition());
		ai.setBallPosition(ball.getPosition());
		
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
		ai.add();
		
		ball.draw(window);
		
		action = gui.check(window);
		
		window.setView(window.getDefaultView());
		gui.draw(window, eclipsed);
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
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
		
		rest_time = bug_clock.restart().asSeconds();
		
		// end the current frame
		eclipsed = clock.restart().asSeconds();
		// display fps
		std::ostringstream s;
		if(1.0/eclipsed < lowest_fps) lowest_fps = 1.0/eclipsed;
		if (1.0/eclipsed < 60.0) low_spikes ++;
		s << "fps: " << 1.0/eclipsed;
		s  << "\nlowest fps: " << lowest_fps << "\nlow spikes: " << low_spikes;
		s << "\nmove time: " << move_time << "\ncollide time: " << collide_time  << "\nrest time: " << rest_time;
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
	collide_thread.terminate();
}