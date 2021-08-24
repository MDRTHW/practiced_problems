#include <bits/stdc++.h>

using namespace std;

double x[100];
double y[100];
double result=0, result1=0;
string buffer;
vector<string> tmp;
int n=9;




void input()
{
    ///if inputs are taken from file
     ifstream fl;

    fl.open("newtons3.txt");

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
        y[j]=stod(tmp.at(i));



}




void table()
{

    cout<<"x\t"<<"y"<<endl;
    for(int i=0;i<n;i++)
        cout<<fixed<<setprecision(4)<<x[i]<<"\t"<<fixed<<setprecision(4)<<y[i]<<endl;
}

void calculation()
{
    ///Step I : taking input
    input();
    ///show_the_table
    table();
    double h=x[1]-x[0];
    double oddsum=0,evensum=0;

    for(int i=1;i<n-1;i++)
    {
        if(i%2==0)
            evensum+=y[i];
        else
            oddsum+=y[i];
    }



    result=((double)(h/(3*1.0))*(y[0] + (4*oddsum) + (2*evensum) + y[n-1]));
    result1=((double)(h/(2*1.0))*(y[0] + 2*(oddsum+evensum)+y[n-1]));


}

int main()
{
    ///Step II : calculate


    calculation();
    cout<<endl<<"The result from Trapizoizal rule = "<<fixed<<setprecision(4)<<result1<<endl;
    cout<<"The result from Simson's rule = "<<fixed<<setprecision(4)<<result<<endl;



    return 0;
}
