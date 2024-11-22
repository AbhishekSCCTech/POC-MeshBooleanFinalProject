#pragma once
#include <vector>
#include "point.h"
#include "RealPoint.h"



namespace Geometry
{
    class Triangle
    {
        // Three points representing the vertices of the triangle
    private:
        Point p1;
        Point p2;
        Point p3;
        Point normal;

    public:
        Triangle(Point normal, Point p1, Point p2, Point p3);
        ~Triangle();

        // Getter functions to access the private members 
        Point P1();
        Point P2();
        Point P3();
        Point Normal();

        std::vector<Point> Points();
        RealPoint triangleCentroid(RealPoint& p1, RealPoint& p2, RealPoint& p3);
        bool operator==(const Triangle& other) const;
        

    };
}