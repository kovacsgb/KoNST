#include "grid.hpp"

class EquationBase
{
    public:
    virtual void compute_flux(Grid& grid, size_t n)=0;
    virtual void compute_velocity(Grid& grid, size_t n)=0;
};



class ScalarAdvection : public EquationBase
{
    private:
        double advection_speed;
    public:
        ScalarAdvection(double advection_speed) : advection_speed(advection_speed) {}
        void compute_flux(Grid& grid, size_t n) override;
        void compute_velocity(Grid& grid, size_t n) override;
};
