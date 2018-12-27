#ifndef BOID_H
#define BOID_H

#include <SFML/Graphics.hpp>

class Boid {
private:
    const float RADIUS = 5;

    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f acc;

public:
    Boid();
    Boid(sf::Vector2f pos);
    Boid(sf::Vector2f pos, sf::Vector2f vel);
    ~Boid();

    void update();
    void bound(int limBot, int limTop, int limLft, int limRgt);
    void draw(sf::RenderWindow& w);
};

#endif
