#include "world.h"

World::World(int limBot_, int limTop_, int limLft_, int limRgt_, int numBoids_) :
    limBot{limBot_},
    limTop{limTop_},
    limLft{limLft_},
    limRgt{limRgt_},
    numBoids{std::max(0, numBoids_)}
{
    if (limBot > limTop) {
        std::swap(limBot, limTop);
    }

    if (limLft > limRgt) {
        std::swap(limLft, limRgt);
    }

    for (int i = 0; i < numBoids; i++) {
        boids.push_back(Boid(
            sf::Vector2f(rand() % (limRgt - limLft + 1), rand() % (limTop - limBot + 1)),
            sf::Vector2f(rand() / (float) RAND_MAX - 0.5, rand() / (float) RAND_MAX - 0.5)
        ));
    }
}

World::~World() {

}

void World::update() {
    for (int i = 0; i < numBoids; i++) {
        boids[i].update();
    }
}

void World::draw(sf::RenderWindow& window) {
    for (int i = 0; i < numBoids; i++) {
        boids[i].draw(window);
    }
}
