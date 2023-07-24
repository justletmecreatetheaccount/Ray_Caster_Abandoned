#pragma once
#include <ratio>
#include <string>
#include <map>
#include <bitset>
#include <utility>
#include <vector>
#include <typeinfo>
#include <memory>
#include "Attributes.hpp"

class Entity {
private :
	static int current_entity_count;
	static std::vector<Entity*> all_entities_ptr;
	static std::vector<std::bitset<Attribute::NUMBER_OF_ATTRIBUTES>> all_entities_signature;
	int ID;
	std::vector<Attribute*> Signature; 

public:
	Entity();
	~Entity();
	const int& getId() const;

	const std::vector<Attribute*>& getSignature() const;

	template<typename T, typename... A>
	void addAttribute(A... args) {
		Signature.emplace_back(new T(ID, args...));
	}

	template<typename T>
	T& getAttribute() {
		for (Attribute* i : this->Signature) {
			if (typeid(T) == typeid(*i)) {
				return dynamic_cast<T&>(*i);
			}
		}
		throw "not in list";
	}
};

std::ostream& operator<<(std::ostream& stream, const Entity& entity);