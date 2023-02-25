
#include"VerticalRectangularPlate.h"

VerticalRectangularPlate::VerticalRectangularPlate(double x, double y, double z) : a(y), b(z)
{
	specific_density = x;
	name_of_grounding_device = "vertical rectangular plate";
	resistance_of_grounding_device = specific_density / (4 * sqrt(a * b));
}
