#include "function.hpp"


void ScalarAdvection::compute_flux(Grid& grid, Quantity& result, std::span<size_t> indices)
{
    auto F_r = static_cast<ScalarQuantity&>(result); 
    auto Qi = grid.get_element(indices[0]);

    F_r[0] = Qi*this->advection_speed;
}

void ScalarAdvection::compute_velocity(Grid& grid, Quantity& result, std::span<size_t> indices)
{
    result[0] = this->advection_speed;
}