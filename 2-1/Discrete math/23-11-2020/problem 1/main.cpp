#include <iostream>

using namespace std;

int main()
{
    long long int a,b,c,m;
    long long int result=0;
    cin>>a>>b>>c>>m;

    result=((a%m)*(b%m)*(c%m))%m;

    cout<<"Result = "<<result<<endl;

    return 0;
}
