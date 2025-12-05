#pragma once 
#include "grid.hpp"
#include "quantity.hpp"
#include "time_integrator.hpp"

class HyperbolicSolver
{
protected: 
    TimeIntegratorStep& TimeInt;
    Grid& grid;
    EquationBase& eq_system;
public:
    HyperbolicSolver(/* args */) =default;
    virtual ~HyperbolicSolver() = 0;

    virtual void operator()(Quantity& delta_F, std::span<size_t> indices) = 0;
};


class UpwindMethod : public HyperbolicSolver
{
    public:
    void operator()(Quantity& delta_F,std::span<size_t> indices);
};

class Reconstuction;

class FluxLimiter
{
    public:
    virtual double operator()(Grid& mesh, int indices...) = 0;
};



