#pragma once

#include "GroundingDeviceClass.h"


class EarthingTape : public GroundingDevice
{

	double a;
	double b;
	double l;
	double H;

public:
	EarthingTape(double x, double y, double m, double n, double h);
};
