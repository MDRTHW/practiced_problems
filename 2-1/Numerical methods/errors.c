#include <stdio.h>
#include <math.h>

int main()
{
    ///problem 1
    /*
    double x1=22/7,x2=3.1416,ea,er,ep;
    ea=abs(x1-x2);
    er=ea/x1;
    ep=er*100;
    printf("Absolute error EA=%lf\n",ea);
    printf("Relative error ER=%lf\n",er);
    printf("Percentage error EP=%lf\n",ep);

    */

    ///problem 2
    double s,a=1.414214,b=1.732051,c=2.2336068,s1,ea,er,ep;
    s1=a+b+c;
    ea=abs(s-s1);
    er=ea/abs(s);
    ep=er*100;
    printf("Absolute error EA=%lf\n",ea);
    printf("Relative error ER=%lf\n",er);
    printf("Percentage error EP=%lf\n",ep);
    return 0;
}
