#include "grid.hpp"

class BoundaryCondition
{
public:
    virtual void apply(Grid& grid)=0;
};