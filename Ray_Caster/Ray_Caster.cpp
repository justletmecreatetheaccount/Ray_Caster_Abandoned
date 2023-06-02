#include <SFML/Graphics.hpp>
#include "Attributes.h"
#include "Entities.h"

/*
int main()
{
    //Window settings definition
    sf::ContextSettings settings_main;
    settings_main.antialiasingLevel = 8;

    //Window creation
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!", sf::Style::Default, settings_main);
    

    //Test player creations
    Entity Player (Attribute::Physics | Attribute::Sprite );
    Player.spr;
    sf::CircleShape shape(25.f, 3);
    shape.setFillColor(sf::Color::Green);

    //Main loop
    while (window.isOpen())
    {
        //Event handeling loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
*/
int main() {
    Entity Player;
    Player.add_attribute<Vertex>();
    std::cout << Player;
    Player.get_attribute<Vertex>().log_position();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
