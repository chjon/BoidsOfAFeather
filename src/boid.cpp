#include "boid.h"
#include "vectorUtil.h"

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

sf::Vector2f Boid::steer(std::vector<Boid>& candidateNeighbours, int numBoids) {
    int numNeighbours = 0;

    sf::Vector2f avgDis;
    sf::Vector2f avgPos;
    sf::Vector2f avgVel;

    // Calculate the average velocity of neighbours
    for (int i = 0; i < numBoids; i++) {
        // Boids cannot be their own neighbours
        if (&candidateNeighbours[i] == this) continue;

        float dist2 = VectorUtil::mag2(candidateNeighbours[i].pos - pos);

        // Boids must be in visible range to be neighbours
        if (dist2 > VIEW_DIST * VIEW_DIST) continue;

        avgDis += candidateNeighbours[i].pos - pos;
        avgPos += candidateNeighbours[i].pos;
        avgVel += candidateNeighbours[i].vel;
        numNeighbours++;
    }

    if (numNeighbours > 0) {
        avgPos.x /= numNeighbours;
        avgPos.y /= numNeighbours;

        avgVel.x /= numNeighbours;
        avgVel.y /= numNeighbours;
    } else {
        avgPos = pos;
    }

    sf::Vector2f alignmentVel  = ALIGNMENT_WEIGHT  * VectorUtil::normalize(avgVel);
    sf::Vector2f cohesionVel   = COHESION_WEIGHT   * VectorUtil::normalize(avgPos - pos);
    sf::Vector2f separationVel = SEPARATION_WEIGHT * VectorUtil::normalize(-avgDis);

    return alignmentVel + cohesionVel + separationVel;
}

/**
 * Update the boid's kinematics vectors
 */
void Boid::update(std::vector<Boid>& candidateNeighbours, int numBoids) {
    pos += vel;
    vel += acc;

    vel = REQ_VEL * VectorUtil::normalize(vel);
    acc = MAX_ACC * VectorUtil::normalize(steer(candidateNeighbours, numBoids));
}

/**
 * Keep the boid within the bounds of the world by wrapping the boid's position
 */
void Boid::bound(int limBot, int limTop, int limLft, int limRgt) {
    if (pos.x < limLft) {
        pos.x += limRgt - limLft;
    } else if (pos.x > limRgt) {
        pos.x += limLft - limRgt;
    }

    if (pos.y < limBot) {
        pos.y += limTop - limBot;
    } else if (pos.y > limTop) {
        pos.y += limBot - limTop;
    }
}

/**
 * Draw the boid
 */
void Boid::draw(sf::RenderWindow& w) {
    sf::ConvexShape b;
    b.setPointCount(3);
    b.setPoint(0, sf::Vector2f(0.f, 5.f));
    b.setPoint(1, sf::Vector2f(20.f, 0.f));
    b.setPoint(2, sf::Vector2f(0.f, -5.f));

    b.setPosition(pos.x, pos.y);

    // Draw the boid's acceleration vector
    b.setRotation(VectorUtil::getAngleDegrees(acc));
    b.setFillColor(sf::Color::Red);

    w.draw(b);

    // Draw the boid
    b.setRotation(VectorUtil::getAngleDegrees(vel));
    b.setFillColor(sf::Color::Green);

    w.draw(b);
}
