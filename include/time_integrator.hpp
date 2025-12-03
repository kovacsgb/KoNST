#include "grid.hpp"
#include "function.hpp"

class D1Integrator
{
    private:
        Grid1D& grid_old;
        Grid1D& grid_new;
        TimeIntegratorStep& time_stepper;
        
        double dt;
        double t0;
        double t_end;
    public:
        D1Integrator(Grid1D& grid_old, Grid1D& grid_new, TimeIntegratorStep& time_stepper, double dt) :
        grid_old(grid_old), grid_new(grid_new), time_stepper(time_stepper), dt(dt)
        {}
        void operator()();
    
};


// Abstract base class for time integration steps


class TimeIntegratorStep
{
    public:
    virtual double advance(double yn, double dt) = 0;
};


class ForwardTime : public TimeIntegratorStep
{
    private:

    public:
    double advance(double yn, double dt) override;
};


