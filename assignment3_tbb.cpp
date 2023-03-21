#include <complex>
#include <iostream>
#include "a3.h"
#include <tbb/tbb.h>

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
    tbb::parallel_for(tbb::blocked_range2d<size_t>(0, NROW, 0, NCOL), [&](const tbb::blocked_range2d<size_t> &r)
                      {
        for (int nr = r.rows().begin(); nr < r.rows().end(); ++nr) {
            for (int nc = r.cols().begin(); nc < r.cols().end(); ++nc) {
                 // Calculate position in complex plane
                complex<double> c((0.5+nr)*(right-left)/NCOL + left,(0.5+nc)*(top-bottom)/NROW + bottom);
                
                // Iterate the mandelbrot sequence.
                counter[nr][nc] = do_mandelbrot(max_depth, c);
            }
        } });
}

//This version is using just the tbb::blocked_range

// void mandelbrot(int max_depth, double left, double bottom, 
//                   double right, double top, int counter[][NCOL])
// {
//     tbb::parallel_for(tbb::blocked_range<size_t>(0, NROW), [&](tbb::blocked_range<size_t> r){
//         for (int nr = r.begin(); nr < r.end(); ++nr) {
//                 for(int nc = 0; nc < NCOL; ++nc) {
//                     // Calculate position in complex plane
//                     complex<double> c((0.5+nr)*(right-left)/NCOL + left,
//                                   (0.5+nc)*(top-bottom)/NROW + bottom);
            
//                     // Iterate the mandelbrot sequence.
//                     counter[nr][nc] = do_mandelbrot(max_depth, c);
//                 }
//         }
//     });    
// }