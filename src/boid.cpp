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

// Calculate the average velocity of neighbours
sf::Vector2f Boid::alignment(std::vector<Boid>& candidateNeighbours, int numBoids) {
    int numNeighbours = 0;
    sf::Vector2f avgVel;

    for (int i = 0; i < numBoids; i++) {
        // Boids cannot be their own neighbours
        if (&candidateNeighbours[i] == this) continue;

        sf::Vector2f dist = candidateNeighbours[i].pos - pos;
        float dist2 = dist.x * dist.x + dist.y + dist.y;

        // Boids must be in visible range to be neighbours
        if (dist2 > VIEW_DIST * VIEW_DIST) continue;

        avgVel += candidateNeighbours[i].vel;
        numNeighbours++;
    }

    if (numNeighbours > 0) {
        avgVel.x /= numNeighbours;
        avgVel.y /= numNeighbours;
    }

    return avgVel;
}

/**
 * Update the boid's kinematics vectors
 */
void Boid::update(std::vector<Boid>& candidateNeighbours, int numBoids) {
    pos += vel;
    vel += acc;

    // Normalize velocity
    float velMag = vel.x * vel.x + vel.y * vel.y;
    velMag = std::sqrt(velMag);

    if (velMag != 0) {
        vel.x /= velMag;
        vel.y /= velMag;
    }

    sf::Vector2f desVel;

    desVel += alignment(candidateNeighbours, numBoids);

    acc.x = 0;
    acc.y = 0;

    if (desVel.x != 0 || desVel.y != 0) {
        acc += desVel - vel;
    }

    // Normalize acceleration
    float accMag = acc.x * acc.x + acc.y * acc.y;
    if (accMag > MAX_ACC * MAX_ACC) {
        accMag = std::sqrt(accMag);
        acc.x *= MAX_ACC / accMag;
        acc.y *= MAX_ACC / accMag;
    }
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

/**
 * Draw the boid
 */
void Boid::draw(sf::RenderWindow& w) {
    sf::CircleShape vis(RADIUS);
    vis.setPosition(pos.x - RADIUS / 2, pos.y - RADIUS / 2);
    vis.setFillColor(sf::Color::Green);
    w.draw(vis);
}
