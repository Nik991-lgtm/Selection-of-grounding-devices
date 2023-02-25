#pragma once

#include "GroundingDeviceClass.h"

class CircularPlate : public GroundingDevice
{
	double D;
	double H;

public:
	CircularPlate(double x, double y, double h);

};
