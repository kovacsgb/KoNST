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