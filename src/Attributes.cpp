#include "./Header_Files/Attributes.hpp"

std::ostream& operator<<(std::ostream& stream, const Attribute& attribute) {
	stream << typeid(attribute).name();
	return stream;
}


Vertex::Vertex(int ID) {
	entity_position = sf::Vector2f(0, 0);
	Owner_ID = ID;
}

void Vertex::logPosition() {
	std::cout << "Enitity " << int(Owner_ID) << " position : (" << entity_position.x << ", " << entity_position.y << ")" << "\n";
}

sf::Vector2f Vertex::setPosition(sf::Vector2f pos) {
	entity_position = pos;
	return entity_position;
}

sf::Vector2f Vertex::updatePosition(sf::Vector2f speed, sf::Time dt) {
	entity_position += speed * dt.asSeconds();
	return entity_position;
}


C_Shape::C_Shape(int ID) {
	Owner_ID = ID;
}

void C_Shape::giveShape(sf::CircleShape* shape) {
	shape_ptr.reset(shape);
	has_shape = true;
}

void C_Shape::linkVertex(Vertex* vertex_ptr) {
	linked_position_ptr.reset(vertex_ptr);
	has_link = true;
}

sf::CircleShape& C_Shape::getShape() {
	return *shape_ptr;
}

bool C_Shape::updatePosition(sf::Vector2f speed, sf::Time dt) {
	if (has_shape) {
		(*shape_ptr).setPosition((*linked_position_ptr).updatePosition(speed, dt));
		return true;
	}
	return false;
}

R_Shape::R_Shape(int ID) {
	Owner_ID = ID;
}

void R_Shape::linkVertex(Vertex* vertex_ptr) {
	linked_position_ptr.reset(vertex_ptr);
	has_link = true;
}

void R_Shape::giveShape(sf::RectangleShape shape) {
	shape_ptr.reset(&shape);
	has_shape = true;
}

sf::RectangleShape& R_Shape::getShape() {
	return *shape_ptr;
}

bool R_Shape::updatePosition(sf::Vector2f speed, sf::Time dt) {
	if (has_shape) {
		(*shape_ptr).setPosition((*linked_position_ptr).updatePosition(speed, dt));
		return true;
	}
	return false;
}

Physics::Physics(int ID) {
	speed = sf::Vector2f(0, 0);
	forces = sf::Vector2f(0, 0);
	mass = 1;
	friction = 0.9;
	Owner_ID = ID;
}

void Physics::updateSpeed(sf::Time dt) {
	speed.x = speed.x + (forces.x / mass) * dt.asSeconds() - friction * speed.x * dt.asSeconds();
	speed.y = speed.y + (forces.y / mass) * dt.asSeconds() - friction * speed.y * dt.asSeconds();
	forces = sf::Vector2f(0, 0);
}