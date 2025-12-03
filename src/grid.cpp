#include "grid.hpp"



Grid::~Grid(){}


void Grid1D::set_element(double value, int indices...)
{
    va_list args;
    va_start(args, indices);
    int i = indices;
    mesh[i + N_ghost] = value;
    va_end(args);
}

double Grid1D::get_element(int indices...) const
{
    va_list args;
    va_start(args, indices);
    int i = indices;
    double value = mesh[i + N_ghost];
    va_end(args);
    return value;
}

void Grid1D::update(Grid& new_grid)
{
    Grid1D& new_grid_1d = static_cast<Grid1D&>(new_grid);
    this->mesh = new_grid_1d.mesh;
}