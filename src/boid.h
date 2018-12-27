#ifndef BOID_H
#define BOID_H

#include <SFML/Graphics.hpp>

class Boid {
private:
    const float RADIUS = 5;
    const float VIEW_DIST = 25;
    const float REQ_VEL = 0.5;
    const float MAX_ACC = 0.05;

    const float ALIGNMENT_WEIGHT  = 0.5;
    const float COHESION_WEIGHT   = 0.35;
    const float SEPARATION_WEIGHT = 0.4;

    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f acc;

    sf::Vector2f steer (std::vector<Boid>& candidateNeighbours, int numBoids);

public:
    Boid();
    Boid(sf::Vector2f pos);
    Boid(sf::Vector2f pos, sf::Vector2f vel);
    ~Boid();

    void update(std::vector<Boid>& candidateNeighbours, int numBoids);
    void bound(int limBot, int limTop, int limLft, int limRgt);
    void draw(sf::RenderWindow& w);
};

#endif
