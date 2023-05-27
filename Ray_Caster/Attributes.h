#pragma once
#include<map>
#include<string>
#include<SFML/Graphics.hpp>

class ECS_Manager {
private:
	std::map<std::string, int> Entities_list;
public:

};

class Position {
private:
	
	sf::Vector2i entity_position;
public:
	Position() {
		entity_position = sf::Vector2i(0, 0);
	}
};