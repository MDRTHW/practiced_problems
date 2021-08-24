#include <iostream>

using namespace std;

int main()
{
    int a[1010];
    int n,ans=0,m;

    cout<<"Give the integer size (digits) and divisor value = ";
    cin>>n>>m;

    cout<<"Input every digit with space"<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<n;i++)
    {
        ans= (ans*10+a[i])%m;
    }

    cout<<"Result = "<<ans<<endl;


    return 0;
}
