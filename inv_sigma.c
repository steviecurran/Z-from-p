#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
 
int main()
{
  int i,npts=99999;
  double prob, whole_prob,x[npts], y[npts], A, a[npts],*area; 
  float ytop, top, norm,sigma,xline[npts], yline[npts];
  
  norm = pow((2*3.141592654),0.5);

   ytop = (1/norm)*exp(-0.5*top*top);
   for (i=0; i<npts; ++i){
       x[i]=(-1*top) + 2*(top/npts)*i;   xline[i] = (float)x[i];
       y[i]=(1/norm)*exp(-0.5*x[i]*x[i]);  yline[i] = (float)y[i];
       a[i] = (x[i]-x[i-1])*y[i];
       a[i]=a[i]+a[i-1];
       area = &a[i];
       A = *area;
   }
 
 printf("Enter Z-value [sigma]: "); scanf("%f", &sigma); 

 top = 20;
 printf("\ntop = %1.0f, set this to 100 if dealing with\nridiculously small probabilities (has to be > sigma)", top);
 npts = 100000; 
 
 for (i=0; i<npts; ++i){ 
   a[0] = 0; 
   x[i] = sigma + ((top-sigma)/npts)*i; xline[i] = (float)x[i];
   y[i]=(1/norm)*exp(-0.5*x[i]*x[i]); yline[i] = (float)y[i];

      a[i] = (x[i]-x[i-1])*y[i];  
      a[i]=a[i]+a[i-1];  // summing up
                
	    area = &a[i];
	    A = *area;
 }

 printf("\nOne-sided probability, p = %1.3g",A);
 printf("\nTwo-sided probability, p = %1.3g\n",2*A);
// two tails, cf. http://davidmlane.com/hyperstat/z_table.html
}
// gcc -o inv_sigma inv_sigma.c; ./inv_sigma
