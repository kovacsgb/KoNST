#include "quantity.hpp"
#include<algorithm>
#include<ranges>

double& Quantity::operator[](size_t i)
{
    return this->values[i];
}

    
unsigned long int Quantity::size()
{
    return this->values.size();
}

void Quantity::add(const Quantity& first, const Quantity& second)
{
    std::ranges::transform(first.values,second.values,this->values.begin(),[](const double a, const double b)
    {
        return a+b;
    });
}

void Quantity::substract(const Quantity& first, const Quantity& second)
{
    std::ranges::transform(first.values,second.values,this->values.begin(),[](const double a, const double b)
    {
        return a-b;
    });
}
void Quantity::multiplyByScalar(const Quantity& quantity, const double value)
{
std::ranges::transform(quantity.values,this->values.begin(),[value](const double a)
    {
        return a*value;
    });
}
double& Quantity::operator[](unsigned long int n)
{
    return this->values[n];
}

const double& Quantity::operator[](unsigned long int n) const
{
    return this->values[n];
}

void Quantity::setGridFromQuantity(Grid& grid, std::span<size_t> indices)
{
    for(auto n=0;n<this->size();n++)
    {
        grid.set_element((*this)[n],n,indices);
    }
}

void Quantity::getQuantityFromGrid(Grid& grid, std::span<size_t> indices)
{
    for(auto n=0;n<this->size();n++)
    {
        this->values[n] = grid.get_element(n,indices);
    }
}