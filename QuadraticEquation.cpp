#include <math.h>
#include "QuadraticEquation.h"

std::vector<double> QuadraticEquation::solve(double a, double b, double c)
{
    const double epsilon = 0.0000001;
    
    double d = b*b-4*a*c;

    if(abs(d) < epsilon)
    {
        vector<double> result { (-1 * b / 2 / a) };
        return result;
    }
    else if (d < 0)
    {
        return vector<double>();
    }
    else
    {
        double sqrt_d = sqrt(d);
        vector<double> result { ((-1 + sqrt_d) * b / 2 / a), ((-1 - sqrt_d) * b / 2 / a) };
        return result;
    }
}