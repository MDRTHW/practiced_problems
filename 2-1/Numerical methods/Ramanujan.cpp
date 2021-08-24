#include <bits/stdc++.h>

using namespace std;
void ramanujan();
void gennew();

double f1(double x)
{
    return x*x*x-x*x-x+1;
}

double f2 (double x)
{
   return  3.0*x*x-2.0*x-1;
}

double f3(double x)
{
    return 6.0*x-2;
}

void gennew()
{
    cout<<"                     Generalized Newton Rapson method"<<endl;
    double x=0.8,x1,t,s;
    int i=0;
    cout<<"Iteration"<<"    "<<"Root"<<endl;
    while(1)
    {
        i++;
        t=x-2.0*f1(x)/f2(x);
        s=x-f2(x)/f3(x);

        if(fabs(t-s)>0.0001)
        {
            x=s;
            cout<<"    "<<i<<"     "<<s<<endl;
        }
        else
            break;
    }

    cout<<"Root is :"<<fixed<<s<<endl<<endl;
}

void ramanujan()
{
    cout<<"                         Ramanujan's Method"<<endl;
    int deg;
    double ka[20],a[100],b[100],ratio1=0,ratio2=0,diff=0;
    int i,j,k;

    for(i=0;i<100;i++)
    {
        a[i]=0;
        b[i]=0;
    }
    cout<<"Give the degree: ";
    cin>>deg;
    cout<<"Give the co-eficient: ";
    for(i=0;i<deg+1;i++)
    {
        cin>>ka[i];
    }
    cout<<"Give the root accuracy difference: ";
    cin>>diff;
    for(i=0,k=deg-1;i<deg;i++,k--)
        a[i]=(double)((-1)*(ka[k]/ka[deg]));

    b[0]=1;
    b[1]=a[0];
    ratio1=(double)(b[0]/b[1]);
    cout<<"Iteration          "<<"bi[i]          "<<"b[i-1]/b[i]"<<endl;
    for(i=2;abs(ratio1-ratio2)>diff;i++)
    {

        ratio1=ratio2;
        for(j=0,k=i-1;k>=0;k--,j++)
        {
            b[i]=a[j]*b[k]+b[i];

        }
        cout<<i-1<<"                     "<<b[i]<<"                "<<ratio2<<endl;
        ratio2=(double)(b[i-1]/b[i]);


    }


    cout<<endl<<endl<<"The result by Ramanujan's method is= "<<ratio2<<endl<<endl;
}



int main()
{

    int n;
    for(;;)
    {
        cout<<"Choose one:"<<endl;
        cout<<"1. Ramnujan's method"<<endl;
        cout<<"2. Generalized newton Rapson method"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>n;
        if(n==1)
            ramanujan();
        else if(n==2)
            gennew();
        else
            break;
        }
    return 0;
}
