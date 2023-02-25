#include "GroundRod.h"

GroundRod::GroundRod(double x, double y, double z, double h) : l(y), d(z), H(h)
{
	specific_density = x;
	name_of_grounding_device = "ground rod";

	if (H == 0)
	{
		resistance_of_grounding_device = (specific_density / (2 * pi * l)) * log((4 * l) / d);
	}

	if (H > 0)
	{
		resistance_of_grounding_device = (specific_density / (2 * pi * l)) * (log((2 * l) / d) + 0.5 * log((4 * l + 7 * H) / (l + 7 * H)));
	}
}