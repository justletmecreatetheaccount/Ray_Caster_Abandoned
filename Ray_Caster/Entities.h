#pragma once
#include "Attributes.h"
#include <string>
#include <map>
#include <vector>
#include <typeinfo>
#include <memory>

class Entity {
private :
	int ID = 999;
	std::vector<Attribute*> Signiature;

public:
	const int& get_id() const {
		return ID;
	}

	const std::vector<Attribute*>& get_signature() const {
		return Signiature;
	}

	template<typename T>
	void add_attribute() {
		Signiature.emplace_back(new T);
		std::cout << "think of a" << typeid(*(*Signiature.begin())).name() << " " << typeid(T).name() << "\n";
	}

	template<typename T>
	T& get_attribute() {
		for (Attribute* i : this->Signiature) {
			if (typeid(T) == typeid(*i)) {
				return dynamic_cast<T&>(*i);
			}
		}
	}

};


std::ostream& operator<<(std::ostream& stream, const Entity& entity) {
	stream << entity.get_id() << " : ";
	for (Attribute* i : entity.get_signature()) {
		stream << *i;
	}

	stream << "\n";
	return stream;
}