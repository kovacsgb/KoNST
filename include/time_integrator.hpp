class TimeIntegrator
{
    public:
    virtual double advance(double yn, double dt) = 0;
};


class ForwardTime : public TimeIntegrator
{
    public:
    double advance(double yn, double dt) override;
};


