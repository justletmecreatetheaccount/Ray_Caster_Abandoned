#pragma once
#include<SFML/Graphics.hpp>
struct Attribute
{
	//Template empty class, nothing to see here
};

struct Mov : public Attribute
{
	//Structure for an object w/ a position and a basic moveset
	//Struct variables
	sf::Vector2i position = { 0, 0 };

	//Struct methods
	virtual void move(int X, int Y) {
		this->position.x += X;
		this->position.y += Y;
	}
};

struct Phy : public Mov
{
	//Same as mother class but with an advanced moveset
	//Struct variables
	sf::Vector2i speed = { 0, 0 };
	sf::Vector2i acceleration = { 0, 0 };


	//Struct methods
	void move(int X, int Y) override {
		this->speed.x += X;
		this->speed.y += Y;
	}

	void accelerate(int X = 0, int Y = 0) {
		this->acceleration.x += X;
		this->acceleration.y += Y;
		this->acceleration += this->speed;
	}
};

struct Spr : public Attribute
{
	//Structure to define an object with an appearence
	sf::CircleShape sprite;

	void assign_sprite(sf::CircleShape spr) {
		sprite = spr;
	}
};