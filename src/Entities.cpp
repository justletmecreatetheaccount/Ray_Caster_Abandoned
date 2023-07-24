#include "./Header_Files/Entities.hpp"
#include "./Header_Files/Attributes.hpp"
#include <bitset>

Entity::Entity(){
		ID = current_entity_count;
		current_entity_count++;
		all_entities_ptr.push_back(this);
		all_entities_signature.push_back(std::bitset<Attribute::NUMBER_OF_ATTRIBUTES>());
	}

Entity::~Entity() {
		if (!Signature.empty()) {
			for (Attribute* ptr : Signature) {
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
const int& Entity::getId() const {
	return ID;
}

const std::vector<Attribute*>& Entity::getSignature() const {
	return Signature;
}

int Entity::current_entity_count = 0;
std::vector<Entity*> Entity::all_entities_ptr;
std::vector<std::bitset<Attribute::NUMBER_OF_ATTRIBUTES>> Entity::all_entities_signature;

std::ostream& operator<<(std::ostream& stream, const Entity& entity) {
	stream << entity.getId() << " : ";
	for (Attribute* i : entity.getSignature()) {
		stream << *i;
	}
	return stream;
}