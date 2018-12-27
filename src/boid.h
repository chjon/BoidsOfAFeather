#ifndef BOID_H
#define BOID_H

#include <SFML/Graphics.hpp>

class Boid {
private:
    const float VIEW_DIST = 50;
    const float REQ_VEL = 2;
    const float MAX_ACC = 0.1;

    const float ALIGNMENT_WEIGHT  = 0.3;
    const float COHESION_WEIGHT   = 0.3;
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

    inline sf::Vector2f getPos () { return pos; }
    void update(std::vector<Boid>& candidateNeighbours, int numBoids);
    void bound(int limBot, int limTop, int limLft, int limRgt);
    void draw(sf::RenderWindow& w);
};

#endif
