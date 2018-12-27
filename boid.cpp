#include "boid.h"

Boid::Boid() :
    pos{sf::Vector2f(0, 0)},
    vel{sf::Vector2f(0, 0)},
    acc{sf::Vector2f(0, 0)}{

}

Boid::Boid(sf::Vector2f pos_) :
    pos{pos_},
    vel{sf::Vector2f(0, 0)},
    acc{sf::Vector2f(0, 0)}
{

}

Boid::Boid(sf::Vector2f pos_, sf::Vector2f vel_) :
    pos{pos_},
    vel{vel_},
    acc{sf::Vector2f(0, 0)} {

}

Boid::~Boid() {

}

void Boid::update() {
    pos += vel;
    vel += acc;
}

void Boid::draw(sf::RenderWindow& w) {
    sf::CircleShape vis(radius);
    vis.setPosition(pos);
    vis.setFillColor(sf::Color::Green);
    w.draw(vis);
}
