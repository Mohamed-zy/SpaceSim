
#include "../src/Gravity.hpp"

#include <iostream>
#include <cmath>
#include <stdexcept>

void require(bool condition, const char* message) {
    if (!condition) {
        throw std::runtime_error(message);
    }
}

int main() {
    constexpr double sunMass = 1.989e30;
    constexpr double earthMass = 5.972e24;
    constexpr double distance = 1.496e11;

    std::vector<Body> bodies = {
        {sunMass, {0, 0, 0}, {0, 0, 0}},
        {earthMass, {distance, 0, 0}, {0, 0, 0}}
    };

    auto a = Gravity::calculateAccelerations(bodies);

    double expectedEarthAcceleration =
        Gravity::G * sunMass / (distance * distance);

    require(a[1].x < 0,
            "Earth must accelerate toward the Sun.");

    require(std::abs(a[1].y) < 1e-15 &&
            std::abs(a[1].z) < 1e-15,
            "Unexpected acceleration direction.");

    require(
        std::abs(a[1].x + expectedEarthAcceleration)
            < expectedEarthAcceleration * 1e-10,
        "Earth acceleration does not match Newton's law."
    );

    require(a[0].x > 0,
            "The Sun must accelerate toward the Earth.");

    std::cout << "Earth acceleration: "
              << a[1].x << " m/s^2\n";

    std::cout << "Sun acceleration: "
              << a[0].x << " m/s^2\n";

    std::cout << "Gravity test passed.\n";

    return 0;
}
