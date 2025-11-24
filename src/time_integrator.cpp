#include "time_integrator.hpp"


double ForwardTime::advance(double yn, double dt)
{
    return yn + dt * yn;
}