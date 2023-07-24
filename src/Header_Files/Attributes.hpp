#pragma once
#include <SFML/System/Vector2.hpp>
#include<iostream>
#include<SFML/Graphics.hpp>

class Attribute{
	public:
	const static int NUMBER_OF_ATTRIBUTES = 4;
	int Owner_ID;
	Attribute(int ID){
		Owner_ID = ID;
	}
	virtual ~Attribute() {};
};

std::ostream& operator<<(std::ostream& stream, const Attribute& attribute);