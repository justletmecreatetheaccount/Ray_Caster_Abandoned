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

std::ostream& operator<<(std::ostream& stream, const Attribute& attribute) {
	stream << typeid(attribute).name();
	return stream;
}

struct Vertex : Attribute {
	sf::Vector2f entity_position;

	Vertex(int ID) {
		entity_position = sf::Vector2f(0, 0);
		Owner_ID = ID;
	}

	~Vertex() {
	}

	void logPosition() {
		std::cout << "Enitity " << int(Owner_ID) << " position : (" << entity_position.x << ", " << entity_position.y << ")" << "\n";
	}

	sf::Vector2f setPosition(sf::Vector2f pos) {
		entity_position = pos;
		return entity_position;
	}

	sf::Vector2f updatePosition(sf::Vector2f speed, sf::Time dt) {
		entity_position += speed * dt.asSeconds();
		return entity_position;
	}
};

struct C_Shape : Attribute {
	std::unique_ptr<sf::CircleShape> shape_ptr;
	std::unique_ptr<Vertex> linked_position_ptr;
	bool has_shape = false;
	bool has_link = false;

	C_Shape(int ID) {
		Owner_ID = ID;
	}

	void giveShape(sf::CircleShape* shape) {
		shape_ptr.reset(shape);
		has_shape = true;
	}

	void linkVertex(Vertex* vertex_ptr) {
		linked_position_ptr.reset(vertex_ptr);
		has_link = true;
	}

	sf::CircleShape& getShape() {
		return *shape_ptr;
	}

	bool updatePosition(sf::Vector2f speed, sf::Time dt) {
		if (has_shape) {
			(*shape_ptr).setPosition((*linked_position_ptr).updatePosition(speed, dt));
			return true;
		}
		return false;
	}
};

struct R_Shape : Attribute {
	std::unique_ptr<sf::RectangleShape> shape_ptr;
	std::unique_ptr<Vertex> linked_position_ptr;
	bool has_shape = false;
	bool has_link = false;

	R_Shape(int ID) {
		Owner_ID = ID;
	}

	void linkVertex(Vertex* vertex_ptr) {
		linked_position_ptr.reset(vertex_ptr);
		has_link = true;
	}

	void giveShape(sf::RectangleShape shape) {
		shape_ptr.reset(&shape);
		has_shape = true;
	}

	sf::RectangleShape& getShape() {
		return *shape_ptr;
	}

	bool updatePosition(sf::Vector2f speed, sf::Time dt) {
		if (has_shape) {
			(*shape_ptr).setPosition((*linked_position_ptr).updatePosition(speed, dt));
			return true;
		}
		return false;
	}
};

struct Physics : Attribute {
	sf::Vector2f speed;
	sf::Vector2f forces;
	float friction;
	int mass;

	Physics(int ID) {
		speed = sf::Vector2f(0, 0);
		forces = sf::Vector2f(0, 0);
		mass = 1;
		friction = 0.9;
		Owner_ID = ID;
	}

	void updateSpeed(sf::Time dt) {
		speed.x = speed.x + (forces.x / mass) * dt.asSeconds() - friction * speed.x * dt.asSeconds();
		speed.y = speed.y + (forces.y / mass) * dt.asSeconds() - friction * speed.y * dt.asSeconds();
		forces = sf::Vector2f(0, 0);
	}
};