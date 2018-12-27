#ifndef VECTOR_UTIL_H
#define VECTOR_UTIL_H

#include <SFML/Graphics.hpp>

class VectorUtil {
public:
    static inline float mag2 (const sf::Vector2f vec) {
        return vec.x * vec.x + vec.y * vec.y;
    }

    static inline float mag (const sf::Vector2f vec) {
        return std::sqrt(mag2(vec));
    }

    static inline sf::Vector2f normalize (const sf::Vector2f vec) {
        float mag_ = mag(vec);
        if (mag_ != 0) {
            return vec / mag_;
        }

        return vec;
    }
};

#endif // VECTOR_UTIL_H
