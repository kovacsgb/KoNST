#include <cstdarg>
#include <vector>

class Grid
{
private:
    
public:
    virtual void set_element(double value, int indices...) = 0;
    virtual double get_element(int indices...) const = 0;
};



class Grid1D : public Grid
{
    private:
        int N;
        int N_ghost;
        std::vector<double> mesh;
    public:
        Grid1D(int N,int N_ghost) : N(N), N_ghost(N_ghost),
        mesh(std::vector<double>(N + 2 * N_ghost, 0.0))
        {
        }
        void set_element(double value, int indices...) override;
        double get_element(int indices...) const override;
        
};