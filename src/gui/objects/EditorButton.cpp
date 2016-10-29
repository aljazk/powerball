#include "EditorButton.hpp"

EditorButton::EditorButton(){
	setName("EditorButton");
	setBorderWidth(0);
	setSize(sf::Vector2f(50,50));
	setTextureSize(sf::Vector2f(250,100));
	
	texture_position = sf::Vector2f(0,0);
	hover_texture_position = texture_position;
	hover_texture_position.y = texture_size.y;
	click_texture_position = texture_position;
	click_texture_position.y = texture_size.y*2;
	
	
	color = sf::Color(180,180,180,255);
	border_color = sf::Color(200,200,200,255);
	text.setCharacterSize(35);
	text.setFillColor(sf::Color::Yellow);
	setText(text);
	
	hover_text.setFillColor(sf::Color(235,235,0));
	
	click_text.setFillColor(sf::Color(215,215,0));
	
	centerText();
}