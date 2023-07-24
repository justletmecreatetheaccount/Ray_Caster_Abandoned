#include "./Header_Files/Attributes.hpp"

std::ostream& operator<<(std::ostream& stream, const Attribute& attribute) {
	stream << typeid(attribute).name() << "Owner ID :" << attribute.Owner_ID;
	return stream;
}
