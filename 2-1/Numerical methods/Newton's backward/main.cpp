#include <bits/stdc++.h>

using namespace std;
int n;
double x[100];
double y[100][100];
string buffer;
vector<string> tmp;


void input()
{
    ifstream file;
    file.open("newback.txt");

    while(! file.eof() )
    {
     file>>buffer;
     tmp.push_back(buffer);
     buffer.clear();
    }

    for(int i=0,j=0;i<tmp.size();i+=2,j++)
        x[j]=stod(tmp.at(i));
    for(int i=1,j=0;i<tmp.size();i+=2,j++)
        y[j][0]=stod(tmp.at(i));

}

void backward_difference_table()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            y[i][j]=y[i][j-1]-y[i-1][j-1];
        }
    }
}


void draw_difference_table()
{
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<"\t";
        for(int j=0;j<=i;j++)
            cout<<y[i][j]<<"\t";

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

double p_val(int n,double p)
{
    double p_original=p;

    for(int i=1;i<n;i++)
        p_original=p_original*(p+i);
    return p_original;
}


double backward_interpolation(double val)
{
    double result=y[n-1][0];
    double h= x[1]-x[0];
    double p= (val-x[n-1])/h;

    for(int i=1;i<n;i++)
    {
        result = result + (p_val(i,p)*y[n-1][i])/factorial(i);

    }
    return result;
}

int main()
{
    ///Step-I : taking the input size
    cout<<"Give the input size: ";
    cin>>n;

    ///Step-II : making input
    input();

    ///Step-III : making difference table
    backward_difference_table();

    ///Step-IV : output difference table
    cout<<endl<<"The difference table: "<<endl;
    draw_difference_table();

    ///Step-V : calculate the missing value
    double val,result;

    while(1){
    cout<<"Give an interpolating  value:  ";
    cin>>val;
    result=backward_interpolation(val);

    cout<<"The missing value is : "<<result<<endl;
    }

    return 0;
}
