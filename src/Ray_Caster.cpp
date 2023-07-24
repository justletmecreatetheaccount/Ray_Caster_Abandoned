#include "./Header_Files/Attributes.hpp"
#include "./Header_Files/Custom_Attributes.hpp"
#include "./Header_Files/Entities.hpp"
#include <SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <future>
#include <iostream>

int main()
{
    std::cout<<"Started ...\n";

    /*
    cv::Mat image = cv::imread("C:/Users/vladd/OneDrive/Images/821995c.jpg", cv::IMREAD_COLOR);
    // Error Handling
    if (image.empty()) {
        std::cout << "Image File "
             << "Not Found" << std::endl;
  
        // wait for any key press
        std::cin.get();
        return -1;
    }

    // Show Image inside a window with
    // the name provided
    cv::imshow("Window Name", image);
    cv::waitKey(0);
    */

    std::string image_path = "C:/Users/vladd/OneDrive/Images/821995c.jpg";
    cv::Mat img = imread(image_path, cv::IMREAD_COLOR);

    imshow("Display window", img);
    int k = cv::waitKey(0);

    //Window settings definition
    sf::ContextSettings settings_main;
    settings_main.antialiasingLevel = 8;

    //Window creation
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!", sf::Style::Default, settings_main);

    sf::Clock clock;

    //Test player creations
    Entity Player;
    int mov_spd = 100;

    Player.addAttribute<DynamicObject>(10, sf::Vector2f(), 1000);
    Player.addAttribute<CircleShape>(25.0, 3);
    Player.getAttribute<DynamicObject>().linkShape(Player.getAttribute<CircleShape>());
    //Main loop
    while (window.isOpen())
    {
        //Event handeling loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                Player.getAttribute<DynamicObject>().speed.y += -mov_spd;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                Player.getAttribute<DynamicObject>().speed.y += mov_spd;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                Player.getAttribute<DynamicObject>().speed.x += -mov_spd;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                Player.getAttribute<DynamicObject>().speed.x += mov_spd;
            }
        }

        //Update Objects
        sf::Time elapsed_btwn_frames = clock.getElapsedTime();
        
        Player.getAttribute<DynamicObject>().updateObject(elapsed_btwn_frames.asSeconds());

        clock.restart();

        //Update Window
        window.clear();
        window.draw(Player.getAttribute<CircleShape>());
        window.display();

    }

    return 0;
}
