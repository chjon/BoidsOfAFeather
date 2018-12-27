#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "boid.h"

class World {
private:
    int limBot;
    int limTop;
    int limLft;
    int limRgt;
    int numBoids;
    std::vector<Boid> boids;

public:
    World(int limBot, int limTop, int limLft, int limRgt, int numBoids);
    ~World();

    void update();
    void draw(sf::RenderWindow& window);
};

#endif
