#include <complex>
#include <cstddef>
#include <iostream>
#include <sys/time.h>

using namespace std;

//
// The function mandelbrot() and the image sizes are declared in the header a3.h.
//
#include "a3.h"

namespace
{
    double dtime();
};

//
//  Function:  do_mandelbrot()
//
//  Iterates the complex series z_n = (z_n-1)^2 + c witj z_0 = 0. Iterations
//  are stopped after max_depth iterations or if the absolute value of z
//  becomes larger than 2.
//
int do_mandelbrot(int max_depth, complex<double> c)
{
    complex<double> z = 0.;
    int count = 0;

    // Iteration loop
    for (count = 0; count < max_depth; ++count)
    {
        if (norm(z) > 4.)
        {
            break;
        }
        z = z * z + c;
    }

    return count; // Return number of iterations
}

//
//  Function:  main()
//
//  The program calls the function mandelbrot() to compute a single image of the Mandelbrot set.
//  The execution time of the call is measured and reported. The image data returned by
//  mandelbrot() are not used.
//
int main()
{
    // Maximum number of iterations
    const int MAX_DEPTH = 10000;

    // "Image" values
    int counter[NROW][NCOL];
    double sum = 0;
    for(int i = 0; i < 3; ++i) {
         double t_run = dtime();
        mandelbrot(MAX_DEPTH, -2, -1., 1., 1., counter);
        t_run = dtime() - t_run;

        // Print wall clock times
        cout.precision(3);
        cout << "Wall clock time: " << (t_run) << " s\n";
        sum += t_run;
    }
    cout << "avg: " << (sum/3) << " s\n";
}

namespace
{
    //
    //  Function: dtime()
    //
    //  Returns the time since the Epoch [1970-01-01 00:00:00 +0000 (UTC)]. The
    //  function combines the number of seconds and microseconds returned by
    //  gettimeofday into a double precision number.
    //
    double dtime()
    {
        struct timeval now;
        gettimeofday(&now, (struct timezone *)0);

        return 1.e-6 * now.tv_usec + now.tv_sec;
    }
}
