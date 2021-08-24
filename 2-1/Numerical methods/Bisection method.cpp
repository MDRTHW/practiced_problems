#include <bits/stdc++.h>

using namespace std;

double a,b,c,d;

int bic=0,falc=0;
void bisection();
void falseposition();
void compare();



double f(double x)
{
    return (a*x*x*x+b*x*x+c*x+d);
}

void bisection(double ia,double ib)
{
    cout<<endl<<endl<<"Bisection method"<<endl<<endl;
    double temp=0,x=0,i=0;
     if((f(ia)*f(ib))<0)
    {

        x=(double)((ia+ib)/2);
        while(abs(temp-x)>0.0001)
        {
            cout<<"a= "<<ia<<"      "<<"b= "<<ib<<"     "<<"x= "<<x<< "   dif="<<abs(temp-x)<<endl;

            if(i==0)
            {
               ///we are chnaging the x not the temp
            x=(double)((ia+ib)/2);
            if((f(ia)*f(x))<0)
                ib=x;
            else
                ia=x;

                i++;
                bic++;
            continue;
            }

            temp=x;
            x=(double)((ia+ib)/2);
            if((f(ia)*f(x))<0)
                ib=x;
            else
                ia=x;

                i++;
                bic++;
        }

    }
    else
        cout<<"Not possible"<<endl;

    cout<<endl<<"The root is x= "<<x<<endl;

}

void falseposition(double ia,double ib)
{
    cout<<endl<<endl<<"False position  method"<<endl<<endl;
    double temp=0,x=0,i=0;
    if((f(ia)*f(ib))<0)
    {

        x=(double)(((ia*f(ib))-(ib*f(ia)))/(f(ib)-f(ia)));
        while(abs(temp-x)>0.0001)
        {
            cout<<"a= "<<ia<<"      "<<"b= "<<ib<<"     "<<"x= "<<x<< "   dif="<<abs(temp-x)<<endl;

            if(i==0)
            {
               ///temp=x;
            x=(double)(((ia*f(ib))-(ib*f(ia)))/(f(ib)-f(ia)));
            if((f(ia)*f(x))<0)
                ib=x;
            else
                ia=x;

                i++;
                falc++;
            continue;
            }

            temp=x;
            x=(double)(((ia*f(ib))-(ib*f(ia)))/(f(ib)-f(ia)));
            if((f(ia)*f(x))<0)
                ib=x;
            else
                ia=x;

                i++;
                falc++;
        }

    }
    else
        cout<<"Not possible"<<endl;

    cout<<endl<<"The root is x= "<<x<<endl;


}

void compare(double ia,double ib)
{

    bisection(ia,ib);
    falseposition(ia,ib);
    cout<<"Total loop needed for bi-section method= "<<bic<<endl;
    cout<<"Total loop needed for false position method ="<<falc<<endl;
}

int main()
{
    int i=0;
    double ia,ib;
    cout<<"Give the co-efficient as(ax^3+bx^2+cx+d=0): ";
    cin>>a>>b>>c>>d;
    cout<<"Give two intervals: ";
    cin>>ia>>ib;
    for(;;)
    {
        int n;
        cout<<"Choose one: "<<endl<<"1. Bi-section method"<<endl<<"2. False position method"<<endl<<"3. Compare"<<endl<<"4. Exit"<<endl;
        cin>>n;
        if(n==1)
            bisection(ia,ib);
        else if(n==2)
            falseposition(ia,ib);
        else if(n==3)
            compare(ia,ib);
        else
            break;
    }


    return 0;
}
