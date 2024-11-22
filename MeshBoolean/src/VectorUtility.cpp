#include "VectorUtility.h"
#include <cmath>
#define M_PI 3.14
using namespace Geometry;

VectorUtility::VectorUtility()
{
}

VectorUtility::~VectorUtility()
{
}

double VectorUtility::angleWithXAxis(RealPoint& normal)
{
    double nx = normal.X();
    double ny = normal.Y();
    double nz = normal.Z();

    double magnitude = std::sqrt(nx * nx + ny * ny + nz * nz);

    // Calculate the cosine of the angle using the dot product with the x-axis
    double cosTheta = nx / magnitude;

    // Compute the angle in radians, then convert it to degrees
    double angle = std::acos(cosTheta) * (180.0 / M_PI);
    return angle;
}


