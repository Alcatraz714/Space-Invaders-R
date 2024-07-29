#include <iostream>
#include <SFML/Graphics.hpp>


class Player
{
private:

    // Private Properties
    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int movement_speed = 5;
    int player_score = 0;

public:

    // Public Properties
    sf::Texture player_texture;
    sf::Sprite player_sprite;

    //Public Getter & Setter methods
    int getScore() {
        return player_score;
    };

    void setScore(int newScore) {
        player_score = newScore;
    };

    //New methods
    void takeDamage() {};
    void move() {};
    void shootBullets() {};
};

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

        Player player;

        // Display whatever you draw
        window.display();
    }

    return 0;
}
