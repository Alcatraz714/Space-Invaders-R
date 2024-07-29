#include <SFML/Graphics.hpp>

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "My SFML Window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window---
        window.clear(sf::Color::Magenta);

        //Start

        // Draw a circle
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(100, 100); // Set position
        window.draw(circle);

        //Draw a Red Square
        sf::RectangleShape square(sf::Vector2f(50, 50));
        square.setFillColor(sf::Color::Red);
        square.setPosition(200, 200); // Set position
        window.draw(square);

        //Draw a Blue Triangle
        sf::CircleShape Triangle(50, 3);
        Triangle.setFillColor(sf::Color::Blue);
        Triangle.setPosition(300, 300); // Set position
        window.draw(Triangle);

        //End

        // Display whatever you draw
        window.display();
    }

    return 0;
}
