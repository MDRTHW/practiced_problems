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

int p(int n, int j)
{
    int result;
    result = fact(n)/fact(n-j);
    return result;
}
int main()
{
    int n,r;
    cout<<"Give the value of n : ";
    cin>>n;
    cout<<"Give the value for r : ";
    cin>>r;
    cout<<"r-permutations of a set n : "<<p(n,r)<<endl;
    cout<<"r-combinations of a set n : "<<c(n,r)<<endl;
    return 0;
}
