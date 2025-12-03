#include "grid.hpp"


class CFLCondition
{
public:
    virtual double compute(const Grid& grid, double dt) = 0;
};