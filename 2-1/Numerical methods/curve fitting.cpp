/// Fitting a curve y=a/x+bx according to tabulated values
/// (x,y):(1,5.43),(2,6.28),(4,10.32),(6,14.86),(8,19.51)

#include <bits/stdc++.h>

using namespace std;

double x[]={1,2,4,6,8};
double y[]={5.43,6.28,10.32,14.86,19.51};
int n;
double a=0,b=0;
double sox=0,soy=0,soxx=0,soxy=0;
void table()
{

    cout<<"X=x^2\t"<<"Y=xy\t"<<"X^2=(x^2)^2\t"<<"XY=x^3y\t"<<endl;
    for(int i=0;i<n;i++)
    {
        sox=sox+x[i]*x[i];
        cout<<x[i]*x[i]<<"\t";

        soy=soy+x[i]*y[i];
        cout<<x[i]*y[i]<<"\t\t";

        soxx=soxx+ pow(x[i],4);
        cout<<pow(x[i],4)<<"\t";

        soxy=soxy+pow(x[i],3)*y[i];
        cout<<pow(x[i],3)*y[i]<<"\t\t"<<endl;
    }
    cout<<endl<<"SOX="<<sox<<"   SOY="<<soy<<"   SOXX="<<soxx<<"   SOXY="<<soxy<<endl<<"m="<<n<<endl<<endl;
}


void calculate()
{
    b= (n*soxy - sox*soy)/(n*soxx-sox*sox);
    a= (soy/(n*1.0))-(b*(sox/n));
}

int main()
{
    cout<<"Give the number of tabulated values: ";
    cin>>n;

    ///Step I : Make required table
    table();

    ///Step II : Calculate a and b
    calculate();
    cout<<"The value of a is = "<<a<<" and b is = "<<b<<" ."<<endl;
    cout<<"The final form of the equation is y = "<<a<<"/x + "<<b<<"x"<<endl;
    return 0;
}
