#pragma once
#include "Attributes.h"
#include <string>
#include <map>

// Definition of the different flags to tell if an entity has a certain charateristic or not
// Workings : Define bytes and add with "|" then compare with "&" 

/* Example :
* 
*  void fnct (Attribute flag):
*  if (flag & Attribute::Movable):
*     ...DOES SOMETHING...
*  
*########################################
* 
* Call with fnct(Attribute::Movable | Attribute::Health)
* we will have flags equals :
* 
*   0000 0001
* + 0000 0010
* -----------
*   0000 0011
* 
* Then in the function the check is:
* 
*     0000 0001
* AND 0000 0011
* -------------
*     0000 0001
* >>> Is different from 0 so signals True
*/


enum Attribute_enum {
	Movment = 1u << 0,
	Physics = 1u << 1,
	Sprite = 1u << 2,
	Collision = 1u << 3
};

class Entity
{
public:
	Entity(int flags);
	~Entity();

private:
	//Create a map of attributes (accesible with an element of Attribute_enum
	std::map<int, Attribute*> signature;
	std::map<int, Attribute*>::iterator iter = signature.begin();
};

Entity::Entity(int flags)
{
	if (flags & Attribute_enum::Movment) {
		signature[Attribute_enum::Movment] = new Mov;
	}
	if (flags & Attribute_enum::Physics) {
		Phy phy;
	}
	if (flags & Attribute_enum::Sprite) {
		Spr spr;
	}
}

Entity::~Entity()
{
	while (iter != signature.end())
	{
		delete iter->first;
		iter++;
	}
}