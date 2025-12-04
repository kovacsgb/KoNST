#include "grid.hpp"
#include "quantity.hpp"


class EquationBase
{
    public:
    virtual void compute_flux(Grid& grid, Quantity& result)=0;
    virtual void compute_velocity(Grid& grid, Quantity& result)=0;
};



class ScalarAdvection : public EquationBase
{
    private:
        double advection_speed;
    public:
        ScalarAdvection(double advection_speed) : advection_speed(advection_speed) {}
        void compute_flux(Grid& grid, Quantity& result) override;
        void compute_velocity(Grid& grid, Quantity& result) override;
};
