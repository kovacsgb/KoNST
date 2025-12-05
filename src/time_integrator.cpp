#include "time_integrator.hpp"

void D1Integrator::operator()()
{
    Quantity y_n;
    Quantity y_np1;
    double t = t0;
    while(t<= t0)
    {
        dt = this->cfl.compute(grid_old,dt);
        for(size_t i=0; i<grid_old.getN(); i++)
        {
            std::array<size_t,1> index = {i};
            std::span<size_t> indices{index};
            y_n.getQuantityFromGrid(grid_old,indices);
            this->time_stepper.advance(y_np1,y_n,dt,indices);
            y_np1.setGridFromQuantity(grid_new,indices);
        }
        t+=dt;
        boundary.apply(grid_new);
        grid_old.update(grid_new);
    }
}


void ForwardTime::advance(Quantity& y_np1,const Quantity& y_n, double dt, std::span<size_t> indices)
{
    this->Fluxcalc(deltaflux,indices);
    deltaflux.multiplyByScalar(deltaflux,dt);
    y_np1.add(y_n,deltaflux);
}