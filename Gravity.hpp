
#pragma once

#include "Body.hpp"

#include <vector>
#include <stdexcept>
#include <cmath>

namespace Gravity {

    constexpr double G = 6.67430e-11;

    std::vector<Vec3> calculateAccelerations(
        const std::vector<Body>& bodies
    ) {
        std::vector<Vec3> accelerations(bodies.size());

        for (std::size_t i = 0; i < bodies.size(); ++i) {
            for (std::size_t j = 0; j < bodies.size(); ++j) {

                if (i == j) {
                    continue;
                }

                Vec3 r =
                    bodies[j].position - bodies[i].position;

                double distanceSquared = r.normSquared();

                if (distanceSquared == 0.0) {
                    throw std::runtime_error(
                        "Two bodies occupy the same position."
                    );
                }

                double distance =
                    std::sqrt(distanceSquared);

                double factor =
                    G * bodies[j].mass /
                    (distanceSquared * distance);

                accelerations[i] =
                    accelerations[i] + r * factor;
            }
        }

        return accelerations;
    }

}
