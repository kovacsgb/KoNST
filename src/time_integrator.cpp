#include "time_integrator.hpp"

void D1Integrator::operator()()
{
    
}


double ForwardTime::advance(double yn, double dt)
{
    return yn + dt * yn;
}