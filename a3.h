//
//  Header for assignment 3.
//  Declares the functions mandelbrot() and do_mandelbrot() as well as the image dimensions.
//

#ifndef a3_h
#define a3_h

#include <complex>
#include <cstddef>

static const std::size_t  NROW = 480;
static const std::size_t  NCOL = 720;


int  do_mandelbrot(int,std::complex<double>);
void mandelbrot(int,double,double,double,double,int[][NCOL]);

#endif
