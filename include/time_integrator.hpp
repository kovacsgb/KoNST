#pragma once 
#include "grid.hpp"
#include "cfl.hpp"
#include "boundary.hpp"
#include "function.hpp"
#include "quantity.hpp"
#include "hyperbolic_solver.hpp"

class D1Integrator
{
    private:
        Grid1D& grid_old;
        Grid1D& grid_new;
        TimeIntegratorStep& time_stepper;
        CFLCondition& cfl;
        BoundaryCondition& boundary; 
        
        double dt;
        double t0;
        double t_end;
    public:
        D1Integrator(Grid1D& grid_old, Grid1D& grid_new, TimeIntegratorStep& time_stepper,
                    CFLCondition& cfl_, BoundaryCondition& bound,double dt) :
                    grid_old(grid_old), grid_new(grid_new), time_stepper(time_stepper),
                    cfl(cfl_),boundary(bound), dt(dt)
                    {}
        void operator()();
        Grid1D& getGrid();
    
};


// Abstract base class for time integration steps


class TimeIntegratorStep
{
    protected:
        HyperbolicSolver& Fluxcalc;
        Quantity deltaflux;
    public:
         virtual void advance(Quantity& y_np1,const Quantity& y_n, double dt, std::span<size_t> indices) = 0;
};


class ForwardTime : public TimeIntegratorStep
{
    private:

    public:
    void advance(Quantity& y_np1,const Quantity& y_n, double dt, std::span<size_t> indices) override;
};


