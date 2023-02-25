#include "HemisphericalGroundingElectrode.h"

HemisphericalGroundingElectrode::HemisphericalGroundingElectrode(double x, double y) : D(y)
{
	specific_density = x;
	name_of_grounding_device = "hemispherical grounding electrode";
	resistance_of_grounding_device = specific_density / (pi * D);
};