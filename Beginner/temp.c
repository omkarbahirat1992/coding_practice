#include <stdio.h>
#include <math.h>

int main (void)
 {
   double param, result;
   param = 1024.0;
   result = sqrt (param);
   printf ("sqrt(%lf) = %lf\n", param, result );
   return 0;
}
