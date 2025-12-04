#include <span>
#include <memory>
#include <vector>

struct Quantity
{
    std::vector<double> values;


    virtual  double& operator[](unsigned long int n);
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