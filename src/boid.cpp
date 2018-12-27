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

/**
 * Keep the boid within the bounds of the world by wrapping the boid's position
 */
void Boid::bound(int limBot, int limTop, int limLft, int limRgt) {
    if (pos.x < limLft) {
        pos.x += (float) (limRgt - limLft);
    } else if (pos.x > limRgt) {
        pos.x += (float) (limLft - limRgt);
    }

    if (pos.y < limBot) {
        pos.y += (float) (limTop - limBot);
    } else if (pos.y > limTop) {
        pos.y += (float) (limBot - limTop);
    }
}

void Boid::draw(sf::RenderWindow& w) {
    sf::CircleShape vis(RADIUS);
    vis.setPosition(pos.x - RADIUS / 2, pos.y - RADIUS / 2);
    vis.setFillColor(sf::Color::Green);
    w.draw(vis);
}
