#include <cstdarg>
#include <vector>

class Grid
{
protected:
    int nvars;
    
public:
    Grid(int nvar) : nvars(nvar) {}
    virtual ~Grid();
    virtual void set_element(double value, int indices...) = 0;
    virtual double get_element(int indices...) const = 0;
    virtual void update(Grid& new_grid)=0;
};



class Grid1D : public Grid
{
    private:
        int N;
        int N_ghost;
        std::vector<double> mesh;
    public:
        Grid1D(int N,int N_ghost,int nvar) : Grid(nvar), N(N), N_ghost(N_ghost),
        mesh(std::vector<double>(N + 2 * N_ghost, 0.0))
        {
        }
        void set_element(double value, int indices...) override;
        double get_element(int indices...) const override;
        void update(Grid& new_grid) override;
};