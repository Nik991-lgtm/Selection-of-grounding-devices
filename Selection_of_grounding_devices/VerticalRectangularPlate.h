#pragma once

#include "GroundingDeviceClass.h"

class VerticalRectangularPlate : public GroundingDevice
{

	double a;
	double b;

public:
	VerticalRectangularPlate(double x, double y, double z);
};
