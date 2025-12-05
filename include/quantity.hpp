#include <span>
#include <memory>
#include <vector>
#pragma once
/** \class Quantity
 *  \brief A class that defines an abstract interface for value manipulation
 * 
 *  Every Equation object should define its Quantity that is working on. This
 *  would be nicer with double dispatch, but we want to reduce abstraction o-
 *  verhead without using templates.
 */
struct Quantity
{
    std::vector<double> values;


    virtual double& operator[](unsigned long int n);
    virtual const double& operator[](unsigned long int n) const;
    virtual unsigned long int size();
    virtual ~Quantity() = default;

    virtual void add(const Quantity& first, const Quantity& second);
    virtual void substract(const Quantity& first, const Quantity& second);
    virtual void multiplyByScalar(const Quantity& quantity, const double value);

    /*
    virtual Quantity& operator+(const Quantity& other) = 0;
    virtual Quantity& operator-(const Quantity& other) = 0;
    virtual Quantity& operator*(double scalar) = 0;
    virtual Quantity& operator/(double scalar) = 0;*/
};


struct ScalarQuantity : public Quantity
{
    ScalarQuantity() : Quantity()
    {
        this->values.resize(1);
    }
};