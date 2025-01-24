#include <math.h>
#include <stdexcept>
#include "QuadraticEquation.h"

std::vector<double> QuadraticEquation::solve(double a, double b, double c)
{
    if (!isfinite(a))
    {
        throw std::invalid_argument("A is not finite number");
    }

    if (!isfinite(b))
    {
        throw std::invalid_argument("B is not finite number");
    }

    if (!isfinite(c))
    {
        throw std::invalid_argument("C is not finite number");
    }
    
    const double epsilon = 0.0000001;

    if (abs(a) < epsilon)
    {
        throw std::invalid_argument("A == 0");
    }
    
    double d = b*b-4*a*c;

    if(abs(d) < epsilon)
    {
        std::vector<double> result { (-1 * b / 2 / a) };
        return result;
    }
    else if (d < 0)
    {
        return std::vector<double>();
    }
    else
    {
        double sqrt_d = sqrt(d);
        std::vector<double> result { ((-1 * b + sqrt_d) / 2 / a), ((-1 * b - sqrt_d) / 2 / a) };
        return result;
    }
}