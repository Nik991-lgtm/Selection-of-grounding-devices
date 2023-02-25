#include "EarthingTape.h"

EarthingTape::EarthingTape(double x, double y, double m, double n, double h) : l(y), a(m), b(n), H(h)
{
	specific_density = x;
	name_of_grounding_device = "earthing tape";

	double d = (2 / pi) * (a + b);

	if (H == 0)
	{
		resistance_of_grounding_device = (specific_density / (pi * l)) * log((2 * l) / d);
	}

	if (H > 0)
	{
		resistance_of_grounding_device = (specific_density / (pi * l)) * log(l / sqrt(H * d));
	}
}