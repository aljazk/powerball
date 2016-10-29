#include "MapEditor.hpp"

MapEditor::MapEditor(){
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	
	createGUI();
}

void MapEditor::createGUI(){
	int startPos = 10;
	int sizeY = 50;
	int gap = 2;
	EditorButton mbutton;
	mbutton.setPosition(sf::Vector2f(10,startPos+(sizeY+gap)*0));
	mbutton.setName("L");
	mbutton.action = "load";
	gui.emplace<EditorButton>(mbutton);
	mbutton.setPosition(sf::Vector2f(10,startPos+(sizeY+gap)*1));
	mbutton.setName("S");
	mbutton.action = "save";
	gui.emplace<EditorButton>(mbutton);
	mbutton.setPosition(sf::Vector2f(10,startPos+(sizeY+gap)*2));
	mbutton.setName("Q");
	mbutton.action = "exit";
	gui.emplace<EditorButton>(mbutton);
	
	//levels
	for(int i=1; i<=2; i++){
		const char c = i+48;
		std::string name;
		name.push_back('L');
		name.push_back(c);
		mbutton.setPosition(sf::Vector2f(startPos+(sizeY+gap)*i, 10));
		mbutton.setName(name);
		name.erase();
		name.append("levels/");
		name.push_back(c);
		name.append("/map");
		mbutton.action = name;
		gui.emplace<EditorButton>(mbutton);
	}
	
	startPos = 100;
	mbutton.setPosition(sf::Vector2f(startPos+(sizeY+gap)*0,710-50));
	mbutton.setName("1");
	mbutton.action = "object1";
	gui.emplace<EditorButton>(mbutton);
	
}

void MapEditor::run(sf::RenderWindow &window){
	EditorCamera cam(1280, 720);
	cam.move_speed = 3;
	ObjectAdding obj;
	obj.gridSize = 20;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
			cam.key(event);
			obj.key(event, window, level);
            if (event.type == sf::Event::Closed){
                window.close();
				break;
			}
			
		}
		cam.move();
		
		// clear window
        window.clear(sf::Color::Black);
		
		window.setView(cam.get());
		level.draw(window);
		
		obj.draw(window);
		obj.drawGrid(window);
		
		window.setView(window.getDefaultView());
		gui.draw(window);
		window.setView(cam.get());
		
		std::string action = gui.check(window);
		
		if (action != ""){
			obj.popPoint();
		}
		
		if (action == "object1"){
			action = "";
		}
		
		if (action != "load" && action[0] == 'l'){
			level.clear();
			level.load(action);
			action = "";
		}
		
		if (action == "load"){
			level.clear();
			level.load();
			action = "";
		}
		if (action == "save"){
			level.save();
			action = "";
		}
		
		if (action != ""){
			window.setView(window.getDefaultView());
			break;
		}
		// draw stuff on window
        window.display();
        //wait();
	}
}