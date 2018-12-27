#ifndef BOID_H
#define BOID_H

#include <SFML/Graphics.hpp>

class Boid {
private:
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f acc;

    float radius = 10;

public:
    Boid();
    Boid(sf::Vector2f pos);
    Boid(sf::Vector2f pos, sf::Vector2f vel);
    ~Boid();

    void update();
    void draw(sf::RenderWindow& w);
};

#endif
