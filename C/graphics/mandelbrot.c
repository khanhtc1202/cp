#include "stdio.h"
 
#define MaxIters 200
#define SIZE     80
#define BLACK    -1
#define LEFT     -2.0
#define RIGHT    1.0
#define TOP      1.0
#define BOTTOM   -1.0
 
main(int argc, char *argv[])
{
    short   x, y, count;
    long double zr, zi, cr, ci;
    long double rsquared, isquared;
 
    for (y = 0; y < SIZE; y++)
    {
        for (x = 0; x < SIZE; x++)
        {
            zr = 0.0;
            zi = 0.0;
            cr = LEFT + x * (RIGHT - LEFT) / SIZE;
 
            ci = TOP + y * (BOTTOM - TOP) / SIZE;
            rsquared = zr * zr;
            isquared = zi * zi;
 
            for (count = 0; rsquared + isquared <= 4.0
                            && count < MaxIters; count++)
            {
                zi = zr * zi * 2;
                zi += ci;
 
                zr = rsquared - isquared;
                zr += cr;
 
                rsquared = zr * zr;
                isquared = zi * zi;
            }
 
            if (rsquared + isquared <= 4.0)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
