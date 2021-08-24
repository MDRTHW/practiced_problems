#include <iostream>

using namespace std;

int main()
{
    int n,m,a,c,x[100];

    cout<<"Give the value of pseudo-numbers you want : ";
    cin>>n;
    cout<<"Give the value of modulus, multiplier, increment seed : ";
    cin>>m>>a>>c>>x[0];

    if((a>=0&&a<m)&&(c>=0&&c<m)&&(x[0]>=0&&x[0]<m))
    {
    for(int i=1;i<n;i++)
    {
        x[i]=((x[i-1]*a)+c)%m;
    }
    cout<<"The pseudo-random numbers are : ";
     for(int i=0;i<n;i++)
        cout<<x[i]<<",";
    }
    else
        cout<<"Invalid input"<<endl;



    cout<<endl;

    return 0;
}
