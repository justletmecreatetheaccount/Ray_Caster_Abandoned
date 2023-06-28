#pragma once
#include <string>
#include <map>
#include <vector>
#include <typeinfo>
#include <memory>

class Entity {
private :
	static int current_entity_count;
	static std::vector<Entity*> all_entities_ptr;
	int ID;
	std::vector<Attribute*> Signiature;

public:
	Entity() {
		ID = current_entity_count;
		current_entity_count++;
		Entity::all_entities_ptr.push_back(this);
	}

	~Entity() {
		if (!Signiature.empty()) {
			for (Attribute* ptr : Signiature) {
				delete ptr;
			}
		} else {
			// Do nothing cuz that's apparently how you're supposed to do it
		}
		current_entity_count -= 1;
		//
		//
		//all entities list TODO
		//
		//
	}

	const int& getId() const {
		return ID;
	}

	const std::vector<Attribute*>& getSignature() const {
		return Signiature;
	}

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

	static bool updatePhysics() {
		//TODO !!!!! IMPLEMENT BITMAPS
	}
};

int Entity::current_entity_count = 0;
std::vector<Entity*> Entity::all_entities_ptr;

std::ostream& operator<<(std::ostream& stream, const Entity& entity) {
	stream << entity.getId() << " : ";
	for (Attribute* i : entity.getSignature()) {
		stream << *i;
	}
	return stream;
}