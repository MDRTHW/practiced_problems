#include <bits/stdc++.h>

using namespace std;

double x[]={0.00,0.50,1.00};
double y[]={1.0000,0.6667,0.5000};
string value;
vector<string> temp;
int n;
#define pi 3.1415926



void input()
{
    ///if inputs are taken from file
     /*fstream file;
     file.open("simpson.txt");
     while( ! file.eof())
     {
         file>>value;
         temp.push_back(value);
         value.clear();
     }
     for(int i=0,j=0;i<temp.size();i+=2,j++)
        x[j]= stod (temp.at(i));
     for(int i=1,j=0;i<temp.size();i+=2,j++)
        y[j]= stod (temp.at(i));    */



}


void table_transformation()
{
    for(int i=0;i<n;i++)
    {
        y[i]=y[i]*y[i];
       //y[i].setprecision(4);
    }
}

void table()
{

    cout<<"x\t"<<"y"<<endl;
    for(int i=0;i<n;i++)
        cout<<fixed<<setprecision(4)<<x[i]<<"\t"<<fixed<<setprecision(4)<<y[i]<<endl;
}

double calculation()
{
    double h=x[1]-x[0];
    double result=0,oddsum=0,evensum=0;

    for(int i=1;i<n-1;i++)
    {
        if(i%2==0)
            evensum+=y[i];
        else
            oddsum+=y[i];
    }


    result=((double)((pi*h)/(3*1.0))*(y[0]+ (4*oddsum) + (2*evensum) + y[n-1]));

    return result;

}

int main()
{
    ///Step I : taking input
    input();
    cout<<"Give the total number of values: ";
    cin>>n;

    ///Step II : making the table pre4pared
    table_transformation();

    ///show_the_table
    table();

    ///Step III : calculate
    double result;
    result=calculation();
    cout<<endl<<"The volume of the solid formed is= "<<fixed<<setprecision(4)<<result<<endl;


    return 0;
}
