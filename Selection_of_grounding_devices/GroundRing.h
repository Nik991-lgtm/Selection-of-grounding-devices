#pragma once

#include "GroundingDeviceClass.h"

class GroundRing : public GroundingDevice
{
	double d;
	double D;
	double H;

public:
	GroundRing(double x, double y, double z, double h);
};
