#include "Triangulation.h"
#include "MeshOperations.h"
#include <cmath>
#define M_PI 3.14

using namespace Geometry;

MeshOperations::MeshOperations()
{

}

MeshOperations::~MeshOperations()
{

}



Geometry::RealPoint MeshOperations::AveragePoint(Geometry::RealPoint& p1, Geometry::RealPoint& p2, Geometry::RealPoint& p3) {
  
    double ax = p1.X();
    double ay = p1.Y();
    double az = p1.Z();

    double bx = p2.X();
    double by = p2.Y();
    double bz = p2.Z();

    double cx = p3.X();
    double cy = p3.Y();
    double cz = p3.Z();

    double Avgx = (ax + bx + cx) / 3;
    double Avgy = (ay + by + cy) / 3;
    double Avgz = (az + bz + cz) / 3;

    RealPoint averagePoint(Avgx, Avgy, Avgz);
    return averagePoint;
}


double MeshOperations::getAngleBetweenNormalAndXAxis(Geometry::RealPoint normal) {
    double nx = normal.X();
    double ny = normal.Y();
    double nz = normal.Z();

    double magnitude = std::sqrt(nx * nx + ny * ny + nz * nz);

    double cosTheta = nx / magnitude;
    double angle = std::acos(cosTheta) * (180.0 / M_PI);
    return angle;
}


