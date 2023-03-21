#include <complex>
#include <iostream>
#include "a3.h"

using namespace std;

//
//  Function:  mandelbrot()
//
//  The function loops over a regular grid of points in the complex plane defined by the
//  parameters 'left', 'bottom', 'right', and 'top'. The density of the grid is determined
//  by the values of NROW and NCOL that are defined in a3.h. For each point of the grid
//  the iteration function do_mandelbrot() is called. The number of iterations returned
//  by this function is stored in the array 'counter[][]'.
//
void mandelbrot(int max_depth, double left, double bottom,
                double right, double top, int counter[][NCOL])
{
    // #pragma omp parallel for schedule(static,1)
    // #pragma omp parallel for collapse(2) schedule(static,1)
    // #pragma omp parallel for schedule(dynamic,1)
    #pragma omp parallel for collapse(2) schedule(dynamic, 1)
    for (int nr = 0; nr < NROW; ++nr)
    {
        for (int nc = 0; nc < NCOL; ++nc)
        {
            // Calculate position in complex plane
            complex<double> c((0.5 + nr) * (right - left) / NCOL + left,
                              (0.5 + nc) * (top - bottom) / NROW + bottom);

            // Iterate the mandelbrot sequence.
            counter[nr][nc] = do_mandelbrot(max_depth, c);
        }
    }
}
