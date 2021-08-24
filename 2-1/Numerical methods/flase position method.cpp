#include <bits/stdc++.h>

using namespace std;

double a,b,c,d;

double f(double x)
{
    return (a*x*x*x+b*x*x+c*x+d);
}

int main()
{
    int i=0;
    double ia,ib,temp=0,x=0;
    cout<<"Give the co-efficient as(ax^3+bx^2+cx+d=0): ";
    cin>>a>>b>>c>>d;
    cout<<"Give two intervals: ";
    cin>>ia>>ib;

    if((f(ia)*f(ib))<0)
    {

        x=(double)(((ia*f(ib))-(ib*f(ia)))/(f(ib)-f(ia)));
        while(abs(temp-x)>0.0001)
        {
            cout<<"a= "<<ia<<"      "<<"b= "<<ib<<"     "<<"x= "<<x<<endl;

            if(i==0)
            {
               ///temp=x;
            x=(double)(((ia*f(ib))-(ib*f(ia)))/(f(ib)-f(ia)));
            if((f(ia)*f(x))<0)
                ib=x;
            else
                ia=x;

                i++;
            continue;
            }

            temp=x;
            x=(double)(((ia*f(ib))-(ib*f(ia)))/(f(ib)-f(ia)));
            if((f(ia)*f(x))<0)
                ib=x;
            else
                ia=x;

                i++;
        }

    }
    else
        cout<<"Not possible"<<endl;

    cout<<endl<<"The root is x= "<<x<<endl;

    return 0;
}
