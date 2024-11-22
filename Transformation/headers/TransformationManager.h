#pragma once
#include "Triangulation.h"
#include "Transformation.h"
#include "VectorUtility.h"
using namespace Geometry;


class TransformationManager
{
public:
	TransformationManager();
	~TransformationManager();
	VectorUtility vectorUtility;
	Transformation::Transformation transformation;
	std::vector<Triangulation> transformObject(std::vector<Triangulation>& triangulation);
};
