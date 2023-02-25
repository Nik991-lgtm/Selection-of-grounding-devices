#include "GroundRing.h"

GroundRing::GroundRing(double x, double y, double z, double h) : d(y), D(z), H(h)
{
	specific_density = x;
	name_of_grounding_device = "ground ring";

	if (H == 0)
	{
		resistance_of_grounding_device = (specific_density / ((pow(pi, 2)) * D)) * log((8 * D) / d);
	}

	if (H > 0)
	{
		resistance_of_grounding_device = (specific_density / ((pow(pi, 2)) * D)) * log((4 * D) / sqrt(H * d));
	}
}