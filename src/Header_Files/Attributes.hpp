#pragma once
#include<iostream>
#include<map>
#include<string>
#include<memory>
#include<SFML/Graphics.hpp>

struct Attribute {
	static const int NUMBER_OF_ATTRIBUTES = 2;
	int Owner_ID;
	virtual ~Attribute() {}
};

std::ostream& operator<<(std::ostream& stream, const Attribute& attribute);

struct Vertex : Attribute {
	sf::Vector2f entity_position;

	Vertex(int ID);

	void logPosition();

	sf::Vector2f setPosition(sf::Vector2f pos);

	sf::Vector2f updatePosition(sf::Vector2f speed, sf::Time dt);
};

struct C_Shape : Attribute {
	std::unique_ptr<sf::CircleShape> shape_ptr;
	std::unique_ptr<Vertex> linked_position_ptr;
	bool has_shape = false;
	bool has_link = false;

	C_Shape(int ID);

	void giveShape(sf::CircleShape* shape);

	void linkVertex(Vertex* vertex_ptr);

	sf::CircleShape& getShape();

	bool updatePosition(sf::Vector2f speed, sf::Time dt);
};

struct R_Shape : Attribute {
	std::unique_ptr<sf::RectangleShape> shape_ptr;
	std::unique_ptr<Vertex> linked_position_ptr;
	bool has_shape = false;
	bool has_link = false;

	R_Shape(int ID);

	void linkVertex(Vertex* vertex_ptr);

	void giveShape(sf::RectangleShape shape);

	sf::RectangleShape& getShape();

	bool updatePosition(sf::Vector2f speed, sf::Time dt);
};

struct Physics : Attribute {
	sf::Vector2f speed;
	sf::Vector2f forces;
	float friction;
	int mass;

	Physics(int ID);

	void updateSpeed(sf::Time dt);
};