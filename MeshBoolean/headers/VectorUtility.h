#pragma once
#include "RealPoint.h"
using namespace Geometry;

    class VectorUtility
    {
    public:
        VectorUtility();
        ~VectorUtility();

        double angleWithXAxis(RealPoint& normal);
    };
