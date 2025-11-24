#include "grid.hpp"
class Reconstuction
{

};

class FluxLimiter
{
    public:
    virtual double operator()(Grid& mesh, int indices...) = 0;
};

class AdvectionTermCalculator
{
};

