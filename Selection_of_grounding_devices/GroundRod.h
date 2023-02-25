#pragma once

#include "GroundingDeviceClass.h"

class GroundRod : public GroundingDevice
{
	double l;
	double d;
	double H;
public:
	GroundRod(double x, double y, double z, double h);
};

