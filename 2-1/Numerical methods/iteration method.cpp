#include <bits/stdc++.h>

using namespace std;
double a,b,c,d;
int itc=0,nrc=0;
double newton,iter;


void iteration();
void newton_rapson();
void compare();
double f(double x);
double fp(double x);

double f(double x)
{
    return (x*x*x-2*x-5);
}

double fp(double x)
{
    return (3*x*x-2);
}

void iteration()
{
    double temp=0,x;
    int i;
    cout<<"Give the guess value: ";
    cin>>x;
    //x=(sqrt((5.0/x)+2.0));
    x=sqrt(((-d-b*x*x)/x-c)/a);
   for( i=0;abs(temp-x)>.0001;i++)
   {
       cout<<"X= "<<x<<endl;
       temp=x;
       // x=(sqrt((5.0/x)+2.0));
       x=sqrt(((-d-b*x*x)/x-c)/a);
        itc++;

   }
   iter=x;
   cout<<"The result is = "<<x<<endl;
}

void newton_rapson()
{
     double temp=0,x;
    int i;
    cout<<"Give the guess value: ";
    cin>>x;
    x=(double)(x-(double)(f(x)/fp(x)));
    for( i=0;abs(temp-x)>.0001;i++)
    {
        cout<<"X= "<<x<<endl;
        temp=x;
        x=(double)(x-(double)(f(x)/fp(x)));
        nrc++;
    }
    newton=x;
    cout<<"The result is = "<<x<<endl;
}
void compare()
{
    iteration();
    newton_rapson();
    cout<<endl<<endl<<endl;
    cout<<"Total loop needed for iteration method= "<<itc<<"    "<<"x= "<<iter<<endl;
    cout<<"Total loop needed for Newton Rapson method= "<<nrc<<"    "<<"x="<<newton<<endl<<endl;
}

int main()
{

    int deg,n;
    cout<<"Give the degree: ";
    cin>>deg;
    cout<<"Give the co-efficient: ";
    cin>>a>>b>>c>>d;

        for(;;)
    {
        cout<<"Choose one :"<<endl<<"1. Iteration method"<<endl<<"2. Newton Rapson method"<<endl<<"3. Compare"<<endl<<"4. Exit";
        cin>>n;
        if(n==1)
            iteration();
        else if(n==2)
            newton_rapson();
        else if(n==3)
            compare();
        else
            break;
        cout<<endl<<endl;
    }

    return 0;
}
