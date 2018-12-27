#ifndef VECTOR_UTIL_H
#define VECTOR_UTIL_H

#include <SFML/Graphics.hpp>
#include <cmath>

class VectorUtil {
private:
    static constexpr float PI = std::atan(1.0) * 4;
    static constexpr float DEG_TO_RAD = PI / 180.f;
    static constexpr float RAD_TO_DEG = 180.f / PI;

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

    static inline float getAngle (const sf::Vector2f vec) {
        if (vec.x == 0 && vec.y == 0) return 0/0.;
        if (vec.x == 0) {
            if (vec.y > 0) {
                return PI / 2;
            } else {
                return -PI / 2;
            }
        }

        float a = std::atan(vec.y / vec.x);
        if (vec.x > 0) {
            return a;
        } else {
            return PI + a;
        }
    }

    static inline float getAngleDegrees (sf::Vector2f vec) {
        return getAngle(vec) * RAD_TO_DEG;
    }
};

#endif // VECTOR_UTIL_H
