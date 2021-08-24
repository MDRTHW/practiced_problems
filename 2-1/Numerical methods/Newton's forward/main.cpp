#include <bits/stdc++.h>

using namespace std;
int n=7;
double x[10];
double y[10][10];
string buffer;
vector<string> tmp;

void input()
{
    ifstream fl;
    fl.open("newtons.txt");
    while(!fl.eof())
    {
        fl>>buffer;
        tmp.push_back(buffer);
        buffer.clear();
    }

    for(int i=0, j=0;i<tmp.size();i+=2,j++)
        x[j]=stod(tmp.at(i));

        ///input y values
        for(int i=1, j=0;i<tmp.size();i+=2,j++)
        y[j][0]=stod(tmp.at(i));

}

void forward_difference_table()
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            y[j][i]= y[j+1][i-1]-y[j][i-1];
        }
    }
}

void draw_difference_table()
{
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<"\t";
        for(int j=0;j<n-i;j++)
        {
            cout<<y[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int factorial(int n)
{
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);
}

double p_val(int n, double p)
{
    double p_original=p;
    for(int i=1;i<n;i++)
        p_original=p_original*(p-i);
    return p_original;  ///p,p p(p-1),......
}



double interpolation(double val)
{
    double result= y[0][0];
    double h=x[1]-x[0];
    double p=(val-x[0])/h;

    for(int i=1;i<n;i++)
    {
        ///cout<<result<<endl;
        result = result + ( p_val(i,p)*y[0][i] )/factorial(i);
        ///cout<<result;
    }
    return result;
}

int main()
{
    ///step 1 : Input
    input();

    ///step 2 : Forward difference table
    forward_difference_table();
     /// Draw the difference table
     cout<<"The difference table:"<<endl;
     draw_difference_table();

     double val;

     while(true)
     {
         cout<<"Enter an interpolating value: "<<endl;
         cin>>val;

         if(val==0)
            break;

         double missing_value= interpolation(val);
         cout<<"Missing value for "<<val<<" is "<<missing_value<<endl;


     }

    return 0;
}
