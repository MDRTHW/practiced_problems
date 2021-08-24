#include <bits/stdc++.h>

using namespace std;

int arr[10000];
int k=0;
void binary(int n)
{
    while(n!=0)
    {
        arr[k]=n%2;
        n=n/2;
        k++;
    }


}

int main()
{
    int b,n,m;
    cout<<"Give b,n,m : ";
    cin>>b>>n>>m;

    binary(n);

    int x=1,power=0;

    power=b%m;

    for(int i=0;i<k;i++)
        {
            cout<<i<<"\t"<<arr[i]<<"\t";
            if(arr[i]==1)
            x= (x*power)%m;

            cout<<x<<"\t";

            power=(power*power)%m;
            cout<<power<<"\t"<<endl;
        }

    cout<<"Result = "<<x<<endl;




    return 0;
}
