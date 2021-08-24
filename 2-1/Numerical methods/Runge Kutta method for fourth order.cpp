///Given y(0.1),y(0.2),y(0.3)  equation y'= 1+ (2xy)/(1+x^2),  y(0)=0

#include <iostream>

using namespace std;
double y[100];
double k[100];
double h=0.1;



void calculate_k(double x,int p)
{
   k[0]= h*(1+(2*x*y[p]/(1+x*x)));

   k[1]= h*(1+((2*(x+.5*h)*(y[p]+.5*k[0]))/(1+(x+.5*h)*(x+.5*h))));

   k[2]= h*(1+((2*(x+.5*h)*(y[p]+.5*k[1]))/(1+(x+.5*h)*(x+.5*h))));

   k[3]= h*(1+((2*(x+h)*(y[p]+k[2]))/(1+(x+h)*(x+h))));

}

double RK_method(double x,int p)
{
    calculate_k(x,p);

    y[p+1]=y[p]+ (.1667)*(k[0]+2*k[1]+2*k[2]+k[3]);

    return y[p+1];
}

int main()
{
    cout<<"\t\tSolving problem using Runge Kutta method for fourth order"<<endl<<endl;
    y[0]=0;
    cout<<"The result for y(0.1) = "<<RK_method(0,0)<<endl;
    cout<<"The result for y(0.2) = "<<RK_method(.1,1)<<endl;
    cout<<"The result for y(0.3) = "<<RK_method(.2,2)<<endl;

    return 0;
}
