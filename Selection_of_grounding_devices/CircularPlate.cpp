#include "CircularPlate.h"

CircularPlate::CircularPlate(double x, double y, double h) : D(y), H(h)
{
	specific_density = x;
	name_of_grounding_device = "vertical rectangular plate";

	if (H == 0)
	{
		resistance_of_grounding_device = specific_density / (2 * D);
	}

	if (H > 0)
	{

		resistance_of_grounding_device = (specific_density / (4 * D)) * (1 + (2 / pi) * (pi / 2 - atan(D / (4 * H))));
	}
}