#pragma once

#include"GroundingDeviceClass.h"

class HemisphericalGroundingElectrode : public GroundingDevice
{
	double D;

public:
	HemisphericalGroundingElectrode(double x, double y);
};
