#include <span>
#include <memory>

struct Quantity
{
    virtual  double& operator[](unsigned long int n) = 0;
    virtual unsigned long int size() const = 0;
    virtual ~Quantity() = default;
    
    virtual Quantity& operator+(const Quantity& other) = 0;
    virtual Quantity& operator-(const Quantity& other) = 0;
    virtual Quantity& operator*(double scalar) = 0;
    virtual Quantity& operator/(double scalar) = 0;
};