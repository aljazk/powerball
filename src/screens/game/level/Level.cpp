#include "Level.hpp"

Level::Level(){
}

void Level::addWall(std::string line){
	std::vector<float> points;
	points = Read::getNumbersf(line);
	Wall w;
	for(unsigned int i=0; i<points.size(); i+=2){
		w.add(points[i], points[i+1]);
	}
	walls.push_back(w);
}

void Level::addWall(const std::vector<sf::Vector2f> &points){
	Wall w;
	for(unsigned int i=0; i<points.size(); i++){
		w.add(points[i]);
	}
	walls.push_back(w);
}

void Level::loadLine(std::string line){
	std::vector<std::string> words;
	words = Read::getWords(line);
	if(words[0] == "wall"){
		addWall(line);
	}
}

void Level::load(){
	std::cout << "Enter map path" << std::endl;
	std::string load_string;
	std::cin >> load_string;
	load(load_string);
}

void Level::load(const std::string &load_string){
	std::string line;
	std::ifstream myfile(load_string);
	if (!myfile.is_open()){
		std::cout << "Unable to open file: " << load_string << std::endl;
	} else {
		std::cout << "Loading map from file: " << load_string << std::endl;
		while ( std::getline(myfile,line) ){
			std::cout << line << std::endl;
			loadLine(line);
		}
		myfile.close();
	}
}

void Level::save(){
	std::cout << "Enter map path" << std::endl;
	std::string save_string;
	std::cin >> save_string;
	save(save_string);
}

void Level::save(const std::string &save_string){
	std::ofstream myfile;
	myfile.open (save_string);
	for(unsigned int i=0; i<walls.size(); i++){
		myfile << "wall:" + walls[i].get();
	}
	myfile.close();
}

void Level::clear(){
	walls.clear();
}

void Level::draw(sf::RenderWindow &window){
	sf::VertexArray vert(sf::Quads);
	for(unsigned int i=0; i<walls.size(); i++){
		walls[i].getVert(vert);
	}
	window.draw(vert);
}

ObjectSetter Level::getWallObject(){
	ObjectSetter os;
	os.mass = 0;
	for(unsigned int i=0; i<walls.size(); i++){
		os.add(walls[i].getPoly());
	}
	return os;
}