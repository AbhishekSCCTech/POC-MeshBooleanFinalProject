#pragma once
#include "Triangulation.h"
#include<vector>


    class MeshOperations
    {
    public:
        MeshOperations();
        ~MeshOperations();

        Geometry::RealPoint AveragePoint(Geometry::RealPoint& p1, Geometry::RealPoint& p2, Geometry::RealPoint& p3);
        //double getAngleBetweenNormalAndXAxis(Geometry::Triangulation& tri, Geometry::Point normal);
        double getAngleBetweenNormalAndXAxis(Geometry::RealPoint normal);

   
    };
