#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "boid.h"
#include "world.h"

int main() {
    const int WIDTH  = sf::VideoMode::getDesktopMode().width;
    const int HEIGHT = sf::VideoMode::getDesktopMode().height;
    const int NUM_BOIDS = 100;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Boids of a feather flock together", sf::Style::None);

    srand(1);

    World world(0, HEIGHT - 1, 0, WIDTH - 1, NUM_BOIDS);

    // Manage main loop delay
    sf::Clock timer;
    sf::Time  delay = sf::seconds(0.01f);

    while (window.isOpen()) {
        // Check whether the window needs to be closed
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update boids
        if (timer.getElapsedTime() >= delay) {
            window.clear();

            world.update();
            world.draw(window);

            window.display();
            timer.restart();
        }
    }

    return 0;
}
