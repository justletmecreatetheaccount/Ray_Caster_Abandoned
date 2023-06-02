#pragma once
#include<iostream>
#include<map>
#include<string>
#include<SFML/Graphics.hpp>

struct Attribute {
	static const int NUMBER_OF_ATTRIBUTES = 2;
	int todo = 7;
	virtual ~Attribute() {}
};

std::ostream& operator<<(std::ostream& stream, const Attribute& attribute) {
	stream << attribute.todo;
	return stream;
}

struct Vertex : Attribute {
private:
	sf::Vector2i entity_position;
	int test = 69;
public:
	static const int ATTRIBUTE_ID = 0;

	Vertex() {
		entity_position = sf::Vector2i(0, 0);
	}

	void log_position() {
		std::cout << test;
	}

};

struct Physics : Attribute {
private:
	int test;
public:
	static const int ATTRIBUTE_ID = 1;

	Physics() {
		test = 4;
	}
	int change_test_int(int rand) {
		test = rand;
		return test;
	}
};