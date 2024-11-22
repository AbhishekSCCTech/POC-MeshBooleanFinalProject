#include "TransformationManager.h"
#include "Triangulation.h"
using namespace Geometry;

TransformationManager::TransformationManager()
{

}

TransformationManager::~TransformationManager()
{

}

std::vector<Triangulation> TransformationManager::transformObject(std::vector<Triangulation>& triangulation)
{
    Triangulation translationTriangulation;
    Triangulation rotationTriangulation;
    Triangulation reverseRotationTriangulation;
    Triangulation reverseTranslationTriangulation;

    Triangulation translationTriangulation2;
    Triangulation rotationTriangulation2;
    Triangulation reverseRotationTriangulation2;
    Triangulation reverseTranslationTriangulation2;

    Triangle triangle1 = triangulation[0].Triangles[0];
    Triangle triangle2 = triangulation[1].Triangles[0];#include "TransformationManager.h"
#include "Triangulation.h"
using namespace Geometry;

TransformationManager::TransformationManager()
{

}

TransformationManager::~TransformationManager()
{

}

std::vector<Triangulation> TransformationManager::transformObject(std::vector<Triangulation>& triangulation)
{
    //load file one object triangulation
    Triangulation translationTriangulationOne;
    Triangulation rotationTriangulationOne;
    Triangulation reverseRotationTriangulationOne;
    Triangulation reverseTranslationTriangulationOne;

    //load file two object triangulation
    Triangulation translationTriangulationTwo;
    Triangulation rotationTriangulationTwo;
    Triangulation reverseRotationTriangulationTwo;
    Triangulation reverseTranslationTriangulationTwo;

    Triangle triangle1 = triangulation[0].Triangles[0];
    Triangle triangle2 = triangulation[1].Triangles[0];

    Point firstNormalPoint = triangle1.Normal();
    RealPoint firstNormal = triangulation[0].getRealPoint(firstNormalPoint);

    Point secondNormalPoint = triangle2.Normal();
    RealPoint secondNormal = triangulation[1].getRealPoint(secondNormalPoint);

    // Compute the angles between specific triangle normal and the X-axis
    double angle1 = vectorUtility.angleWithXAxis(firstNormal);
    double angle2 = vectorUtility.angleWithXAxis(secondNormal);


    // First Triangle avgerage
    Point firstTriangleP1 = triangle1.P1();
    Point firstTriangleP2 = triangle1.P2();
    Point firstTriangleP3 = triangle1.P3();
    //RealPoint of First Triangle avgerage
    RealPoint firstRealPoint1 = triangulation[0].getRealPoint(firstTriangleP1);
    RealPoint firstRealPoint2 = triangulation[0].getRealPoint(firstTriangleP2);
    RealPoint firstRealPoint3 = triangulation[0].getRealPoint(firstTriangleP3);
    RealPoint avgFirstTriangle = triangle1.triangleCentroid(firstRealPoint1, firstRealPoint2, firstRealPoint3);
  
    translationTriangulationOne = transformation.translation(triangulation[0], -(avgFirstTriangle.X()), -(avgFirstTriangle.Y()), -(avgFirstTriangle.Z()));
    rotationTriangulationOne = transformation.rotationX(translationTriangulationOne, -angle1);

    // Second Triangle average
    Point secondTriangleP1 = triangle2.P1();
    Point secondTriangleP2 = triangle2.P2();
    Point secondTriangleP3 = triangle2.P3();
    //RealPoint of Second Triangle average
    RealPoint secondRealPoint1 = triangulation[1].getRealPoint(secondTriangleP1);
    RealPoint secondRealPoint2 = triangulation[1].getRealPoint(secondTriangleP2);
    RealPoint secondRealPoint3 = triangulation[1].getRealPoint(secondTriangleP3);
    RealPoint avgSecondTriangle = triangle2.triangleCentroid(secondRealPoint1, secondRealPoint2, secondRealPoint3);


    translationTriangulationTwo = transformation.translation(triangulation[1], -(avgSecondTriangle.X()), -(avgSecondTriangle.Y()), -(avgSecondTriangle.Z()));
    rotationTriangulationTwo = transformation.rotationX(translationTriangulationTwo, -angle2);
    
    // Apply reverse rotation to restore the original orientation
    reverseRotationTriangulationOne = transformation.rotationX(translationTriangulationOne, angle1);
    reverseRotationTriangulationTwo = transformation.rotationX(translationTriangulationTwo, angle1);

    // Apply reverse translation to restore the original position
    reverseTranslationTriangulationOne = transformation.translation(reverseRotationTriangulationOne, (avgFirstTriangle.X()), (avgFirstTriangle.Y()), (avgFirstTriangle.Z()));
    reverseTranslationTriangulationTwo = transformation.translation(reverseRotationTriangulationTwo, (avgFirstTriangle.X()), (avgFirstTriangle.Y()), (avgFirstTriangle.Z()));


    std::vector<Triangulation> resultTriangulation;
    resultTriangulation.push_back(reverseTranslationTriangulationOne);
    resultTriangulation.push_back(reverseTranslationTriangulationTwo);

    return resultTriangulation;
}





    Point firstNormalPoint = triangle1.Normal();
    RealPoint firstNormal = triangulation[0].getRealPoint(firstNormalPoint);

    Point secondNormalPoint = triangle2.Normal();
    RealPoint secondNormal = triangulation[1].getRealPoint(secondNormalPoint);


    double angle1 = mesh.getAngleBetweenNormalAndXAxis(firstNormal);
    double angle2 = mesh.getAngleBetweenNormalAndXAxis(secondNormal);


    // First Triangle avg
    Point firstTriangleP1 = triangle1.P1();
    Point firstTriangleP2 = triangle1.P2();
    Point firstTriangleP3 = triangle1.P3();
    //RealPoint of First Triangle avg
    RealPoint firstRealPoint1 = triangulation[0].getRealPoint(firstTriangleP1);
    RealPoint firstRealPoint2 = triangulation[0].getRealPoint(firstTriangleP2);
    RealPoint firstRealPoint3 = triangulation[0].getRealPoint(firstTriangleP3);
    Geometry::RealPoint avgFirstTriangle = mesh.averagePoint(firstRealPoint1, firstRealPoint2, firstRealPoint3);
  
    translationTriangulation = t.translation(triangulation[0], -(avgFirstTriangle.X()), -(avgFirstTriangle.Y()), -(avgFirstTriangle.Z()));
    rotationTriangulation = t.rotationX(translationTriangulation, -angle1);

    // Second Triangle average
    Point secondTriangleP1 = triangle2.P1();
    Point secondTriangleP2 = triangle2.P2();
    Point secondTriangleP3 = triangle2.P3();
    //RealPoint of Second Triangle average
    RealPoint secondRealPoint1 = triangulation[1].getRealPoint(secondTriangleP1);
    RealPoint secondRealPoint2 = triangulation[1].getRealPoint(secondTriangleP2);
    RealPoint secondRealPoint3 = triangulation[1].getRealPoint(secondTriangleP3);
    Geometry::RealPoint avgSecondTriangle = mesh.averagePoint(secondRealPoint1, secondRealPoint2, secondRealPoint3);


    translationTriangulation2 = t.translation(triangulation[1], -(avgSecondTriangle.X()), -(avgSecondTriangle.Y()), -(avgSecondTriangle.Z()));
    rotationTriangulation2 = t.rotationX(translationTriangulation2, -angle2);
    
    reverseRotationTriangulation = t.rotationX(translationTriangulation, angle1);
    reverseRotationTriangulation2 = t.rotationX(translationTriangulation2, angle1);

    reverseTranslationTriangulation = t.translation(reverseRotationTriangulation, (avgFirstTriangle.X()), (avgFirstTriangle.Y()), (avgFirstTriangle.Z()));
    reverseTranslationTriangulation2 = t.translation(reverseRotationTriangulation2, (avgFirstTriangle.X()), (avgFirstTriangle.Y()), (avgFirstTriangle.Z()));
    std::vector<Triangulation> resultTriangulation;
    resultTriangulation.push_back(reverseTranslationTriangulation);
    resultTriangulation.push_back(reverseTranslationTriangulation2);

    return resultTriangulation;
}
