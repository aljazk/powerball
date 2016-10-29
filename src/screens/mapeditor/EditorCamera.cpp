#include "EditorCamera.hpp"

EditorCamera::EditorCamera(){
	set(640, 480);
}

EditorCamera::EditorCamera(unsigned int x, unsigned int y){
	set(x,y);
}

void EditorCamera::set(unsigned int x, unsigned int y){
	keyA = false; keyD = false; keyW = false; keyS = false;
	move_speed = 0.1;
	zoom_speed = 0.1;
	setWindowSize(x, y);
	view.reset(sf::FloatRect(0, 0, window_size_x, window_size_y));
}

void EditorCamera::setWindowSize(unsigned int x, unsigned int y){
	window_size_x = x;
	window_size_y = y;
}

sf::View EditorCamera::get(){
	return view;
}

void EditorCamera::move(){
	move(1);
}

void EditorCamera::move(const float eclipsed){
	if (keyA || mA){
		view.move(-move_speed * eclipsed,0);
	}
	if (keyD || mD){
		view.move(move_speed * eclipsed,0);
	}
	if (keyW || mW){
		view.move(0,-move_speed * eclipsed);
	}
	if (keyS || mS){
		view.move(0,move_speed * eclipsed);
	}
	if (zoom){
		view.zoom(1.0 + delta * zoom_speed * eclipsed * -1);
	}
	zoom = false;
}

void EditorCamera::key(const sf::Event &event){
	if(event.type == sf::Event::KeyPressed){
		if(event.key.code == 0){
			keyA = true;
		}
		if(event.key.code == 3){
			keyD = true;
		}
		if(event.key.code == 22){
			keyW = true;
		}
		if(event.key.code == 18){
			keyS = true;
		}
	}
	if(event.type == sf::Event::KeyReleased){
		if(event.key.code == 0){
			keyA = false;
		}
		if(event.key.code == 3){
			keyD = false;
		}
		if(event.key.code == 22){
			keyW = false;
		}
		if(event.key.code == 18){
			keyS = false;
		}
	}
	if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel){
		if (event.mouseWheelScroll.delta == -1 ||  event.mouseWheelScroll.delta == 1){
			delta =  event.mouseWheelScroll.delta;
			zoom = true;
		}
	}
	if (event.type == sf::Event::MouseMoved){
		int gap = 30;
		if (event.mouseMove.x < gap){
			mA = true;
		} else mA = false;
		if (event.mouseMove.x > (int)window_size_x - gap){
			mD = true;
		} else mD = false;
		if (event.mouseMove.y < gap){
			mW = true;
		} else mW = false;
		if (event.mouseMove.y > (int)window_size_y - gap){
			mS = true;
		} else mS = false;
	}
	if (event.mouseMove.y < 0){ // mouse left window
		mA = false;
		mD = false;
		mW = false;
		mS = false;
	}
}

float EditorCamera::getZoom(){
	return window_size_x/view.getSize().x;
}