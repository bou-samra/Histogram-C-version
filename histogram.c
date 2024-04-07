/************************************
 ** Display data file as Histogram **
 ** Jason Bou-Samra 06/04/2024     **
 ** Paragon Software               **
 ************************************/

#include <stdio.h>
#include <math.h>

int main()
{

int	N	= 10000;		// number of samples (data points)
int	nbin	=  round(sqrt(N));	// number of bins ~ sqrt(N) (or nearest integer value if not perfect square)
float	hist[nbin];			// histogram array
float	x[N];				// array of data points
float	xmax, xmin;			// minimum & maximum x data point values
float	summ;				// used to normalise data
float	dx;				// dx	= (xmax - xmin) / nbin (delta value)
int	i,j;				// index variables

FILE *fptr_r, *fptr_w;			// read and write file pointers

fptr_r = fopen("uniform.dat", "r");	// data points (read in)
fptr_w = fopen("dist3.dat", "w");	// the histogram output file (write out)

   if(fptr_r == NULL || fptr_w == NULL) {
      perror("Error opening file");
      return(-1);}			// handle fopen error, if any

for (i = 0; i < N+1; i++)
{
    fscanf(fptr_r, "%G", &x[i]);
}

xmin = x[1];				// search for xmin
for (i = 1 ; i < N+1 ; i++)
{
    if (x[i] < xmin) {
	xmin = x[i];
	}
}

xmax = x[1];				// search for xmax
for (i = 1 ; i < N+1 ; i++)
{
    if (x[i] > xmax) {
	xmax = x[i];
	}
}
    dx = (xmax - xmin) / (float)(nbin);	// calculate dx

for (j = 0 ; j < nbin+1 ; j++)		// compute histogram
{
    hist[j] = 0.0f;
    for (i = 0 ; i < N+1 ; i++)
    {
    if ((x[i] >= (xmin + (j - 1) * dx) && x[i] < xmin + j * dx))
	hist[j] = hist[j] + 1.0f;
	}
}

//summ = 0.0f;				// normalize
//for (i = 1 ; i < nbin ; i++) summ = summ + hist[i];
//for (i = 1 ; i < nbin ; i++) hist[i] = hist[i] / summ;

for (i = 1; i < nbin+1; i++)
{
	fprintf(fptr_w, "  %3.18f        %3.18f\n", xmin+i*dx, hist[i]);
}

return 0;
}
