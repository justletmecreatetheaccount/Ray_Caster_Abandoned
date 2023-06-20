#include <SFML/Graphics.hpp>
#include "Attributes.h"
#include "Entities.h"
#include<SFML/System/Clock.hpp>

int main()
{
    //Window settings definition
    sf::ContextSettings settings_main;
    settings_main.antialiasingLevel = 8;

    //Window creation
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!", sf::Style::Default, settings_main);

    sf::Clock clock;

    //Test player creations
    Entity Player;
    int mov_spd = 10000;
    Player.addAttribute<Vertex>();
    Player.addAttribute<Physics>();
    Player.addAttribute<C_Shape>();
    Player.getAttribute<C_Shape>().giveShape(new sf::CircleShape(25.f, 3));
    Player.getAttribute<C_Shape>().getShape().setFillColor(sf::Color::Green);
    Player.getAttribute<C_Shape>().linkVertex(&Player.getAttribute<Vertex>());

    //Main loop
    while (window.isOpen())
    {
        //Event handeling loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed :
                window.close();
                break;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                Player.getAttribute<Physics>().forces += sf::Vector2f(0, -mov_spd);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                Player.getAttribute<Physics>().forces += sf::Vector2f(0, mov_spd);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                Player.getAttribute<Physics>().forces += sf::Vector2f(-mov_spd, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                Player.getAttribute<Physics>().forces += sf::Vector2f(mov_spd, 0);
            }
        }

        //Update Objects
        sf::Time elapsed_btwn_frames = clock.getElapsedTime();

        Player.getAttribute<Physics>().updateSpeed(elapsed_btwn_frames);
        Player.getAttribute<C_Shape>().updatePosition(Player.getAttribute<Physics>().speed, elapsed_btwn_frames);

        clock.restart();

        //Update Window
        window.clear();
        window.draw(Player.getAttribute<C_Shape>().getShape());
        window.display();

    }

    return 0;
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
