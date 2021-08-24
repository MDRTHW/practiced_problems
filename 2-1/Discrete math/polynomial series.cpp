#include <iostream>

using namespace std;

int fact(int n)
{
    if(n==0)
        return 1;
    return n*fact(n-1);
}

int c(int n,int j)
{
    int result;
    result = fact(n)/(fact(n-j)*fact(j));
    return result;
}

int main()
{
    int n;
    cout<<"Give the value of n : ";
    cin>>n;

    cout<<"(x+y)^"<<n<<" = x^"<<n<<" + ";
    for(int j=1;j<n;j++)
    {
        cout<<c(n,j)<<" x^"<<n-j<<" y^"<<j<<" + ";
    }
    cout<<"y^"<<n<<endl;
    return 0;
}
