#pragma once
#include <string>
#include <map>
#include <vector>
#include <typeinfo>
#include <memory>
#include "Attributes.hpp"

class Entity {
private :
	static int current_entity_count;
	static std::vector<Entity*> all_entities_ptr;
	int ID;
	std::vector<Attribute*> Signiature;

public:
	Entity();
	~Entity();
	const int& getId() const;

	const std::vector<Attribute*>& getSignature() const;

	template<typename T>
	void addAttribute() {
		Signiature.emplace_back(new T(ID));
	}

	template<typename T>
	T& getAttribute() {
		for (Attribute* i : this->Signiature) {
			if (typeid(T) == typeid(*i)) {
				return dynamic_cast<T&>(*i);
			}
		}
	}

	static bool updatePhysics();
};

std::ostream& operator<<(std::ostream& stream, const Entity& entity);