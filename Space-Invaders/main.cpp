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
        window.clear(sf::Color::Black);

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

        //Drawing a sprite 
        sf::Texture outscal_texture;
        outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

        sf::Sprite outscal_sprite;
        outscal_sprite.setTexture(outscal_texture);

        outscal_sprite.setPosition(500, 200); // Position
        outscal_sprite.setRotation(45); // Rotation in degrees
        outscal_sprite.setScale(0.5, 0.5); // Scale factor

        window.draw(outscal_sprite);

        //Drawing a text
        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text("SFML is Awesome", font, 50);
        text.setFillColor(sf::Color::White);
        window.draw(text);

        //End

        // Display whatever you draw
        window.display();
    }

    return 0;
}
